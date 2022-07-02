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
node* mergeSort(node* head1, node* head2){
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    if(head1->data > head2->data) swap(head1,head2);
    node* res = head1;

    while(head1 != NULL and head2 != NULL){
        node* temp = NULL;

        while(head1 != NULL and head2->data  >= head1->data){
            temp = head1;
            head1=head1->next;
        }
        temp->next = head2;
        swap(head1,head2);
    }
    return res;
}
int main(){
    node* head1=NULL;
    insertatTail(3,head1);
    insertatTail(7,head1);
    insertatTail(10,head1);
    node* head2=NULL;

    insertatTail(1,head2);
    insertatTail(2,head2);
    insertatTail(5,head2);
    insertatTail(8,head2);
    insertatTail(10,head2);
    /*display(head1);
    display(head2);*/
    mergeSort(head1,head2);
}