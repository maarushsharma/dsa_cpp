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
void delet(node* dn){
    dn->data = dn->next->data;dn->next=dn->next->next;
}
//intersection
node* intersactionPresent(node* head1 , node *head2){
    node* d1 = head1;
    node* d2 = head2;

    while(d1 != d2){
        if(d1 == NULL){
            d1 = head2;
        }else{
            d1=d1->next;
        }
        if(d2 == NULL){
            d2 = head2;
        }else{
            d2=d2->next;
        }
    }
    return d1;
}
int main(){
    node* head1=NULL;
    insertatTail(3,head1);
    insertatTail(7,head1);
    insertatTail(10,head1);
    //delet(head1->next);
     node* head2=NULL;

    insertatTail(1,head2);
    insertatTail(2,head2);
    insertatTail(5,head2);
    insertatTail(8,head2);
    insertatTail(10,head2);
    display(head1);
    display(head2);
    node* root = intersactionPresent(head1,head2);
    cout<<root;
}