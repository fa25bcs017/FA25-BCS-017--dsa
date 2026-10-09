#include <iostream>
#include <string>
using namespace std;

// Node for Dynamic Stack
struct Node
{
    char data;
    Node* next;
};

// Dynamic Stack class
class Stack
{
private:
    Node* top;

public:
    // Constructor
    Stack()
    {
        top = NULL;
    }

    // Push element into stack
    void push(char value)
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    // Remove and return top element
    char pop()
    {
        if (top == NULL)
            return '\0';

        Node* temp = top;
        char value = top->data;
        top = top->next;
        delete temp;

        return value;
    }

    // Return top element
    char peek()
    {
        if (top == NULL)
            return '\0';

        return top->data;
    }

    // Check whether stack is empty
    bool isEmpty()
    {
        return top == NULL;
    }

    // Destructor
    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

// Check whether character is an operand
bool isOperand(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9'));
}

// Return precedence of operator
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;

    if (op == '*' || op == '/')
        return 2;

    if (op == '^')
        return 3;

    return 0;
}

// Infix to Postfix conversion
string infixToPostfix(string infix)
{
    Stack s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        // Ignore spaces
        if (ch == ' ')
            continue;

        // If operand, add directly to postfix
        if (isOperand(ch))
        {
            postfix = postfix + ch;
        }

        // If opening bracket, push into stack
        else if (ch == '(')
        {
            s.push(ch);
        }

        // If closing bracket
        else if (ch == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix = postfix + s.pop();
            }

            // Remove '('
            if (!s.isEmpty())
                s.pop();
        }

        // If operator
        else
        {
            while (!s.isEmpty() &&
                   s.peek() != '(' &&
                   precedence(s.peek()) >= precedence(ch))
            {
                postfix = postfix + s.pop();
            }

            s.push(ch);
        }
    }

    // Pop remaining operators
    while (!s.isEmpty())
    {
        postfix = postfix + s.pop();
    }

    return postfix;
}

int main()
{
    string infix;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    cout << "Postfix Expression: "
         << infixToPostfix(infix) << endl;

    return 0;
}
