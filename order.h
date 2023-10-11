/*********************************************************************
** Program Filename: order.h
** Author: Anthony Silva
** Date: 02/17/2023
** Description: Stores class declaration, which includes private member
   variables and public function prototypes, for the shop class,
   implemented in the "order.cpp" class.
** Type: Header File
*********************************************************************/

#ifndef ORDER_H
#define ORDER_H 

#include <iostream>
#include <string>

using namespace std;

class Order
{
private:
	int id;
	string coffee_name;
	char coffee_size;
	int quantity;

public:
	Order();
	void set_id(const int id);
	void set_coffee_name(const string coffee_name);
	void set_coffee_size(const char coffee_size);
	void set_quantity(const int quantity);
	int get_id() const;
	string get_coffee_name() const;
	char get_coffee_size() const;
	int get_quantity() const;
};
#endif