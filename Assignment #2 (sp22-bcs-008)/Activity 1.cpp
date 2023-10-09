#include<iostream>
using namespace std;
//creating the node
struct Node {
  int data;
  Node * next; //it is Node type pointer as it points the next node.
};
class Linklist {
  private: Node * head;
  public: Linklist() {
    head = NULL;
  }
  //insert at the end
  void insertAtEnd(int val) {
    Node * newNode = new Node;
    newNode -> data = val;
    newNode -> next = NULL;
    // check if the node linked list is empty or not
    if (head == NULL) {
      head = newNode;
    } else {
      Node * currentNode = head;
      while (currentNode -> next != NULL) {
        currentNode = currentNode -> next;
      }
      currentNode -> next = newNode;
    }
  }
  
  // Function to display the contents of the list
  void display() {
    cout<<"The linked list is:\n";
    Node * ptr = head;
    while (ptr != NULL) {
      cout << ptr -> data << " ";
      ptr = ptr -> next;
    }
    ptr = head;
    cout<<endl <<endl
        <<"     ***Head Address:*** "<<&head<<endl
        <<"--------------------------------------"<<endl
        <<"     head content: "<<head->next<<endl  
        <<"--------------------------------------"<<endl
        <<"     ***ptr address:*** " <<&ptr<<endl
        <<"--------------------------------------"<<endl
        <<"     ptr content: "<<ptr->next<<endl
        <<"--------------------------------------"<<endl
        <<"ptr -> data: " << ptr -> data <<endl
        <<"--------------------------------------"<<endl
        ;
    ptr = head->next;
// for printing the data
    while (ptr != NULL) {
        cout<<"ptr: " <<  ptr <<endl
            <<"ptr -> next: " << ptr -> next <<endl
            <<"ptr -> data: " << ptr -> data <<endl
            <<"--------------------------------------"<<endl
      ;
        ptr = ptr -> next;
        } 
        
    }
    

  
};
int main() {
  Linklist list;
  list.insertAtEnd(1);
  list.insertAtEnd(2);
  list.insertAtEnd(20);
  list.insertAtEnd(30);
  list.display();
  
}
