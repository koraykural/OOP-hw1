#include <iostream>

using namespace std;

template <class T> class MyVector
{
private:
    T *arr;
    int current_size;
    int capacity;
public:
    MyVector(/* args */);
    //MyVector(const MyVector &old);
    ~MyVector();
    void push(T data);
    T get(int index);
    int size();
};

template <class T> MyVector<T>::MyVector()
{
    capacity = 1;
    current_size = 0;
    arr = new T[1];
}

// template <class T> MyVector<T>::MyVector(const MyVector &old)
// {
//     current_size = old.current_size;
//     capacity = old.capacity;

//     // Copy old array
//     delete [] arr;
//     arr = new T[capacity];
//     for (int i = 0; i < old.current_size; i++)
//     {
//         arr[i] = old.arr[i];
//     }
//     cout << "Copy constructor" << endl;
// }

template <class T> MyVector<T>::~MyVector()
{
    delete [] arr;
}

template <class T> void MyVector<T>::push(T data)
{
    if(current_size == capacity)
    {
        // Double the capacity
        capacity *= 2; 

        // Create temporary array with new capacity
        T *temp = new T[capacity];

        // Copy old items to temporary array
        for (int i = 0; i < (capacity / 2); i++) { 
            temp[i] = arr[i]; 
        }

        // Delete old items
        delete [] arr;

        // Copy back to original array
        arr = temp;        
    }

    // Insert the new item
    arr[current_size] = data;
    current_size++;
}

template <class T> T MyVector<T>::get(int index)
{
    return arr[index];
}

template <class T> int MyVector<T>::size()
{
    return current_size;
}