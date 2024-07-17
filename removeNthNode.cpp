#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

Node* arr2LL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"x";
}
//OPTIMAL APPROACH
Node* removeNthNodeFromBack(Node* head,int n)
{
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL)
    {
        cnt++;
        temp=temp->next;
    }
    int res=cnt-n;
    if(res==0)
    {
        return head->next;
    }
    temp=head;
    while(temp!=NULL)
    {
        res--;
        if(res==0)break;
        temp=temp->next;
    }
    Node* deleteNode=temp->next;
    temp->next=temp->next->next;
    free(deleteNode);
    return head;
}

//BETTER APPROACH
Node* removeNthNodeBetter(Node* head, int n)
{
    Node* fast=head;
    Node* slow=head;
    for(int i=0;i<=n;i++)
    {
        fast=fast->next;
    }
    while(fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }
    Node* deleteNode=slow->next;
    slow->next=slow->next->next;
    free(deleteNode);
    return head;
}

int main()
{
    vector<int> arr={1,2,3,4,5,6};
    Node* head=arr2LL(arr);
    head=removeNthNodeBetter(head,3);
    print(head);
}