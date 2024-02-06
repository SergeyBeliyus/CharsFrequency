#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int main() {
	std::string str;
	std::map <char, unsigned int> data_map;
	std::vector<std::pair<unsigned int, char>> data_vector;

	std::cout << "Введите строку: ";
	std::getline(std::cin,str);
	for (const auto c : str) {
		if (data_map.count(c) > 0) {
			data_map[c]++;
		}
		else {
			data_map.insert({ c, 1 });
		}
	}

	for (const auto pair : data_map) {
		std::pair<unsigned int, char> temp;
		temp.first = pair.second;
		temp.second = pair.first;
		data_vector.push_back(temp);
	}

	std::sort(data_vector.begin(), data_vector.end(), std::greater<std::pair<unsigned int, char>>());

	for (const auto pair : data_vector) {
		std::cout << pair.second << " : " << pair.first << std::endl;
	}
}