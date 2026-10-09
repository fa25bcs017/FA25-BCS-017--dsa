#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL";
}

void swapPairs(Node*& head) {
    Node* current = head;

    while (current != NULL && current->next != NULL) {

        Node* first = current;
        Node* second = current->next;

        // Swap the links
        first->next = second->next;
        second->next = first;

        // If this is the first pair, update head
        if (current == head) {
            head = second;
        }

        // Move to the next pair
        current = first->next;
    }
}

int main() {

    Node* head = NULL;

    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);

    cout << "Original Linked List: ";
    display(head);

    swapPairs(head);

    cout << "\nAfter Swapping Pairs: ";
    display(head);

    return 0;
}
