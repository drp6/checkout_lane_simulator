#include <vector>
#include <string>
#include <algorithm>
#include "store.hpp"
#include "register.hpp"
#include "customer.hpp"

Store::Store(std::vector<Customer*> &_customer_list, std::vector<Register*> &_register_list) :
customer_list (_customer_list), register_list (_register_list), customers_remaining (_customer_list.size()),
current_time (0), customer_index (0)
{};

int Store::get_customers_remaining() {
    return customers_remaining;
}

void Store::simulate_second() {
    ++current_time;

    for (const auto &reg : register_list) {
        reg->simulate_second();
    }

    std::vector<Customer*> entering_customers;
    while (customer_index < customer_list.size() && customer_list[customer_index]->get_time_placed() == current_time) {
        entering_customers.push_back(customer_list[customer_index++]);
    }
    //order_entering_customers(entering_customers);
}

void Store::order_entering_customers(std::vector<Customer*> &entering_customers) {
    std::sort(entering_customers.begin(), entering_customers.end(), []( const auto &lhs, const auto &rhs )
    {   
        if (lhs->get_number_of_items() == rhs->get_number_of_items()) {
            return lhs->get_customer_type() < rhs->get_customer_type();
        }
        return lhs->get_number_of_items() < rhs->get_number_of_items();
    });
}

 void Store::place_A_type(Customer* _customer) {
    int shortest_queue_size = register_list[0]->get_queue_size();
    int shortest_queue_index = 0;
    

    for (size_t i = 0; i < register_list.size(); ++i) {
        int queue_size = register_list[i]->get_queue_size();
        if (queue_size == 0) {
            register_list[i]->add_customer_to_queue(_customer);
            return;
        }
        if (queue_size < shortest_queue_size) {
            shortest_queue_size == queue_size;
            shortest_queue_index = i;
        }

    }
    register_list[shortest_queue_index]->add_customer_to_queue(_customer);
}

void Store::place_B_type(Customer* _customer) {
    int smallest_basket_size = register_list[0]->get_back_customer_basket_size();
    int smallest_basket_index = 0;
    

    for (size_t i = 0; i < register_list.size(); ++i) {
        int basket_size = register_list[i]->get_back_customer_basket_size();
        if (basket_size == 0) {
            register_list[i]->add_customer_to_queue(_customer);
            return;
        }
        if (basket_size < smallest_basket_size) {
            smallest_basket_size == basket_size;
            smallest_basket_index = i;
        }

    }
    register_list[smallest_basket_index]->add_customer_to_queue(_customer);
}






