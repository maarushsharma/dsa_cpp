#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int num;
        node* next;
        node* random;
        node(int a) {
            num = a;
            next = NULL;
            random = NULL;
        }
};
//utility function to insert node at the end of the list
void insertNode(node* &head,int val) {
    node* newNode = new node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}
void printList(node* head) {
    while(head->next != NULL) {
        cout<<head->num<<"->";
        head = head->next;
    } 
    cout<<head->num<<endl;
    return;
}
node* cloneRandom(node* &head){
    node* iter = head;
    node * front = head;
    //make clone
    while (iter != NULL)
    {
        front = iter->next;
        node * copy = new node(iter->num);
        iter->next = copy;
        copy->next = front;
        iter=front;
    }
    //make random pointer
    iter=head;
    while(iter != NULL){
        if(iter->random != NULL)
        iter->next->random = iter->random->next;
        iter->next->random = NULL;
    }

    iter = head;
    node* dummy = new node(0);
    node *copy = dummy;
    while(iter != NULL){front = iter->next->next;
            copy->next = iter->next;
            iter->next = front;
            copy=copy->next;
            iter=front;
    }
    return dummy->next;
}

int main() {
    node* head = NULL;
    //inserting Node
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    
    cout<<"Original list: ";
    printList(head);
    
    node* newHead = cloneRandom(head);
    printList(newHead);
    return 0;
}