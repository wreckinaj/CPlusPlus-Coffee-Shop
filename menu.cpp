/*********************************************************************
** Program Filename: menu.cpp
** Author: Anthony Silva
** Date: 02/18/2023
** Description: Implements the menu class. Stores accessor and mutator
   functions for the number of menu items and the array of them. Handles
   setting the new coffee array whenever an item is being added or removed,
   as well as the searching for menu items from the customer.
** Input: the functions are called when the program is wanting to set or
   access one of the private variables, when the customer is searching
   for items by price or by name, or when the employee is adding or
   removing an item from the menu.
** Output: the variables for the menu are set, or they are returned. The
   customer gets results that match what was requested, or else a message
   that shows that no items were found. An item is either added or removed
   from the menu.
** Type: Implementation File
*********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "coffee.h"
#include "menu.h"

using namespace std;

/*********************************************************************
** Function: Menu::Menu()
** Description: Sets the default values for the menu object.
** Parameters: None
** Pre-Conditions: the program is able to be run.
** Post-Conditions: the variables of the object created can be modified
   depending on what's read in a file.
** Type: Constructor Function
*********************************************************************/ 
Menu::Menu(){
    this->num_coffee = 0;
    this->coffee_arr = NULL;
}

/*********************************************************************
** Function: Menu::Menu(int size)
** Description: creates a new menu object based on the requested size.
** Parameters: the number of items to be set in the menu.
** Pre-Conditions: a new menu needs to be created so the correct amount
   of memory is allocated.
** Post-Conditions: the new menu object is created based on the number of
   items in the menu.
** Type: Non-Default Constructor Function
*********************************************************************/ 
Menu::Menu(int size){
    this->num_coffee = size;
    this->coffee_arr = new Coffee[size];
}

/*********************************************************************
** Function: Coffee Menu::get_coffee_arr(int i)
** Description: returns the index of the coffee array.
** Parameters: The index requested.
** Pre-Conditions: A search in the coffee array needs to be made, or a
   new coffee array needs to be created.
** Post-Conditions: The index of the coffee array is returned so that
   the correct call to the object represented by this index can be made.
** Type: Accessor Function
*********************************************************************/ 
Coffee Menu::get_coffee_arr(int i) const{
    return this->coffee_arr[i];
}

/*********************************************************************
** Function: void Menu::set_coffee_arr(const int num_coffee)
** Description: memory is dynamically allocated for the coffee array
   during the set up of the shop.
** Parameters: the number of items that need to go in the menu.
** Pre-Conditions: assume the "menu.txt" file is in the correct format.
** Post-Conditions: Memory is dynamically allocated based on the number
   of items that need to go in the menu.
** Type: Mutator Function
*********************************************************************/ 
void Menu::set_coffee_arr(const int num_coffee){
    this->coffee_arr = new Coffee [num_coffee];
}

/*********************************************************************
** Function: void Menu::set_num_coffee(const int num_coffee)
** Description: the number of items on the menu is set.
** Parameters: The number of items on the menu.
** Pre-Conditions: assume the "menu.txt" file is in the correct format
   for set up purposes.
** Post-Conditions: The numbeer of items on the menu is set, ready to
   use for the program.
** Type: Mutator Function
*********************************************************************/ 
void Menu::set_num_coffee(const int num_coffee){
    this->num_coffee = num_coffee;
}

/*********************************************************************
** Function: int Menu::get_num_coffee() const
** Description: the number of items on the menu is returned.
** Parameters: None
** Pre-Conditions: We need to loop through the coffee array in order to
   search for items or transfer data.
** Post-Conditions: The number of items on the menu is returned.
** Type: Accessor Function
*********************************************************************/ 
int Menu::get_num_coffee() const{
    return this->num_coffee;
}

/*********************************************************************
** Function: void Menu::populate_menu(int num_coffee, ifstream &fileB)
** Description: populate the coffee array based on the information from
   the "menu.txt" file.
** Parameters: the number of items on the menu, and the "menu.txt" input
   object.
** Pre-Conditions: assume the "menu.txt" file is in the correct format.
** Post-Conditions: the coffee array is populated with coffee objects
   based on information from the menu file.
** Type: Populator Function
*********************************************************************/ 
void Menu::populate_menu(int num_coffee, ifstream &fileB){
    string name;
    float small_cost;
    float medium_cost;
    float large_cost;
    for(int i = 0; i < num_coffee; i++){
        fileB >> name;
        this->coffee_arr[i].set_name(name);
        fileB >> small_cost;
        this->coffee_arr[i].set_small_cost(small_cost);
        fileB >> medium_cost;
        this->coffee_arr[i].set_medium_cost(medium_cost);
        fileB >> large_cost;
        this->coffee_arr[i].set_large_cost(large_cost);
    }
}

/*********************************************************************
** Function: bool Menu::search_coffee_by_name(string name)
** Description: determines if any items in a search are found based on
   input from the customer. If no, then the function returns false. If
   yes, then the program prints out the menu item, as well as the cost
   for small, medium, and large sizes.
** Parameters: the name of the drink requested.
** Pre-Conditions: a search by name is requested by the customer.
** Post-Conditions: the function returns false if no items were found
   based on the search. The function prints out the item and costs and
   returns true if a match is found.
** Type: Search Function
*********************************************************************/ 
bool Menu::search_coffee_by_name(string name){
    // every object is looped through until a match is made (if there is one)
    for(int i = 0; i < get_num_coffee(); i++){
        // the loop stops once a match is found
        if(get_coffee_arr(i).get_name() == name){
            cout << "Results: " << endl;
            cout << i + 1 << ". " << get_coffee_arr(i).get_name() << endl;
            cout << "Small: $" << get_coffee_arr(i).get_small_cost() << endl;
            cout << "Medium: $" << get_coffee_arr(i).get_medium_cost() << endl;
            cout << "Large: $" << get_coffee_arr(i).get_large_cost() << endl;
            return true;
        }
    }
    return false;
}

/*********************************************************************
** Function: bool Menu::search_coffee_by_price(int upper_bound)
** Description: determines if there are any items that fit the
   customer's budget.
** Parameters: the upper limit for prices set by the customer.
** Pre-Conditions: a search by price is requested by the customer.
** Post-Conditions: the function returns false if there are no items that
   fit the customer's budget. The function returns true if there is. If
   there is, then the name of the item and appropriate costs are displayed.
** Type: Search Function
*********************************************************************/ 
bool Menu::search_coffee_by_price(int upper_bound){
    int print = 0;
    // every object is looped through
    for(int i = 0; i < get_num_coffee(); i++){
        // we start printing as soon as we get a match.
        if(get_coffee_arr(i).get_small_cost() <= upper_bound){
            print = print + 1;
            cout << i + 1 << ". " << get_coffee_arr(i).get_name() << endl;
            cout << "Small: $" << get_coffee_arr(i).get_small_cost() << endl;
            // is medium cost appropriate?
            if(get_coffee_arr(i).get_medium_cost() <= upper_bound){
                cout << "Medium: $" << get_coffee_arr(i).get_medium_cost() << endl;
            }
            // is large cost appropriate?
            if(get_coffee_arr(i).get_large_cost() <= upper_bound){
                cout << "Large: $" << get_coffee_arr(i).get_large_cost() << endl;
            }
        }
    }
    // returns false if no results were found.
    if(print == 0){
        cout << "No results were found." << endl;
        return false;
    }
    return true;
}

/*********************************************************************
** Function: void Menu::add_to_menu(string name, float small, float medium, float large)
** Description: adds an item to the menu by creating a new array, copying
   the contents of the old coffee array, and adding the contents of the
   new item.
** Parameters: the name of the name and its three costs for different sizes.
** Pre-Conditions: a new item is set to be added to the menu by the
   employee.
** Post-Conditions: a new coffee array is set with the new item.
** Type: Addition Function
*********************************************************************/
void Menu::add_to_menu(string name, float small, float medium, float large){
    Coffee* temp_arr = new Coffee[get_num_coffee() + 1];
    // all contents are copied to the new array
    for(int i = 0; i < get_num_coffee(); i++){
        temp_arr[i] = get_coffee_arr(i);
    }
    // the new item is added to the menu here.
    this->num_coffee = this->num_coffee + 1;
    temp_arr[get_num_coffee() - 1].set_name(name);
    temp_arr[get_num_coffee() - 1].set_small_cost(small); 
    temp_arr[get_num_coffee() - 1].set_medium_cost(medium);
    temp_arr[get_num_coffee() - 1].set_large_cost(large);
    delete [] this->coffee_arr;
    this->coffee_arr = NULL;
    this->coffee_arr = temp_arr;
}

/*********************************************************************
** Function: void Menu::remove_from_menu(int index_of_coffee_on_menu)
** Description: removes an item from the array by creating a new array
   and copying the contents over from the old array, except for the
   item being removed.
** Parameters: the index of the item that needs to be removed.
** Pre-Conditions: the employee requests an item to be removed.
** Post-Conditions: a new coffee array is set without the removed item.
** Type: Subtraction Function
*********************************************************************/ 
void Menu::remove_from_menu(int index_of_coffee_on_menu){
    int breakpoint = 1;
    Coffee* temp_arr = new Coffee [get_num_coffee() - 1];
    for(int i = 0; i < get_num_coffee(); i++){
        // cout << "new iteration" << endl;
        if(breakpoint == 1 && i != index_of_coffee_on_menu){
            cout << "keeping item " << i << endl;
            temp_arr[i] = get_coffee_arr(i);
        }
        else if(breakpoint == 1 && i == index_of_coffee_on_menu){
            cout << "deleting item " << i << endl;
            breakpoint = 0;
        }
        else{
            cout << "keeping item " << i << endl;
            temp_arr[i - 1] = get_coffee_arr(i);
        }
    }
    this->num_coffee--;
    delete [] this->coffee_arr;
    this->coffee_arr = NULL;
    this->coffee_arr = temp_arr;
}

/*********************************************************************
** Function: Menu::~Menu()
** Description: destroys the menu object. The purpose of this function
   is primarily to delete the coffee array, which is stored a member dynamic
   array in the menu object.
** Parameters: None
** Pre-Conditions: the user decides to quit the program.
** Post-Conditions: All dynamic memory from the menu class is deleted.
** Type: Destructor Function
*********************************************************************/ 
Menu::~Menu(){
    if(this->coffee_arr != NULL){
        delete [] this->coffee_arr;
        this->coffee_arr = NULL;
    }
}

/*********************************************************************
** Function: Menu::Menu(const Menu &old_m)
** Description: creates a new menu object with the same variables as the
   old one. This is an important part of assigning a new coffee array to
   a temporary array that was created, as the coffee objects need to be
   returned in accessor functions for this work.
** Parameters: The old menu class as a reference.
** Pre-Conditions: The old array is ready to transfer data to a new array.
** Post-Conditions: All data is transferred to a new array.
** Type: Copy Constructor Function
*********************************************************************/ 
Menu::Menu(const Menu &old_m){
    this->num_coffee = old_m.num_coffee;
    this->coffee_arr = new Coffee[this->num_coffee];
    for(int i = 0; i < this->num_coffee; i++){
        this->coffee_arr[i] = old_m.coffee_arr[i];
    }
}

/*********************************************************************
** Function: Menu& Menu::operator=(const Menu &old_m)
** Description: assigns the data from an old array to a new array that
   was created previously. This is important for when the menu is being
   adjusted, and we need more (or less) space.
** Parameters: The old menu class as a reference.
** Pre-Conditions: The new array is ready to be set to the old array.
** Post-Conditions: All data from the new array is dynamically
   allocated in the old array.
** Type: Assignment Operator Overload Function
*********************************************************************/ 
Menu& Menu::operator=(const Menu &old_m){
    this->num_coffee = old_m.num_coffee;
    if(this->coffee_arr != NULL){
        delete [] this->coffee_arr;
        this->coffee_arr = NULL;
    }
    this->coffee_arr = new Coffee[this->num_coffee];
    for(int i = 0; i < this->num_coffee; i++){
        this->coffee_arr[i] = old_m.coffee_arr[i];
    }
    return *this;
}