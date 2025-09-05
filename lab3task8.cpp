#include <iostream>
using namespace std;

//doubly node
class DNode{
    public:
    int data;
    DNode* next,*prev;
    DNode (int d){
        data = d;
        next=prev=NULL;
    }
};
//singly node
class SNode{
    public:
    int data;
    SNode* next;
    SNode (int d){
        data = d;
        next=NULL;
    }
};

class doublyList{
    public:
    DNode *head, *tail;
    doublyList(){
        head=tail=NULL;
    }

    void insert_at_end(int data){
        DNode *newnode = new DNode(data);
        if(head==NULL){
            head=tail=newnode;
            return;
        }
        tail->next = newnode;
        newnode->prev= tail;
        tail = newnode;
    }

    void display(){
        DNode *temp = head;
        while(temp!=NULL){
            cout<<temp->data;
            if(temp->next!=NULL) cout<<" -> ";
            temp = temp->next;
        }
        cout<<endl;
    }

    ~doublyList(){
        DNode* temp1=head, *temp2;
		while(temp1!=NULL){
			temp2=temp1->next;
			delete temp1;
			temp1=temp2;
		}
    }

};

class singlyList{
    public:
    SNode *head, *tail;

    singlyList(){
		head=tail=NULL;
	}
	
	void insert_at_end(int data){
		SNode* newnode = new SNode(data);
		if(head==NULL){
			head=tail=newnode;
			return;
		}
		tail->next = newnode;
		tail=newnode;	
	}

    void display(){
		SNode *temp =head;
		while(temp!=NULL){
			cout<<temp->data;
			if(temp->next!=NULL) cout<<" -> ";
			temp=temp->next;
		}
		cout<<endl;
	}

	~singlyList(){
		SNode* temp1=head, *temp2;
		while(temp1!=NULL){
			temp2=temp1->next;
			delete temp1;
			temp1=temp2;
		}
	}

    void Concatenate(DNode* head1, DNode* head2){
        DNode *temp=head1;
        while(temp!=NULL){
            insert_at_end(temp->data);
            temp = temp->next;
        }
        temp = head2;
        while(temp!=NULL){
            insert_at_end(temp->data);
            temp= temp->next;
        }
    }
};

int main(){

    doublyList L, M;
    L.insert_at_end(1);
    L.insert_at_end(2);
    L.insert_at_end(3);
    cout<<"L:  ";
    L.display();
    M.insert_at_end(4);
    M.insert_at_end(5);
    M.insert_at_end(6);
    cout<<"M:  ";
    M.display();

    singlyList S;
    S.Concatenate(L.head, M.head);
    cout<<"Result: ";
    S.display();

    return 0;
}