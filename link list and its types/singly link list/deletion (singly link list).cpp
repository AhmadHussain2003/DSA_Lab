#include<iostream>
using namespace std;


class Node {
	
	public:
	int data;
	Node* next;
	
	Node(int data){
		this -> data=data;
		this -> next=NULL;	
	}	
	
};
void insertathead(Node* &head,int d){
	Node* temp=new Node(d);
	temp ->next =head;
	head=temp;
	
	
}

void insertattail(Node* &tail ,int d){
	Node* temp=new Node(d);
	tail ->next =temp;
	tail = tail ->next;
	
	
	
}


void print (Node* &head){
	Node* temp=head;
	
	while(temp != NULL ){
		cout << temp -> data <<" ";
		temp = temp ->next;
}
	cout<< endl;
}

void insertatposition(Node* &tail, Node* &head, int position ,int d){
	
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
	temp -> next= nodetoinsert;
}

void deletenode(int position,Node* &head){
	
	//deleting first or start node 
	if(position ==1){
		Node* temp= head;
		head= head->next;
		//memory free start node
		temp->next=NULL; 
		delete temp;
		
	}
	else
	{
		//deleting any middle or last node
		Node* curr=head;
		Node* prev=NULL;
		
		int cnt =1;
		while(cnt < position){
			prev =curr;
			curr =curr->next;
			cnt++;
			
		}
		prev->next=curr->next;
		curr->next=NULL;
		delete curr;
	}
}
int main (){
	
	Node* node1=new Node(10);

	
	Node* head= node1;
	Node* tail= node1;
	print(head);
	
	insertattail(tail, 12);
	print(head);
	
	insertattail(tail, 15);
	print(head);
	
	insertatposition(tail,head,3,22);
	print(head);
	
	deletenode(4,head);
	print(head);
}
