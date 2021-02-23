#pragma once
#include"Item.h"
#include<vector>

struct Bag {
	std::vector<Item> items;
	float capacity; // udüwig
	float maxCapacity;
	float value;
};

void clearBag(Bag &bag) {
	bag.items.clear();
	bag.capacity = 0;
	bag.value = 0;
}

bool add(Bag &bag, Item item) {

	if (bag.capacity + item.weight <= bag.maxCapacity) {
		bag.capacity += item.weight;
		bag.value += item.value;
		bag.items.push_back(item);
		return true; // z powodzeniem dodano przedmiot
	}
	return false; // przedmiot za ciÍøki
}

Bag createBag(float maxCapacity, int memory) {
	Bag bag;
	bag.maxCapacity = maxCapacity;
	bag.capacity = 0;
	bag.value = 0;
	if(memory > 0) bag.items.reserve(memory);
	else bag.items.reserve(100);
	return bag;
}

void showBag(Bag &bag) {
	//for (auto i = bag.items.begin(); i < bag.items.end(); ++i) {
	for(int i = 0; i < bag.items.size(); ++i){
		showItem(bag.items[i]);
	}
}
