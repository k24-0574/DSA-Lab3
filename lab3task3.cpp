#include <iostream>
#include <string>
using namespace std;

class Node{
	public:
	string name;
	Node *next;
	Node(string n){
		name=n;
		next =NULL;
	}
};

class PassengerlinkedList{
	public:
	Node *head, *tail;

	PassengerlinkedList(){
		head=tail=NULL;
	}

	void insert(string name) {
		Node* newnode = new Node(name);
		if(head==NULL){
			head=tail=newnode;
			return;
		}
		if (name<head->name) {
			newnode->next= head;
			head = newnode;
			return;
		}

		Node* temp = head;
		Node* previous = NULL;
		while (temp!=NULL && temp->name< name) {
			previous = temp;
			temp = temp->next;
		}
		newnode->next = temp;
		previous->next = newnode;

		if (temp == NULL) 
			tail = newnode;
	}

	void deleteData(string name){
		Node*temp = head, *prev=NULL;
		
		while(temp!=NULL){
			if(temp->name == name){
				if(temp==head){
					head=head->next;
					delete temp;
					return;
				}
				prev->next = temp->next;
				delete temp;
				return;	
			}
			prev=temp;
			temp=temp->next;
		}
		
		cout<<"Passenger not found"<<endl;
	}

	bool search(string name){
		Node* temp=head;
		while(temp!=NULL){
			if (temp->name == name) return 1;
			temp=temp->next;
		}
		return 0;
	}
	
	void display(){
		Node *temp =head;
		if(temp==NULL) cout<<"No passengers"<<endl;
		while(temp!=NULL){
			cout<<temp->name;
			if(temp->next!=NULL) cout<<", ";
			temp=temp->next;
		}
		cout<<endl;
	}
	
	~PassengerlinkedList(){
		Node* temp1=head, *temp2;
		while(temp1!=NULL){
			temp2=temp1->next;
			delete temp1;
			temp1=temp2;
		}
	}
};

class FlightNode{
	public:
	PassengerlinkedList* passengers;
	FlightNode *next;
	FlightNode(PassengerlinkedList *p){
		passengers=p;
		next = NULL;
	}
};

class FlightLinkedList{
	public:
	FlightNode *head, *tail;
	FlightLinkedList(){
		head=tail=NULL;
	}

	void insertAtEnd(PassengerlinkedList *p){
		FlightNode* newnode = new FlightNode(p);
		if(head==NULL){
			head=tail=newnode;
			return;
		}
		tail->next = newnode;
		tail=newnode;
	}

	void display(){
		FlightNode *temp =head;
		if(temp==NULL) cout<<"No Flights"<<endl;
		int i=1;
		while(temp!=NULL){
			cout<<"Flight "<<i++<<" Passengers: ";
			temp->passengers->display();
			temp=temp->next;
		} 
		cout<<endl;
	}
};

int main(){
	int choice;
	string name;
	PassengerlinkedList *passengers = new PassengerlinkedList;
	do{
		cout<<"1. Reserve a Ticket\n2. Cancel reservation\n3. check whether a ticket is reserved for particular person\n4. display the passengers\n0. Exit"<<endl;
		cout<<"Enter choice: ";cin>>choice;
		switch(choice){
			case 0: 
			cout<<"Exsiting"<<endl;
			break;
			case 1: 
				cout<<"Enter Name: ";cin>>name;
				passengers->insert(name);
			break;
			case 2: 
				cout<<"Enter Name: ";cin>>name;
				passengers->deleteData(name);
			break;
			case 3: 
				cout<<"Enter Name: ";cin>>name;
				if(passengers->search(name)) cout<<"Ticket reserved"<<endl;
				else cout<<"Ticket not reserved"<<endl;
			break;
			case 4: 
				passengers->display();
			break;
			default: cout<<"Invalid input"<<endl;

		}
	}while(choice!=0);

	FlightLinkedList F;
	F.insertAtEnd(passengers);
	PassengerlinkedList *p2 = new PassengerlinkedList;
	p2->insert("Csahi");
	p2->insert("cydug");
	p2->insert("jwddo");

	F.insertAtEnd(p2);

	cout<<endl<<"All Flights: "<<endl;
	F.display();

	delete p2;
	delete passengers;

	return 0;
}
