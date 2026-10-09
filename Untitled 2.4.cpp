#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Insert node at end
void insert(Node*& head, int value) {
    Node* newNode = new Node;

    newNode->data = value;
    newNode->prev = NULL;
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
    newNode->prev = temp;
}

// Display linked list
void display(Node* head) {
    while (head != NULL) {
        cout << head->data;

        if (head->next != NULL)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

// Swap seats alternately from both ends
void alternateSwap(Node* head) {

    if (head == NULL || head->next == NULL)
        return;

    // Find last node
    Node* tail = head;

    while (tail->next != NULL) {
        tail = tail->next;
    }

    // First and last seats remain fixed
    Node* left = head->next;
    Node* right = tail->prev;

    // Alternately swap from both ends
    while (left != NULL && right != NULL && left != right) {

        // Avoid crossing
        if (left->next == right || right->next == left)
            break;

        // Swap seat values
        int temp = left->data;
        left->data = right->data;
        right->data = temp;

        // Move two positions toward center
        if (left->next != NULL)
            left = left->next->next;
        else
            break;

        if (right->prev != NULL)
            right = right->prev->prev;
        else
            break;
    }
}

int main() {

    Node* head = NULL;

    // Seats: 1 2 3 4 5 6 7 8 9
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);
    insert(head, 8);
    insert(head, 9);

    cout << "Original Seating: ";
    display(head);

    alternateSwap(head);

    cout << "After Swapping: ";
    display(head);

    return 0;
}
