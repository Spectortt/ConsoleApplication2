#include <string>
using namespace std;

class Product {
protected:
    string name;
    string category;
    float price;
    int quantity;

public:
    Product(string n, string c, float p, int q);
    virtual void display() const = 0;

    string getName() const;
    int getQuantity() const;
    void decreaseQuantity(int qty);
};
