/*
    author: Bekir Koray Kural
    id:     150170053
    date:   08/04/2020
*/
#include "Order.h"
#include <iostream>
#include <string>

using namespace std;

class OrderList
{
private:
    int num_of_orders;
    Order *head;
public:
    OrderList();
    ~OrderList();
    void takeOrder();
    void listOrders();
    void deliverOrders();
};