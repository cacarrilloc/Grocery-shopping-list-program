/*******************************************************
 ** Author: Carlos Carrillo                            *
 ** Date:   10/16/2015                                 *
 ** Description: This is the MAIN function to call the *
 *  class Item and List function members in order to   *
 *  execute the entire program.                        *
 ******************************************************/

//main function
#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>
#include <vector>
#include "Item.hpp"
#include "List.hpp"

using namespace std;

int main()
{
    //main variables
    string producto;
    int cantidad;
    string unidades;
    double precio;
    int choice;
    
    //List object
    List myList;
    
    do
    {
        do
        {
            //main menu
            cout<<"\n\nPLEASE FOLLOW THIS MENU TO CREATE YOUR SHOPPING LIST.\n"<<endl;
            cout<< "Enter 1 to ADD an item to the list." <<endl;
            cout<< "Enter 2 to REMOVE an item from the list." <<endl;
            cout<< "Enter 3 to EXIT and start a new list." <<endl;
          
            //Prompt the user to enter an option from the menu
            cout << "\nPlease enter your option: ";
            cin>>choice; //take the input value
            cout <<endl;
        
            if(choice == 1) //ADD an item
              {
                cout <<"Enter the name of the product: ";
                cin >> producto;
                cout <<endl;

                cout <<"How many of this product would you like?: ";
                cin >> cantidad;
                cout <<endl;
             
                cout <<"Enter item units (i.e: cans, lb, onz, doz, kg, gr, gal, etc): ";
                cin >> unidades;
                cout <<endl;
            
                cout <<"Enter price per unit: $";
                cin >> precio;
                cout <<endl;
             
                Item *pItem = new Item(producto, cantidad, unidades, precio);
                myList.compareItem(pItem);
                myList.addItem(pItem);
                myList.displayItem();
                cout <<"| YOUR TOTAL IS: $"<<std::setw(12)<<std::right<<myList.totalPrice()<<" |"<<endl;
                cout <<"--------------------------------"<<endl;
              }
         
            else if(choice == 2) //REMOVE an item
              {
                cout << "Enter the name of the product you would like to remove from the list: ";
                cin >> producto;
                cout <<endl;
               
                Item b(producto, cantidad, unidades, precio);
                myList.removeItem(&b);
                cout << "THE ITEM HAS BEEN SUCCESSFULLY REMOVED FROM THE LIST!!\n";
                myList.displayItem();
                cout <<"| YOUR TOTAL IS: $"<<std::setw(12)<<std::right<<myList.totalPrice()<<" |"<<endl;
                cout <<"--------------------------------"<<endl;
              }
        
            else if(choice == 3)//EXIT the list
              {
                return 0;
              }
        
            else if (!isdigit(choice)) //input validation
            {
                cout << "Invalid option entered. Try again!\n" << endl;
                return 0;
            }
         
        }while(choice != 1 && choice != 2 && choice != 3);
    
    }while(choice);
    
    return 0;
}






