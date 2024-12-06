#include "Product.h"
#include <iostream>

class ProductItem : public Product {
private:
    string expirationDate;

public:
    ProductItem(string n, string c, float p, int q, string expDate);
    void display() const override;
};
