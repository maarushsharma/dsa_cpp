// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class node{
    public:
        int data;
        int i;
        int j;
        node(int data , int row , int  col){
            this->data=data;
            i=row;
            j=col;
    }
};

class compare{
    public:
        bool operator()(node* a, node* b){
            return a->data >b->data;
        }
};

class Solution{
    public:
    
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        priority_queue<node* , vector<node*> , compare > pq;
        int mini=INT_MAX,maxi=INT_MIN;
        //push first element of  k array and store minimun and maximum 
        for(int i=0;i<k;i++){
            int ele = KSortedArray[i][0];
            mini = min(mini,ele);
            maxi = max(maxi,ele);
            pq.push(new node(KSortedArray[i][0],i,0));
        }
        //variable for range change
        int start =mini, end=maxi; 
        //new mini
        while(!pq.empty()){
            node* temp = pq.top();
            pq.pop();
            mini = temp->data;
        //if range decreases    
            if(maxi-mini < start-end){
                start = mini;
                end=maxi;
            }
            
        //push in heap
        
            if(temp->j+1 < n){
                maxi = max(maxi,KSortedArray[temp->i][temp->j+1] );
                pq.push(new node(KSortedArray[temp->i][temp->j+1],temp->i,temp->j+1));
            }
        // agar ith array finish ho gaya terminate    
            else{
                break;
            }
        }
        return {start , end};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}
/*
N = 5, K = 3
KSortedArray[][] = {{1 3 5 7 9},
                    {0 2 4 6 8},
                    {2 3 5 7 11}}
                    */
  // } Driver Code Ends