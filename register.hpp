#ifndef register_h
#define register_h

#include <queue>
#include "customer.hpp"

class Register {

protected:
    int time_per_item;
    std::queue<Customer*> customer_queue;
    void set_time_per_item(int _time_per_item);

public:
    Register();

    int get_queue_size();
    int get_back_customer_basket_size();
    void add_customer_to_queue(Customer* _customer);
    void remove_front_customer_from_queue();


    // Only done if in store active register?
    virtual int simulate_second();
    virtual ~Register() {};
};

// For any time_per_item > 1
class Training_Register : public Register {

private:
    int current_time_left_on_item;

public:
    Training_Register(int _time_per_item);
    int simulate_second();
    void reset_current_time_left_on_item();
};


#endif