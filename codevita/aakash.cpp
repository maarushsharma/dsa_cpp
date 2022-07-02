#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> subsets;
void generate(vector<string> &empty,int idx,vector<string> &v , int n){
    if(idx == n){
        subsets.push_back(empty);
    }

    generate(empty,idx+1,v,n);

    empty.push_back(v[idx]);
    generate(empty,idx+1,v,n);
    empty.pop_back();
}
int main(){
    int n;
    cin>>n;
    int r;
    cin>>r;
    string str;
    cin>>str;


    stringstream s(str);
    vector<string> v;
    map <int , string > hmap;
    for(int i=1;i<=n;i++){
        string temp="";
        getline(s,temp,',');
        v.push_back(temp);
    }
    vector<string> empty; 
    generate(empty,0,v,n);
    for(int i=0;i<n;i++){
        if(i == r){
            
    cout<<subsets[r]<<endl;}
    }
}