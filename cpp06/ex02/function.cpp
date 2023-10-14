#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base * generate(void)
{
	srand((unsigned int)time(NULL));
	if (rand() % 3 == 1)
	{
		A *a = new A;
		return (dynamic_cast<Base *>(a));
	}
	else if (rand() % 3 == 2)
	{
		B *b = new B;
		return (dynamic_cast<Base *>(b));
	}
	else
	{
		C *c = new C;
		return (dynamic_cast<Base *>(c));
	}
}

void identify(Base* p)
{
	A *a = dynamic_cast<A *>(p);
	if (a == NULL)
	{
		B *	b = dynamic_cast<B *>(p);
		if (b == NULL)
		{
			C *c = dynamic_cast<C *>(p);
			if (c == NULL)
			{
				std::cout<<"Error: Not Matching\n";
				return ;
			}
			std::cout<<"Type of Class: C\n";
			return ;
		}
		std::cout<<"Type of Class: B\n";
		return ;
	}
	std::cout<<"Type of Class: A\n";
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout<<"Type of Class: A\n";
		return ;
	}
	catch(std::bad_cast expt)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout<<"Type of Class: B\n";
			return ;
		}
		catch(std::bad_cast expt)
		{
			try
			{
				(void)dynamic_cast<C &>(p);
				std::cout<<"Type of Class: C\n";
				return ;
			}
			catch(std::bad_cast expt)
			{
				std::cerr << expt.what() << '\n';
			}
		}
	}
}