/*********************************************************************
** Program Filename: coffee++.cpp
** Author: Anthony Silva
** Date: 02/17/2023
** Description: holds driver function to run the main shop object.
** Input and Output: see class implementation files.
** Type: Driver File
*********************************************************************/

#include <string>
#include <fstream>
#include "shop.h"

using namespace std;

int main(){
    ifstream fin1;
    ifstream fin2;
    ifstream fin3;
    Shop CoffeePlusPlus;
    if(!CoffeePlusPlus.open_files(fin1, fin2, fin3)){
        cout << "Failed to open files. Shutting down..." << endl;
        return 1;
    }
    CoffeePlusPlus.load_data(fin1, fin2, fin3);
    CoffeePlusPlus.close_files(fin1, fin2, fin3);
    CoffeePlusPlus.run_shop();
    return 0;
}