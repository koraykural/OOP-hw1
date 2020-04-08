#include <iostream>
#include <string>
#include "MyVector.h"

using namespace std;

MyVector<int> function()
{
    MyVector<int> newObj;;
    for (int i = 0; i < 5; i++)
    {
        newObj.push(i);
    }   
    return newObj;
}

int main()
{
    MyVector<int> arr = function();
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr.get(i);
    }
    
    return 0;
}