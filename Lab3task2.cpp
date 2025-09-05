#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
	Node(int d){
		data=d;
		next =NULL;
	}
};

class linkedList{
	public:
	Node *head, *tail;
	
	linkedList(){
		head=tail=NULL;
	}
	
	void insertAtEnd(int data){
		Node* newnode = new Node(data);
		if(head==NULL){
			head=tail=newnode;
			return;
		}
		tail->next = newnode;
		tail=newnode;	
	}
	
	void insertAtFront(int data){
		Node* newnode = new Node(data);
		if(head==NULL){
			head=tail=newnode;
			return;
		}
		newnode->next = head;
		head = newnode;
	}
	void insertAtPos(int data, int pos){
		Node *temp = head;
		if(pos==0){
			insertAtFront(data); return;
		}
		for(int i=0;i<pos-1;i++){
			temp = temp->next;
			if(temp==NULL){
				cout<<"Insufficient number of nodes"<<endl;
				return;
			}
		}
		
		if(temp==tail){
			insertAtEnd(data);
			return;
		}
		
		Node* newnode = new Node(data);

		newnode->next = temp->next;
		temp->next = newnode;
	}
	
	void display(){
		Node *temp =head;
		while(temp!=NULL){
			cout<<temp->data;
			if(temp->next!=NULL) cout<<" -> ";
			temp=temp->next;
		}
		cout<<endl;
		
	}
	
	void shift(int s){
		Node* newHead=head;
		for(int i=0;i<s;i++){
			newHead=newHead->next;
		}
		Node *temp=tail; 
		Node*temp2=head;
		
		for(int i=0;i<s;i++){
			temp->next=temp2;
			temp=temp2;
			temp2=temp2->next;
		}
		tail=temp;
		tail->next=NULL;
		head=newHead;
		
	}
	
	~linkedList(){
		Node* temp1=head, *temp2;
		while(temp1!=NULL){
			temp2=temp1->next;
			delete temp1;
			temp1=temp2;
		}
	}
	
};

int main(){
	/*
	Example: 
	given list: 5, 3 1 8 6 4 2
	Enter the number: 2
	After rotation: 1 8 6 4 2 5 3
	*/
	linkedList L;
	L.insertAtEnd(5);
	L.insertAtEnd(3);
	L.insertAtEnd(1);
	L.insertAtEnd(8);
	L.insertAtEnd(6);
	L.insertAtEnd(4);
	L.insertAtEnd(2);
	int num;
	cout<<"Given list: ";
	L.display();
	cout<<"Enter the number: ";cin>>num;
	L.shift(num);
	cout<<"After rotation: ";
	L.display();
	
}
