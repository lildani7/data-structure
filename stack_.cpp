#include <iostream>
using namespace std;

class Stack 
{
    static const int MAX = 100;
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int x) {
        if (isFull()) 
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (isEmpty()) 
        {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int peek() {
        if (isEmpty()) 
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
};


int main()
{

}