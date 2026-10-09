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

Node* reverseList(Node* head) {
    Node* previous = NULL;
    Node* current = head;

    while (current != NULL) {
        Node* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    return previous;
}

void reverseHalves(Node*& head) {
    Node* slow = head;
    Node* fast = head;
    Node* previous = NULL;

    while (fast != NULL && fast->next != NULL) {
        previous = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Separate the two halves
    previous->next = NULL;

    // Reverse first half
    Node* firstHalf = reverseList(head);

    // Reverse second half
    Node* secondHalf = reverseList(slow);

    // Join both halves
    Node* temp = firstHalf;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = secondHalf;

    head = firstHalf;
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL";
}

int main() {

    Node* head = NULL;

    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);
    insert(head, 8);

    cout << "Original List: ";
    display(head);

    reverseHalves(head);

    cout << "\nReversed Halves: ";
    display(head);

    return 0;
}
