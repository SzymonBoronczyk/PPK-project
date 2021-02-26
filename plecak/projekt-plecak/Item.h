#pragma once
#include<iostream>
#include<string>

struct item {
	int id;
	std::string name;
	float weight;
	float value;

};


item create_item(int id, std::string name, float weight, float value) {
	item item;
	item.id = id;
	item.name = name;
	item.weight = weight;
	item.value = value;
	return item;
}

void show_item(item item) {
	std::cout << "Id: " << item.id << std::endl;
	std::cout << "Nazwa: " << item.name << std::endl;
	std::cout << "Waga: " << item.weight << std::endl;
	std::cout << "Wartosc: " << item.value << std::endl;
}



