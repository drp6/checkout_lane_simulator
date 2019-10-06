#include "customer.hpp"

Customer::Customer(std::string _customer_type, int _time_placed, int _items_in_basket) :
customer_type(_customer_type), time_placed(_time_placed), items_in_basket(_items_in_basket)
{}

int Customer::get_number_of_items() {
    return items_in_basket;
}

int Customer::decrement_items() {
    return --items_in_basket;
}
