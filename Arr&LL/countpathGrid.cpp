#include<bits/stdc++.h>
using namespace std;
//Recurrsion
/*class Solution{
    public:
        int countPath(int i,int j, int m, int n){
            if(i == (n-1) && j == (m-1) ){
                return 1;
            }
            if(i >= n || j >= m) return 0;
            else return countPath(i+1,j,m,n)+countPath(i,j+1,m,n);
        }
        int uniquePath(int m,int n){
            return countPath(0,0,m,n);
        }
};*/
//DP
class Solution{
    public:
        int countPath(int i,int j, int m, int n,vector<vector<int>> &dp){
            if(i == (n-1) && j == (m-1) ){
                return 1;
            }
            if(i >= n || j >= m) return 0;
            if(dp[i][j] != -1) return dp[i][j];
            else return dp[i][j] = countPath(i+1,j,m,n,dp)+countPath(i,j+1,m,n,dp);
        }
        int uniquePath(int m,int n){
            vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
            int num = countPath(0,0,m,n,dp);
            if(m==1 and n == 1) return num;
            return dp[0][0];
        }
};

//counting soution
class solution{
    public:
    int uniquePath(int m,int n){
        int N = n+m-2;
        int r = m-1;
        double result = 1;
        for(int i=1;i<=r;i++){ // insted of i<=r => i<r then segment fault
            result = result*(N -r +i)/i;
        }
        return (int) result;
    }
};
int main(){
    Solution obj;
    int totalCount = obj.uniquePath(2,3);
    cout<<"The total number of Unique Paths are "<<totalCount<<endl;
}
