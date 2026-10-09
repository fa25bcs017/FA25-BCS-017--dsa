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

void separateEvenOdd(Node* head) {
    Node* evenHead = NULL;
    Node* evenTail = NULL;

    Node* oddHead = NULL;
    Node* oddTail = NULL;

    while (head != NULL) {
        Node* newNode = new Node;
        newNode->data = head->data;
        newNode->next = NULL;

        if (head->data % 2 == 0) {
            if (evenHead == NULL) {
                evenHead = newNode;
                evenTail = newNode;
            }
            else {
                evenTail->next = newNode;
                evenTail = newNode;
            }
        }
        else {
            if (oddHead == NULL) {
                oddHead = newNode;
                oddTail = newNode;
            }
            else {
                oddTail->next = newNode;
                oddTail = newNode;
            }
        }

        head = head->next;
    }

    cout << "Even List: ";
    display(evenHead);

    cout << "\nOdd List: ";
    display(oddHead);
}

int main() {

    Node* head = NULL;

    insert(head, 10);
    insert(head, 15);
    insert(head, 20);
    insert(head, 25);
    insert(head, 30);
    insert(head, 35);

    cout << "Original Linked List: ";
    display(head);

    cout << "\n\n";

    separateEvenOdd(head);

    return 0;
}
