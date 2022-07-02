#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > a, int m, int n) 
    {
        /*int i;//iterator
        int k=0; // starting row;
        int l=0; // starting col;
        vector<int> v;
        
        while(k<r and l<c){ // r->m and c->n
        
        for(i = l;i<c;++i){
            v.push_back(matrix[l][i]);
        }
        k++;
        
        for(i = k;i<r;++i){
            v.push_back(matrix[i][c-1]);
        }
        c--;
        
        if(k<r){
            for(i=c-1;i>=k;--i){
                v.push_back(matrix[i][r-1]);
            }
            r--;
        }
        
        if(l<c){
            for(i = r-1;i>=l;--i){
                v.push_back(matrix[l][i]);
            }
            l--;
        }
        }
        return v;*/
        //
        int i, k = 0, l = 0;
        vector<int> v;
 
    /* k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */
 
    while (k < m && l < n) {
        
        for (i = l; i < n; ++i) {
            v.push_back(a[k][i]);
        }
        k++;
 
 
        for (i = k; i < m; ++i) {
            v.push_back(a[i][n - 1]);
        }
        n--;
 
 
        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                v.push_back(a[m-1][i]);
            }
            m--;
        }
 
 
        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                v.push_back(a[i][l] );
                
            }
            l++;
        }
    }
    return  v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends