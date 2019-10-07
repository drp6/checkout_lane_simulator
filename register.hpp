#ifndef register_h
#define register_h

#include <queue>
#include "customer.hpp"

class Register {

protected:
    std::queue<Customer*> customer_queue;
    int time_per_item;
    // Changes the time required to process an item for subclasses
    void set_time_per_item(int _time_per_item);

public:
    Register();
    virtual ~Register() {};

    // Getters
    int get_queue_size();
    int get_back_customer_basket_size();

    // Adds a customer to the back of the register's queue
    void add_customer_to_queue(Customer* _customer);

    // Removes the customer from the front of the queue;
    void remove_front_customer_from_queue();

    // If there is a customer in the queue, this function will process the front user's
    // items at a rate of 1 per minute. If the front customer has no remaining items,
    // the customer is removed from the queue and the next customer (if available) will
    // be brought to the front.
    // This function will return 1 if a customer transaction is completed, and will
    // return 0 in all other cases.
    virtual int simulate_minute();
};

// The Training_Register subclass can be used for any cashier that has an item processing
// rate greater than 1.
class Training_Register : public Register {

private:
    int current_time_left_on_item;

protected:
    // Helper function for subclass simulate_minute()
    void reset_current_time_left_on_item();

public:
    // Constructor accepts an integer value for the time required to process 1 item.
    Training_Register(int _time_per_item);

    // Same functionality as superclass, overridden to account for longer item processing times.
    int simulate_minute();
    
};

#endif