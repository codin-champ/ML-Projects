#include <iostream>
using namespace std;
//Inserion of elements in ink list

class node
{
    public:
    int data;
    node*next;

    node(int d)
    {
        data=d;
        next=NULL;
    }
};


//Linked list class(Generic programming/Object oriented approach)

/*
class Linked_list
{
    node*head;
    node*tail;

    public:
    Linked_list()
    {

    }

    void insert(int d)
    {

    }

};
*/

//Functions(Procedural Programming)

void build()
{

}

//Passing a pointer variable by reference
void insertAtHead(node*&head,int d)//something needs to be figured about passing by reference and passing by value
{
    if(head==NULL)
    {
        head=new node(d);//dynamic allocation is used so as to delete the previous node like once the data is used----the address is no longer needed
        return;
    }

    node *n=new node(d);
    n->next = head;
    head=n;

}

int length(node*head)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=(*head).next;
    }

    return count;
}

void insertAtTail(node*&head, int d)
{
    if(head==NULL)
    {
        head=new node(d);
        return;
    }
    node*tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    tail->next=new node(d);
    return;
}


void insertAtMiddle(node*&head,int d,int p)
{
    //p==0--->Insertion at head
    //p-1 jumps to reach the required position

    //Corner case
    if(head==NULL or p==0)
    {
        insertAtHead(head,d);
        return;
    }

    else if(p>length(head))
    {
        insertAtTail(head,d);
    }

    else
    {
        //Take p-1 jumps
        int jump=1;
        node*temp=head;
        while(jump<=p-1)
        {
            temp=temp->next;
            jump++;
        }

        //Create a new node
        node*n=new node(d);
        n->next=temp->next;
        temp->next=n;
    }
}


void print(node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
}

int main() 
{
    node*head=NULL;
    // insertAtHead(head,3);
    // insertAtHead(head,2);
    // insertAtHead(head,5);
    // insertAtHead(head,15);

    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        insertAtMiddle(head,t,3);
    }

    print(head);
    print(head);//This prints the linked list twice because we are passing the function by value and not by reference
    //Had we used void print(node*&head)--The second function wont have given an output because the value of head would have reached NULL already

    return 0;
}
