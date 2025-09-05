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

Node* reverse(Node* head){
    Node* prev=NULL,*curr = head, *next;

    while (curr!= NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

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
		while(temp!=NULL){
			cout<<temp->data;
			if(temp->next!=NULL) cout<<" -> ";
			temp=temp->next;
		}
		cout<<endl;
		
	}
    void rearrange(){
        Node* newHead, *newTail, *temp=head;
        if(head->next==NULL) return;
        else {
            newHead = head->next;
            newTail = newHead;        
        }

        bool end=0;

        //seperate intervals
        while(!end){
            if(temp->next){
                if(temp==head){
                    temp ->next = newTail->next;
                    if(temp->next) 
                        temp=temp->next;
                    else end=1;

                    newTail->next=NULL;
                }
                else{
                    newTail->next=temp->next;
                    newTail = newTail->next;
                    temp->next = newTail->next;
                    newTail->next=NULL;
                    if(temp->next) 
                        temp=temp->next;
                    else end=1;
                    
                    
                } 
            }
            else end=1;
        }

        //reverse
        newHead = reverse(newHead);

        //join
        temp->next = newHead; 
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
    Input:
    LinkedList = 10 4 9 1 3 5 9 4
    Output:
    10 9 3 9 4 5 1 4
    */
    linkedList L;
    int arr[] = {10, 4, 9, 1, 3, 5, 9, 4};
    for(int i=0 ; i<(sizeof(arr)/sizeof(arr[0])); i++){
        L.insertAtEnd(arr[i]);
    }

    L.display();

    L.rearrange();
    L.display();

    return 0;
}