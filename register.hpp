#ifndef register_h
#define register_h

#include <queue>
#include "customer.hpp"

class Register {
private:
    int time_per_item;
    int current_time_left_on_item;
    std::queue<Customer> customer_queue;

public:
    Register(int _time_per_item) : 
    time_per_item (_time_per_item) {}

    int get_queue_size();
    int get_back_customer_basket_size();
    void add_customer_to_queue(Customer _customer);
    void remove_front_customer_from_queue();

    // Only done if in store active register
    void simulate_second();
    


}


#endif