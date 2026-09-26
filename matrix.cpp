#include <iostream>
using namespace std;

class Array
{
private:
    int* arr;
    int capacity; // تعداد خونه های رزرو شده
    int size; // تعداد عنصر های داخل آرایه

public:
    Array(int cap)
    {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    ~Array()
    {
        delete[] arr;
    }

    void Insert(int value, int index)
    {
        if (size == capacity) {
            cout << "Array is full\n";
            return;
        }

        if (index < 0 || index > size)
        {
            cout << "Invalid index\n";
            return;
        }

        // شیفت عناصر به راست
        for (int i = size; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[index] = value;
        size++;
    }

    int Delete(int index)
    {
        if (size == 0)
        {
            cout << "Array is empty\n";
            return -1;
        }

        if (index < 0 || index >= size)
        {
            cout << "Invalid index\n";
            return -1;
        }

        int value = arr[index];

        // شیفت عناصر به چپ
        for (int i = index; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        size--;

        return value;
    }

    int Find(int value)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
                return i;
        }

        return -1;
    }
};


int main()
{
    
}