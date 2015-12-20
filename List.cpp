/*******************************************************
 ** Author: Carlos Carrillo                            *
 ** Date:   10/16/2015                                 *
 ** Description: This is the class implementation file *
 *  of a class called List. This class contains        *
 *  as a data member a vector of pointer-to-Item. It   *
 *  has a default constructor. It has a function       *
 *  called addItem that takes as a parameter a pointer *
 *  to an Item and adds it to the vector. It also      *
 *  has a function called totalPrice that returns the  *
 *  total cost of all Items in the list for which you  *
 *  must take into account the quantity of each Item.  *
 ******************************************************/

//List.cpp
#include <list>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "List.hpp"

using namespace std;

/*************************************************
 *                  List::List                   *
 * Default constructor: initializes each element *
 * of the vector to NULL.                        *
 ************************************************/

List::List()
{
    //for loop to initialize each array element
    for(int i=0; i<product.size(); i++)
     {
       product.at(i) = NULL;
     }
}

/*************************************************
 *            List::List(std::string)            *
 * 1-parameter constructor: passes a parameter   *
 * to set the method to overload the equality    *
 * operator.                                     *
 ************************************************/

List::List(std::string comparacion)
{
    setList(comparacion);
}

/*************************************************
 *                 List::setList                 *
 * This function sets the value of the member    *
 * variable compara for the overload operator == *
 ************************************************/

void List::setList(std::string comparacion)
{
    compara = comparacion;
}

/*************************************************
 *               List::getCompara                *
 * This function returns the value of the member *
 * variable compara for the overload operator == *
 ************************************************/

std::string List::getCompara()
{
    return compara;
}

/*************************************************
 *           Overloaded operator ==              *
 * This function overload the equality operator  *
 * (==) to prevent including duplicate items in  *
 * the shopping list.                            *
 ************************************************/

bool operator==(List a, List b)
{
    return a.compara == b.compara;
}

/*************************************************
 *                 List::addItem                 *
 * This function takes as a parameter a pointer  *
 * to an Item and adds it to the vector.         *
 ************************************************/

void List::addItem(Item *object)
{
    product.push_back(object);
}

/*************************************************
 *               List::removeItem                *
 * This function removes a specified item from   *
 * products vector/shopping list.                *
 ************************************************/

void List::removeItem(Item *remove)
{
    for(int i=0; i<product.size(); i++)
      {
        if(product.at(i)->getName()==remove->getName())
          {
             product.erase(product.begin()+i);
          }
      }
}

/*************************************************
 *                List::totalPrice               *
 * This function returns the total cost of all   *
 * the items contained in the shopping list.     *
 ************************************************/

double List::totalPrice()
{
    double price = 0.0;//internal variable
    double total = 0.0;//internal/return variable
    
    //iteration through the items already
    //contained in the vector of pointer-to-Item
    for(int i = 0; i < product.size(); i++)
      {
        //computation to get the price of each item
        price=(product.at(i)->getPrice())*(product.at(i)->getQuantity());
        //computation to get the total price
        //of all the items in the list.
        total += price;
      }
    
    return total;
}

/*************************************************
 *              List::displayItem                *
 * This function displays the entire list of     *
 * items with the extended price for each item   *
 * entered by the user.                          *
 ************************************************/

void List::displayItem()
{
    cout<<"---------------------------------------------------------------------------------"<<endl;
         
         cout<<"| "<<std::setw(17)<<std::left<<"ITEM"<<" | "<<std::setw(8)<<std::right<<"QUANTITY"<<" | "<<std::setw(8)<<std::right<<"UNIT"<<" | "<<std::setw(16)<<std::right<<"PRICE PER UNIT"<<" | "<<std::setw(16)<<std::right<<"TOTAL PER ITEM"<<" |"<<std::endl;
         cout<<"---------------------------------------------------------------------------------"<<endl;

        for(int i=0; i<product.size(); i++)
         {
             
           cout<<"| "<<std::setw(17)<<std::left<<product.at(i)->getName()<<" | "<<std::setw(8)<<std::right<<product.at(i)->getQuantity()<<" | "<<std::setw(8)<<std::right<<product.at(i)->getUnit()<<" | $"<<std::setw(15)<<std::right<<product.at(i)->getPrice()<<" | $"<<std::setw(15)<<std::right<<(product.at(i)->getQuantity())*(product.at(i)->getPrice())<<" |"<<std::endl;
             
           cout<<"---------------------------------------------------------------------------------"<<endl;
         }
}

/*************************************************
 *               List::compareItem               *
 * This function prevents the user to include    *
 * duplicate items in the shopping list by       *
 * displaying a warning message. This function   *
 * also overloads the operator function (==)     *
 ************************************************/

void List::compareItem(Item *compare)
{
    for(int i=0; i<product.size(); i++)
     {
         std::string comparar1 = product.at(i)->getName();
         std::string comparar2 = compare->getName();
         List compa1 (comparar1);
         List compa2 (comparar2);

       if(compa1==compa2)
         {
            cout<<"\n\n\n***WARNING! YOU ALREADY INCLUDED "<<"'"<<comparar2<<"'"<<" IN YOUR LIST!***"<<endl;
            cout<<"**PLEASE SELECT OPTION 2 TO REMOVE THIS ITEM FROM THE LIST!**"<<endl;
         }
     }
}



