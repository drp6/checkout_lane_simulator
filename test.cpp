#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "customer.hpp"
#include "register.hpp"
#include "store.hpp"

int get_store_info(std::string file_path, std::vector<Customer*> &customer_list, std::vector<Register*> &register_list);
std::vector<Register*> create_register_list(int number_of_registers);
void clean_up_lists(std::vector<Customer*> &customer_list, std::vector<Register*> &register_list);

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cout << "usage: cashier_sim input_file" << std::endl;
        return 1;
    }

    std::vector<Customer*> customer_list;
    std::vector<Register*> register_list;
    if (get_store_info(argv[1], customer_list, register_list) == -1) {
        return 1;
    };

    Store store(customer_list, register_list);
    store.order_entering_customers(customer_list);
    for (auto i : customer_list) i->print();

    // int ptr = 0;
    // for (int i = 1; i < 10; ++i) {
    //     std::cout << i << std::endl;
    //     register_list[0]->simulate_second();
    //     if (ptr < customer_list.size() && customer_list[ptr]->get_time_placed() == i) {
    //         register_list[0]->add_customer_to_queue(customer_list[ptr++]);
    //     }
    // }

    clean_up_lists(customer_list, register_list);
    
    return 0;
}

int get_store_info(std::string file_path, std::vector<Customer*> &customer_list, std::vector<Register*> &register_list) {

    std::ifstream customer_data;
    customer_data.open(file_path);

    if (!customer_data.is_open()) {
        std::cout << "ERROR: could not open file" << std::endl;
        return -1;
    }

    std::string line;

    getline(customer_data, line);
    int number_of_registers = std::stoi(line);
    register_list = create_register_list(number_of_registers);
    
    int ret = 0;
    while(getline(customer_data, line)) {
        int time_placed, items_in_basket;
        std::istringstream iss(line);
        std::string arg, customer_type;
        
        iss >> arg;
        if (arg != "A" && arg != "B") {
            std::cout << "ERROR: customer type not recognized" << std::endl;
            return -1;
        }
        customer_type = arg;

        iss >> arg;
        time_placed = std::stoi(arg);

        iss >> arg;
        items_in_basket = std::stoi(arg);
        
        customer_list.emplace_back(new Customer(customer_type, time_placed, items_in_basket));
        ++ret;
    }
    customer_data.close();

    return ret;
}

std::vector<Register*> create_register_list(int number_of_registers) {
    std::vector<Register*> ret;

    for (int i = 0; i < number_of_registers - 1; ++i) {
        ret.emplace_back(new Register());
    }

    if (number_of_registers != 0) {
        ret.emplace_back(new Training_Register(2));
    }
    return ret;
}

void clean_up_lists(std::vector<Customer*> &customer_list, std::vector<Register*> &register_list) {
    for (size_t i = 0; i < customer_list.size(); ++i) {
        delete(customer_list[i]);
    }

    for (size_t i = 0; i < register_list.size(); ++i) {
        delete(register_list[i]);
    }
}
