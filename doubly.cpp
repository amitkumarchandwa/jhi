#include<iostream>
using namespace std;

class Node
{
   public:
   int data;
   Node* prev;
   Node* next;

   //constructor
   Node(int d)
   {
       this->data=d;
       this->prev=NULL;
       this->next=NULL;
   }

    //destructor
   ~Node()
   {
       int value=this->data;
        //memory free
        if(next!=NULL)
        {
            delete next;
            next=NULL;
        }
         cout<<"Memory is free for node with data : "<<value<<endl;
   }
};

void print(Node* head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
      cout<<temp->data<<" ";
      temp = temp->next;  
    }
    cout<<endl;
}

//for counting lenth of linked list
int getLength(Node*head)
{
   Node*temp=head;
   int len=0;
   while(temp!=NULL)
   {
       len++;
       temp=temp->next;
   }
   return len;
}

void insertAthead(Node* &head,int d)
{
    Node* temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}

void insertAttail(Node* &tail,int d)
{
    Node*temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

void insertAtmiddle(Node* &tail,Node* &head,int pos,int d)
{
    //insert at start
    if(pos==1)
    {
        insertAthead(head,d);
        return;
    }

    Node*temp=head;
    int count=1;
    while(count<pos-1)
    {
        temp=temp->next;
        count++;
    }

    //insert at last position
    if(temp->next==NULL)
    {
        insertAttail(tail,d);
        return;
    }
    Node* nodeToinsert=new Node(d);
    nodeToinsert->next=temp->next;
    temp->next=nodeToinsert;
    nodeToinsert->prev=temp;
}

void deleteNode(int position,Node* &head)
{
    //deleting first or last
    if(position==1)
    {
       Node*temp=head;
       temp->next->prev=NULL;
       head=temp->next;
       //memory free start node
       temp->next=NULL;
       delete temp;
    }
    else
    {
        Node*curr=head;
        Node*prev=NULL;
        int count=1;
        while(count<position)
        {
            prev=curr;
            curr=curr->next;
            count++;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL; 
        delete curr;
    }
}

int main()
{
    Node* node1=new Node(10);
    Node*head=node1;
    Node*tail=node1; 
    // print(head); 
    
    insertAthead(head,20);
    print(head);

    insertAthead(head,30);
    print(head);

    insertAttail(tail,40);
    print(head);

    insertAtmiddle(tail,head,2,250);
    print(head);

    insertAtmiddle(tail,head,1,150);
    print(head);

    insertAtmiddle(tail,head,7,350);
    print(head);

    deleteNode(1,head);
    print(head);

    deleteNode(6,head);
    print(head);

    deleteNode(3,head);
    print(head);

    // cout<<getLength(head)<<endl;
}