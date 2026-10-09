
//Lab Task 4
//task 1

#include <iostream>
using namespace std;
struct Node {
 int data;
 Node* next;
};
void deleteEvenOdd(Node*& head, int choice) {
 Node* current = head;
 Node* prev = NULL;
 while (current != NULL) {
 if ((choice == 1 && current->data % 2 == 0) ||
 (choice == 2 && current->data % 2 != 0)) {
 Node* temp = current;
 if (prev == NULL)
 head = current->next;
 else
 prev->next = current->next;
 current = current->next;
 delete temp;
 }
 else {
 prev = current;
 current = current->next;
 }
 }
}
void display(Node* head) {
 while (head != NULL) {
 cout << head->data << " ";
 head = head->next;
 }
}
int main() {
 Node* head = new Node{10, NULL};
 head->next = new Node{15, NULL};
 head->next->next = new Node{20, NULL};
 head->next->next->next = new Node{25, NULL};
 head->next->next->next->next = new Node{30, NULL};
 cout << "Original List: ";
 display(head);
 int choice;
 cout << "\n1. Delete Even Values";
 cout << "\n2. Delete Odd Values";
 cout << "\nEnter choice: ";
 cin >> choice;
 deleteEvenOdd(head, choice);
 cout << "Updated List: ";
 display(head);
 return 0;
}/*
// Task 2

#include <iostream>
using namespace std;
struct Node {
 int data;
 Node* next;
};
int josephus(int n, int k) {
 Node* head = new Node{1, NULL};
 Node* tail = head;
 for (int i = 2; i <= n; i++) {
 tail->next = new Node{i, NULL};
 tail = tail->next;
 }
 tail->next = head;
 Node* current = head;
 Node* prev = tail;
 while (current->next != current) {
 for (int i = 1; i < k; i++) {
 prev = current;
 current = current->next;
 }
 prev->next = current->next;
 delete current;
 current = prev->next;
 }
 int winner = current->data;
 delete current;
 return winner;
}
int main() {
 int n, k;
 cout << "Enter number of people: ";
 cin >> n;
 cout << "Enter elimination number: ";
 cin >> k;
 cout << "Winner is: " << josephus(n, k);
 return 0;
}

// Task 3
Write a function that deletes all even positioned nodes from a linked list. Last node should also be deleted if its
position is even
CODE:
#include <iostream>
using namespace std;
// Node structure
struct Node {
 int data;
 Node* next;
};
// Function to delete even positioned nodes
void deleteEvenPosition(Node*& head) {
 Node* current = head;
 Node* prev = NULL;
 // Position starts from 1
 int position = 1;
 // Traverse linked list
 while (current != NULL) {
 // Check whether position is even
 if (position % 2 == 0) {
 // Store node to be deleted
 Node* temp = current;
 // Connect previous node to next node
 prev->next = current->next;
 // Move current to next node
 current = current->next;
 // Delete even positioned node
 delete temp;
 }
 else {
 // Keep odd positioned node
 prev = current;
 current = current->next;
 }
 // Move to next position
 position++;
 }
}
// Function to display linked list
void display(Node* head) {
 // Traverse and print all nodes
 while (head != NULL) {
 cout << head->data << " ";
 head = head->next;
 }
}
int main() {
 // Create linked list
 Node* head = new Node{10, NULL};
 head->next = new Node{20, NULL};
 head->next->next = new Node{30, NULL};
 head->next->next->next = new Node{40, NULL};
 head->next->next->next->next = new Node{50, NULL};
 head->next->next->next->next->next = new Node{60, NULL};
 cout << "Original List: ";
 display(head);
 // Call deletion function
 deleteEvenPosition(head);
 cout << "\nAfter Deletion: ";
 display(head);
 return 0;
}*/

