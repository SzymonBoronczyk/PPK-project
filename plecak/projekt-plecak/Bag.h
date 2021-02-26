#pragma once
#include"item.h"
#include<vector>

struct Bag {
	std::vector<int> item_id;
	float capacity; // udüwig
	float max_capacity;
	float value;
};

void clearBag(Bag &bag) {
	bag.item_id.clear();
	bag.capacity = 0;
	bag.value = 0;
}

bool add_to_bag(Bag &bag, item &item) {

	if (bag.capacity + item.weight <= bag.max_capacity) {
		bag.capacity += item.weight;
		bag.value += item.value;
		bag.item_id.push_back(item.id);
		return true; // z powodzeniem dodano przedmiot
	}
	return false; // przedmiot za ciÍøki
}

bool remove_item_from_bag(Bag &bag, const std::vector<item> &items, int remove_id) {
	if (bag.item_id.size() < remove_id || remove_id < 0) return false;
	bag.value -= items[remove_id].value;
	bag.capacity -= items[remove_id].weight;
	auto it = bag.item_id.begin();
	for (int i = 0; i < bag.item_id.size(); ++i) {
		if (bag.item_id[i] == remove_id) {
			bag.item_id.erase(it);
			return true;
		}
		it++;
	}
	return false;
}


Bag create_bag(float maxCapacity) {
	Bag bag;
	bag.max_capacity = maxCapacity;
	bag.capacity = 0;
	bag.value = 0;
	return bag;
}

void show_bag(Bag &bag, std::vector<item> items) {
	//for (auto i = bag.items.begin(); i < bag.items.end(); ++i) {
	int temp;
	for (int i = 0; i < bag.item_id.size(); ++i) {
		temp = bag.item_id[i];
		show_item(items[temp]);
	}
}

void show_bag_2(Bag &bag, std::vector<item> items) {
	std::cout << "Pojemnosc: " << bag.capacity << " / " << bag.max_capacity << std::endl;
	std::cout << "Wartosc: " << bag.value << std::endl;
	std::cout << "Przedmioty: ";
	for (int i = 0; i < bag.item_id.size(); ++i) {
		std::cout << bag.item_id[i] << " ";
	}
	std::cout << std::endl;
}

bool is_in_bag(Bag &bag, int item_id) {
	for (int i = 0; i < bag.item_id.size(); ++i) {
		if (bag.item_id[i] == item_id) return true;
	}
	return false;

}
