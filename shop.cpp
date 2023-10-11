/*********************************************************************
** Program Filename: shop.cpp
** Author: Anthony Silva
** Date: 02/17/2023
** Description: Implements the shop class. Handles all processes of the
   program, including taking orders, searching for items, printing
   general information, and adding and removing from the menu.
** Input: the correct files need to be opened for the good majority
   of the program. If any one of the files cannot be opened, the program
   will fail. Otherwise, the data is loaded to open up the shop. This
   includes setting up the data for the orders, the menu, and the shop
   info. Then the majority of the program is run.
** Output: This program completes a wide variety of tasks, depending on
   the status of the user. See the functions below for all actions
   completed.
** Type: Implementation File
*********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "menu.h"
#include "order.h"
#include "shop.h"

using namespace std;

/*********************************************************************
** Function: Shop::Shop()
** Description: sets the default values for the shop object.
** Parameters: None
** Pre-Conditions: the program is able to be run.
** Post-Conditions: the variables of the object created can be modified
   depending on what's read in a file.
** Type: Constructor Function
*********************************************************************/ 
Shop::Shop(){
    this->phone = "";
    this->address = "";
    this->revenue = 0.00;
    this->order_arr = NULL;
    this->num_orders = 0;
}

/*********************************************************************
** Function: bool Shop::open_files(ifstream &fileA, ifstream &fileB, ifstream &fileC)
** Description: program that opens three input file objects, or at least
   attempts to.
** Parameters: three input file objects.
** Pre-Conditions: The correct files with the correct names are able
   to be opened, and they are in the correct format.
** Post-Conditions: the function returns false if anyone of the files
   cannot be found in the computer. It returns true if all three
   files with the names below are found and opened.
** Type: File Opener
*********************************************************************/ 
bool Shop::open_files(ifstream &fileA, ifstream &fileB, ifstream &fileC){
    string file1{"orders.txt"};
    fileA.open(file1.c_str(), ios::in);
    string file2{"menu.txt"};
    fileB.open(file2.c_str(), ios::in);
    string file3{"shop_info.txt"};
    fileC.open(file3.c_str(), ios::in);
    // The program cannot continue if any one of the files failed to open.
    if(fileA && fileB && fileC){
        return true;
    }
    else{
        return false;
    }
}

/*********************************************************************
** Function: float Shop::get_revenue() const
** Description: gets the value of the revenue based on orders taken in
   one running of the program.
** Parameters: none
** Pre-Conditions: The employee calls to view the revenue for the shop.
** Post-Conditions: The revenue is returned so it can be printed to the
   screen.
** Type: Accessor Function
*********************************************************************/ 
float Shop::get_revenue() const{
    return this->revenue;
}

/*********************************************************************
** Function: void Shop::view_revenue()
** Description: prints the shop revenue for the day to the employee.
** Parameters: none
** Pre-Conditions: The employee calls to view the revenue for the shop.
** Post-Conditions: The daily revenue is printed to the screen.
** Type: Printer Function
*********************************************************************/ 
void Shop::view_revenue(){
    cout << "The shop revenue is: $" << get_revenue() << endl;
}

/*********************************************************************
** Function: void Shop::set_num_orders(const int num_orders)
** Description: sets the number of orders taken whenever a new order
   is taken.
** Parameters: the new number of orders taken (should be 1 more)
** Pre-Conditions: A new order is taken.
** Post-Conditions: the number of orders is raised up by one.
** Type: Mutator Function
*********************************************************************/ 
void Shop::set_num_orders(const int num_orders){
    this->num_orders = num_orders;
}

/*********************************************************************
** Function: void Shop::set_order_arr(const int num_orders)
** Description: dynamically allocates memory for the order array based
   on the number of orders on file.
** Parameters: The number of orders on file.
** Pre-Conditions: The shop is being set up. Assume the "orders.txt"
   file is in the correct format.
** Post-Conditions: The order array is set up correctly.
*********************************************************************/ 
void Shop::set_order_arr(const int num_orders){
    this->order_arr = new Order [num_orders];
}

/*********************************************************************
** Function: Order* Shop::get_order_arr()
** Description: collects the order array, typically to get the object
   at a particular index.
** Parameters: None
** Pre-Conditions: the call to get an index of the array is made.
** Post-Conditions: the order array is returned so the requested
   index can be accessed.
** Type: Accessor Function
*********************************************************************/ 
Order* Shop::get_order_arr() const{
    return this->order_arr;
}

/*********************************************************************
** Function: void Shop::populate_order_arr(int num_orders, ifstream &fileA)
** Description: populates the order array with previously established
   memory. This is done by examining the contents of the order file.
** Parameters: the number of orders on file, as well as the "orders.txt"
   input file.
** Pre-Conditions: assume the "orders.txt" file is in the correct format.
   Possible segmentation fault or logic error if the file is not
   structured correctly.
** Post-Conditions: The order array is populated using every element
   of every order in the correct format.
** Type: Populator Function
*********************************************************************/ 
void Shop::populate_order_arr(int num_orders, ifstream &fileA){
    int id;
    string coffee_name;
    char coffee_size;
    int quantity;
    // sets the member variables for each order object in the order array.
    for(int i = 0; i < num_orders; i++){
        fileA >> id;
        get_order_arr()[i].set_id(id);
        fileA >> coffee_name;
        get_order_arr()[i].set_coffee_name(coffee_name);
        fileA >> coffee_size;
        get_order_arr()[i].set_coffee_size(coffee_size);
        fileA >> quantity;
        get_order_arr()[i].set_quantity(quantity);
    }
}

/*********************************************************************
** Function: void Shop::load_order_data(ifstream &fileA)
** Description: the information for the orders is set up based on the
   "orders.txt" file.
** Parameters: the "orders.txt" file object.
** Pre-Conditions: "orders.txt" is in the correct format.
** Post-Conditions: the initial number of orders and the array of orders
   is set up.
** Type: Start Up Function
*********************************************************************/ 
void Shop::load_order_data(ifstream &fileA){
    int num_orders;
    fileA >> num_orders;
    set_num_orders(num_orders);
    set_order_arr(num_orders);
    populate_order_arr(num_orders, fileA);
}

/*********************************************************************
** Function: void Shop::load_menu_data(ifstream &fileB)
** Description: the information for the menu is set up based on the
   "menu.txt" file.
** Parameters: the "menu.txt" file object.
** Pre-Conditions: "menu.txt" is in the correct format.
** Post-Conditions: the initial number of coffee objects and the array
   of items is set up.
** Type: Start Up Function
*********************************************************************/ 
void Shop::load_menu_data(ifstream &fileB){
    int num_coffee;
    fileB >> num_coffee;
    m.set_num_coffee(num_coffee);
    m.set_coffee_arr(num_coffee);
    m.populate_menu(num_coffee, fileB);
}

/*********************************************************************
** Function: void Shop::set_phone(const string phone)
** Description: sets the phone number of the shop based on the
   "shop_info.txt" file.
** Parameters: the phone number read from the "shop_info.txt" file.
** Pre-Conditions: Assume the "shop_info.txt" is in the correct format.
** Post-Conditions: The phone number of the shop is set.
** Type: Mutator Function
*********************************************************************/ 
void Shop::set_phone(const string phone){
    this->phone = phone;
}

/*********************************************************************
** Function: void Shop::set_address(const string address)
** Description: sets the address of the shop based on the
   "shop_info.txt" file.
** Parameters: the address read from the "shop_info.txt" file.
** Pre-Conditions: Assume the "shop_info.txt" is in the correct format.
** Post-Conditions: The address of the shop is set.
** Type: Mutator Function
*********************************************************************/ 
void Shop::set_address(const string address){
    this->address = address;
}

/*********************************************************************
** Function: void Shop::load_shop_data(ifstream &fileC)
** Description: the information for the shop is set up based on the
   "shop_info.txt" file.
** Parameters: the "shop_info.txt" file object.
** Pre-Conditions: Assume the "shop_info.txt" is in the correct format.
** Post-Conditions: the phone number and address of the shop is set up.
** Type: Start Up Function
*********************************************************************/ 
void Shop::load_shop_data(ifstream &fileC){
    string phone;
    getline(fileC, phone);
    set_phone(phone);
    string address;
    getline(fileC, address);
    set_address(address);
}

/*********************************************************************
** Function: void Shop::load_data(ifstream &fileA, ifstream &fileB, ifstream &fileC)
** Description: main function for loading all the data to set up the
   shop.
** Parameters: the "orders.txt", "menu.txt", and "shop_info.txt" input files.
** Pre-Conditions: Assume all files are structured in the correct format.
** Post-Conditions: All information for all four classes are set up.
** Type: Start Up Function
*********************************************************************/ 
void Shop::load_data(ifstream &fileA, ifstream &fileB, ifstream &fileC){
    load_order_data(fileA);
    load_menu_data(fileB);
    load_shop_data(fileC);
}

/*********************************************************************
** Function: void Shop::close_files(ifstream &fileA, ifstream &fileB, ifstream &fileC)
** Description: Closes all the files used for input.
** Parameters: the "orders.txt", "menu.txt", and "shop_info.txt" input files.
** Pre-Conditions: All input files are no longer necessary for use.
** Post-Conditions: The input file objects are closed.
** Type: File Closer
*********************************************************************/ 
void Shop::close_files(ifstream &fileA, ifstream &fileB, ifstream &fileC){
    fileA.close();
    fileB.close();
    fileC.close();
}

/*********************************************************************
** Function: void Shop::view_menu()
** Description: allows the customer or employee to view the menu.
** Parameters: None
** Pre-Conditions: the user makes the call to view the menu.
** Post-Conditions: The entire menu is displayed.
** Type: Printer Function
*********************************************************************/ 
void Shop::view_menu(){
    // prints out data for every element in the coffee array.
    for(int i = 0; i < m.get_num_coffee(); i++){
        cout << i + 1 << ". ";
        cout << m.get_coffee_arr(i).get_name() << " ";
        cout << m.get_coffee_arr(i).get_small_cost() << " ";
        cout << m.get_coffee_arr(i).get_medium_cost() << " ";
        cout << m.get_coffee_arr(i).get_large_cost() << endl;
    }
}

/*********************************************************************
** Function: string Shop::get_address() const
** Description: returns the address of the shop so that it can be printed.
** Parameters: None
** Pre-Conditions: The address is requested by the customer or employee.
** Post-Conditions: The address is returned so that it can be printed.
** Type: Accessor Function
*********************************************************************/ 
string Shop::get_address() const{
    return this->address;
}

/*********************************************************************
** Function: void Shop::view_address()
** Description: prints out the address of the shop.
** Parameters: None
** Pre-Conditions: The call to view the address is made by the user.
** Post-Conditions: The address of the shop is printed to the terminal.
** Type: Printer Function
*********************************************************************/ 
void Shop::view_address(){
    cout << "Our address is: " << get_address() << endl;
}

/*********************************************************************
** Function: string Shop::get_phone() const
** Description: returns the phone number of the shop so that it can be printed.
** Parameters: None
** Pre-Conditions: The phone number is requested by the customer or employee.
** Post-Conditions: The phone number is returned so that it can be printed.
** Type: Accessor Function
*********************************************************************/ 
string Shop::get_phone() const{
    return this->phone;
}

/*********************************************************************
** Function: void Shop::view_phone()
** Description: prints out the phone number of the shop.
** Parameters: None
** Pre-Conditions: The call to view the phone number is made by the user.
** Post-Conditions: The phone number of the shop is printed to the terminal.
** Type: Printer Function
*********************************************************************/ 
void Shop::view_phone(){
    cout << "Our phone number is: " << get_phone() << endl;
}

/*********************************************************************
** Function: int Shop::get_item_quantity()
** Description: collects how many of one item the customer wants.
** Parameters: None
** Pre-Conditions: the program collects the size of the drink the
   customer wants.
** Post-Conditions: the number of drinks the customer wants is returned.
** Type: Collector Function
*********************************************************************/ 
int Shop::get_item_quantity(){
    string quantity;
    // repeat until a valid input is given.
    while(true){
        cout << "Enter quantity: " << endl;
        getline(cin, quantity);
        // input cannot be null. Without this conditional, we get a segmentation fault.
        if(quantity != ""){
            int q = stoi(quantity);
            // quantity cannot be zero or negative.
            if(q >= 0){
                return q;
            }
            else{
                cout << "Invalid input. Please try again." << endl;
            }
        }
        else{
            cout << "Invalid input. Please try again." << endl;
        }
    }
}

/*********************************************************************
** Function: int Shop::get_confirmation()
** Description: asks the user if they want to confirm their order.
** Parameters: None
** Pre-Conditions: the program is able to display the cost so that the
   customer can make an informed decision.
** Post-Conditions: returns a value based on whether the customer has
   confirmed their order or not.
** Type: Collector Function
*********************************************************************/ 
int Shop::get_confirmation(){
    string confirmation;
    // repeat until a valid input is given.
    while(true){
        cout << "Confirm? (1-yes, 0-no) " << endl;
        getline(cin, confirmation);
        // input cannot be null. A segmentation fault occurs without this conditional.
        if(confirmation != ""){
            int c = stoi(confirmation);
            // input must be zero or one.
            if(c == 0 || c == 1){
                return c;
            }
            else{
                cout << "Invalid input. Please try again." << endl;
            }
        }
        else{
            cout << "Invalid input. Please try again." << endl;
        }
    }
}

/*********************************************************************
** Function: void Shop::add_order(string name, char size, int quantity)
** Description: creates a new array with the new order taken from the
   customer.
** Parameters: the name of the drink, the size, and the number of drinks
   being ordered.
** Pre-Conditions: the customer has confirmed their order.
** Post-Conditions: a new order array is created based on the new order
   taken from the customer.
** Type: Addition Function
*********************************************************************/ 
void Shop::add_order(string name, char size, int quantity){
    // a temporary array is created.
    Order* temp_arr = new Order[get_num_orders() + 1];
    // the contents of the old array are copied to the temporary array.
    for(int i = 0; i < get_num_orders(); i++){
        temp_arr[i] = get_order_arr()[i];
    }
    // Here, the new order is added to the temporary array.
    this->num_orders = this->num_orders + 1;
    temp_arr[get_num_orders() - 1].set_id(get_num_orders());
    temp_arr[get_num_orders() - 1].set_coffee_name(name); 
    temp_arr[get_num_orders() - 1].set_coffee_size(size);
    temp_arr[get_num_orders() - 1].set_quantity(quantity);
    // process of transferring contents of temporary array to the old array.
    delete [] this->order_arr;
    this->order_arr = NULL;
    this->order_arr = temp_arr;
}

/*********************************************************************
** Function: float Shop::calculate_cost(int quantity, char size, string name)
** Description: the cost is calculated, and then displayed to the
   customer.
** Parameters: the number of drinks ordered, the size of the drink, and
   the name of the item.
** Pre-Conditions: the number of drinks requested is collected from the
   user.
** Post-Conditions: the cost is correctly calculated and printed to the
   terminal.
** Type: Calculator Function
*********************************************************************/ 
float Shop::calculate_cost(int quantity, char size, string name){
    float cost;
    if(size == 's'){
        for(int i = 0; i < m.get_num_coffee(); i++){
            if(m.get_coffee_arr(i).get_name() == name){
                cost = quantity * m.get_coffee_arr(i).get_small_cost();
            }
        }
    }
    else if(size == 'm'){
        for(int i = 0; i < m.get_num_coffee(); i++){
            if(m.get_coffee_arr(i).get_name() == name){
                cost = quantity * m.get_coffee_arr(i).get_medium_cost();
            }
        }
    }
    else if(size == 'l'){
        for(int i = 0; i < m.get_num_coffee(); i++){
            if(m.get_coffee_arr(i).get_name() == name){
                cost = quantity * m.get_coffee_arr(i).get_large_cost();
            }
        }
    }
    cout << "Your total is: $" << cost << endl;
    return cost;
}

/*********************************************************************
** Function: void Shop::set_revenue(const float revenue)
** Description: sets the new value of the revenue based on the cost
   of the items requested on the order.
** Parameters: The cost of the order.
** Pre-Conditions: The order is placed by the customer.
** Post-Conditions: The new revenue is set, ready to be viewed by the
   employeee.
** Type: Mutator Function
*********************************************************************/ 
void Shop::set_revenue(const float revenue){
    this->revenue = get_revenue() + revenue;
}

/*********************************************************************
** Function: void Shop::create_new_order_text()
** Description: the new order is taken into account when it comes to
   the storage of orders on file.
** Parameters: None
** Pre-Conditions: a new order array is created based on the order placed
   by the customer.
** Post-Conditions: a new text file with the up-to-date-information is
   created.
** Type: Addition Function
*********************************************************************/ 
void Shop::create_new_order_text(){
    remove("orders.txt");
    ofstream fout;
    fout.open("orders.txt", ios::out | ios::app); // new file created
    fout << get_num_orders() << endl;
    // the new file is created based on every order collected.
    for(int i = 0; i < get_num_orders(); i++){
        fout << get_order_arr()[i].get_id() + 1 << " ";
        fout << get_order_arr()[i].get_coffee_name() << " ";
        fout << get_order_arr()[i].get_coffee_size() << " ";
        fout << get_order_arr()[i].get_quantity() << endl;
    }
    fout.close();
}

/*********************************************************************
** Function: void Shop::place_order_from_size(string name)
** Description: an order is set up by the customer before they are asked
   to confirm their order. If yes, then the order is put in storage.
** Parameters: the name of the drink.
** Pre-Conditions: the name of the drink is requested for by the customer.
** Post-Conditions: the order is set up with the correct size and quantity,
   the cost is displayed, and the user confirms their order or not. If yes,
   then the order is added to the order array and text file.
** Type: Complex Function
*********************************************************************/ 
void Shop::place_order_from_size(string name){
    char size;
    int quantity;
    int confirmation = 0;
    // valid size input must be given.
    while(true){
        cout << "Enter the size: (s-small, m-medium, l-large) " << endl;
        cin >> size;
        // small, medium, or large respectively
        if(size == 's' || size == 'm' || size == 'l'){
            quantity = get_item_quantity();
            float cost = calculate_cost(quantity, size, name);
            confirmation = get_confirmation();
            // if order is confirmed
            if(confirmation == 1){
                set_revenue(cost);
                add_order(name, size, quantity);
                create_new_order_text();
            }
            return;
        }
        else{
            cout << "Invalid input. Please try again." << endl;
        }
    }
}

/*********************************************************************
** Function: void Shop::place_order_from_name()
** Description: collects the name of the order the customer wants. If
   no drink is found in the menu, then an error message is displayed,
   and they are taken back to the main menu.
** Parameters: None
** Pre-Conditions: The call to place an order is set by the customer.
** Post-Conditions: The name of the drink is requested by the customer,
   and the program searches for it. If it is found, then the program
   continues with placing the order. If not, then an error message is
   displayed, and they are taken back to the main menu.
** Type: Collector Function
*********************************************************************/ 
void Shop::place_order_from_name(){
    string name;
    cout << "Enter the coffee name: " << endl;
    getline(cin, name);
    // if the name of the item is not found:
    if(!m.search_coffee_by_name(name)){
        cout << "Sorry. That drink wasn't found." << endl;
        return;
    }
    place_order_from_size(name);
}

/*********************************************************************
** Function: void Shop::search_by_price()
** Description: the customer is asked to plug in an upper limit for the
   price of the drink they want. The program then searches for items that
   are at or below this price limit. If no drinks were found, an error
   message is displayed, and the user is returned to the main menu.
   Otherwise, the program asks them if they want to place an order from
   the information printed. If yes, then they place an order starting by
   requesting the name of their drink. If no, then they are returned to
   the main menu.
** Parameters: None
** Pre-Conditions: The call to search for items by price is made by the
   customer.
** Post-Conditions: The upper limit for the drink is collected by the
   user. If no drinks could be printed that meet the limits, then an
   error message is displayed. Otherwise, the user is asked if they
   want to place an order. If yes, then the customer continues to
   place an order starting by requesting the name. If no, then the
   program returns to the main menu.
*********************************************************************/ 
void Shop::search_by_price(){
    int upper_bound;
    cout << "Enter the budget for your drink: " << endl;
    cin >> upper_bound;
    // if no drinks could be found
    if(!m.search_coffee_by_price(upper_bound)){
        return;
    }
    string order_decision;
    // repeat until a valid input is given
    while(true){
        cout << "Would you like to place an order based on the results? (y/n)" << endl;
        getline(cin, order_decision);
        // if yes, place an order
        if(order_decision == "y"){
            place_order_from_name();
            return;
        }
        // if no, go back to main menu
        else if(order_decision == "n"){
            return;
        }
        else{
            cout << "Invalid input. Please try again." << endl;
        }
    }
}

/*********************************************************************
** Function: void Shop::search_by_name()
** Description: the customer is asked to plug in the name of the drink
   they want. The program then searches for this item. If no drinks were
   found, an error message is displayed, and the user is returned to the
   main menu. Otherwise, the program asks them if they want to place an
   order from the information printed. If yes, then they place an order
   starting by requesting the size of their drink. If no, then they are 
   returned to the main menu.
** Parameters: None
** Pre-Conditions: The call to search for an item by name is made by the
   customer.
** Post-Conditions: The name of the drink requested is collected by the
   user. If no drinks could be found, then an error message is displayed.
   Otherwise, the user is asked if they want to place an order. If yes,
   then the customer continues to place an order starting by requesting
   the size. If no, then the program returns to the main menu.
*********************************************************************/ 
void Shop::search_by_name(){
    string name;
    cout << "Enter the coffee name: " << endl;
    getline(cin, name);
    // if no item was found
    if(!m.search_coffee_by_name(name)){
        cout << "Sorry. That drink wasn't found." << endl;
        return;
    }
    string order_decision;
    // repeat until a valid input is given
    while(true){
        cout << "Would you like to place an order based on the results? (y/n)" << endl;
        getline(cin, order_decision);
        // if yes, continue placing the order
        if(order_decision == "y"){
            place_order_from_size(name);
            return;
        }
        // if no, return to the main menu
        else if(order_decision == "n"){
            return;
        }
        else{
            cout << "Invalid input. Please try again." << endl;
        }
    }
}

/*********************************************************************
** Function: void Shop::create_new_menu_text()
** Description: a new menu text is created based on the item that was
   added or deleted.
** Parameters: None
** Pre-Conditions: the menu array has been updated based on the
   employee's actions.
** Post-Conditions: the old menu text is deleted, and then brought back
   to the computer based on the updated menu.
** Type: Addition/SubtractioN Function
*********************************************************************/ 
void Shop::create_new_menu_text(){
    remove("menu.txt");
    ofstream fout;
    fout.open("menu.txt", ios::out | ios::app);
    fout << m.get_num_coffee() << endl;
    // every coffee object's elements are written to the new file.
    for(int i = 0; i < m.get_num_coffee(); i++){
        fout << m.get_coffee_arr(i).get_name() << " ";
        fout << m.get_coffee_arr(i).get_small_cost() << " ";
        fout << m.get_coffee_arr(i).get_medium_cost() << " ";
        fout << m.get_coffee_arr(i).get_large_cost() << endl;
    }
    fout.close();
}

/*********************************************************************
** Function: void Shop::add_to_menu()
** Description: A new item is added to the menu by the employee, as well
   as the costs for the small, medium, and large sizes.
** Parameters: None
** Pre-Conditions: The employee makes the call to this function.
** Post-Conditions: Assume the user uses correct input, including one
   word for the name, and positive float numbers where the medium cost
   is larger than the small cost, and the large cost is larger than the
   medium cost. Then the new menu item is created from this information.
   Also assume the user will not create a duplicate item.
*********************************************************************/ 
void Shop::add_to_menu(){
    string name;
    cout << "Enter the name of the item (1 word please): " << endl;
    getline(cin, name);
    float small_cost;
    cout << "Enter the cost for the small size: " << endl;
    cin >> small_cost;
    float medium_cost;
    cout << "Enter the cost for the medium size: " << endl;
    cin >> medium_cost;
    float large_cost;
    cout << "Enter the cost for the large size: " << endl;
    cin >> large_cost;
    m.add_to_menu(name, small_cost, medium_cost, large_cost);
    create_new_menu_text();
}

/*********************************************************************
** Function: void Shop::remove_from_menu()
** Description: The menu is printed, and then the employee removes a
   certain item from the menu.
** Parameters: None
** Pre-Conditions: The employee makes the call to this function.
** Post-Conditions: The correct menu item is deleted.
** Type: Subtraction Function
*********************************************************************/ 
void Shop::remove_from_menu(){
    view_menu();
    int removal_selection;
    while(true){
        cout << "Which item would you like to remove? Type the corresponding number: " << endl;
        cin >> removal_selection;
        if(removal_selection >= 1 && removal_selection <= m.get_num_coffee()){
            m.remove_from_menu(removal_selection - 1);
            create_new_menu_text();
            return;
        }
        else{
            cout << "Invalid input. Please try again." << endl;
        }
    }
}

/*********************************************************************
** Function: int Shop::get_num_orders() const
** Description: the function returns the number of orders on file so
   that the employee can view all of them.
** Parameters: None
** Pre-Conditions: the employee makes the call to view all of the orders.
** Post-Conditions: The number of orders is returned so all of the orders
   on file can be printed.
** Type: Accessor Function
*********************************************************************/ 
int Shop::get_num_orders() const{
    return this->num_orders;
}

/*********************************************************************
** Function: void Shop::view_orders()
** Description: allows the employee to view all of the orders on file.
** Parameters: None
** Pre-Conditions: the employee makes the call to this function.
** Post-Conditions: all of the information for every single order on
   file is printed to the terminal.
** Type: Printer Function
*********************************************************************/ 
void Shop::view_orders(){
    for(int i = 0; i < get_num_orders(); i++){
        cout << get_order_arr()[i].get_id() << " ";
        cout << get_order_arr()[i].get_coffee_name() << " ";
        cout << get_order_arr()[i].get_coffee_size() << " ";
        cout << get_order_arr()[i].get_quantity() << endl;
    }
}

/*********************************************************************
** Function: void Shop::check_customer_selection(string user_selection)
** Description: checks to see if the customer's selection from the main
   menu is valid. If yes, then the proper action is performed. If no,
   then an error message is displayed, and the user is prompted again.
** Parameters: the customer's selection from the main menu.
** Pre-Conditions: The customer makes a selection from the main menu.
** Post-Conditions: A special action is made unless the input is invalid.
   In that case, an error message is displayed, and the user is prompted
   to try again.
** Type: Evaluator Function
*********************************************************************/ 
void Shop::check_customer_selection(string user_selection){
    if(user_selection == "1"){view_menu();}
    else if(user_selection == "2"){search_by_price();}
    else if(user_selection == "3"){search_by_name();}
    else if(user_selection == "4"){place_order_from_name();}
    else if(user_selection == "5"){view_address();}
    else if(user_selection == "6"){view_phone();}
    else if(user_selection == "7"){return;}
    else{cout << "Invalid input. Please try again." << endl;}
}

/*********************************************************************
** Function: void Shop::customer_menu()
** Description: collects input from the customer about what they want
   to do.
** Parameters: None
** Pre-Conditions: the user logs in as a customer.
** Post-Conditions: the user selects an option of their choosing to be
   evaluated by the program.
** Type: Printer/Collector Function
*********************************************************************/ 
void Shop::customer_menu(){
    string user_selection = "";
    // function keeps running until the customer logs out
    while(user_selection != "7"){
        cout << "Welcome, how can I help you?" << endl;
        cout << "1. View coffee menu" << endl;
        cout << "2. Search by price" << endl;
        cout << "3. Search by coffee name" << endl;
        cout << "4. Place an order" << endl;
        cout << "5. View address" << endl;
        cout << "6. View phone" << endl;
        cout << "7. Log out" << endl;
        getline(cin, user_selection);
        check_customer_selection(user_selection);
    }
}

/*********************************************************************
** Function: void Shop::check_employee_selection(string user_selection)
** Description: checks to see if the employee's selection from the main
   menu is valid. If yes, then the proper action is performed. If no,
   then an error message is displayed, and the user is prompted again.
** Parameters: the employee's selection from the main menu.
** Pre-Conditions: The employee makes a selection from the main menu.
** Post-Conditions: A special action is made unless the input is invalid.
   In that case, an error message is displayed, and the user is prompted
   to try again.
** Type: Evaluator Function
*********************************************************************/ 
void Shop::check_employee_selection(string user_selection){
    if(user_selection == "1"){view_revenue();}
    else if(user_selection == "2"){view_orders();}
    else if(user_selection == "3"){add_to_menu();}
    else if(user_selection == "4"){remove_from_menu();}
    else if(user_selection == "5"){view_menu();}
    else if(user_selection == "6"){view_address();}
    else if(user_selection == "7"){view_phone();}
    else if(user_selection == "8"){return;}
    else{cout << "Invalid input. Please try again." << endl;}
}

/*********************************************************************
** Function: void Shop::employee_menu()
** Description: collects input from the employee about what they want
   to do.
** Parameters: None
** Pre-Conditions: the user logs in as an employee.
** Post-Conditions: the user selects an option of their choosing to be
   evaluated by the program.
** Type: Printer/Collector Function
*********************************************************************/ 
void Shop::employee_menu(){
    string user_selection = "";
    // function keeps running until they log out
    while(user_selection != "8"){
        cout << "What would you like to do?" << endl;
        cout << "1. View shop revenue" << endl;
        cout << "2. View orders" << endl;
        cout << "3. Add an item to coffee menu" << endl;
        cout << "4. Remove an item from coffee menu" << endl;
        cout << "5. View coffee menu" << endl;
        cout << "6. View address" << endl;
        cout << "7. View phone number" << endl;
        cout << "8. Log out" << endl;
        getline(cin, user_selection);
        check_employee_selection(user_selection);
    }
}

/*********************************************************************
** Function: void Shop::evaluate_status(string user_status)
** Description: checks to see if the user's selection for logging in is
   valid. If yes, then the proper main menu is printed. If no, then an
   error message is displayed, and the user is prompted again. Note that
   if "q" is plugged in as input, the program terminates.
** Parameters: the user's input for logging in.
** Pre-Conditions: the user makes a decision for how they want to log
   in.
** Post-Conditions: The user logs in unless the input is invalid. In that
   case, an error message is displayed, and the user is prompted to try again.
   If the input is the character "q", then the program terminates.
** Type: Evaluator Function
*********************************************************************/ 
void Shop::evaluate_status(string user_status){
    if(user_status == "c"){
        customer_menu();
    }
    else if(user_status == "e"){
        cout << "Welcome my boss!" << endl;
        employee_menu();
    }
    else if(user_status == "q"){
        cout << "Thanks for visiting. Shutting down..." << endl;
    }
    else{
        cout << "Invalid input. Please try again." << endl;
    }
}

/*********************************************************************
** Function: void Shop::run_shop()
** Description: Collects the log in decision from the user. The function
   runs until "q" is put in. Then the program terminates.
** Parameters: None
** Pre-Conditions: The shop is all set up.
** Post-Conditions: The user plugs in input ready to evaluated for the
   appropriate action.
** Type: Collector Function
*********************************************************************/ 
void Shop::run_shop(){
    string user_status = "";
    // Repeat until "q" is put in, in which the program terminates.
    while(user_status != "q"){
        cout << "Welcome to Coffee++ Shop!" << endl;
        cout << "Are you a customer (c) or employee (e) or would you like to quit (q)?" << endl;
        getline(cin, user_status);
        evaluate_status(user_status); 
    }
}

/*********************************************************************
** Function: Shop::~Shop()
** Description: destroys the shop object. The purpose of this function
   is primarily to delete the order array, which is stored a member dynamic
   array in the shop object.
** Parameters: None
** Pre-Conditions: the user decides to quit the program.
** Post-Conditions: All dynamic memory from the shop class is deleted.
** Type: Destructor Function
*********************************************************************/ 
Shop::~Shop(){
    if(this->order_arr != NULL){
        delete [] this->order_arr;
        this->order_arr = NULL;
    }
}

/*********************************************************************
** Function: Shop::Shop(const Shop &old_s)
** Description: creates a new shop object with the same variables as the
   old one. This is an important part of assigning a new order array to
   a temporary array that was created, as the order objects need to be
   returned in accessor functions for this work.
** Parameters: The old shop class as a reference.
** Pre-Conditions: The old array is ready to transfer data to a new array.
** Post-Conditions: All data is transferred to a new array.
** Type: Copy Constructor Function
*********************************************************************/ 
Shop::Shop(const Shop &old_s){
    this->m = old_s.m;
    this->phone = old_s.phone;
    this->address = old_s.address;
    this->revenue = old_s.revenue;
    this->num_orders = old_s.num_orders;
    this->order_arr = new Order [this->num_orders];
    for(int i = 0; i < this->num_orders; i++){
        this->order_arr[i] = old_s.order_arr[i];
    }
}

/*********************************************************************
** Function: Shop& Shop::operator=(const Shop &old_s)
** Description: assigns the data from an old array to a new array that
   was created previously. This is important for when a new order is
   being placed, and we need more space.
** Parameters: the old shop class as a reference.
** Pre-Conditions: The new array is ready to be set to the old array.
** Post-Conditions: All data from the new array is dynamically
   allocated in the old array.
** Type: Assignment Operator Overload Function
*********************************************************************/ 
Shop& Shop::operator=(const Shop &old_s){
    this->m = old_s.m;
    this->phone = old_s.phone;
    this->address = old_s.address;
    this->revenue = old_s.revenue;
    this->num_orders = old_s.num_orders;
    if(this->order_arr != NULL){
        delete [] this->order_arr;
        this->order_arr;
    }
    this->order_arr = new Order [this->num_orders];
    for(int i = 0; i < this->num_orders; i++){
        this->order_arr[i] = old_s.order_arr[i];
    }
}