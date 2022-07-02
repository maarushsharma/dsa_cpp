#include<bits/stdc++.h>
using namespace std;
class node{
    public : 
    int data;
    node* next;

    node(int val){
        data = val;
        next=NULL;
    }
};

void insertatTail(int val,node* &head ){
    node* n = new node(val);
    if(head == NULL){
        head =n;
        return ;
    }
    node* temp =head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void display(node* head){
    node* temp =head;
    while(temp != NULL){
         cout<<temp->data<<"->";
         temp =temp->next;
    }
    cout<<"NULL"<<endl;
}
node* reverse(node* head ){
    if(head == NULL || head->next == NULL){
        return head; 
    }
    node* newnode = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newnode;
}
node* middleLL(node* &head){
    node* slow=head;
    node* fast=head;
    while(fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
int main(){
    node* head=NULL;
    insertatTail(1,head);
    insertatTail(2,head);
    insertatTail(3,head);
    insertatTail(4,head);
    insertatTail(5,head);
    //display(head);
    node* newhead=  reverse(head);
    cout<<middleLL(newhead);
    display(newhead);
}