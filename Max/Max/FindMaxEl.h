#pragma once
template <typename T, typename Less = std::less<T>>

bool FindMax(const std::vector<T> &vect, T &maxValue, const Less &less = Less())
{
	if (vect.size() == 0)
	{
		return false;
	}
	const T *max = &vect.front();

	for (const auto &element : vect)
	{
		if (less(*max, element))
		{
			max = &element;
		}
	}

	maxValue = *max;
	return true;
}