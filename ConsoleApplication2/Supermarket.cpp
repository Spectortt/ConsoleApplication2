#include "Supermarket.h"

void Supermarket::addProduct(Product* product) {
    products.push_back(product);
}

void Supermarket::removeProduct(const string& name) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if ((*it)->getName() == name) {
            products.erase(it);
            return;
        }
    }
}

void Supermarket::displayProducts() const {
    for (const auto& product : products) {
        product->display();
    }
}

Product* Supermarket::searchProduct(const string& name) {
    for (auto& product : products) {
        if (product->getName() == name) {
            return product;
        }
    }
    return nullptr;
}

void Supermarket::sellProduct(const string& name, int quantity) {
    Product* product = searchProduct(name);
    if (product && product->getQuantity() >= quantity) {
        product->decreaseQuantity(quantity);
        cout << "Sold " << quantity << " of " << name << ".\n";
    }
    else {
        cout << "Not enough quantity or product not found.\n";
    }
}
