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
//BRUTE FORCE APPROACH
bool checkPalindrome(Node* head)
{
    stack<int> st;
    Node* temp=head;
    while(temp!=NULL)
    {
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data!=st.top())return false;
        temp=temp->next;
        st.pop();
    }
    return true;
}
Node* reverse(Node* head)
{
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL)
    {
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;

}
//OPTIMAL APPROACH
bool checkPalindromeBetter(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* newHead=reverse(slow->next);
    Node* first=head;
    Node* second=newHead;
    while(second!=NULL)
    {
        if(first->data!=second->data){
            reverse(newHead);
            return false;
        }
        fast=fast->next;
        second=second->next;
    }
    reverse(newHead);
    return true;

}
int main()
{
    vector<int> arr={1,2,3,3,2,1};
    Node* head=arr2LL(arr);
    // cout<<checkPalindrome(head);
    cout<<checkPalindromeBetter(head);
    // head=reverse(head);
    // print(head);
}