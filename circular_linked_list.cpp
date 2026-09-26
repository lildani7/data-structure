#include <iostream>
using namespace std;

struct Node {
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

}

int SizeOfList(Node*& head) {
    if (head == nullptr) return 0;

    int count = 1;
    Node* temp = head;

    while (temp->next != head) {
        count++;
        temp = temp->next;
    }

    return count;
}

void InsertAtBegin(Node*& head, int data) {
    Node* newNode = new Node{data, nullptr};

    if (head == nullptr) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void InsertAtEnd(Node*& head, int data) {
    Node* newNode = new Node{data, nullptr};

    if (head == nullptr) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

void InsertAtIndex(Node*& head, int data, int index) {
    if (index == 0) {
        InsertAtBegin(head, data);
        return;
    }

    int size = SizeOfList(head);
    if (index >= size) {
        InsertAtEnd(head, data);
        return;
    }

    Node* newNode = new Node{data, nullptr};
    Node* temp = head;

    for (int i = 0; i < index - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

void UpdateNode(Node*& head, int data, int index) {
    if (head == nullptr) return;

    Node* temp = head;

    for (int i = 0; i < index; i++)
        temp = temp->next;

    temp->data = data;
}

int RemoveNodeAtBegin(Node*& head) {
    if (head == nullptr) return -1;

    int value = head->data;

    if (head->next == head) {
        delete head;
        head = nullptr;
        return value;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    Node* toDelete = head;
    head = head->next;
    temp->next = head;

    delete toDelete;
    return value;
}

int RemoveNodeAtEnd(Node*& head) {
    if (head == nullptr) return -1;

    if (head->next == head) {
        int value = head->data;
        delete head;
        head = nullptr;
        return value;
    }

    Node* temp = head;
    while (temp->next->next != head)
        temp = temp->next;

    Node* toDelete = temp->next;
    int value = toDelete->data;

    temp->next = head;
    delete toDelete;

    return value;
}

int RemoveNodeAtIndex(Node*& head, int index) {
    if (index == 0)
        return RemoveNodeAtBegin(head);

    int size = SizeOfList(head);
    if (index >= size - 1)
        return RemoveNodeAtEnd(head);

    Node* temp = head;
    for (int i = 0; i < index - 1; i++)
        temp = temp->next;

    Node* toDelete = temp->next;
    int value = toDelete->data;

    temp->next = toDelete->next;
    delete toDelete;

    return value;
}

void Concatenate(Node*& head1, Node*& head2) {
    if (head2 == nullptr) return;

    if (head1 == nullptr) {
        head1 = head2;
        return;
    }

    Node* tail1 = head1;
    while (tail1->next != head1)
        tail1 = tail1->next;

    Node* tail2 = head2;
    while (tail2->next != head2)
        tail2 = tail2->next;

    tail1->next = head2;
    tail2->next = head1;
}

void Invert(Node*& head) {
    if (head == nullptr || head->next == head)
        return;

    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode;
    Node* tail = head;

    do {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    } while (current != head);

    head->next = prev;
    head = prev;
}
