#include <iostream>
#include <stdint.h>

struct Data{
	int	value;
	std::string name;
};

class Serialize
{
	private:
		Serialize();
		~Serialize();
		Serialize(const Serialize& other);
		Serialize& operator=(const Serialize& other);
	public:
		static uintptr_t serialize (Data* ptr);
		static Data* deserialize (uintptr_t raw);
		class InitializationException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Serialization Cannot be initialized";
				}
		};
};
