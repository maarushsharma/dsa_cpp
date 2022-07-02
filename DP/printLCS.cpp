#include<bits/stdc++.h>
using namespace std;
string lcs(string x,string y ,int m,int n){
    int t[m+1][n+1];
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j == 0) t[i][j] = 0;
        }
    }

    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1] == y[j-1]){
                t[i][j] = t[i-1][j-1] +1;
            }else{
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    int i=m,j=n;
    string ans = "";
    while(i>0 and j>0){
        if(x[i-1] == y[j-1]){
            ans.push_back(x[i-1]);
            i--;
            j--;
        }else {if(t[i][j-1] > t[i-1][j]){
            j--;
        }else{
            i--;
        }}
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    string x = "bcacaaab";
    string y = "bbabacacaaabc";
    string ans = lcs(x,y,x.length(),y.length());
    cout<<ans<<endl;
}