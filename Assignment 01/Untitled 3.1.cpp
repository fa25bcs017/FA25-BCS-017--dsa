#include <iostream>
using namespace std;

struct Node {
    int person;
    Node* next;
};

// Create circular linked list
Node* createCircle(int N) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 1; i <= N; i++) {

        Node* newNode = new Node;
        newNode->person = i;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            newNode->next = head;
        }
        else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    return head;
}

// Solve Josephus Problem
int josephus(int N, int M) {

    Node* head = createCircle(N);

    Node* current = head;
    Node* previous = NULL;

    // Continue until only one person remains
    while (current->next != current) {

        // Move M-1 times
        for (int i = 1; i < M; i++) {
            previous = current;
            current = current->next;
        }

        // Kill Mth person
        previous->next = current->next;

        delete current;

        current = previous->next;
    }

    int survivor = current->person;

    delete current;

    return survivor;
}

int main() {

    int N, M;

    cout << "Enter total number of persons (N): ";
    cin >> N;

    cout << "Enter number of persons to skip (M): ";
    cin >> M;

    if (N <= 0 || M <= 0) {
        cout << "Invalid input!" << endl;
        return 0;
    }

    int survivor = josephus(N, M);

    cout << "The surviving position is: " << survivor << endl;

    return 0;
}
