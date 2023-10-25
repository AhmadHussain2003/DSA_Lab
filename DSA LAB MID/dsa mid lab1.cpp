#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() : head(NULL) {}

    
    void insertEnd(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    
    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* nextNode = NULL;

        while (current != NULL) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head = prev;
    }

    
    bool isPalindrome() {
        if (head == NULL || head->next == NULL) {
            return true; 
        }

        Node* slow = head;
        Node* fast = head;
        Node* prevSlow = NULL;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prevSlow = slow;
            slow = slow->next;
        }

        
        prevSlow->next = NULL; 
        reverse(); 

        Node* firstHalf = head;
        Node* secondHalf = slow;

        while (firstHalf != NULL && secondHalf != NULL) {
            if (firstHalf->data != secondHalf->data) {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};

int main() {
    SinglyLinkedList list;
    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(3);
    list.insertEnd(3);
    list.insertEnd(2);
    list.insertEnd(1);

    if (list.isPalindrome()) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}

