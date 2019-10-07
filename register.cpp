#include "register.hpp"
#include "customer.hpp"

Register::Register() : 
time_per_item (1)
{}

void Register::add_customer_to_queue(Customer* _customer) {
    customer_queue.push(_customer);
}

void Register::remove_front_customer_from_queue() {
    customer_queue.pop();
}

void Register::set_time_per_item(int _time_per_item) {
    time_per_item = _time_per_item;
}

int Register::get_queue_size() {
    return customer_queue.size();
}

int Register::get_back_customer_basket_size() {
    if (get_queue_size() == 0) {
        return 0;
    }

    return customer_queue.back()->get_number_of_items();
}

int Register::simulate_minute() {
    if (get_queue_size() == 0) {
        return 0;
    }

    if(customer_queue.front()->decrement_items() == 0) {
        remove_front_customer_from_queue();
        return 1;
    }   
    
    return 0;
}

///////////////////////////////////////////////////////////////////////////
//Training Register subclass functions
///////////////////////////////////////////////////////////////////////////

Training_Register::Training_Register(int _time_per_item) : 
current_time_left_on_item (_time_per_item)
{set_time_per_item(_time_per_item);}

void Training_Register::reset_current_time_left_on_item() {
    current_time_left_on_item = time_per_item;
}

int Training_Register::simulate_minute() {
    if (get_queue_size() == 0) {
        return 0;
    }

    if (--current_time_left_on_item == 0) {
        customer_queue.front()->decrement_items();
        reset_current_time_left_on_item();
    }

    if(customer_queue.front()->get_number_of_items() == 0) {
        remove_front_customer_from_queue();
        return 1;
    }

    return 0;
}
///////////////////////////////////////////////////////////////////////////