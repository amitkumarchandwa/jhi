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

void insertNode(Node* &tail,int ele,int d)
{
    //empty list
    if(tail==NULL)
    {
        Node*newNode=new Node(d);
        tail=newNode;
        newNode->next=newNode;
    }

    else
    {
        //non empty list
        Node*curr=tail;
        while(curr->data!=ele)
        {
            curr=curr->next;
        }

        //element found->curr representing element wala node
        Node*temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}

void print(Node*tail)
{
    Node*temp=tail;
    do{
        cout<<tail->data<<" " ;
        tail=tail->next;
    }while(tail!=temp);
    cout<<endl;
}

int main()
{
    Node*tail=NULL;

    insertNode(tail,5,3);
    // print(tail);

    insertNode(tail,3,8);
    // print(tail);

    insertNode(tail,8,9);
    // print(tail);

    insertNode(tail,9,24);
    // print(tail);

    insertNode(tail,9,25);
    print(tail);
     
}