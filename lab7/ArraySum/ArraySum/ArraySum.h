#pragma once
#include <vector>

template <typename T>
T ArraySum(const std::vector<T> & arr)
{
	T sum = T();

	for (auto &elem : arr)
	{
		sum += elem;
	}

	return sum;
}