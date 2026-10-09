#include <iostream>
#include <string>
using namespace std;
struct Node {
 string taskName;
 int priority;
 string status;
 Node* next;
};
Node* head = NULL;
// Add a task at the end
void addTask(string name, int priority, string status) {
 Node* newNode = new Node;
 newNode->taskName = name;
 newNode->priority = priority;
 newNode->status = status;
 if (head == NULL) {
 head = newNode;
 newNode->next = head;
 return;
 }
 Node* temp = head;
 while (temp->next != head) {
 temp = temp->next;
 }
 temp->next = newNode;
 newNode->next = head;
}
// Remove a task by name
void removeTask(string name) {
 if (head == NULL) {
 cout << "Task list is empty!" << endl;
 return;
 }
 Node* current = head;
 Node* previous = NULL;
 do {
 if (current->taskName == name) {
 // Only one node
 if (current == head && current->next == head) {
 delete current;
 head = NULL;
 cout << "Task removed successfully." << endl;
 return;
 }
 // Removing head
 if (current == head) {
 Node* last = head;
 while (last->next != head) {
 last = last->next;
 }
 head = head->next;
 last->next = head;
 delete current;
 cout << "Task removed successfully." << endl;
 return;
 }
 // Removing any other node
 previous->next = current->next;
 delete current;
 cout << "Task removed successfully." << endl;
 return;
 }
 previous = current;
 current = current->next;
 } while (current != head);
 cout << "Task not found!" << endl;
}
// Get next pending task
void getNextTask() {
 if (head == NULL) {
 cout << "No tasks available!" << endl;
 return;
 }
 Node* current = head;
 do {
 if (current->status == "pending") {
 cout << "\nNext Task:" << endl;
 cout << "Name: " << current->taskName << endl;
 cout << "Priority: " << current->priority << endl;
 cout << "Status: " << current->status << endl;
 return;
 }
 current = current->next;
 } while (current != head);
 cout << "No pending task found!" << endl;
}
// Display all tasks
void displayTasks() {
 if (head == NULL) {
 cout << "No tasks available!" << endl;
 return;
 }
 Node* current = head;
 cout << "\nAll Tasks:" << endl;
 do {
 cout << "Task Name: " << current->taskName << endl;
 cout << "Priority: " << current->priority << endl;
 cout << "Status: " << current->status << endl;
 cout << "--------------------" << endl;
 current = current->next;
 } while (current != head);
}
// Update task status
void updateTaskStatus(string name, string newStatus) {
 if (head == NULL) {
 cout << "Task list is empty!" << endl;
 return;
 }
 Node* current = head;
 do {
 if (current->taskName == name) {
 current->status = newStatus;
 cout << "\nTask Status Updated!" << endl;
 cout << "Task: " << current->taskName << endl;
 cout << "New Status: " << current->status << endl;
 return;
 }
 current = current->next;
 } while (current != head);
 cout << "Task not found!" << endl;
}
int main() {
 // Add tasks
 addTask("Design Website", 1, "pending");
 addTask("Write Report", 2, "pending");
 addTask("Testing", 3, "in-progress");
 addTask("Deployment", 4, "completed");
 // Display all tasks
 displayTasks();
 // Get next pending task
 getNextTask();
 // Update task status
 updateTaskStatus("Design Website", "completed");
 // Get next pending task
 getNextTask();
 // Remove a task
 removeTask("Testing");
 // Display tasks again
 displayTasks();
 return 0;
}
