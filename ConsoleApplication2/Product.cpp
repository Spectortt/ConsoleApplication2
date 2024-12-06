#include "Product.h"
#include <iostream>

Product::Product(string n, string c, float p, int q)
    : name(n), category(c), price(p), quantity(q) {}

string Product::getName() const {
    return name;
}

int Product::getQuantity() const {
    return quantity;
}

void Product::decreaseQuantity(int qty) {
    quantity -= qty;
}
