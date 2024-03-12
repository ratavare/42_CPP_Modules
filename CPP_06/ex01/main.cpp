#include "Serializer.hpp"

int main(void)
{
	Data data;
	
	data.n = 42;
	Data* data_ptr;
	uintptr_t uint_ptr;

	data_ptr = &data;
	uint_ptr = Serializer::serialize(data_ptr);
	data_ptr = Serializer::deserialize(uint_ptr);

	
	std::cout << data_ptr->n << std::endl;
}