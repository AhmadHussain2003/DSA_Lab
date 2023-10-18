#include <iostream>
#include <string>
using namespace std;

class CustomStack {
private:
    static const int MAX_SIZE = 100;
    char stackArray[MAX_SIZE];
    int top;

public:
    CustomStack() {
        top = -1;
    }

    void push(char val) {
        cout << "\npush\n";
        if (top == MAX_SIZE - 1) {
            cout << "Stack is full\n";
        } else {
            top++;
            stackArray[top] = val;
        }
        display();
    }

    void pop() {
        cout << "\npop\n";
        if (top == -1) {
            cout << "Stack is empty!!!\n";
        } else {
            top--;
        }
        display();
    }

    bool isBalancedParentheses(string inputString) {
        for (int i = 0; i < inputString.length(); i++) {
            if (inputString[i] == '(' || inputString[i] == '{' || inputString[i] == '[') {
                char inputChar = inputString[i];
                push(inputChar);
            } else {
                char check = inputString[i];
                if ((check == ')' && stackArray[top] == '(') ||
                    (check == '}' && stackArray[top] == '{') ||
                    (check == ']' && stackArray[top] == '[')) {
                    pop();
                } else {
                    cout << "Not valid!!!\n";
                }
            }
        }
        if (top == -1) {
            return true;
        }
        return false;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty\n";
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++) {
                cout << stackArray[i];
            }
            cout << endl;
        }
    }
};

int main() {
    CustomStack myCustomStack;
    string inputStr;
    cout << "Enter a string: ";
    getline(cin, inputStr);
    if (myCustomStack.isBalancedParentheses(inputStr)) {
        cout << "Parentheses are balanced.\n";
    } else {
        cout << "Parentheses are not balanced.\n";
    }

    return 0;
}

