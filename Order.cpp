/*
    author: Bekir Koray Kural
    id:     150170053
    date:   08/04/2020
*/
#include "Order.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Order::Order(string customer_name, MyVector<Pizza> &incoming_pizzas)
{
    customer = customer_name;
    pizzas = incoming_pizzas;
    next = NULL;
    drinks = "";
    total_price = pizzas.size() * pizzas.get(0).getPrice();
}

Order::Order(string customer_name, MyVector<Pizza> &incoming_pizzas, MyVector<int> &incoming_drinks)
{
    customer = customer_name;
    pizzas = incoming_pizzas;
    next = NULL;
    drinks = "";
    total_price = pizzas.size() * pizzas.get(0).getPrice();

    // create drinks string and add drink prices to total
    int num_cola = 0, num_soda = 0, num_juice = 0, num_tea = 0;
    for (int i = 0; i < incoming_drinks.size(); i++)
    {
        switch (incoming_drinks.get(i))
        {
        case 1:
            num_cola++;
            total_price += 4;
            break;
        case 2:
            num_soda++;
            total_price += 2;
            break;
        case 3:
            num_tea++;
            total_price += 3;
            break;
        case 4:
            num_juice++;
            total_price += 3.5;
            break;
        default:
            break;
        }
    }

    stringstream ss;
    string str;
    if(num_cola > 0)
    {
        ss << num_cola;
        str = ss.str();
        drinks += str + " cola, ";
    }
    ss.str("");
    if(num_soda > 0)
    {
        ss << num_soda;
        str = ss.str();
        drinks += str + " soda, ";
    }
    ss.str("");
    if(num_tea > 0)
    {
        ss << num_tea;
        str = ss.str();
        drinks += str + " ice tea, ";
    }
    ss.str("");
    if(num_juice > 0)
    {
        ss << num_juice;
        str = ss.str();
        drinks += str + " fruit juice, ";
    }
}

void Order::printOrder()
{
    cout << "-----------------------------------------------" << endl;
    cout << "Name: " << customer << "\n\n";
    for (int i = 0; i < pizzas.size(); i++)
    {
        pizzas.get(i).printPizza();
    }
    
    cout << "Drinks: " << drinks << endl;
    cout << "-----------------------------------------------" << endl;    
}

string Order::getCustomer()
{
    return customer;
}

float Order::getPrice()
{
    return total_price;
}