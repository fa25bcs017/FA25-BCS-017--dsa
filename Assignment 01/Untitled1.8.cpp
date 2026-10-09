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
        Node* temp = current;

        while (temp->next != NULL) {

            if (temp->next->data == current->data) {
                Node* duplicate = temp->next;
                temp->next = duplicate->next;
                delete duplicate;
            }
            else {
                temp = temp->next;
            }
        }

        current = current->next;
    }
}

int main() {

    Node* head = NULL;

    insert(head, 5);
    insert(head, 10);
    insert(head, 5);
    insert(head, 15);
    insert(head, 10);
    insert(head, 20);

    cout << "Original Linked List: ";
    display(head);

    removeDuplicates(head);

    cout << "\nAfter Removing Duplicates: ";
    display(head);

    return 0;
}
