#include "Pizza.h"
#include "MyVector.h"
#include <string>

using namespace std;

class Order
{
private:
    string customer;
    MyVector<Pizza> pizzas;
    string drinks;
    float total_price;
public:
    Order *next;
    Order(string customer_name, MyVector<Pizza> pizzas);
    Order(string customer_name, MyVector<Pizza> pizzas, MyVector<int> drinks);
    void printOrder();
    string getCustomer();
    float getPrice();
};