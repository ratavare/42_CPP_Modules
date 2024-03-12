#pragma once

#include <iostream>
#include "Base.hpp"

class A : public Base
{
public:
	A() {std::cout << "A constructor called" << std::endl;}
	~A() {}
};

class B : public Base
{
public:
	B() {std::cout << "B constructor called" << std::endl;}
	~B() {}
};

class C : public Base
{
public:
	C() {std::cout << "C constructor called" << std::endl;}
	~C() {}
};