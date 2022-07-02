#include<bits/stdc++.h>
using namespace std;
int solve(vector<string> &v,int n){
    int idx0 ; 
    int idx1; 
    for(int i=0;i<n;i++){
        if(v[i] == '0'){
            idx0=i;
            break;
        }

    }

    int i=idx0,j=idx0;
    while(i>=0 or j<= n){
        i--;j++;
        if(v[i] == '1'){
            idx1=i;
            break;
        }

        if(v[j] == '1'){
            idx1=j;
            break;
        }
    }
    return abs(i-j);
}
int main(){
    int n;
    cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    solve(v,n);
} 
