#include <windows.h>
#include <locale.h>

#include <iostream>
#include <set>
#include <string>


class MyCmp
{
public:
	bool operator()(const int lval, const int rval) const
	{
		return lval > rval ? true : false;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");


	std::string buf;
	unsigned size=0;
	int val=0;
	std::set<int,MyCmp> set;
	std::cout << "Введите колличество элементов\n";
	std::cin >> size;
	std::cout << "Введите значения через 'Enter' для завершения введите 'exit'\n";

	while (true)
	{
		std::cin >> buf;
		if ("exit" == buf) { break; }
		int val = std::stoi(buf);
 		set.insert(val);
		std::cout << "Введите значения через 'Enter' для завершения введите 'exit'\n";
	}
	
	

	std::cout << "\n";

 	for ( auto &buf : set)
	{
		std::cout <<buf  << "\n";
	}

}	
