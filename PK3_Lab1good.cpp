#include <iostream>
#include <string>
#include "Header.h"
#include<conio.h>

int main()
{
	lw::Vector<char> v1;
	v1.pushback('b');
	v1.pushback('c');
	for (int i = 0;i < v1.sizeGet(); i++)
	{
		std::cout << v1[i];
	}
}
