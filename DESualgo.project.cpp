#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <windows.h>
using namespace std;

// Structure for a product
struct Product {
    string name;
    double price;
    int quantity;
    Product* prev;
    Product* next;
};

// Class for online shopping system
class OnlineShopping {
private:
    Product* head;
    Product* tail;

public:
    OnlineShopping() {
        head = NULL;
        tail = NULL;
    }

    // Function to add a product to the shopping system
    void addProduct(const string& name, double price, int quantity) {
        Product* newProduct = new Product;
        newProduct->name = name;
        newProduct->price = price;
        newProduct->quantity = quantity;
        newProduct->prev = NULL;
        newProduct->next = NULL;

        if (head == NULL) {
            head = newProduct;
            tail = newProduct;
        } else {
            tail->next = newProduct;
            newProduct->prev = tail;
            tail = newProduct;
        }
    }

    // Function to delete a product from the shopping system
    void deleteProduct(const string& name) {
        Product* current = head;
        while (current != NULL) {
            if (current->name == name) {
                if (current == head) {
                    head = current->next;
                    if (head != NULL) {
                        head->prev = NULL;
                    }
                } else if (current == tail) {
                    tail = current->prev;
                    if (tail != NULL) {
                        tail->next = NULL;
                    }
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                cout << "Product \"" << name << "\" has been deleted." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Product \"" << name << "\" not found in the shopping system." << endl;
    }

    // Function to search for a product in the shopping system
    void searchProduct(const string& name) {
        Product* current = head;
        while (current != NULL) {
            if (current->name == name) {
                cout << "Product Name: " << current->name << endl;
                cout << "Price: $" << current->price << endl;
                cout << "Quantity: " << current->quantity << endl;
                return;
            }
            current = current->next;
        }
        cout << "Product \"" << name << "\" not found in the shopping system." << endl;
    }

    // Function to display all products in the shopping system
    void displayProducts() {
        cout << "+------------------+-------------+----------+" << endl;
        cout << "|   Product Name   |    Price    | Quantity |" << endl;
        cout << "+------------------+-------------+----------+" << endl;
        
        Product* current = head;
        while (current != NULL) {
            cout << "| " << setw(17) << left << current->name << " |"
                 << " $" << setw(10) << left << fixed << setprecision(2) << current->price << " |"
                 << " " << setw(8) << left << current->quantity << " |" << endl;
            current = current->next;
        }
        cout << "+------------------+-------------+----------+" << endl;
    }

    // Function to save products to a file
    void saveToFile(const string& filename) {
        ofstream file;
        file.open("elite");
        if (file.is_open()) {
            Product* current = head;
            while (current != NULL) {
                file << current->name << "," << current->price << "," << current->quantity << endl;
                current = current->next;
            }
            file.close();
            cout << "Products have been saved to file \"" << filename << "\"." << endl;
        } else {
            cout << "Unable to open file \"" << filename << "\" for writing." << endl;
        }
    }

// Function to load products from a file
    void loadFromFile(const string& filename) {
        ifstream file;
        file.open("elite");
        if (file.is_open()) {
          //char atoi,atof;
          int price;
          int quantity;
            string line;
            while (getline(file, line)) {
                stringstream ss(line);
                string token;
                getline(ss, token, ',');
                string name = token;
                getline(ss, token, ',');
               // double price = atof(token.c_str());
                getline(ss, token, ',');
                //int quantity = atoi(token.c_str());
                addProduct(name, price, quantity);
            }
            file.close();
            cout << "Products have been loaded from file \"" << filename << "\"." << endl;
        } else {
            cout << "Unable to open file \"" << filename << "\" for reading." << endl;
        }
    }
};

int main() {
	system("color E");
    OnlineShopping shoppingSystem;
    string name;
    double price;
    int quantity;

	cout << "\t\t\t #####  #        #  #        #####   #       #  ##### " << endl;
	Sleep(70);
	cout << "\t\t\t#     # # #      #  #          #     # #     #  #        " << endl;
	Sleep(70);
	cout << "\t\t\t#     # #   #    #  #          #     #   #   #  #####" << endl;
	Sleep(70);
	cout << "\t\t\t#     # #     #  #  #          #     #     # #  #        " << endl;
	Sleep(70);
	cout << "\t\t\t #####  #        #  #  #  #  #####   #       #  ##### " << endl;
	Sleep(70);
	cout << "\n\n\n";
	cout << "\t\t ######   #     #      #####     #####      #####    #####    #        #    ##### " << endl;
	Sleep(70);
	cout << "\t\t #        #     #     #     #   #     #    #     #     #      # #      #   #      " << endl;
	Sleep(70); 
	cout << "\t\t   #      #######     #     #   ######     ######      #      #   #    #   #  ####" << endl;
	Sleep(70);
	cout << "\t\t      #   #     #     #     #   #          #           #      #      # #   #     #" << endl;
	Sleep(70);
	cout << "\t\t ######   #     #      #####    #          #         #####    #        #    ##### " << endl;
	Sleep(70);
	cout << "\n\n\n";
	cout << "\t\t\t ######     #       #    ######     #####    #####     #          #" << endl;
	Sleep(70);
	cout << "\t\t\t #            #    #     #            #      #         #  #    #  #   " << endl;
	Sleep(70);
	cout << "\t\t\t   #            #          #          #      #####     #    #     #     " << endl;
	Sleep(70);
	cout << "\t\t\t      #         #             #       #      #         #          #     " << endl;
	Sleep(70);
	cout << "\t\t\t ######         #        ######       #      #####     #          #    " << endl;
	Sleep(70);
	cout << "\n\n\n\n\n\n\n";
	int x(219);
	cout << right << setw(60);
	cout << "LOADING\n\n";
	cout << right << setw(20);
	for(int j = 1; j <= 70; j++) // for the beauty of code
	{
		cout << char(x);
		Sleep(14);
	}
	cout << endl<<endl<<endl<<endl;
    int choice;
    do {
        cout << "1. Add Product" << endl;
        cout << "2. Delete Product" << endl;
        cout << "3. Search Product" << endl;
        cout << "4. Display Products" << endl;
        cout << "5. Save Products to File" << endl;
        cout << "6. Load Products from File" << endl;
        cout << "7. Developers" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear the input buffer
        cin.ignore();

        cout << endl;

        switch (choice) {
            case 1: {
                cout << "Enter the product name: ";
                getline(cin, name);

                cout << "Enter the product price: ";
                cin >> price;

                cout << "Enter the product quantity: ";
                cin >> quantity;

                // Clear the input buffer
                cin.ignore();

                // Adding the product to the system
                shoppingSystem.addProduct(name, price, quantity);

                cout << "Product \"" << name << "\" has been added." << endl;
                break;
            }
            case 2: {
                cout << "Enter the product name to delete: ";
                getline(cin, name);

                shoppingSystem.deleteProduct(name);
                break;
            }
            case 3: {
                cout << "Enter the product name to search: ";
                getline(cin, name);

                shoppingSystem.searchProduct(name);
                break;
            }
            case 4: {
                cout << "Products in the shopping system:" << endl;
                shoppingSystem.displayProducts();
                break;
            }
            case 5: {
                string filename;
                cout << "Enter the filename to save products: ";
                getline(cin, filename);

                shoppingSystem.saveToFile(filename);
                break;
            }
            case 6: {
                string filename;
                cout << "Enter the filename to load products: ";
                getline(cin, filename);

                shoppingSystem.loadFromFile(filename);
                break;
            }
          
            case 7: {
                cout << "Exiting the program..." << endl;
                return 0;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;

    } while (true);
}