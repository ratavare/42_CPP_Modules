#pragma once

#include <iostream>
#include <stdint.h>

typedef struct s_Data
{
	int n;
} Data;

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer& copy);
	Serializer& operator=(const Serializer& copy);
	~Serializer();
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
