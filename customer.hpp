#ifndef customer_h
#define customer_h

#include <string>
#include <iostream> // DEBUG

class Customer {
private:
    std::string customer_type;
    int time_placed;
    int items_in_basket;

public:

    Customer(std::string _customer_type, int _time_placed, int _items_in_basket);

    // Returns the number of items in the customer's basket
    int get_number_of_items();

    int get_time_placed();

    // Decreases the amount of items in the customer's basket by 1
    // Returns the number of remaining items in the customer's basket
    int decrement_items() ;

    void print() { //DEBUG
        std::cout << customer_type << " " << time_placed << " " << items_in_basket << std::endl;  
    }
};

#endif