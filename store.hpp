#ifndef store_h
#define store_h

#include <vector>
#include "customer.hpp"
#include "register.hpp"

class Store {
private:
    int number_of_registers;
    int customers_remaining;
    int current_time;
    int customer_index;
    std::vector<Register*> register_list;
    std::vector<Customer*> customer_list;

protected:
    // This custom sorting function will sort in ascending order of customer items,
    // and will place "A" types in front of "B" types in the case of a tie.
    void order_entering_customers(std::vector<Customer*> &entering_customers);

    // Places customers in a register based on "A" or "B" type
    void place_entering_customers(std::vector<Customer*> const &entering_customers);

    // Will place a customer in the register queue that has the shortest line.
    void place_A_type(Customer* _customer);

    // Will place a customer in the register queue whose back customer has the fewest items.
    void place_B_type(Customer* _customer); 

public:
    // Constructor accepts a list of customers (in ascending order of time) and a list of registers available
    Store(std::vector<Customer*> &_customer_list, std::vector<Register*> &_register_list);

    // Getters
    int get_customers_remaining();
    int get_current_time();

    // This function will simulate a second of time for the grocery store.
    // It will increment the current_time, place incoming customers at registers,
    // and process items for customers already at a register.
    void simulate_minute(); 
};

#endif