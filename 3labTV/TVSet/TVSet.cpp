#include "stdafx.h"
#include "TVSet.h"
#include <regex>



std::string DeleteSpaces(const std::string & channelName)
{
	std::string str = std::regex_replace(channelName, std::regex("[ ]+"), " ");
	boost::trim(str);
	if (str == " ")
	{
		str.clear();
	}
	return str;
}

auto CTVSet::SearchChannelByNumberInMap(int channel)const
{
	return m_channelMap.find(channel);
}

auto CTVSet::SearchChannelByNameInMap(const std::string & str)const
{
	return (std::find_if(m_channelMap.begin(), m_channelMap.end(),
		[&](auto a) {return a.second == str; }));
}

bool CTVSet::IsChannelExists(int channel)const
{
	return SearchChannelByNumberInMap(channel) != m_channelMap.end();
}

bool CTVSet::IsChannelExists(const std::string & str)const
{
	return SearchChannelByNameInMap(str) != m_channelMap.end();
}

bool IsAvailableChannel(int channel)
{
	return channel >= 1 && channel <= 99;
}

bool CTVSet::IsTurnedOn()const
{
	return m_isOn;
}

void CTVSet::TurnOn()
{
	m_isOn = true;
}

void CTVSet::TurnOff()
{
	m_isOn = false;
}

int CTVSet::GetChannel()const
{
	return m_isOn ? m_selectedChannel : 0;
}
bool CTVSet::SelectChannel(int channel)
{
	if (IsAvailableChannel(channel) && m_isOn)
	{
		m_prevChannel = m_selectedChannel;
		m_selectedChannel = channel;
		return true;
	}
	return false;
}
int CTVSet::GetPreviousChannel()const
{
	return m_prevChannel;
}
bool CTVSet::SelectPreviousChannel()
{
	return SelectChannel(GetPreviousChannel()) && m_isOn;
}
bool CTVSet::SelectChannel(const std::string & channelName)
{
	int num = GetChannelByName(channelName);
	if (num != 0 && m_isOn)
	{
		SelectChannel(num);
		return true;
	}
	return false;
}
int CTVSet::GetChannelByName(const std::string & channelName)const
{
	int num = 0;
	std::string str = DeleteSpaces(channelName);
	if (IsChannelExists(str))
	{
		num = SearchChannelByNameInMap(str)->first;
	}
	return num;
}
bool CTVSet::SetChannelName(int channel, std::string const & channelName)
{
	std::string str = DeleteSpaces(channelName);
	if (IsAvailableChannel(channel) && m_isOn && !str.empty())
	{
		DeleteChannelByName(str);
		if (IsChannelExists(channel))
		{
			m_channelMap.erase(SearchChannelByNumberInMap(channel));
		}
		auto it = m_channelMap.begin();
		m_channelMap.insert(it, std::pair<int, std::string>(channel, str));
		return true;
	}
	return false;
}
bool CTVSet::DeleteChannelByName(const std::string & channelName)
{
	std::string str = DeleteSpaces(channelName);
	if (IsChannelExists(str) && m_isOn)
	{
		m_channelMap.erase(SearchChannelByNameInMap(str));
		return true;
	}
	return false;
}
std::string CTVSet::GetChannelName(int channel)const
{
	std::string str;
	if (IsAvailableChannel(channel) && m_isOn && IsChannelExists(channel))
	{
		str = SearchChannelByNumberInMap(channel)->second;
	}
	return str;
}
void CTVSet::PrintMap(std::ostream & out)const
{
	for (auto it = m_channelMap.begin(); it != m_channelMap.end(); ++it)
	{
		out << it->first << " - " << it->second << "\n";
	}
}
