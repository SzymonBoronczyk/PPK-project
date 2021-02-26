#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include"Item.h"
#include"Bag.h"
#include<ctime>


std::vector<item> read_from_file(const std::string &fileName) {

	std::ifstream file(fileName);
	std::vector<item> result;
	std::stringstream ss;
	std::string fileText, name;
	float weight, value;
	int i = 0;

	while (getline(file, fileText)) {
		ss << fileText;
		ss >> name >> weight >> value;
		result.push_back(create_item(i++, name, weight, value));
		ss.clear();
	}

	file.close();

	return result;
}

std::vector<Bag> generate(std::vector<item> &items, float max_capacity, int ammount_generations) {
	std::vector<Bag> result;
	int rand, items_size, temp = 0;

	items_size = items.size();

	srand(time(NULL));
	int generations = 0;

	while (generations++ < ammount_generations) {
		Bag bag = create_bag(max_capacity);

		while (true) {
			temp = 0;
			rand = std::rand() % items_size;
			if(is_in_bag(bag, rand)) rand = std::rand() % items_size;

			while (is_in_bag(bag, rand)) {
				temp++;
				rand = (rand + 1) % items_size;
				if (temp == items_size) break;
			}
			if (temp == items_size) break;


			temp = rand;

			while (!add_to_bag(bag, items[rand])) {

				do{
					rand = (rand + 1) % items_size;

				} while (is_in_bag(bag, rand));

				if (temp == rand) {
					temp = -1;
					break;
				}
			}

			if (temp == -1) break;
		}

		result.push_back(bag);

	}

	return result;
}


std::vector<Bag> selection(std::vector<Bag> bags, int quantity_selection) {
	std::vector<Bag> result;
	int vector_bags_size = bags.size();
	if (quantity_selection >= vector_bags_size) return result;
	auto it = bags.begin();
	int max = 0;
	for (int j = 0; j < quantity_selection; ++j) {
		for (int i = 0; i < vector_bags_size; ++i) {
			if (bags[max].value < bags[i].value) max = i;
		}
		result.push_back(bags[max]);
		it += max;
		bags.erase(it);
		it = bags.begin();
		max = 0;
		vector_bags_size--;
	}
	return result;
}

Bag cross(Bag bag1, Bag bag2, std::vector<item> &items) {
	int rand, bag1_item_id_size, temp, bag2_item_id_size; 
	int determinant; // dokladny item z wektora item, na ktory wskazuje rand
	auto it = bag1.item_id.begin();
	srand(time(NULL));
	bag1_item_id_size = (int)bag1.item_id.size();
	bag2_item_id_size = (int)bag2.item_id.size();

	for (int i = 0; i < bag1_item_id_size /2 ; ++i) {
		rand = std::rand() % (int)bag1.item_id.size();
		determinant = bag1.item_id[rand];
		remove_item_from_bag(bag1, items, determinant);
	}
	bag1_item_id_size = (int)bag1.item_id.size();

	while (true) {
		temp = 0;
		rand = std::rand() % bag2_item_id_size;		// w tym przypadku rand wsazuje na tablice item_id z bag2
		determinant = bag2.item_id[rand];

		if (is_in_bag(bag1, determinant)) {
			rand = std::rand() % bag2_item_id_size; 
			determinant = bag2.item_id[rand];
		}


		while (is_in_bag(bag1, determinant)) {
			temp++;
			rand = (rand + 1) % bag2_item_id_size;

			determinant = bag2.item_id[rand];

			if (temp == bag2_item_id_size) {
				break;
			
			}

		}

		if (temp == bag2_item_id_size) break;

		temp = rand;

		while (!add_to_bag(bag1, items[determinant])) {

			do {
				rand = (rand + 1) % bag2_item_id_size;
				determinant = bag2.item_id[rand];
			} while (is_in_bag(bag1, determinant));
			if (temp == rand) {
				temp = -1;
				break;
			}
		}

		if (temp == -1) break;
	}

	return bag1;

}