#ifndef customer_h
#define customer_h

#include <string>

class Customer {
private:
    std::string customer_type; 
    int time_placed;
    int items_in_basket;

public:
    Customer(std::string _customer_type, int _time_placed, int _items_in_basket);

    // Getters
    int get_number_of_items();
    int get_time_placed();
    std::string get_customer_type();

    // Decreases the amount of items in the customer's basket by 1
    // Returns the number of remaining items in the customer's basket
    int decrement_items() ;
};

#endif