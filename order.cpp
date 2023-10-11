/*********************************************************************
** Program Filename: order.cpp
** Author: Anthony Silva
** Date: 02/18/2023
** Description: Implements the order class. Handles the construction of
   new orders, as well as the accessor and mutator functions for the
   order objects stored in the order array.
** Input: the functions are called when in the process of collecting
   the order of the customer or displaying the orders to the
   employee.
** Output: the variables for the order are set, or they are returned.
** Type: Implementation File
*********************************************************************/

#include <iostream>
#include <string>
#include "order.h"

using namespace std;

/*********************************************************************
** Function: Order::Order()
** Description: sets the default values for the order object.
** Parameters: None
** Pre-Conditions: an order is being placed, and new memory needs to be
   made for this to occur. At the beginning of the program, the files
   should be opened so that the program can be run.
** Post-Conditions: the variables of the object created can be modified
   depending on the contents of the orders.
** Type: Constructor Function
*********************************************************************/ 
Order::Order(){
    id = 0;
    coffee_name = "";
    coffee_size = 'N';
    quantity = 0;
}

/*********************************************************************
** Function: void Order::set_id(const int id)
** Description: sets the order number of the object based on the position
   in the file.
** Parameters: The order number of the order object.
** Pre-Conditions: A new order is taken.
** Post-Conditions: the order number is set for the order placed.
** Type: Mutator Function
*********************************************************************/ 
void Order::set_id(const int id){
    this->id = id;
}

/*********************************************************************
** Function: void Order::set_coffee_name(const string coffee_name)
** Description: sets the name of the item in the order based on what
   the customer wants.
** Parameters: the item ordered
** Pre-Conditions: A new order is taken.
** Post-Conditions: the name of the item ordered is set.
** Type: Mutator Function
*********************************************************************/ 
void Order::set_coffee_name(const string coffee_name){
    this->coffee_name = coffee_name;
}

/*********************************************************************
** Function: void Order::set_coffee_size(const char coffee_size)
** Description: sets the size of the item in the order based on what
   the customer wants.
** Parameters: the size of the item ordered
** Pre-Conditions: A new order is taken.
** Post-Conditions: the size of the item ordered is set.
** Type: Mutator Function
*********************************************************************/ 
void Order::set_coffee_size(const char coffee_size){
    this->coffee_size = coffee_size;
}

/*********************************************************************
** Function: void Order::set_quantity(const int quantity)
** Description: sets the number of an item ordered into the object.
** Parameters: the number of items ordered.
** Pre-Conditions: A new order is taken.
** Post-Conditions: the number of items in an order is set.
** Type: Mutator Function
*********************************************************************/ 
void Order::set_quantity(const int quantity){
    this->quantity = quantity;
}

/*********************************************************************
** Function: int Order::get_id() const
** Description: collects the order number of an object so that it can
   be transferred to a new order array.
** Parameters: None
** Pre-Conditions: A new order is taken.
** Post-Conditions: the order number is returned so that it can be copied
   to the new array.
** Type: Accessor Function
*********************************************************************/ 
int Order::get_id() const{
    return this->id;
}

/*********************************************************************
** Function: string Order::get_coffee_name() const
** Description: collects the item of an object so that it can be
   transferred to a new order array.
** Parameters: None
** Pre-Conditions: A new order is taken.
** Post-Conditions: the item in the order is returned so that it can be
   copied to the new array.
** Type: Accessor Function
*********************************************************************/ 
string Order::get_coffee_name() const{
    return this->coffee_name;
}

/*********************************************************************
** Function: char Order::get_coffee_size() const
** Description: collects the size of an item so that it can be
   transferred to a new order array.
** Parameters: None
** Pre-Conditions: A new order is taken.
** Post-Conditions: the size of the item is returned so that it can be
   copied to the new array.
** Type: Accessor Function
*********************************************************************/ 
char Order::get_coffee_size() const{
    return this->coffee_size;
}

/*********************************************************************
** Function: int Order::get_quantity() const
** Description: collects the number of items ordered so that it can be
   transferred to a new order array.
** Parameters: None
** Pre-Conditions: A new order is taken.
** Post-Conditions: the number of items ordered is returned so that it
   can be copied to the new array.
** Type: Accessor Function
*********************************************************************/ 
int Order::get_quantity() const{
    return this->quantity;
}