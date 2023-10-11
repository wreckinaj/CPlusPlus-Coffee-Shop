/*********************************************************************
** Program Filename: menu.h
** Author: Anthony Silva
** Date: 02/17/2023
** Description: Stores class declaration, which includes private member
   variables and public function prototypes, for the shop class,
   implemented in the "menu.cpp" class.
** Type: Header File
*********************************************************************/

#ifndef MENU_H
#define MENU_H 

#include <iostream>
#include <string>
#include <fstream>
#include "coffee.h"

using namespace std;

class Menu {
  private:
    int num_coffee;
    Coffee* coffee_arr;
  public:
    Menu();
    Menu(int size);
    Coffee get_coffee_arr(int i) const;
    void set_coffee_arr(const int num_coffee);
    void set_num_coffee(const int num_coffee);
    int get_num_coffee() const;
    void populate_menu(int num_coffee, ifstream &fileB);
    bool search_coffee_by_name(string name); 
    bool search_coffee_by_price(int upper_bound);
    void add_to_menu(string name, float small, float medium, float large);
    void remove_from_menu(int index_of_coffee_on_menu);
    ~Menu();
    Menu (const Menu &old_m);
    Menu& operator=(const Menu &old_m);
};

#endif