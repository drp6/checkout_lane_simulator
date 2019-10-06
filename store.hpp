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
    std::string file_path;

public:
    Store(std::string _file_path);
    void place_A_type();
    void place_B_type();

    int get_store_info(std::string file_path);
    


};





#endif