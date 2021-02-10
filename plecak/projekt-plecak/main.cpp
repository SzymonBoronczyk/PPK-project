#include<iostream>
#include"Item.h"
#include"Bag.h"
using namespace std;

int main() {
	Item item = createItem("Kielich", 1000, 14.20);
	//show(item);
	Item item1 = createItem("Pierscien", 2000, 15.50);
	Bag bag = createBag(5000, 10);
	add(bag, item);
	add(bag, item1);
	showBag(bag);

	return 0;
}