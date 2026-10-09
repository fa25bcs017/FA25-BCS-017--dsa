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

void removeDuplicates(Node* head) {
    Node* current = head;

    while (current != NULL) {
        Node* previous = current;
        Node* temp = current->next;

        while (temp != NULL) {

            if (temp->data == current->data) {
                previous->next = temp->next;
                delete temp;
                temp = previous->next;
            }
            else {
                previous = temp;
                temp = temp->next;
            }
        }

        current = current->next;
    }
}

int main() {

    Node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 10);
    insert(head, 30);
    insert(head, 20);
    insert(head, 40);

    cout << "Original Linked List: ";
    display(head);

    removeDuplicates(head);

    cout << "\nAfter Removing Duplicates: ";
    display(head);

    return 0;
}
