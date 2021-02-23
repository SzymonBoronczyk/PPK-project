#pragma once
#include<string>


struct Item {
	std::string name;
	float weight;
	float value;
};


Item createItem(std::string name, float weight, float value) {
	Item item;
	item.name = name;
	item.weight = weight;
	item.value = value;
	return item;
}

void showItem(Item item) {
	std::cout << "Nazwa: " << item.name << std::endl;
	std::cout << "Waga: " << item.weight << std::endl;
	std::cout << "Wartosc: " << item.value << std::endl;
}
