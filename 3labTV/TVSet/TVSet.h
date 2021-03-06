#pragma once

class CTVSet
{
	typedef std::map<int, std::string> ChannelMap;
public:
	bool IsTurnedOn()const;
	void TurnOn();
	void TurnOff();
	int GetChannel()const;
	bool SelectChannel(int channel);
	int GetPreviousChannel()const;
	bool SelectChannel(const std::string & channel);
	bool SetChannelName(int channel, const std::string & channelName);
	bool DeleteChannelByName(const std::string & channelName);
	std::string CTVSet::GetChannelName(int channel)const;
	int GetChannelByName(const std::string & channelName)const;
	bool SelectPreviousChannel();
	void CTVSet::PrintMap(std::ostream & out)const;

private:
	auto CTVSet::SearchChannelByNameInMap(const std::string & str)const;
	auto CTVSet::SearchChannelByNumberInMap(int num)const;
	bool IsChannelExists(int channel) const;
	bool IsChannelExists(const std::string & str)const;
	bool m_isOn = false;
	int m_selectedChannel = 1;
	int m_prevChannel = 1;
	ChannelMap m_channelMap;
};