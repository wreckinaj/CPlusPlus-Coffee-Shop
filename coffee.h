/*********************************************************************
** Program Filename: coffee.h
** Author: Anthony Silva
** Date: 02/17/2023
** Description: Stores class declaration, which includes private member
   variables and public function prototypes, for the shop class,
   implemented in the "coffee.cpp" class.
** Type: Header File
*********************************************************************/

#ifndef COFFEE_H
#define COFFEE_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Coffee {
  private:
    string name;
    float small_cost;
    float medium_cost;
    float large_cost;
    
  public:
    Coffee();
    void set_name (const string name);
    void set_small_cost(const float cost);
    void set_medium_cost(const float cost);
    void set_large_cost(const float cost);
    string get_name() const;
    float get_small_cost () const;
    float get_medium_cost () const;
    float get_large_cost () const;
};

#endif