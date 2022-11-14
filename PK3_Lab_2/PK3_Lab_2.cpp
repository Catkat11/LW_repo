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
    auto potega = [](int x)
    {
        return std::pow(2, x);
    };
    std::vector<int> potegowy = CreateVector<int>(7, potega);
    wypisz(potegowy);

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

    std::vector<int> zbior = { 1,3,5,7,123,999,-999,0 };
    RemoveMinMax(zbior);
    wypisz(zbior);


    //4

    std::vector<int> parzyste = { 1,2,3,4,5,6,7,8 };
    int wynik_parzyste = std::count_if(parzyste.begin(), parzyste.end(), [](int i) {return i % 2 == 0; });
    std::cout << wynik_parzyste;

    //5

    std::vector<int> multiplekser = { 1,2,2,3,3,3,4,4,4,4 };
    multiplekser.erase(std::unique(multiplekser.begin(), multiplekser.end(), multiplekser.end()));

    wypisz(multiplekser);

}