#include <iostream>
#include <string>
#include "Header.h"
#include<conio.h>
#define LOG(x) std::cout << x << std::endl;

int main()
{
	lw::Vector<char> v1;
	v1.pushback('b');
	v1.pushback('c');
	for (int i = 0;i < v1.sizeGet(); i++)
	{
		std::cout << v1[i];
	}
    
    lw::Vector<int> vTest1(1, 1);
    lw::Vector<int> vTest2(vTest1);
    vTest1[0] = 2;

    LOG(vTest1[0]);
    LOG(vTest2[0]);
    //_getch();
}
