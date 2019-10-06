#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "customer.hpp"
#include "register.hpp"

int get_store_info(std::string file_path, int &number_of_registers, std::vector<Customer> &customer_list);

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cout << "usage: cashier_sim input_file" << std::endl;
        return 1;
    }

    std::vector<Customer> customer_list;
    int number_of_registers;
    if (get_store_info(argv[1], number_of_registers, customer_list) == -1) {
        return 1;
    };

    // for (auto i : customer_list) {
    //     i.print();
    // }

    int ptr = 0;
    Register r1(2);
    for (int i = 1; i < 10; ++i) {
        std::cout << i << std::endl;
        r1.simulate_second();
        if (customer_list[ptr].get_time_placed() == i) {
            r1.add_customer_to_queue(customer_list[ptr++]);
        }
        
    }

    std::vector<Register> regi; //(5,Register(1));
    regi.resize(5, Register(1));
    std::cout << regi[2].get_queue_size();
    
    return 0;
}

int get_store_info(std::string file_path, int &number_of_registers, std::vector<Customer> &customer_list) {

    std::ifstream customer_data;
    customer_data.open(file_path);

    if (!customer_data.is_open()) {
        std::cout << "ERROR: could not open file" << std::endl;
        return -1;
    }

    std::string line, customer_type;
    int time_placed, items_in_basket;
    

    getline(customer_data, line);
    number_of_registers = std::stoi(line);
    //create_register_list(number_of_registers)
    

    int ret = 0;
    while(getline(customer_data, line)) {
        std::istringstream iss(line);
        std::string arg;
        
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
        
        customer_list.push_back(Customer(customer_type, time_placed, items_in_basket));
        ++ret;
    }
    customer_data.close();

    return ret;
}
