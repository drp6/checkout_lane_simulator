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

public:
    // If original vectors should not be altered or info is sensitive then alternative (new pass by* remove etc)
    Store(std::vector<Customer*> &_customer_list, std::vector<Register*> &_register_list);
    int get_customers_remaining();
    
    void simulate_second();
    void order_entering_customers(std::vector<Customer*> &entering_customers);

    void place_A_type(Customer* _customer);
    void place_B_type(Customer* _customer);

    
};


#endif