#include<bits/stdc++.h>
using namespace std;
vector<int> sum(vector<int> &arr,int target){
    unordered_map<int,int> mp;
    vector<int> result;
    for(int i=0;i<arr.size();i++){
        if(mp.find(target - arr[i]) != mp.end()){
            result.push_back(mp[target - arr[i]]);
            result.push_back(i);
            return result;
        }
           mp[arr[i]]=i;
        }    return result;
}
int main(){

    vector<int> arr;
    arr = {3,2,4,6};
    int target =6;
    vector<int> v = sum(arr , target);
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
}
