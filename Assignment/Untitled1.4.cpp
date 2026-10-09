#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool detectLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {

    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;
    Node* fourth = new Node;

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;

    // Creating a loop
    fourth->next = second;

    if (detectLoop(head)) {
        cout << "Loop Detected";
    }
    else {
        cout << "No Loop Found";
    }

    return 0;
}
