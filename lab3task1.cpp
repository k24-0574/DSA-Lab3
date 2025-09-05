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
	int count;
	linkedList(){
		head=tail=NULL;
		count=0;
	}
	
	void insertAtEnd(int data){
		Node* newnode = new Node(data);
		if(head==NULL){
			head=tail=newnode;
			return;
		}
		tail->next = newnode;
		tail=newnode;
		count++;	
	}
	
	void insertAtFront(int data){
		Node* newnode = new Node(data);
		if(head==NULL){
			head=tail=newnode;
			return;
		}
		newnode->next = head;
		head = newnode;
		count++;
	}
	void insertAtPos(int data, int pos){
		Node *temp = head;
		if(pos==0){
			insertAtFront(data); return;
		}
		for(int i=0;i<pos-1;i++){
			if(temp==NULL){
				cout<<"Insufficient number of nodes"<<endl;
				return;
			}
			temp = temp->next;
		}
		
		if(temp==tail){
			insertAtEnd(data);
			return;
		}
		
		Node* newnode = new Node(data);

		newnode->next = temp->next;
		temp->next = newnode;
		count++;
	}
	
	void deleteData(int data){
		Node*temp = head, *prev;
		
		while(temp!=NULL){
			if(temp->data == data){
				if(temp==head){
					head=head->next;
					delete temp;
					return;
				}
				prev->next = temp->next;
				delete temp;
				count--;
				return;	
			}
			prev=temp;
			temp=temp->next;
		}
		
		cout<<"data not found"<<endl;
	}
	
	void display(){
		Node *temp =head;
		if(temp==NULL) cout<<"Empty linked list"<<endl;
		while(temp!=NULL){
			cout<<temp->data;
			if(temp->next!=NULL) cout<<" -> ";
			temp=temp->next;
		}
		
		cout<<endl<<"Using For loop: ";
		temp =head;
		for(int i=0;i<=count;i++){
			cout<<temp->data;
			if(temp->next!=NULL) cout<<" -> ";
			temp=temp->next;
		}
		cout<<endl<<endl;
		
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
	//(3 1 2, 5, 8)
	int arr[5] = {3, 1, 2, 5, 8};
	linkedList L;
	cout<<"ARRAY: ";
	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
		L.insertAtEnd(arr[i]);
	}
	
	cout<<endl<<"LINKED LIST: ";
	L.display();
	
	//insert 9 at the end;
	L.insertAtEnd(9);
	L.insertAtPos(11, 3);
	L.insertAtFront(4);
	L.display();
	L.deleteData(1);
	L.deleteData(2);
	L.deleteData(5);
	L.display();
	
}
