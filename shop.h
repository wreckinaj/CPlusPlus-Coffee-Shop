/*********************************************************************
** Program Filename: shop.h
** Author: Anthony Silva
** Date: 02/17/2023
** Description: Stores class declaration, which includes private member
   variables and public function prototypes, for the shop class,
   implemented in the "shop.cpp" class.
** Type: Header File
*********************************************************************/

#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <fstream>
#include "menu.h"
#include "order.h"

using namespace std;

class Shop {
  private:
    Menu m;
    string phone;
    string address;
    float revenue;
    Order *order_arr;
    int num_orders;
  public:
    Shop();
    bool open_files(ifstream &fileA, ifstream &fileB, ifstream &fileC);
    void set_phone(const string phone);
    void set_address(const string address);
    void set_num_orders(const int num_orders);
    void set_order_arr(const int num_orders);
    Order* get_order_arr() const;
    void populate_order_arr(int num_orders, ifstream &fileA);
    void load_order_data(ifstream &fileA);
    void load_menu_data(ifstream &fileB);
    void load_shop_data(ifstream &fileC);
    void load_data(ifstream &fileA, ifstream &fileB, ifstream &fileC);
    void close_files(ifstream &fileA, ifstream &fileB, ifstream &fileC);
    float get_revenue() const;
    void view_revenue();
    void view_menu();
    string get_address() const;
    void view_address();
    string get_phone() const;
    void view_phone();
    int get_item_quantity();
    int get_confirmation();
    void add_order(string name, char size, int quantity);
    void search_by_price();
    void search_by_name();
    float calculate_cost(int quantity, char size, string name);
    void set_revenue(const float revenue);
    void create_new_order_text();
    void place_order_from_size(string name);
    void place_order_from_name();
    void create_new_menu_text();
    void add_to_menu();
    void remove_from_menu();
    int get_num_orders() const;
    void view_orders();
    void check_customer_selection(string user_selection);
    void customer_menu();
    void check_employee_selection(string user_selection);
    void employee_menu();
    void evaluate_status(string user_status);
    void run_shop();
    ~Shop();
    Shop(const Shop &old_s);
    Shop& operator=(const Shop &old_s);
};

#endif