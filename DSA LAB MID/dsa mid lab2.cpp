#include <iostream>
using namespace std;
int stack[50], s=50, top=-1;
void push(int value) {
   if(top>s-1)
   cout<<"Stack is full "<<endl;
   else {
      top++;
      stack[top]=value;
   }
}
void pop() {
   if(top<=-1)
   cout<<"Stack is empty "<<endl;
   else {
      cout<<"The  element that  is poped from stack  "<< stack[top] <<endl;
      top--;
   }
}
void display() {
   if(top>=0) {
      cout<<"Elements in stack  are : ";
      for(int i=top; i>=0; i--)
      cout<<stack[i]<<" ";
      cout<<endl;
   } else
   cout<<"Stack is empty";
}
int main(){
	
   int choice, value;
   cout<<"1) Push in stack"<<endl;
   cout<<"2) Pop from stack"<<endl;
   cout<<"3) Display stack"<<endl;
   cout<<"4) To Exit the program"<<endl;
   
      do {
      cout<<"Enter your choice to perform above operations: "<<endl;
      cin>>choice ;
      switch(choice ) {
         case 1: {
            cout<<"Enter value to be pushed in stack :"<<endl;
            cin>>value;
            push(value);
            break;
         }
         case 2: {
            pop();
            break;
         }
         case 3: {
            display();
            break;
         }
         case 4: {
            cout<<"program is terminated successfully"<<endl;
            break;
         }
         default: {
            cout<<"you have entered an Invalid Choice"<<endl;
         }
      }
   }while(choice!=4);
   return 0;
}
