
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include "Stopwatch.h"
#include <queue>
#include <stack>


int main()
{
	const size_t size = 1'000'000;
	ap::Stopwatch sw;
	
	//set dodawanie

	std::set<int> s;
	sw.Start();
	for (size_t i = 0; i < size; ++i) s.insert(i);
	sw.Stop();
	std::cout << "dodawanie setu: " << sw.ToString() << std::endl;

	//set wyszukiwanie

	sw.Start();
	s.find(500'000);
	sw.Stop();
	std::cout << "wyszukiwanie setu: " << sw.ToString() << std::endl;

	//set usuwanie
	sw.Start();
	for (size_t i = 0; i < size; ++i) s.erase(i);
	sw.Stop();
	std::cout << "usuwanie setu: " << sw.ToString() << std::endl;

	//map dodawanie

	std::map<int, int> m;
	sw.Start();
	for (size_t i = 0; i < size; ++i) m.insert(std::pair<int, int>(i, i));
	sw.Stop();
	std::cout << "dodawanie mapy: " << sw.ToString() << std::endl;


	//map wyszukiwanie

	sw.Start();
	m.find(500000);
	sw.Stop();
	std::cout << "wyszukiwanie mapy: " << sw.ToString() << std::endl;

	//map usuwanie

	sw.Start();
	for (size_t i = 0; i < size; ++i) m.erase(i);
	sw.Stop();
	std::cout << "usuwanie mapy: " << sw.ToString() << std::endl;

	// dodawanie unordered_map

	std::unordered_map<int, int> um;
	sw.Start();
	for (size_t i = 0; i < size; ++i) um.insert(std::pair<int, int>(i, i));
	sw.Stop();
	std::cout << "dodawanie unordered_mapy: " << sw.ToString() << std::endl;

	//unordered_map wyszukiwanie

	sw.Start();
	um.find(500000);
	sw.Stop();
	std::cout << "wyszukiwanie unordered_mapy: " << sw.ToString() << std::endl;

	//unordered_map usuwanie

	sw.Start();
	for (size_t i = 0; i < size; ++i) um.erase(i);
	sw.Stop();
	std::cout << "usuwanie unordered_mapy: " << sw.ToString() << std::endl;

	//dodawanie do wektora
	sw.Start();
	std::vector<int> v;
	for (size_t i = 0; i < size; ++i) v.insert(v.begin(),i);
	sw.Stop();
	std::cout << "dodawanie wektora: " << sw.ToString() << std::endl;

	//wyszukiwanie wektora

	sw.Start();
	for (size_t i = 0; i < size; ++i)
	{
		if (v[i] == size / 2)
			break;
	}
	sw.Stop();
	std::cout << "wyszukiwanie wektora: " << sw.ToString() << std::endl;

	//usuwanie wektora
	/*sw.Start();
	for (size_t i = 0; i < size; ++i) v.erase(v.begin());
	sw.Stop();
	std::cout << "usuwanie wektora: " << sw.ToString() << std::endl;
	*/
	//dodawanie queue

	std::queue<int> q;
	sw.Start();
	for (size_t i = 0; i < size; ++i) q.push(i);
	sw.Stop();
	std::cout << "dodawanie queue: " << sw.ToString() << std::endl;
	
	//usuwanie queue

	sw.Start();
	for (size_t i = 0; i < size; ++i) q.pop();
	sw.Stop();
	std::cout << "usuwanie queue: " << sw.ToString() << std::endl;

	//dodawanie stack
	std::stack<int> st;
	sw.Start();
	for (size_t i = 0; i < size; ++i) st.push(i);
	sw.Stop();
	std::cout << "dodawanie stack: " << sw.ToString() << std::endl;

	//usuwanie stack

	sw.Start();
	for (size_t i = 0; i < size; ++i) st.pop();
	sw.Stop();
	std::cout << "usuwanie stack: " << sw.ToString() << std::endl;


}
