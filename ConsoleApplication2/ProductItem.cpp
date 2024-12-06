#include "ProductItem.h"

ProductItem::ProductItem(string n, string c, float p, int q, string expDate)
    : Product(n, c, p, q), expirationDate(expDate) {}

void ProductItem::display() const {
    cout << "Name: " << name << ", Category: " << category
        << ", Price: " << price << ", Quantity: " << quantity
        << ", Expiration Date: " << expirationDate << endl;
}
