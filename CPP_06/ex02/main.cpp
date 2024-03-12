#include "ABC.hpp"
#include "Base.hpp"
#include <exception>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


Base* generate(void) {
	if (rand() % 3 == 0)
		return new A();
	else if (rand() % 2 == 0)
		return new B();
	else
		return new C();
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if ((dynamic_cast<B*>(p)))
		std::cout << "B" << std::endl;
	else if ((dynamic_cast<C*>(p)))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (const std::exception &e_A)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch(const std::exception& e_B)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch(const std::exception& e_C)
			{
				std::cout << "Unknown" << std::endl;
			}
			
		}
		
	}
}

int main(void)
{
	srand(time(0));
	for(int i = 0; i < 5; i++) {
		Base *base = generate();
    	identify(base);
    	identify(*base);
    	delete base;
	}
}