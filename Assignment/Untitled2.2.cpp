#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* prev;
    Node* next;
};

void insert(Node*& head, string song) {
    Node* newNode = new Node;
    newNode->song = song;
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

void displayForward(Node* head) {
    cout << "Playlist Forward: ";

    while (head != NULL) {
        cout << head->song;

        if (head->next != NULL)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

void displayBackward(Node* head) {
    if (head == NULL)
        return;

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    cout << "Playlist Backward: ";

    while (temp != NULL) {
        cout << temp->song;

        if (temp->prev != NULL)
            cout << " -> ";

        temp = temp->prev;
    }

    cout << endl;
}

int main() {

    Node* head = NULL;

    insert(head, "Song 1");
    insert(head, "Song 2");
    insert(head, "Song 3");
    insert(head, "Song 4");

    displayForward(head);
    displayBackward(head);

    return 0;
}
