/******************************************************
 ** Author: Carlos Carrillo                           *
 ** Date:   10/16/2015                                *
 ** Description: This is the class specification file *
 *  of a class called Item. this class consists of a  *
 *  string called name, a double called price, and an *
 *  int called quantity. It has get and set methods   *
 *  for each field. It has a constructor that takes   *
 *  three parameters and passes them to the set       *
 *  methods. It has a default constructor that sets   *
 *  name to "", price to 0.0 and quantity to 0.       *
 *****************************************************/

// Item.hpp
#ifndef ITEM_HPP
#define ITEM_HPP

class Item
{
    private:
    
        std::string name; //string private member variable
        int quantity; //int private member variable
        std::string unit; //string private member variable
        double price; //double private member variable
    
    public:
    
        //4-parameter constructor
        Item(std::string, int, std::string, double);
    
        Item(); //default constructor
    
        void setName(std::string);//mutator
        void setQuantity(int);//mutator
        void setUnit(std::string);//mutator
        void setPrice(double);//mutator
    
        std::string getName();//getter
        int getQuantity(); //getter
        std::string getUnit();//getter
        double getPrice(); //getter
};
#endif

