/*********************************************************************
** Program Filename: coffee.cpp
** Author: Anthony Silva
** Date: 02/18/2023
** Description: Implements the coffee class. Handles the construction of
   new items, as well as the accessor and mutator functions for the
   coffee objects stored in the coffee array.
** Input: the functions are called when in the process of creating the
   new menu.
** Output: the variables for the item are set, or they are returned.
** Type: Implementation File
*********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "coffee.h"

using namespace std;

/*********************************************************************
** Function: Coffee::Coffee()
** Description: sets the default values for the coffee object.
** Parameters: None
** Pre-Conditions: the menu needs to be adjusted, and new memory needs
   to me made. At the beginning of the program, the files should be
   opened so that the program can be run.
** Post-Conditions: the variables of the object created can be modified
   depending on the contents of the items.
** Type: Constructor Function
*********************************************************************/ 
Coffee::Coffee(){
    name = "DEFAULT";
    small_cost = 0.0;
    medium_cost = 0.0;
    large_cost = 0.0;
}

/*********************************************************************
** Function: void Coffee::set_name (const string name)
** Description: sets the name of the coffee item.
** Parameters: the name of the item.
** Pre-Conditions: the menu needs to be adjusted.
** Post-Conditions: the name of the item on the menu is set.
** Type: Mutator Function
*********************************************************************/ 
void Coffee::set_name (const string name){
    this->name = name;
}

/*********************************************************************
** Function: void Coffee::set_small_cost(const float cost)
** Description: sets the cost for a small-sized coffee.
** Parameters: the cost for the small size.
** Pre-Conditions: the menu needs to be adjusted.
** Post-Conditions: the small cost for the item is set.
** Type: Mutator Function
*********************************************************************/ 
void Coffee::set_small_cost(const float cost){
    this->small_cost = cost;
}

/*********************************************************************
** Function: void Coffee::set_medium_cost(const float cost)
** Description: sets the cost for a medium-sized coffee.
** Parameters: the cost for the medium size.
** Pre-Conditions: the menu needs to be adjusted.
** Post-Conditions: the medium cost for the item is set.
** Type: Mutator Function
*********************************************************************/ 
void Coffee::set_medium_cost(const float cost){
    this->medium_cost = cost;
}

/*********************************************************************
** Function: void Coffee::set_large_cost(const float cost)
** Description: sets the cost for a large-sized coffee.
** Parameters: the cost for the large size.
** Pre-Conditions: the menu needs to be adjusted.
** Post-Conditions: the large cost for the item is set.
** Type: Mutator Function
*********************************************************************/ 
void Coffee::set_large_cost(const float cost){
    this->large_cost = cost;
}

/*********************************************************************
** Function: string Coffee::get_name() const
** Description: collects the name of the item so that it can be
   transferred to a new array.
** Parameters: None
** Pre-Conditions: the menu needs to be adjusted.
** Post-Conditions: the name of the item is returned.
** Type: Accessor Function
*********************************************************************/ 
string Coffee::get_name() const{
    return this->name;
}

/*********************************************************************
** Function: float Coffee::get_small_cost () const
** Description: collects the cost for a small-sized coffee so that it
   can be transferred to a new array.
** Parameters: None
** Pre-Conditions: the menu needs to be adjusted.
** Post-Conditions: the small cost of the item is returned.
** Type: Accessor Function
*********************************************************************/ 
float Coffee::get_small_cost () const{
    return this->small_cost;
}

/*********************************************************************
** Function: float Coffee::get_medium_cost () const
** Description: collects the cost for a medium-sized coffee so that it
   can be transferred to a new array.
** Parameters: None
** Pre-Conditions: the menu needs to be adjusted.
** Post-Conditions: the medium cost of the item is returned.
** Type: Accessor Function
*********************************************************************/         
float Coffee::get_medium_cost () const{
    return this->medium_cost;
}

/*********************************************************************
** Function: float Coffee::get_large_cost () const
** Description: collects the cost for a large-sized coffee so that it
   can be transferred to a new array.
** Parameters: None
** Pre-Conditions: the menu needs to be adjusted.
** Post-Conditions: the large cost of the item is returned.
** Type: Accessor Function
*********************************************************************/ 
float Coffee::get_large_cost () const{
    return this->large_cost;
}