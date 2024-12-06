#include "Product.h"
#include "Item.h"
#include "ProductItem.h"
#include <vector>
#include <iostream>

class Supermarket {
private:
    vector<Product> products;

public:
    void addProduct(Product* product);
    void removeProduct(const string& name);
    void displayProducts() const;
    Product* searchProduct(const string& name);
    void sellProduct(const string& name, int quantity);
};
