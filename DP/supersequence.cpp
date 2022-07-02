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
        string s = "";
        while(i>0 and j>0){
            if(x[i-1] == y[j-1]){
                s.push_back(x[i-1]);
                i--;
                j--;
            }else{ if(t[i-1][j] > t[i][j-1]){
                i--;
            }else{
                j--;
            }}
        }
       
        reverse(s.begin(),s.end());
        int pt=0;
        j=0;
        string ans=""; 
        while(j<n){
            if(y[j] == s[pt]){
                pt++;
                j++;
            }else{
                ans.push_back(y[j]);
                j++;
            }
        }
       if(ans.size() <= 1){
           ans.append(x);
            return ans;
        
       }
        else{
           x.append(ans);
        return x; 
        }
    }
}
int main(){
    string x = "acbcf";
    string y = "abcdaf";
    cout<<lcs(x,y,x.length(),y.length());
    cout<<endl;
}