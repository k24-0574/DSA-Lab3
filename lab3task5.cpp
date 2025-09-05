#include <iostream>
using namespace std;

template <typename T>
class Node{
	public:
	T data;
	Node<T> *next;
	Node(T d){
		data=d;
		next = NULL;
	}
};

template <typename T>
Node<T>* reverse(Node<T>* head){
    Node<T>* prev=NULL,*curr = head, *next;

    while (curr!= NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

template <typename T>
class linkedList{
	public:
	Node<T> *head, *tail;
	int count;
	linkedList(){
		head=tail=NULL;
		count=0;
	}
	
	void insertAtEnd(T data){
		Node<T>* newnode = new Node(data);
		count++;
		if(head==NULL){
			head=tail=newnode;
			return;
		}
		tail->next = newnode;
		tail=newnode;
	}

	void display(){
		Node<T> *temp =head;
		while(temp!=NULL){
			cout<<temp->data;
			if(temp->next!=NULL) cout<<" -> ";
			temp=temp->next;
		}
		cout<<endl;
	}

    ~linkedList(){
		Node<T>* temp1=head, *temp2;
		while(temp1!=NULL){
			temp2=temp1->next;
			delete temp1;
			temp1=temp2;
		}
	}

    bool isPalindrome(){
        //find middle
		int middle;
		if(count%2) middle = count/2 +1;
		else middle = count/2;

		Node<T> *temp = head, *revHead, *temp2;
		for(int i=0;i<middle;i++){
			temp= temp->next;
		}
		
        //reverse
		revHead = reverse(temp);
		temp = head;
        
        //check if equal
		while(revHead!=NULL){
			if(revHead->data!=temp->data){
				cout<<"List is not Palindrome"<<endl;
				return 0;
			}
			revHead=revHead->next;
			temp=temp->next;
		}
		cout<<"List is Palindrome"<<endl;
		return 1;
    }
};

int main(){
	linkedList<int> IntegerList1, IntegerList2;
	int arrI[] = {1, 0, 2 , 0, 1};
	int arrI2[] = {0, 0, 5, 7, 4};

	for(int i=0;i<sizeof(arrI)/sizeof(arrI[0]);i++) {
		IntegerList1.insertAtEnd(arrI[i]);
		IntegerList2.insertAtEnd(arrI2[i]);
	}
	cout<<"Integer List 1: ";
	IntegerList1.display();
	IntegerList1.isPalindrome();
	cout<<"Integer List 2: ";
	IntegerList2.display();
	IntegerList2.isPalindrome();

	linkedList<char> CharList1,CharList2;
	char arrC1[] = {'B', 'O', 'R', 'R', 'O', 'W', 'O', 'R', 'R', 'O', 'B' };
	char arrC2[] = {'A', 'B', 'C', 'D', 'E', 'W', 'O', 'R', 'R', 'O', 'B' };

	for(int i=0;i<sizeof(arrC1)/sizeof(arrC1[0]);i++) {
		CharList1.insertAtEnd(arrC1[i]);
		CharList2.insertAtEnd(arrC2[i]);
	}
	
	cout<<"Character List 1: ";
	CharList1.display();
	CharList1.isPalindrome();
	cout<<"Character List 2: ";
	CharList2.display();
	CharList2.isPalindrome();


	return 0;
}