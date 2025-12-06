#include <iostream>

#include "Base.hpp"
#include <cstdlib>
#include <typeinfo>

Base *generate(void)
{

	srand(time(0));
	int randomNum = rand() % 3;
	Base *a = NULL;

	if (randomNum == 0)
	{
		std::cout << "A created" << std::endl;
		a = new A();
	}
	else if (randomNum == 1)
	{
		std::cout << "B created" << std::endl;
		a = new B();
	}
	else if (randomNum == 2)
	{
		std::cout << "C created" << std::endl;
		a = new C();
	}
	return (a);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "is an A type" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "is a B type" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "is a C type" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "is an A type" << std::endl;
		return ;
	}
	catch (std::bad_cast &bc)
	{
		(void)bc;
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "is a B type" << std::endl;
		return ;
	}
	catch (std::bad_cast &bc)
	{
		(void)bc;
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "is a C type" << std::endl;
		return ;
	}
	catch (std::bad_cast &bc)
	{
		(void)bc;
	}
}

int	main(void)
{
	Base *a = generate();
	identify(a);
	identify(*a);
	delete a;
	return (0);
}
