#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "customer.hpp"

int update_customer_list(std::string file_path, std::vector<Customer> &customer_list);

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cout << "usage: cashier_sim input_file" << std::endl;
        return 1;
    }

    std::vector<Customer> customer_list;
    if (update_customer_list(argv[1], customer_list) == -1) {
        std::cout << "error opening file" << std::endl;
        return 1;
    };

    for (auto i : customer_list) {
        i.print();
    }

    return 0;
}

int update_customer_list(std::string file_path, std::vector<Customer> &customer_list) {

    std::ifstream customer_data;
    customer_data.open(file_path);

    if (!customer_data.is_open()) {
        return -1;
    }

    std::string line, customer_type;
    int time_placed, items_in_basket;

    int ret = 0;
    while(getline(customer_data, line)) {
        std::istringstream iss(line);
        std::string arg;

        iss >> arg;
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
