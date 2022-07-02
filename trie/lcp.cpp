#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class TrieNode{
  public:
    
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;
    
    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        childCount=0;
        isTerminal=false;
    }
};

class Trie{
  public:
        
    TrieNode* root;
    Trie(char ch){
        root = new TrieNode(ch);
    }
    
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
            root->childCount++;
            root->children[index] = curr;
        }

        insertNodeUtil(curr, word.substr(1));
    }

    void insert(string word)
    {
        insertNodeUtil(root, word);
    }
    
    void lcp(string first,string &ans){
        for(int i=0;i<first.length();i++){
            char ch = first[i];
            
            if(root->childCount == 1){
                ans.push_back(ch);
                
                int index = ch - 'a';
                root = root->children[index];
            }
            else{
                break;
            }
            
            if(root->isTerminal == true) break;
        }
    }
};
class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        for(int i=0;i<N;i++)
        if(arr[0][0] != arr[i][0] ){
            return "-1";
        }
        Trie *t = new Trie('\0');
        
        for(int i=0;i<N;i++){
            t->insert(arr[i]);
        }
        
        string first = arr[0];
        string ans = "";
        
        t->lcp(first,ans);
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class TrieNode{
  public:
    
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;
    
    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        childCount=0;
        isTerminal=false;
    }
};

class Trie{
  public:
        
    TrieNode* root;
    Trie(char ch){
        root = new TrieNode(ch);
    }
    
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
            root->childCount++;
            root->children[index] = curr;
        }

        insertNodeUtil(curr, word.substr(1));
    }

    void insert(string word)
    {
        insertNodeUtil(root, word);
    }
    
    void lcp(string first,string &ans){
        for(int i=0;i<first.length();i++){
            char ch = first[i];
            
            if(root->childCount == 1){
                ans.push_back(ch);
                
                int index = ch - 'a';
                root = root->children[index];
            }
            else{
                break;
            }
            
            if(root->isTerminal == true) break;
        }
    }
};
class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        for(int i=0;i<N;i++)
        if(arr[0][0] != arr[i][0] ){
            return "-1";
        }
        Trie *t = new Trie('\0');
        
        for(int i=0;i<N;i++){
            t->insert(arr[i]);
        }
        
        string first = arr[0];
        string ans = "";
        
        t->lcp(first,ans);
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}
