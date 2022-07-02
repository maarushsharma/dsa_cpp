#include<bits/stdc++.h>
using namespace std;
class node{
    public : 
    int data;
    node* next;
    node* bottom;

    node(int val){
        data = val;
        next=NULL;
        bottom = NULL;
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
node* addTwonumbers(node* head1, node* head2){
    node *dummy = new node(0);
    node *temp = dummy;
    int carry =0;
    while((head1 != NULL or head2 != NULL) or carry){
        int sum = 0;
        if(head1 != NULL){
            sum+=head1->data;
            head1 = head1->next;
        }
        if(head2 != NULL){
            sum += head2->data;
            head2 = head2->next;
        }
        sum += carry;
        carry = sum /10;
        node *newnode = new node(sum%10);
        temp->next =newnode;
        temp=temp->next; 
    }
    return dummy->next; 
}
bool detectCycle(node* root){
    if(root == NULL){
            return false;
        }
    node *slow = root;
    node* fast = root;
    while(fast->next != NULL and fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast) return true;
    }
    return false;
}
int lengthOfLinkedList(node* head) {
    int length = 0;
    while(head != NULL) {
        ++length;
        head = head->next;
    }
    return length;
}
//reverse K group
node* reverseK(node* head,int k){
    if(head == NULL || head->next == NULL) return head;
    int length = lengthOfLinkedList(head);

    node* dummyHead = new node(0);
    dummyHead->next = head;

    node* prev = dummyHead;
    node* curr;
    node* nxt;

    while(length >= k){
        curr = prev->next;
        nxt = curr->next;
        for(int i=1;i<k;i++){
            curr->next = nxt->next;
            nxt->next=prev->next;
            prev->next = nxt;
            nxt = curr->next;
        }
        prev =curr;
        length -= k;
    }
    return dummyHead->next;
}

//LL is palindrome

node* reverse(node* head){
    node* prevptr = NULL;
    node *nextptr ;
    node* currptr = head;
    while(currptr != NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;
        nextptr->next = currptr;
        currptr=nextptr;
    }
    return prevptr;
}
bool ispalindrome(node* head){
    node *slow = head;
    node* fast = head;

    //half way
    while(fast->next != NULL and fast->next->next != NULL){
        slow = slow->next;
        fast=fast->next->next;
    }
    slow->next = reverse(slow->next);
    slow=slow->next;
    node* dummy=head;
    while(slow != NULL){
        if(dummy->data != slow->data) return false;            
            dummy=dummy->next;
            slow = slow->next;
        
    }
    return true;
} 
//merge flattren 
node* mergeRoot(node* a, node*b){
    node *temp = new node(0);
    node* res = temp;
    while(a != NULL and b != NULL){
        if(a->data > b->data){
            temp->bottom =b;
            b=b->bottom;
            temp=temp->bottom;
        }else{
            temp->bottom=a;
            temp=temp->bottom;
            a=a->bottom;
        }
    }
    if(a) temp->bottom=a;
    else temp->bottom=b;

    return res->bottom;
}
// Flatteninr a LL
node* Flatten(node* root){
    if(root==NULL or root->next==NULL)return root;
    root->next = Flatten(root->next);
    root = mergeRoot(root,root->next);
    return root;
}

//Rotate right
node *right(node* head , int k){
    if(head == NULL or head->next ==NULL or k  == 0){
        return head;
    }
    int length=1;
    node* temp  =head;
    while(head->next != NULL){
        ++length;
        temp=temp->next;
    }
    temp->next=head;
    k=k%length;
    int end=length -k;
    while(end--){temp=temp->next;}
    head=temp->next;
    temp->next=NULL;
    return head;
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
    /*node* rootdummy = addTwonumbers(head1,head2);
    display(rootdummy);*/
    //cout<<detectCycle(NULL);
    //reverseK(head2,2);
    //cout<<ispalindrome(head2);
     right(head2,2);
    display(head2);
}