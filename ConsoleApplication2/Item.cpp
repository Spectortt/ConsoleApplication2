#include "Item.h"

Item::Item(string n, string c, float p, int q)
    : Product(n, c, p, q) {}

void Item::display() const {
    cout << "Name: " << name << ", Category: " << category
        << ", Price: " << price << ", Quantity: " << quantity << endl;
}
