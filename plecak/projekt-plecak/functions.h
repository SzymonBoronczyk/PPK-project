#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include"Item.h"
#include"Bag.h"


std::vector<Item> readFromFile(const std::string &fileName) {

	std::ifstream file(fileName);
	std::vector<Item> result;
	std::stringstream ss;
	std::string fileText, name;
	float weight, value;
	
	while (getline(file, fileText)) {
		ss << fileText;
		ss >> name >> weight >> value;
		result.push_back(createItem(name, weight, value));
		ss.clear();
	}

	file.close();

		return result;
}