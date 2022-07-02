#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << (root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void preorderIter(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        cout << root->data << endl;
        if (root->right != NULL)
            st.push(root->right);
        if (root->left)
            st.push(root->left);
    }
}
// 2 stack
void post1(Node *root)
{
    stack<Node *> st1;
    stack<Node *> st2;
    st1.push(root);
    Node *node = root;
    while (!st1.empty())
    {
        node = st1.top();
        st1.pop();
        st2.push(node);
        if (node->left != NULL)
            st1.push(node->left);
        if (node->right != NULL)
            st1.push(node->right);
    }
    while (!st2.empty())
    {
        cout << st2.top()->data;
        st2.pop();
    }
}
//using 2 stack
void post2(Node* root){
    stack<Node*> st;
    Node* node = root;
    while(node != NULL || !st.empty()){
        if(node != NULL){
            st.push(node);
            node=node->left;
        }else{
            Node* temp = st.top()->right;
            if(temp == NULL){
                temp=st.top();
                st.pop();
                cout<<temp->data;
                while( !st.empty() and temp == st.top()->right){
                    temp=st.top();
                    st.pop();
                    cout<<temp->data;
                }
            }else{
                node=temp;
            }
        }
    }
}
void in(Node *root)
{
    stack<Node *> st;
    Node *node = root;
    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty() == true)
                break;
            node = st.top();
            st.pop();
            cout << node->data;
            node = node->right;
        }
    }
}
//all in one traversal
void all(Node * root){
    stack<pair<Node*,int>> st;
    Node* node=root;
    vector<int> in,pre,post;
    st.push({node,1});
    while(!st.empty()){
        auto it = st.top();
        st.pop();

        if(it.second == 1){
            pre.push_back(it.first->data);                            
            it.second++;
            st.push(it);
            if(it.first->left != NULL){
                st.push({it.first->left,1});
            }
        }

        else if(it.second == 2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right != NULL){
                st.push({it.first->right,1});
            }
        }

        else{
            post.push_back(it.first->data);
        }
    }
    
    for(int i=0;i<in.size();i++){
        cout<<in[i]<<" ";
    }

    for(int i=0;i<in.size();i++){
        cout<<pre[i]<<" ";
    }

    for(int i=0;i<in.size();i++){
        cout<<post[i]<<" ";
    }
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    all(root);
}