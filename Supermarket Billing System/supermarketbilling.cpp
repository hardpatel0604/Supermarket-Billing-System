#include <iostream>
#include <vector>

using namespace std;


//create a class for the products and define the properties
class Product {
private:
    int code;
    string name;
    float price;
    float discount;

//add a public class which uses the private properties above as inputs for different functions
public:
    
    // create different functions with the inputs from the class above 
    Product(int code, string name, float price, float discount)
        : code(code), name(name), price(price), discount(discount) {}

    int getCode() const { return code; }
    string getName() const { return name; }
    float getPrice() const { return price; }
    float getDiscount() const { return discount; }

    void setCode(int code) { this->code = code; }
    void setName(string name) { this->name = name; }
    void setPrice(float price) { this->price = price; }
    void setDiscount(float discount) { this->discount = discount; }
};

//create a shopping class with different functions that can be called later 
class Shopping {
private:
    vector<Product> products;

    //define a boolean variable for admin, to check if login credentials are correct.
    bool admin;
    string username;
    string password;

    //define functions that will be called later.
    bool login();
    void menu();
    void adminMenu();
    void customerMenu();
    void addProduct();
    void editProduct();
    void removeProduct();
    void listProducts();
    void receipt();

//create 'run()' function to run the program later.
public:
    Shopping() : admin(false) {}
    void run();
};


// create the login function which allows the user to access other admin functions.
bool Shopping::login() {
    
    //take user input for username and password 
    cout << "Please login" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    //check username and password with simple if/else statement
    if (username == "temp99" && password == "test99") {
        admin = true;
        return true;
    }
    else {
        cout << "Invalid username or password, please try again." << endl;
        return false;
    }
}

//create a starting 'menu' function where the user can decide which features they want to access
//the function will redirect to the correct function depending on the user input
void Shopping::menu() {
    while (true) {

        //simple text based graphical menu screen 
        int choice;
        cout << "*****************************************************\n";
        cout << "               Supermarket Main menu                 \n";
        cout << "*****************************************************\n";
        cout << "      1) Admin login\n";
        cout << "      2) Customer\n";
        cout << "      3) Exit\n";
        cout << "         Please select one of the options            \n";
        cin >> choice;

        //use a switch statement to redirect to the other functions depending on the user input.
        switch (choice) {
        case 1:
            if (login()) {
                adminMenu();
            }
            break;
        case 2:
            customerMenu();
            break;
        case 3:
            exit(0);
        default:
            cout << "Invalid selection, please try again." << endl;
        }
    }
}

//create an adminmenu function which allows the admin to access 'admin' features 
void Shopping::adminMenu() {
    while (true) {

        //simple text based graphical menu screen
        int choice;
        cout << "*****************************************************\n";
        cout << "               Admin Main menu                 \n";
        cout << "*****************************************************\n";
        cout << "      1) Add a product\n";
        cout << "      2) Edit a product\n";
        cout << "      3) Remove a product\n";
        cout << "      4) List products\n";
        cout << "      5) Back to main menu\n";
        cout << "         Please select one of the options            \n";
        cin >> choice;

        //use a switch statement to redirect to the other functions depending on the user input.
        switch (choice) {
        case 1:
            addProduct();
            break;
        case 2:
            editProduct();
            break;
        case 3:
            removeProduct();
            break;
        case 4:
            listProducts();
            break;
        case 5:
            admin = false;
            menu();
            break;
        default:
            cout << "Invalid selection, please try again." << endl;
        }
    }
}

//create a customermenu functions where a customer can choose what they would like to do 
void Shopping::customerMenu() {
    while (true) {
        
        //display a menu screen and take the users input 
        int choice;
        cout << "*****************************************************\n";
        cout << "               Customer Main menu                 \n";
        cout << "*****************************************************\n";
        cout << "      1) Buy a product\n";
        cout << "      2) List products\n";
        cout << "      3) Back to main menu\n";
        cout << "         Please select one of the options            \n";
        cin >> choice;

        //again using the switch statement, redirect to the correct function depending on user function
        switch (choice) {
        case 1:
            receipt();
            break;
        case 2:
            listProducts();
            break;
        case 3:
            menu();
            break;
        default:
            cout << "Invalid selection, please try again." << endl;
        }
    }
}

// create a function for the admin to add a new product to the list
void Shopping::addProduct() {
    
    //define variables 
    int code;
    string name;
    float price;
    float discount;

    //take in user inputs 
    cout << "Enter the product code: ";
    cin >> code;
    cout << "Enter the product name: ";
    cin >> name;
    cout << "Enter the product price: ";
    cin >> price;
    cout << "Enter the product discount: ";
    cin >> discount;

    //add the product and its details into a vector named products
    products.push_back(Product(code, name, price, discount));
    
    //display a successful message
    cout << "Product added successfully." << endl;
}

//create a function for the admin to edit a product
void Shopping::editProduct() {

    //define the variable and take in user inputs 
    int code;
    cout << "Enter the product code: ";
    cin >> code;

    //check if the input mataches a product already present in the products vector.
    for (auto& product : products) {

        //if product exists, define the variables below 
        if (product.getCode() == code) {
            string name;
            float price;
            float discount;

            //take in user input for the new details of the product
            cout << "Enter the new product name: ";
            cin >> name;
            cout << "Enter the new product price: ";
            cin >> price;
            cout << "Enter the new product discount: ";
            cin >> discount;

            //update the details
            product.setName(name);
            product.setPrice(price);
            product.setDiscount(discount);

            cout << "Product edited successfully." << endl;
            return;
        }
    }

    //if the product does not already exist in the vector, display the following message
    cout << "Product not found." << endl;
}

//create a function for the admin to remove a product
void Shopping::removeProduct() {

    //define variables and get user input 
    int code;
    cout << "Enter the product code: ";
    cin >> code;

    //loop through the vector 'products' to find the product the user wishes to remove.
    for (auto it = products.begin(); it != products.end(); it++) {

        //if there exists a product with a match code remove it using .erase().
        if (it->getCode() == code) {
            products.erase(it);
            cout << "Product removed successfully." << endl;
            return;
        }
    }

    //if no product exists with the inputted code then display this message.
    cout << "Product not found." << endl;
}

//create function to list all the products that are available 
void Shopping::listProducts() {
    cout << "Code\tName\tPrice\tDiscount" << endl;

    //using a for loop, go through all the products inside the vector 'products' and display it with its code, name, price and discount.
    for (const auto& product : products) {
        cout << product.getCode() << "\t" << product.getName() << "\t" << product.getPrice() << "\t" << product.getDiscount() << endl;
    }
}

//create a receipt function
void Shopping::receipt() {

    //define variables and take in user input
    int code;
    cout << "Enter the product code: ";
    cin >> code;

    //check if the product code matches any product code in the vector
    for (const auto& product : products) {

        //if that product exists print out the following. 
        if (product.getCode() == code) {
            cout << "Code: " << product.getCode() << endl;
            cout << "Name: " << product.getName() << endl;
            cout << "Price: " << product.getPrice() << endl;
            cout << "Discount: " << product.getDiscount() << endl;
            cout << "Total Price: " << product.getPrice() - (product.getPrice() * (product.getDiscount() / 100)) << endl;
            return;
        }
    }

    cout << "Product not found." << endl;
}

//use the run() function the start the program by calling the menu() function (starting screen for the program)
void Shopping::run() {
    menu();
}

//main function of the program which basically 'runs' the function 
int main() {
    Shopping shopping;
    shopping.run();

    return 0;
}

