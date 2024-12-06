#include "Product.h"
#include <iostream>

class Item : public Product {
public:
    Item(string n, string c, float p, int q);
    void display() const override;
};
