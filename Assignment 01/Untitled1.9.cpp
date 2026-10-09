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

void deleteValue(Node*& head, int value) {

    // Delete matching nodes from the beginning
    while (head != NULL && head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete matching nodes from middle and end
    Node* current = head;

    while (current != NULL && current->next != NULL) {

        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        else {
            current = current->next;
        }
    }
}

int main() {

    Node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 10);
    insert(head, 30);
    insert(head, 10);
    insert(head, 40);

    cout << "Original Linked List: ";
    display(head);

    int value = 10;

    deleteValue(head, value);

    cout << "\nAfter Deleting " << value << ": ";
    display(head);

    return 0;
}

