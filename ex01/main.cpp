#include <iostream>
#include "Serialize.hpp"

int main()
{
	Data data;
	data.value = 42;
	data.name = "The Answer";

	uintptr_t raw = Serialize::serialize(&data);
	std::cout << "Serialized data to uintptr_t: " << raw << std::endl;
	Data* deserializedData = Serialize::deserialize(raw);
	std::cout << "Deserialized Data - value: " << deserializedData->value <<
		", name: " << deserializedData->name << std::endl;
	return 0;
}
