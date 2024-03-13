#pragma once

#include <iostream>

template <typename T>
void iter(T* array, int len, void (*f)(T&)) {
	if (!array)
		return ;
	for (int i = 0; i < len; i++)
		f(array[i]);
}

template <typename T>
void setToZero(T val) {
	val = 0;
}
