#include "Serialize.hpp"

Serialize::Serialize()
{
	throw InitializationException();
}
Serialize::~Serialize()
{
}
Serialize::Serialize(const Serialize& other)
{
	(void)other;
	throw InitializationException();
}
Serialize& Serialize::operator=(const Serialize& other)
{
	(void)other;
	throw InitializationException();
}

uintptr_t Serialize::serialize (Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialize::deserialize (uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
