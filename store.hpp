#ifndef store_h
#define store_h

#include <vector>
#include "customer.hpp"
#include "register.hpp"

class Store {
private:
    int number_of_registers;
    vector<Register> register_list;
    vector<Customer> customer_list;

public:
    // If original vectors should not be altered or info is sensitive then alternative (new pass by* remove etc)
    Store(std::vector<Register> &_register_list, std::vector<Customer> &_customer_list);
    void place_A_type();
    void place_B_type();
};





#endif