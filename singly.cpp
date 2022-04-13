#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node * next;
//constructor
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
//destructor
    ~Node()
    {
        int value=this->data;
        //memory free
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
         cout<<"Memory is free for node with data : "<<value<<endl;
    }
};

//Insert at head

void insertAtHead(Node* &head,int d)
{
    Node * temp=new Node(d);
    temp->next=head;
    head=temp;
}

//Insert At tail

void insertAtTail(Node* &tail,int d)
{
    Node *temp=new Node(d);
    tail->next= temp;
    tail=temp;
}

//Insert At middle 

void insertAtmiddle(Node* &tail,Node* &head,int pos,int d)
{
    //insert at start
    if(pos==1)
    {
        insertAtHead(head,d);
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
        insertAtTail(tail,d);
        return;
    }
    Node* nodeToinsert=new Node(d);
    nodeToinsert->next=temp->next;
    temp->next=nodeToinsert;
}

//delete function
void deleteNode(int position,Node* &head)
{
    //deleting first or last
    if(position==1)
    {
       Node*temp=head;
       head=head->next;
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
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

void print(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    Node * node1=new Node(10);
    Node * head=node1;
    Node *tail=node1;
     print(head);

     insertAtHead(head,15);
     //print(head);

    insertAtTail(tail,12);
    //print(head);

    //  insertAtTail(tail,20);
    // print(head);

    insertAtmiddle(tail,head,3,50);
    print(head);

    deleteNode(4,head);
    print(head);

    cout<<"head :"<<head->data<<endl;
    cout<<"tail :"<<tail->data<<endl;

    return 0;
}
