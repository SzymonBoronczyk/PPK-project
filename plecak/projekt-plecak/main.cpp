#include<iostream>
#include "bag.h"
#include "functions.h"
#include "item.h"


using namespace std;

int main() {
	std::string name_file = "odczyt.txt";

	vector<item> items = read_from_file(name_file);
	int i = 0;
	while (i < items.size()) {
		show_item(items[i++]);
		cout << endl;
	}
	cout << "-----------" << endl;

	Bag bag = create_bag(15);
	
	for (int i = 0; i < items.size(); ++i) {
		cout << add_to_bag(bag, items[i]) << endl;
	}

	cout << "-----------" << endl;
	show_bag(bag, items);
	show_bag_2(bag, items);

	cout << " \n \n -------------\n  \n";

	vector<Bag> bags;
	bags.push_back(bag);
	bags.push_back(create_bag(20));

	for (int i = items.size() - 1; i > 0; --i) {
		cout << add_to_bag(bags[1], items[i])<< " ";
	}
	cout << endl;

	cout << "Plecak 1: ";
	show_bag_2(bags[0], items);

	cout << endl << "Plecak 2: ";
	show_bag_2(bags[1], items);

	bags.clear();

	bags = generate(items, 13, 20);

	cout << "\n \nWygenerowane plecaki: " << endl;
	for (int i = 0; i < 20; ++i) {
		cout << "Plecak " << i + 1 << " ";
		show_bag_2(bags[i], items);
		cout << endl;
	}

	bags = selection(bags, 5);

	cout << "\n \nSelekcja plecakow: " << endl;
	for (int i = 0; i < 5; ++i) {
		cout << "Plecak " << i + 1 << " ";
		show_bag_2(bags[i], items);
		cout << endl;
	}

	cout << "\n\n\nczy usuwarka dziala:  \n";
	cout << remove_item_from_bag(bags[0], items, 2)<<endl;
	cout << remove_item_from_bag(bags[0], items, 6)<<endl<<endl;
	show_bag_2(bags[0], items);

	cout << endl << endl << endl;
	Bag cross_bag;
	cross_bag = cross(bags[0], bags[1], items);
	show_bag_2(cross_bag, items);
	cout << endl;
	cross_bag = cross(bags[2], bags[3], items);
	show_bag_2(cross_bag, items);

	return 0;
}