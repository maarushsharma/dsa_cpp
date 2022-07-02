#include <bits/stdc++.h>
using namespace std;

int main() {
    int m1,m2;
    long long unsigned int n;
    cin>>m1>>m2>>n;
    vector<int> arr(n);
    for(long long unsigned int i=0;i<n;i++){
        cin>>arr[i];
    }
int sum1=0;
int sum2=0;
vector<long long unsigned int> v1;
vector<long long unsigned int> v2;
    sort(arr.begin(),arr.end(),greater<int>());
    for(long long unsigned int i=0;i<n;i+=2){
        sum1+=arr[i];
        v1.push_back(arr[i]);
        if(i+1 >= n )break;
        sum2+=arr[i+1];
        v2.push_back(arr[i+1]);
    }

    for(long long unsigned int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    for(long long unsigned int i=0;i<v2.size();i++){
        cout<<v2[i]<<" ";
    }

    if(m2>m1){
        for(long long unsigned int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    for(long long unsigned int i=0;i<v2.size();i++){
        cout<<v2[i]<<" ";
    }
    }else{
        for(long long unsigned int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }cout<<endl;
    for(long long unsigned int i=0;i<v2.size();i++){
        cout<<v2[i]<<" ";
    }
    }

}