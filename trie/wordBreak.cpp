//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    // constractor for the present class

    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

    // insert main fun

    void insertNodeUtil(TrieNode *root, string word)
    {
        // base case

        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // got the index of given word

        int index = word[0] - 'a';
        TrieNode *curr;
        // just check weather the chracter is present do nothing
        if (root->children[index] != NULL)
        {
            curr = root->children[index];
        }
        else
        {
            curr = new TrieNode(word[0]);
            root->children[index] = curr;
        }

        insertNodeUtil(curr, word.substr(1));
    }

    void insert(string word)
    {
        insertNodeUtil(root, word);
    }

    //lets start the seaching
    bool searchutil(TrieNode* root , string word){
        if(word.length() == 0){
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        TrieNode* curr;
        if(root->children[index] != NULL){
            curr=root->children[index];
        }else{
            return false;
        }

        return searchutil(curr,word.substr(1));
    }
    bool search(string word){
        return searchutil(root,word);
    }
    
    bool Wordb(string a){
        int n =a.length();
        if(n == 0) return true;
        for(int i=1;i<=n;i++){
            if(search(a.substr(0,i)) and Wordb(a.substr(i,n-i)))
            return true;
        }
        return false;
    }
};

class Solution{
    public:
    
    int wordBreak(string A, vector<string> &B) {
        Trie *t = new Trie('\0');
        
        for(int i=0;i<B.size();i++){
            t->insert(B[i]);
        }
        
        return t->Wordb(A);
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends