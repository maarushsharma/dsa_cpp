#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,pair<int,int>> arr1,pair<int,pair<int,int>>arr2){
    if(arr1.second.first == arr2.second.first) return arr1.second.first > arr2.second.first;
    return arr1.second.first > arr2.second.first;
}
pair<int,int> solve(vector<pair<int,pair<int,int>>> &arr,int n , int name ){
    pair<int,int> ans;
    sort(arr.begin(),arr.end(),comp);
    unordered_map<int,bool> mp;
    int count =1;
    int maxCount=1;
    int entime = arr[0].second.second+arr[0].second.first;


    mp[arr[0].second.first] = true;
    for(int i=1;i<n;i++){
        if(arr[i].second.first <= entime){
            mp[count]=true;
            count++;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,pair<int,int>>> arr;
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        cin>>arr[i].second.first;
        cin>>arr[i].second.second;
    }
    int name;
    cin>>name;

    solve(arr,n,name);
}