#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
};

void insert(Node*& head, string value) {
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

void display(Node* head) {
    while (head != NULL) {
        cout << head->data;

        if (head->next != NULL) {
            cout << " -> ";
        }

        head = head->next;
    }

    cout << endl;
}

void swapNodes(Node* head) {
    Node* left = head;
    Node* right = head;

    // Move right to the last node
    while (right->next != NULL) {
        right = right->next;
    }

    // Swap first with last, second with second-last, etc.
    while (left != right && left->prev != right) {

        string temp = left->data;
        left->data = right->data;
        right->data = temp;

        left = left->next;
        right = right->prev;
    }
}

int main() {

    Node* head = NULL;

    insert(head, "Alice");
    insert(head, "Bob");
    insert(head, "Charlie");
    insert(head, "Dana");
    insert(head, "Eva");
    insert(head, "Frank");

    cout << "Original List: ";
    display(head);

    swapNodes(head);

    cout << "After Swapping: ";
    display(head);

    return 0;
}
