#include<iostream>
#include "bag.h"
#include "functions.h"
#include "item.h"


using namespace std;

int main() {
	string name_file = "odczyt.txt";
	vector<item> items;
	items = read_from_file(name_file);

	float max_capity;
	int a, b;
	cout << "Wpisz maksymalny rozmiar plecaka: ";
	cin >> max_capity;
	cout << "Wpisz liczbe generacji: ";
	cin >> a;
	cout << "Wpisz liczbe generwanych plecakow: ";
	cin >> b;

	vector<Bag> results;
	Bag result;
	for (int i = 0; i < b; ++i) {
		result = algorithme(items, max_capity, a);
		show_bag_2(result, items);
		results.push_back(result);
	}




	result = algorithme(items, max_capity, a);

	//show_bag_2(result, items);

	save_to_file(results, items);


	return 0;
}