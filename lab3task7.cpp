#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

class CircularList{
    public:
    Node* head;

    CircularList(){
        head = NULL;
    }

    void insert_at_end(int data){
        Node* newNode = new Node(data);
        if(head==NULL){
            head = newNode;
            head->next = newNode;
        }
        Node* temp = head;
        while(temp->next !=head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    void insert_at_beginning(int data){
        Node* newNode = new Node(data);
        if(head==NULL){
            head = newNode;
            head->next = newNode;
        }
        Node* temp = head;
        while(temp->next !=head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    void insert_at_pos(int data, int pos){
        if(pos == 0){
            insert_at_beginning(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* temp = head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        newNode->next =temp->next;
        temp->next = newNode;
    }

    void display(){
        Node *temp = head;
        do{
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }while(temp!=head);
        cout<<"repeat"<<endl;
    }

    void deleteNode(int data){
        Node* temp = head, *prev;

        do{
            if(temp->data==data){
                if(temp==head){
                    prev = head;
                    while(prev->next!=head) prev=prev->next;
                    head = temp->next;
                }
                prev->next = temp->next;
                delete temp;
                return;
            }
            prev=temp;
            temp = temp->next;
        }while(temp!=head);
        cout<<data<<" not found"<<endl;
    }

    ~CircularList(){
        if (!head) return;

        Node *temp=NULL;
        Node *prev = head->next;

        while(temp!=head){
            temp = prev->next;
            delete prev;
            prev = temp;
        }
        delete head;
    }
};

int main(){
    CircularList l1;
    l1.insert_at_beginning(1);
    l1.insert_at_beginning(2);
    l1.insert_at_beginning(3);
    l1.insert_at_beginning(4);
    l1.display();

    l1.insert_at_end(5);
    l1.insert_at_end(6);
    l1.insert_at_end(7);
    l1.display();

    l1.insert_at_pos(10, 3);
    l1.display();

    l1.deleteNode(4);
    l1.display();


    return 0;
}