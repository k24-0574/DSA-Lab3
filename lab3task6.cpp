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
		cout<<endl;
		
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
    linkedList L;
    L.insertAtEnd(1);
    L.insertAtEnd(2);
    L.insertAtEnd(3);
    L.insertAtEnd(4);
    cout<<"List: "<<endl;
    L.display();
    int num;
    cout<<"Which number to remove: ";cin>>num;
    L.deleteData(num);
    L.display();
    return 0;
}