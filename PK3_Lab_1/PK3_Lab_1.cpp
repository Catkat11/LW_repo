#include <iostream>
#include <string>
#include "Header.h"
#include<conio.h>
#define Wypisz(x) std::cout << x << std::endl;
int main()
{
    lw::Vector<char> v1;
    v1.pushback('a');
    v1.pushback('b');
    for (int i = 0; i < v1.sizeGetter(); i++) 
    {
        std::cout << v1[i];
    }
    Wypisz("");

    lw::Vector<int> vTest1(1, 1);
    lw::Vector<int> vTest2(vTest1);
    vTest1[0] = 4;

    Wypisz(vTest1[0]);
    Wypisz(vTest2[0]);

    lw::Vector<int> v2;
    v2 = { 1,2,5,33 };
    for (int i = 0; i < v2.sizeGetter(); i++)
        Wypisz(v2[i]);
    lw::Vector<int> v3(1, 5);
    v2 = v3;
    for (int i = 0; i < v2.sizeGetter(); i++)
        Wypisz(v2[i]);
    _getch();
    lw::Vector<char>oneParamNumvber(4);
    for (int i = 0; i < oneParamNumvber.sizeGetter(); i++) 
    {
        Wypisz(oneParamNumvber[i]);
    }
}