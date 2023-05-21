#include <windows.h>
#include <locale.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <functional>
#include <utility> 


bool comp_decrease(const std::pair<char, int>& a, const std::pair<char, int>& b)
{
	return a.second > b.second;
}

class MyCmp
{
public:
	bool operator()(const int lval, const int rval) const
	{
		return lval > rval ? true : false;
	}
};




template<typename T1, typename T2>
std::vector<std::pair<T1,T2>> sort(std::map<T1,T2>& map)
{
	

	std::vector<std::pair<T1, T2>> temp_vec;
	for (auto i : map)
	{
		temp_vec.push_back(i);
	}

	std::sort(temp_vec.begin(), temp_vec.end(), comp_decrease);
		
	return temp_vec;

}

template <typename M> void print(const M& m) {
	std::cout << m.size() << " elements: " << std::endl;

	for (const auto& p : m) {
		std::cout << "(" << p.first << "," << p.second << ") ";
	}

	std::cout << std::endl;
}


std::vector<std::pair<char, int>> input_processing(std::string& s)
{
	std::vector<std::pair<char, int>> vec;
	std::map <char, int> cr_char;

	for (auto ch : s)
	{

		if (cr_char.find(ch) == cr_char.end())
		{
			cr_char.emplace(ch, 1);
		}
		else
		{
			cr_char[ch] += 1;
		}
	}

	vec = sort(cr_char);
	return vec;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
 
	std::string str = { "Hello world!!" };

	std::vector<std::pair<char, int> > vec;

 
	vec= input_processing(str);
	

 	for (const auto &buf : vec)
	{
		std::cout << buf.first << "______" << buf.second << "\n";
	}
 
}	
