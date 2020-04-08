#include "OrderList.h"
#include <iostream>
#include <string>

using namespace std;

OrderList::OrderList()
{
    num_of_orders = 0;
    head = NULL;
}

OrderList::~OrderList()
{
    Order *ptr = head;
    while(ptr)
    {
        head = ptr;
        ptr = ptr->next;
        delete head;
    }
}

void OrderList::takeOrder()
{
    // Get pizza selection
    int selected_pizza;
    bool valid_pizza_selection = false;
    while(!valid_pizza_selection)
    {
        cout << endl << "Pizza Menu:" << endl;
        cout << "1. Chicken Pizza (mozarella, chicken, mushroom, corn, onion, tomato)" << endl;
        cout << "2. Broccoli Pizza (mozarella, broccoli, pepperoni, corn, onion, olive)" << endl;
        cout << "3. Sausage Pizza (mozarella, sausage, mushroom, corn, olive, tomato)" << endl;
        cout << "0. Back to main menu" << endl;

        cin >> selected_pizza;

        switch (selected_pizza)
        {
        case 0:
            return;
            break;
        case 1:
        case 2:
        case 3:
            valid_pizza_selection = true;
            break;
        default:
            cout << "Invalid selection!" << endl;
            break;
        }
    }

    // Get size selection
    string selected_size;
    bool valid_size_selection = false;
    while(!valid_size_selection)
    {
        cout << endl << "Select size: 'small' (15 TL), 'medium' (20 TL), 'big' (25 TL)" << endl;
        cout << "Your choice: ";

        cin >> selected_size;

        if(selected_size == "small" || selected_size == "medium" || selected_size == "big")
            valid_size_selection = true;
        else
            cout << "Invalid selection!" << endl;
    }

    // Get crust type selection
    string selected_crust;
    bool valid_crust_selection = false;
    while(!valid_crust_selection)
    {
        cout << endl << "Select crust type: 'thin', 'normal', 'thick'" << endl;
        cout << "Your choice: ";

        cin >> selected_crust;

        if(selected_crust == "thin" || selected_crust == "normal" || selected_crust == "thick")
            valid_crust_selection = true;
        else
            cout << "Invalid selection!" << endl;
    }

    // Get pizza amount
    int amount = 0;
    cout << endl << "Number of pizzas you want: ";
    cin >> amount;

    // Create pizza vector with size 'amount'
    MyVector<Pizza> pizza_arr;

    for (int i = 0; i < amount; i++)
    {
        Pizza this_pizza(selected_size, selected_crust, selected_pizza);

        // Remove some ingredients
        if(i != 0)
        {
            cout << "Enter the index of ingredient(s) you want to remove from the " << (i+1) << "th pizza." << endl;
            this_pizza.print_ingredient_list(selected_pizza);
            cout << "0: Save and continue" << endl;

            while(true)
            {
                int choice;
                cin >> choice;

                if(choice > 0 && choice < 7)
                {
                    int index = choice - 1;
                    this_pizza.remove_ingredient(index);
                }
                else if(choice == 0)
                    break;
                else
                    cout << "Invalid choice!" << endl;
            }
        }

        // Add pizza to vector
        pizza_arr.push(this_pizza);
    }

    // Get drink selection
    MyVector<int> drink_arr;

    cout << endl << "Please choose drink(s)" << endl;
    cout << "1. cola        4 TL" << endl;
    cout << "2. soda        2 TL" << endl;
    cout << "3. ice tea     3 TL" << endl;
    cout << "4. fruit juice 3.5 TL" << endl;
    cout << "0. Save and continue (no drink initially)" << endl;

    bool drink_input = true;
    while(drink_input)
    {
        int drink_choice;
        cin >> drink_choice;

        switch (drink_choice)
        {
        case 0:
        case -1:
            drink_input = false;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
            drink_arr.push(drink_choice);
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }

    // Get customer name
    string customer_name;
    cout << endl << "Please enter your name: ";
    cin >> customer_name;

    // Create Order node
    Order *order_node;
    
    if(drink_arr.size() > 0)
        order_node = new Order(customer_name, pizza_arr, drink_arr);
    else
        order_node = new Order(customer_name, pizza_arr);

    cout << endl << "Your order is taken and will be delivered ASAP. " << endl;
    order_node->printOrder();
    cout << endl;

    // Add new order to the list
    Order *ptr = head;
    if(num_of_orders == 0)
    {
        head = order_node;
        num_of_orders = 1;
    }
    else
    {
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = order_node;
        num_of_orders++;
    }
}

void OrderList::listOrders()
{
    Order *ptr = head;
    while(ptr)
    {
        ptr->printOrder();
        ptr = ptr->next;
    }

    if(!head)
        cout << "There is no order" << endl;
}

void OrderList::deliverOrders()
{
    listOrders();
    if(num_of_orders == 0)
    {
        return;
    }

    // Learn the customer name of the order which will be delivered
    cout << endl << "Enter the owner name of the order you want to be delivered: ";
    string deliver_name;
    cin >> deliver_name;

    // Find the order node to be delivered
    Order *ptr = head;
    Order *before_ptr;
    while(ptr)
    {  
        if(ptr->getCustomer() == deliver_name)
            break;

        before_ptr = ptr;
        ptr = ptr->next;
    }

    // Get price of order
    float price = ptr->getPrice();

    // Print order again
    cout << "This order is going to be delivered: " << endl;
    ptr->printOrder();
    cout << "Total price: " << price << endl;

    // Ask for pomotion code
    string promotion_code;
    char does_have_code;
    cout << "Do you have a promotion code? (y/n): ";
    cin >> does_have_code;

    if(does_have_code == 'y') {
        cin.ignore();
        cout << "Enter the promotion code." << endl;
        getline(cin, promotion_code);
        if(promotion_code == "I am a student")
            price = price * 0.9;
        else
            cout << "Sorry but this code is invalid" << endl;
    }
    else if(does_have_code == 'n') {
    }
    else {
        cout << "Invalid choice" << endl;
    }

    cout << "Final price: " << price << endl;

    // Arrange nodes in the list
    if(num_of_orders == 1) {
        head = NULL;
    }
    else if(ptr == head) {
        head = ptr->next;
    }
    else {
        before_ptr->next = ptr->next;
    }

    num_of_orders--;
    delete ptr;

    cout << "Order is delivered successfully" << endl;
    return;
}