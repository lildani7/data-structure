#include <iostream>
using namespace std;

struct Node
{
    int data; 
    Node* next;
};

int SizeOfList(Node*& head);
void InsertAtBegin(Node*& head, int data);
void InsertAtEnd(Node*& head, int data);
void InsertAtIndex(Node*& head, int data, int index);
void UpdateNode(Node*& head, int data, int index);
int RemoveNodeAtBegin(Node*& head);
int RemoveNodeAtEnd(Node*& head);
int RemoveNodeAtIndex(Node*& head, int index);
void Concatenate(Node*& head1, Node*& head2);
void Invert(Node*& head);


int main()
{
    Node* n1 = new Node{0, nullptr};
    Node* Head = n1;
}



void insertAtIndex(Node*& head, int index, int value)
{
    Node* new_node = new Node{value, nullptr};

    if (index == 0)
    {
        new_node->next = head;
        head = new_node;
        return;
    }

    Node* temp = head;

    for (int i = 0; i < index - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Index out of range\n";
        delete new_node;
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

void insert_at_beginning(Node*& head, int value)
{
    Node* new_node = new Node{value, head};
    head = new_node;
}

void insert_at_end(Node*& head, int value)
{
    Node* new_node = new Node{value, nullptr};

    if(head == nullptr)
    {
        head = new_node;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = new_node;
}

void update_node(Node* head, int data, int index)
{
    Node* temp = head;

    for(int i=0; temp != nullptr && i < index; i++)
        temp = temp->next;

    if (temp == nullptr)
    {
        cout << "Index out of range\n";
        return;
    }

    temp->data = data;
}

int remove_node_at_index(Node*& head, int index)
{
    if (head == nullptr)
    {
        cout << "List is empty\n";
        return -1;
    }

    Node* temp = head;

    if (index == 0)
    {
        int value = head->data;
        head = head->next;
        delete temp;
        return value;
    }

    Node* prev = nullptr;
    int i = 0;
    while (temp != nullptr && i < index)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (temp == nullptr)
    {
        cout << "Index out of range\n";
        return -1;
    }

    prev->next = temp->next;
    int value = temp->data;
    delete temp;
    return value;
}

int remove_node_at_begin(Node*& head)
{
    if (head == nullptr)
    {
        cout << "List is empty\n";
        return -1;
    }

    Node* temp = head;
    int value = temp->data;
    head = head->next;
    delete temp;
    return value;
}

int remove_node_at_end(Node*& head)
{
    if (head == nullptr)
    {
        cout << "List is empty\n";
        return -1;
    }

    if (head->next == nullptr)
    {
        int value = head->data;
        delete head;
        head = nullptr;
        return value;
    }

    Node* temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    int value = temp->next->data;
    delete temp->next;
    temp->next = nullptr;

    return value;
}

int size_of_list(Node*& head) {
    int size = 0;
    Node* temp = head;
    while (temp != nullptr)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

void Concatenate(Node*& head1, Node* head2)
{
    if (head1 == nullptr)
    {
        head1 = head2;
        return;
    }

    Node* temp = head1;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = head2;
}

void invert(Node*& head)
{
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while(curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}