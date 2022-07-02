#include<bits/stdc++.h>
using namespace std;
int mincoins(vector<int> &Coins , int sum){
    int n=Coins.size();
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(j==0) t[i][j] =0;
            if(i==0) t[i][j] = INT_MAX-1;
            if(i==1){ for(int k=1;k<sum+1;k++){
                if(k%Coins[0] == 0){
                    t[i][j] = k/Coins[0];
                }else{
                    t[i][j] = INT_MAX-1;
                }
            }
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(Coins[i-1] <= j){
                t[i][j] = min(t[i][j-Coins[i-1]] + 1 , t[i-1][j]);
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}
int main(){
    vector<int> Coins = {1,2,3};
    int sum = 5;
    int ways = mincoins(Coins,sum);
    cout<<ways<<endl;
}