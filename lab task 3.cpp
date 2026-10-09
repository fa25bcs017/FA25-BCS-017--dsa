// lab task 03
//task 1
// Write a function which reverses the order of a doubly linked list.

#include <iostream>
using namespace std;
struct Node {
 int data;
 Node* prev;
 Node* next;
};
void reverseList(Node*& head) {
 Node* current = head;
 Node* temp = NULL;
 while (current != NULL) {
 temp = current->prev;
 current->prev = current->next;
 current->next = temp;
 current = current->prev;
 }
 if (temp != NULL) {
 head = temp->prev;
 }
}
void display(Node* head) {
 while (head != NULL) {
 cout << head->data << " ";
 head = head->next;
 }
}
int main() {
 Node* head = new Node{10, NULL, NULL};
 Node* second = new Node{20, head, NULL};
 Node* third = new Node{30, second, NULL};
 head->next = second;
 second->next = third;
 cout << "Original List: ";
 display(head);
 reverseList(head);
 cout << "\nReversed List: ";
 display(head);
 return 0;
}
/*
// Task 2

#include using namespace std;
struct Node { int data; Node* next; };
void swapNodes(Node*& head, int x, int y) {
if (x == y)
 return;
Node *prevX = NULL, *currX = head;
Node *prevY = NULL, *currY = head;
while (currX != NULL && currX->data != x) {
 prevX = currX;
 currX = currX->next;
}
while (currY != NULL && currY->data != y) {
 prevY = currY;
 currY = currY->next;
}
if (currX == NULL || currY == NULL) {
 cout << "Both values must be present!";
 return;
}
if (prevX != NULL)
 prevX->next = currY;
else
 head = currY;
if (prevY != NULL)
 prevY->next = currX;
else
 head = currX;
Node* temp = currX->next;
currX->next = currY->next;
currY->next = temp;
}
void display(Node* head) { while (head != NULL) { cout << head->data << " "; head = head->next; } }
int main() { Node* head = new Node{10, NULL}; head->next = new Node{20, NULL}; head->next-
>next = new Node{30, NULL}; head->next->next->next = new Node{40, NULL};
cout << "Original List: ";
display(head);
int x, y;
cout << "\nEnter two values: ";
cin >> x >> y;
swapNodes(head, x, y);
cout << "After Swapping Nodes: ";
display(head);
return 0;
}

//Lab Task 3

#include using namespace std;
struct SNode { int data; SNode* next; };
struct DNode { int data; DNode* prev; DNode* next; };
DNode* convertToDoubly(SNode* head) {
DNode* newHead = NULL;
DNode* tail = NULL;
while (head != NULL) {
 DNode* newNode = new DNode;
 newNode->data = head->data;
 newNode->prev = tail;
 newNode->next = NULL;
 if (newHead == NULL) {
 newHead = newNode;
 tail = newNode;
 }
 else {
 tail->next = newNode;
 tail = newNode;
 }
 head = head->next;
}
return newHead;
}
void displayDoubly(DNode* head) { while (head != NULL) { cout << head->data << " "; head =
head->next; } }
int main() {
// Singly Linked List
SNode* head = new SNode{10, NULL};
head->next = new SNode{20, NULL};
head->next->next = new SNode{30, NULL};
cout << "Singly Linked List: ";
SNode* temp = head;
while (temp != NULL) {
 cout << temp->data << " ";
 temp = temp->next;
}
// Conversion
DNode* doublyHead = convertToDoubly(head);
cout << "\nDoubly Linked List: ";
displayDoubly(doublyHead);
return 0;
}*/
