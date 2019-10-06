#include "customer.hpp"

Register::Register(int _time_per_item) : 
    time_per_item (_time_per_item) {}




int get_queue_size() {
    return customer_queue.size()
}

int get_back_customer_basket_size() {
    if (get_queue_size() == 0) {
        return 0;
    }

    return customer_queue.back.items_in_basket;
}