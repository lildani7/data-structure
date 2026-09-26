#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
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

}


int SizeOfList(Node*& head) {
    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    return count;
}

void InsertAtBegin(Node*& head, int data) {
    Node* newNode = new Node{data, head, nullptr};

    if (head != nullptr)
        head->prev = newNode;

    head = newNode;
}

void InsertAtEnd(Node*& head, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void InsertAtIndex(Node*& head, int data, int index) {
    if (index == 0) {
        InsertAtBegin(head, data);
        return;
    }

    Node* temp = head;
    for (int i = 0; temp != nullptr && i < index - 1; i++)
        temp = temp->next;

    if (temp == nullptr || temp->next == nullptr) {
        InsertAtEnd(head, data);
        return;
    }

    Node* newNode = new Node{data, temp->next, temp};
    temp->next->prev = newNode;
    temp->next = newNode;
}

void UpdateNode(Node*& head, int data, int index) {
    Node* temp = head;

    for (int i = 0; temp != nullptr && i < index; i++)
        temp = temp->next;

    if (temp != nullptr)
        temp->data = data;
}

int RemoveNodeAtBegin(Node*& head) {
    if (head == nullptr)
        return -1;

    int value = head->data;
    Node* temp = head;

    head = head->next;

    if (head != nullptr)
        head->prev = nullptr;

    delete temp;
    return value;
}

int RemoveNodeAtEnd(Node*& head) {
    if (head == nullptr)
        return -1;

    Node* temp = head;

    if (temp->next == nullptr) {
        int value = temp->data;
        delete temp;
        head = nullptr;
        return value;
    }

    while (temp->next != nullptr)
        temp = temp->next;

    int value = temp->data;
    temp->prev->next = nullptr;
    delete temp;

    return value;
}

int RemoveNodeAtIndex(Node*& head, int index) {
    if (index == 0)
        return RemoveNodeAtBegin(head);

    Node* temp = head;

    for (int i = 0; temp != nullptr && i < index; i++)
        temp = temp->next;

    if (temp == nullptr)
        return -1;

    if (temp->next == nullptr)
        return RemoveNodeAtEnd(head);

    int value = temp->data;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
    return value;
}

void Concatenate(Node*& head1, Node*& head2) {
    if (head2 == nullptr)
        return;

    if (head1 == nullptr) {
        head1 = head2;
        return;
    }

    Node* temp = head1;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = head2;
    head2->prev = temp;
}

void Invert(Node*& head) {
    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != nullptr)
        head = temp->prev;
}
