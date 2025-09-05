#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
	Node(int d){
		data=d;
		next = NULL;
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

    void arrangeEvenOdd(){
        Node* temp=head, *prev=NULL;
        Node* evenTail=NULL;
        bool found=0;
        
        while(temp!=NULL){
            if(temp->data %2 ==0){
                
                if(!evenTail){
                    //make this the head
                    if(temp!=head){
                        prev->next = temp->next;
                        temp->next= head;
                        head=temp;   
                    }
                    evenTail = temp;
                }
                else{
                    //add after eventail
                    if(temp != evenTail->next){
                        if(temp==tail)
                            tail = prev;
                        prev->next = temp->next;
                        temp->next = evenTail->next;
                        evenTail->next = temp;

                    }
                    evenTail=temp;
                }
            }
            prev=temp;
            temp=temp->next;
        }
    }
	
};

int main(){
    /*
    Input: 17 → 15 → 8 → 12 → 10 → 5 → 4 → 1 → 7 → 6 → NULL
    Output: 8 → 12 → 10 → 4 → 6 → 17 → 15 → 5 → 1 → 7 → NULL
    */
    linkedList l;

    int arr[] = {17, 15, 8, 12, 10, 5, 4, 1, 7, 6};
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
        l.insertAtEnd(arr[i]);

    cout<<"Input: ";
    l.display();
    l.arrangeEvenOdd();
    cout<<"Output: ";
    l.display();
    cout<<endl;

    linkedList l2;
    l2.insertAtEnd(2);
    l2.insertAtEnd(4);
    l2.insertAtEnd(6);
    l2.insertAtEnd(8);
    cout<<"Input: ";
    l2.display();
    l2.arrangeEvenOdd();
    cout<<"Output: ";
    l2.display();
    cout<<endl;

    linkedList l3;
    l3.insertAtEnd(1);
    l3.insertAtEnd(3);
    l3.insertAtEnd(5);
    l3.insertAtEnd(7);
    cout<<"Input: ";
    l3.display();
    l3.arrangeEvenOdd();
    cout<<"Output: ";
    l3.display();
    cout<<endl;

    return 0;
}
