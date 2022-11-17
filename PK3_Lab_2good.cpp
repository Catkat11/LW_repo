#include <iostream>
#include<vector>
#include<algorithm>
#include<functional>

#define LOG(x) std::cout<< x << std::endl;


template <class T>

std::vector<T> CreateVector(const size_t size, std::function<T(const size_t)> f)
{
    std::vector<T> result(size);
    for (size_t i = 0; i < size; i++)
    {
        result[i] = f(i);
    }
    return result;
}


template <class T>
void RemoveMinMax(std::vector<T>& takimalytakiduzy)
{
    auto minmax = minmax_element(takimalytakiduzy.begin(), takimalytakiduzy.end());
    takimalytakiduzy.erase(minmax.first);
    takimalytakiduzy.erase(minmax.second);
}
void wypisz(const std::vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        LOG(v[i]);
    }
}


int main()
{

    //1

    auto potega = [](int x)
    {
        return std::pow(2, x);
    };
    std::vector<int> potegowy = CreateVector<int>(7, potega);
    wypisz(potegowy);


    //2

    std::function<int(int)> fibonacci;
    fibonacci = [&fibonacci](int x) -> int
    {
        if ((x == 1) or (x == 0)) return x;
        else {
            return (fibonacci(x - 1) + fibonacci(x - 2));
        }
    };
    std::vector<int> fibonacciowy = CreateVector<int>(15, fibonacci);
    wypisz(fibonacciowy);


    //3 

    std::vector<int> zbior = { 1,3,5,7,123,999,-999,0 };
    RemoveMinMax(zbior);
    wypisz(zbior);


    //4

    std::vector<int> parzyste = { 1,2,3,4,5,6,7,8,9,10 };
    int wynik_parzyste = std::count_if(parzyste.begin(), parzyste.end(), [](int x) {return x % 2 == 0; });
    std::cout << wynik_parzyste << std::endl;
    

    //5

    std::vector<int> multiplekser = { 1,3,2,2,3,3,3,4,4,4,4 };
    std::sort(multiplekser.begin(), multiplekser.end());
    auto it = std::unique(multiplekser.begin(), multiplekser.end(), [](const int x, const int y) {return x == y; });
    multiplekser.erase(it, multiplekser.end());
    wypisz(multiplekser);


    //6

    std::vector<int> positive = { 1,2,3,-1,-2,-3,34,-99 };
    it = std::remove_if(positive.begin(), positive.end(), [](const int x) {return x < 0; });
    positive.erase(it, positive.end());
    wypisz(positive);


    //7 
    std::vector<int> total = { 1,2,3,4,5,6,7,8,23,24 };
    it = std::remove_if(total.begin(), total.end(), [](const int x) {return x % 2 ==0; });
    total.erase(it, total.end());
    wypisz(total);


    //8

    std::vector<int> overwrite = { 1,23,4563,756,8,34,432,2,5,76 };
    int p1 = 999; 
    int p2 = 600;
    for_each(overwrite.begin(), overwrite.end(), [p1, p2](int& x) mutable {if (x > p1) x = p1; else if (x < p2) x = p2; });
    wypisz(overwrite);
}