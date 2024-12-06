#include "Supermarket.h"
#include <iostream>
#include <string>
using namespace std;

class SupermarketSystem {
private:
    Supermarket market;

    void adminMode() {
        int adminChoice;
        do {
            cout << "\n--- Admin Mode ---\n";
            cout << "1. Add product\n";
            cout << "2. Remove product\n";
            cout << "3. View all products\n";
            cout << "0. Back to main menu\n";
            cout << "Your choice: ";
            cin >> adminChoice;

            switch (adminChoice) {
            case 1: {
                string name, category, expirationDate;
                float price;
                int quantity, type;

                cout << "Enter product type (1 - General Item, 2 - Product with Expiration Date): ";
                cin >> type;

                cout << "Enter name: ";
                cin.ignore(); 
                getline(cin, name); 
                cout << "Enter category: ";
                getline(cin, category); 
                cout << "Enter price: ";
                cin >> price;
                cout << "Enter quantity: ";
                cin >> quantity;

                if (type == 2) {
                    cout << "Enter expiration date (YYYY-MM-DD): ";
                    cin >> expirationDate;
                    market.addProduct(new ProductItem(name, category, price, quantity, expirationDate));
                }
                else {
                    market.addProduct(new Item(name, category, price, quantity));
                }

                cout << "Product added successfully.\n";
                break;
            }
            case 2: {
                string name;
                cout << "Enter the name of the product to remove: ";
                cin.ignore(); 
                getline(cin, name); 

                market.removeProduct(name);
                cout << "Product removed (if it existed).\n";
                break;
            }
            case 3:
                cout << "\n--- All Products ---\n";
                market.displayProducts();
                break;

            case 0:
                cout << "Returning to main menu...\n";
                break;

            default:
                cout << "Invalid choice!\n";
                break;
            }
        } while (adminChoice != 0);
    }

    void userMode() {
        int userChoice;
        do {
            cout << "\n--- User Mode ---\n";
            cout << "1. View all products\n";
            cout << "2. Search for a product\n";
            cout << "3. Buy a product\n";
            cout << "0. Back to main menu\n";
            cout << "Your choice: ";
            cin >> userChoice;

            switch (userChoice) {
            case 1:
                cout << "\n--- All Products ---\n";
                market.displayProducts();
                break;

            case 2: {
                string name;
                cout << "Enter the name of the product to search: ";
                cin.ignore();
                getline(cin, name);

                Product* product = market.searchProduct(name);
                if (product) {
                    cout << "Product found:\n";
                    product->display();
                }
                else {
                    cout << "Product not found.\n";
                }
                break;
            }

            case 3: {
                string name;
                int quantity;

                cout << "Enter the name of the product to buy: ";
                cin.ignore();
                getline(cin, name); 
                cout << "Enter the quantity to buy: ";
                cin >> quantity;

                market.sellProduct(name, quantity);
                break;
            }

            case 0:
                cout << "Returning to main menu...\n";
                break;

            default:
                cout << "Invalid choice!\n";
                break;
            }
        } while (userChoice != 0);
    }

public:
    void run() {
        int mode;
        do {
            cout << "\n--- Select Mode ---\n";
            cout << "1. Admin\n";
            cout << "2. User\n";
            cout << "0. Exit\n";
            cout << "Your choice: ";
            cin >> mode;

            switch (mode) {
            case 1:
                adminMode();
                break;
            case 2:
                userMode();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice!\n";
                break;
            }
        } while (mode != 0);
    }
};

int main() {
    SupermarketSystem system;
    system.run();
    return 0;
}
