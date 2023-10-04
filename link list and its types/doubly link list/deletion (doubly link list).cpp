#include<iostream>
using namespace std;


class Node {
	
	public:
	int data;
	Node* prev;
	Node* next;
	
	Node(int d){
		this -> data=d;
		this -> prev=NULL;
		this -> next=NULL;	
		
	}	
	
};
void print(Node* &head){
	Node* temp =head ;
	
	while(temp != NULL){
		cout << temp -> data<< " ";
		temp = temp -> next;
	}
	cout << endl;
	
}
void insertathead(Node* &head, int d){
	
	Node* temp = new Node(d);
	temp -> next = head;
	head -> prev = temp;
	head = temp;
}

void insertattail(Node* &tail, int d){
	Node* temp = new Node(d);
	tail -> next = temp;
	temp -> prev = tail;
	tail = temp;
}
void deleteNode(int position, Node* & head) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
            
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;

    }
}
int main(){
	Node* node1 =new Node(10);
	Node* head = node1;
	Node* tail = node1;
	
	print(head);
	
	insertathead(head,11);
	print(head);
	
	insertathead(head,12);
	print(head);
	
	insertattail(tail ,25);
	print (head);
	
	insertattail(tail ,30);
	print (head);
	
	deleteNode(5, head);
    print(head);
	return 0;
}
