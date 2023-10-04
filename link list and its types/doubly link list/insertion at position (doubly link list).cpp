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

void insertatposition(Node* &tail,Node* &head,int position, int d){
		//insert at start
	if(position == 1){
		insertathead(head,d);
		return;
	}
	
	Node* temp = head;
	int cnt = 1;
	
	while(cnt < position-1){
		temp = temp->next;
		cnt++;
	}
	
		//insert at end
	if(temp ->next ==NULL){
		insertattail(tail,d);
		return;
	}
	
	//creating a node for d
	Node* nodetoinsert = new Node(d);
	
	nodetoinsert -> next = temp -> next;
	temp -> next ->prev = nodetoinsert;
	temp -> next=nodetoinsert;
	nodetoinsert->prev=temp;
}

int main(){
	Node* node1 =new Node(10);
	Node* head = node1;
	Node* tail = node1;
	
	print(head);
	
	insertathead(head,11);
	print(head);
	
	insertattail(tail ,25);
	print (head);
	
	insertatposition(tail,head,1,101);
	print (head);
	
	insertatposition(tail,head,2,100);
	print (head);
	
	insertatposition(tail,head,6,102);
	print (head);
	
	
	return 0;
}
