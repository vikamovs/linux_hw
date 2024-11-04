#include "ComplexNumber.h"
#include "Sort.h"
#include <iostream>
#include <vector>

int main()
{
	std::vector<ComplexNumber> complexNumbers = {
	ComplexNumber(3,4),
	ComplexNumber(1,2),
	ComplexNumber(5,1),
	ComplexNumber(2,3)
	};

	for(const auto& c : complexNumbers)
	{
		c.print();
		std::cout <<  c.abs() << std::endl;
	}

	SortComplex(complexNumbers);

	for(const auto& c : complexNumbers)
	{
		c.print();
		std::cout << c.abs() << std::endl;
	}

	return 0;
}
