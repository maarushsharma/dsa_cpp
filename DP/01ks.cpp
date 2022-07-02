 
#include <bits/stdc++.h>
using namespace std;
 int knapSack(int W, int wt[], int val[], int n) 
    { 
        
    int static dp[1002][1002];
    memset(dp,-1,sizeof(dp));

        //recurrsive
       /*if(n==0 || W ==0){
           return 0;
       }
       if(W>=wt[n-1]){
       return max(val[n-1] + knapSack(W - wt[n-1],wt,val,n-1) , knapSack(W,wt,val,n-1));
       }else if(wt[n-1] > W){
           return knapSack(W,wt,val,n-1);
       }*/
       //memorization
       /*if(n==0 || W ==0){
           return 0;
       }
       if(dp[n][W] != -1){
           return dp[n][W];
       }
       if(W>=wt[n-1]){
       return dp[n][W] = max(val[n-1] + knapSack(W - wt[n-1],wt,val,n-1) , knapSack(W,wt,val,n-1));
       }else if(wt[n-1] > W){
           return dp[n][W]=knapSack(W,wt,val,n-1);
       }*/
       
       //Top down - real DP
       if(n==0 || W ==0){
           return 0;
       }
       for(int i=0;i<n+1;i++){
           for(int j=0;j<W+1;j++){
               dp[i][j] = 0;
           }
       }
       for(int i=1;i<n+1;i++){
           for(int j=1;j<W+1;j++){
               if(j>= wt[i-1]){
                   dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]] , dp[i-1][j]);
               }else{
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       return dp[n][W];
    }
    int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;
}