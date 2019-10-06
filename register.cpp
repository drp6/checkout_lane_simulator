#include "register.hpp"
#include "customer.hpp"

#include <iostream> // DEBUG

Register::Register(int _time_per_item) : 
time_per_item (_time_per_item), current_time_left_on_item (_time_per_item)
{}

void Register::add_customer_to_queue(Customer &_customer) {
    customer_queue.push(_customer);
}

void Register::remove_front_customer_from_queue() {
    customer_queue.pop();
}


int Register::get_queue_size() {
    return customer_queue.size();
}

int Register::get_back_customer_basket_size() {
    if (get_queue_size() == 0) {
        return 0;
    }

    return customer_queue.back().get_number_of_items();
}

void Register::reset_current_time_left_on_item() {
    current_time_left_on_item = time_per_item;
}

void Register::simulate_second() {
    if (get_queue_size() == 0) {
        return;
    }

    if (--current_time_left_on_item == 0) {
        customer_queue.front().decrement_items();
        reset_current_time_left_on_item();
    }

    if(customer_queue.front().get_number_of_items() == 0) {
        remove_front_customer_from_queue();
        std::cout << "CUSTOMER DONE!" << std::endl; //DEBUG
    }

    

}