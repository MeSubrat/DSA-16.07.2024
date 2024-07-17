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

Node* segregateOddnEven(Node* head)
{
    vector<int> arr;
    Node* temp=head;
    while(temp!=NULL && temp->next!=NULL)
    {
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp)arr.push_back(temp->data);
    temp=head->next;
    while(temp!=NULL && temp->next!=NULL)
    {
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp)arr.push_back(temp->data);

    int i=0;
    temp=head;
    while(temp!=NULL)
    {
        temp->data=arr[i];
        i++;
        temp=temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr={1,2,3,4,5,6};
    Node* head=arr2LL(arr);
    head=segregateOddnEven(head);
    print(head);
}