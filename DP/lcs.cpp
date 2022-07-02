#include<bits/stdc++.h>
using namespace std;
int lcs(string x,string y ,int n,int m){
    /*int t[m+1][n+1];
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            t[i][j] = -1;
        }
    }
    if(n==0||m==0){
        return 0;
    }
    if(t[m][n] != -1){
        return t[m][n];
    }
            if(x[n-1] == y[m-1]){
        return t[m][n] = lcs(x,y,n-1,m-1)+1;

    }else{
       return t[m][n] = max(lcs(x,y,n,m-1) ,lcs(x,y,m-1,n));
    }*/

    // top down

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
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return t[m][n];
}
int main(){
    string x = "ABCDGH";
    string y = "ACDGHR";
    cout<<lcs(x,y,x.length(),y.length());
}