/*******************************************************
 ** Author: Carlos Carrillo                            *
 ** Date:   10/16/2015                                 *
 ** Description: This is the class specification file  *
 *  of a class called List. This class contains        *
 *  as a data member a vector of pointer-to-Item. It   *
 *  has a default constructor. It has a function       *
 *  called addItem that takes as a parameter a pointer *
 *  to an Item and adds it to the vector. It also      *
 *  has a function called totalPrice that returns the  *
 *  total cost of all Items in the list for which you  *
 *  must take into account the quantity of each Item.  *
 ******************************************************/

// List.hpp
#ifndef LIST_HPP
#define LIST_HPP
#include "Item.hpp"
#include <vector>

class List
{
    private:
    
        //Vector of pointer-to-Item
        std::vector<Item*> product;
    
        //Member variable for the overload operator ==
        std::string compara;
    
    public:
    
        //Default constructor
        List();
    
        //1-parameter constructor for the overload operator ==
        List(std::string);
    
        //mutator for the overload operator ==
        void setList(std::string);
    
        //getter for the overload operator ==
        std::string getCompara();
   
        //fuctionprototype for the overloaded operator ==
        friend bool operator== (List a, List b);
    
        //method to add items to the array
        void addItem(Item*);
    
        //method to prevent including duplicate
        //items in the shopping list.
        void compareItem(Item*);

        //method to remove items from the array
        void removeItem(Item*);
    
        //method to display items from the array
        void displayItem();
    
        //method to calculate the total price of
        //all the items contained in the array.
        double totalPrice();    
};
#endif





