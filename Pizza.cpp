/*
    author: Bekir Koray Kural
    id:     150170053
    date:   08/04/2020
*/
#include "Pizza.h"
#include <iostream>
#include <string>

#define INGREDIENTS_SIZE 6

using namespace std;

string ingredients_of_chicken[INGREDIENTS_SIZE] =  {"mozarella", "chicken", "mushroom", "corn", "onion", "tomato"};
string ingredients_of_broccoli[INGREDIENTS_SIZE] = {"mozarella", "broccoli", "pepperoni", "corn", "onion", "olive"};
string ingredients_of_sausage[INGREDIENTS_SIZE] = {"mozarella", "sausage", "mushroom", "corn", "olive", "tomato"};

// creates pizza with medium size, normal crust and mozarella as the ingredient
Pizza::Pizza()
{
    name = "default";
    size = "medium";
    crust_type = "normal";
    ingredients[0] = "mozarella";
}

// creates pizza with given size, crust type and ingredients for chosen type.
Pizza::Pizza(string incoming_size, string incoming_crust_type, int pizza_type)
{
    size = incoming_size;
    crust_type = incoming_crust_type;

    switch (pizza_type)
    {
    case 1:
        name = "Chicken Pizza";
        for (int i = 0; i < INGREDIENTS_SIZE; i++)
        {
            ingredients[i] = ingredients_of_chicken[i];
        }
        break;

    case 2:
        name = "Broccoli Pizza";
        for (int i = 0; i < INGREDIENTS_SIZE; i++)
        {
            ingredients[i] = ingredients_of_broccoli[i];
        }
        break;

    case 3:
        name = "Sausage Pizza";
        for (int i = 0; i < INGREDIENTS_SIZE; i++)
        {
            ingredients[i] = ingredients_of_sausage[i];
        }
        break;

    default:
        // Error 
        break;
    }
}

// Lists the ingredients of copied object and asks the customer the
// ingredients that are wanted to be removed. The ingredients of the new object will update
Pizza::Pizza(Pizza& this_pizza)
{  
    name = this_pizza.name;
    size = this_pizza.size;
    crust_type = this_pizza.crust_type;
    for (int i = 0; i < INGREDIENTS_SIZE; i++)
    {
        ingredients[i] = this_pizza.ingredients[i];
    }
}

void Pizza::print_ingredient_list(int pizza)
{
    for (int i = 0; i < INGREDIENTS_SIZE; i++)
    {
        switch (pizza)
        {
        case 1:
            cout << i+1 << ": " << ingredients_of_chicken[i] << endl;
            break;
        case 2:
            cout << i+1 << ": " << ingredients_of_broccoli[i] << endl;
            break;
        case 3:
            cout << i+1 << ": " << ingredients_of_sausage[i] << endl;
            break;
        default:
            cout << "Oops! Sorry about that :(" << endl;
            break;
        }
    }
}

string Pizza::get_ingredient(int index)
{
    return ingredients[index];
}

void Pizza::remove_ingredient(int index)
{
    ingredients[index] = "";
}

void Pizza::printPizza()
{
    cout << "Pizza: " << name << " (";
    for (int i = 0; i < INGREDIENTS_SIZE; i++)
    {
        if(ingredients[i] != "")
            cout << ingredients[i] << ", ";
    }
    cout << ")" << endl;
    cout << "Size: " << size << ", ";
    cout << "Crust: " << crust_type << endl;
    cout << endl;
}

int Pizza::getPrice()
{
    if(size == "small")
    {
        return 15;
    }
    if(size == "medium")
    {
        return 20;
    }
    if(size == "big")
    {
        return 25;
    }
}