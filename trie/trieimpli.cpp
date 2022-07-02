#include <bits/stdc++.h>
using namespace std;

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

    Trie()
    {
        root = new TrieNode('\0');
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

        int index = word[0] - 'A';
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
        int index = word[0] - 'A';
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
};

int main()
{
    Trie *t = new Trie();

    t->insert("hello");
    t->insert("help");
    //t->search("help");
    t->search("hel");
    t->search("hel");
    cout<<t->search("hel")<<endl;
}