#include <string>
#define INGREDIENTS_SIZE 6

using namespace std;

class Pizza
{
private:
    string name;
    string size;
    string crust_type;
    string ingredients[INGREDIENTS_SIZE];
public:
    Pizza();
    Pizza(string size, string crust_type, int pizza_type);
    Pizza(Pizza&);
    void printPizza();
    string get_ingredient(int index);
    void print_ingredient_list(int pizza);
    void remove_ingredient(int index);
    int getPrice();
};