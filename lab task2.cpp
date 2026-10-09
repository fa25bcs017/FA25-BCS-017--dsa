
//LAB TASK:02
//Q 01:
#include <iostream>
using namespace std;
int main() {
 int var = 10;
 // declare pointer and store address of var
 int* ptr = &var;
 // print value and address
 cout << "Value of var: " << var << endl;
 cout << "Address of var: " << &var << endl;
 cout << "Value stored in pointer ptr: " << ptr << endl;
 cout << "Value pointed to by ptr: " << *ptr << endl;
 return 0;
}
/*
//Q NO 2:
#include <iostream>
using namespace std;
int main() {
 int var = 10;

 // Store the address of
 // var variable
 int* ptr = &var;

 // Access value using (*)
 // operator
 cout << *ptr;
 return 0;
}

//Q no 3:
#include <iostream>
using namespace std;
int main() {
 int var = 10;

 // Store the address of
 // var variable
 int* ptr = &var;

 // Access the address value
 cout << ptr;
 return 0;
}

//Q NO 04:
#include <iostream>
using namespace std;
int main() {
 int a = 10;
 int b = 99;
 int *ptr = &a;
 cout << *ptr << endl;

 // Changing the address stored
 ptr = &b;
 cout << *ptr;

 return 0;
}

//Q NO 05:
#include <iostream>
using namespace std;
int main() {
 int *ptr1;
 char *ptr2;

 // Finding size using sizeof()
 cout << sizeof(ptr1) << endl;
 cout << sizeof(ptr2);

 return 0;
}

//Q NO 06:
#include <iostream>
using namespace std;
int main() {
 // Wild pointer
 int *ptr;
 return 0;
}
//
Q NO 07:
#include <iostream>
using namespace std;
int main() {

 // nullptr pointer
 int *ptr = nullptr;

 return 0;
}

//Q NO 08:
#include <iostream> using namespace std;
int main() { int x = 42;// void pointer holding address of an intvoid* ptr = &x;
// Error: cannot dereference void pointer
// cout << *ptr;
// Typecast before dereferencing
cout << "Value pointed by void pointer: " << *(static_cast<int*>(ptr)) << endl;
return 0;
}

//Q NO 09:
#include <iostream>
using namespace std;
int main()
{ int var = 10;
// Store the address of
// var variable int* ptr1 = &var;int** ptr2 = &ptr1;
// Access values using (*)// operator
cout << *ptr1 << endl;cout << **ptr2;return 0;}
 //REFRENCES
// task 1
#include <iostream>
using namespace std;
int main() {
 int x = 10;
 // ref is a reference to x.
 int& ref = x;
 // printing value using ref
 cout << ref << endl;

 // Changing the value and printing again
 ref = 22;
 cout << ref;
 return 0;
}
//task2;
#include <iostream>
using namespace std;
void modifyValue(int &x) {

 // Modifies the original variable
 x = 20;
}
int main() {
 int a = 10;
 // Pass a by reference
 modifyValue(a);
 cout << a;
 return 0;
}

//task 03:
#include <iostream>
using namespace std;
int& getMax(int &a, int &b) {

 // Return the larger of the two numbers
 return (a > b) ? a : b;
}
int main() {
 int x = 10, y = 20;
 int &maxVal = getMax(x, y);

 // Modify the value of the larger number
 maxVal = 30;
 cout << "x = " << x << ", y = " << y;
 return 0;
}

//task 04:
#include <iostream>
#include <vector>
using namespace std;
int main() {
 vector<int> vect{ 10, 20, 30, 40 };
 // We can modify elements if we
 // use reference
 for (int& x : vect) {
 x = x + 5;
 }
 // Printing elements
 for (int x : vect) {
 cout << x << " ";
 }
 return 0;
}*/
