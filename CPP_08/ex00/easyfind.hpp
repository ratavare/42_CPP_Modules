#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
typename T::value_type* easyfind(T& container, int val) {
	typename T::iterator it = std::find(container.begin(), container.end(), val);
	if (it == container.end())
		return NULL;
	return &(*it);
}
