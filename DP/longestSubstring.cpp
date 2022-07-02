#include<bits/stdc++.h>
using namespace std;
int lcsubString(string x,string y,int m,int n){
    int t[m+1][n+1];
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j == 0) t[i][j] = 0;
        }
    }

    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[j-1] == y[i-1]){
                t[i][j] = t[i-1][j-1] +1;
            }else{
                t[i][j] = 0;
            }
        }
    }
    int mx = INT_MIN;
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            mx = max(mx,t[i][j]);
        }
    }
    return mx;
}
int main(){
    string x = "adac";
    string y = "adadac";
    cout<<lcsubString(x,y,x.length(),y.length());
}