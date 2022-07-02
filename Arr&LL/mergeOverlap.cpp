#include<bits/stdc++.h>
using namespace std;

// vector<vector<int>> mergeSorted(vector<vector<int>> &intervals){
    
//     sort(intervals.begin(),intervals.end());
//     for(int i=0;i<intervals.size();i++){
//         if(merged.empty() || merged.back()[1] < intervals[i][0]){
//             vector<int> v = {
//                 intervals[i][0],intervals[i][1]
//             };
//             merged.push_back(v);
//         }else{
//             merged.back()[1] = max(merged.back()[1],intervals[i][1]);
//         }
//     }
//     return merged;
// }
// int main(){
//     vector<vector<int>> Arr;
//     Arr = {{1, 3}, {2, 4}, {2, 6}, {8, 9}, {8, 10}, {9, 11}, {15, 18}, {16, 17}};
//     vector<vector<int>> ans = mergeSorted(Arr);

//     cout<<"Marged Overlapped intervals"<<endl;
    
//     for(auto it: ans){
//         cout<<it[0]<<" "<<it[1]<<"\n";
//     }
// }

vector<pair<int,int>> Merge(vector<pair<int,int>> &intervals){
    vector<pair<int,int>> ans;
    sort(intervals.begin(),intervals.end());
    for(int i=0;i<intervals.size();i++){
        if(ans.empty() || ans.back().second < intervals[i].first){
            pair<int,int> p = {intervals[i].first ,intervals[i].second};
            ans.push_back(p);
        }
        else{
        ans.back().first = max(ans.back().first , intervals[i].second);
    }
    }
    return ans;
}
int main(){
    vector<pair<int,int>> interval;
    cout<<"Entre"<<endl;
    for(int i=0;i<interval.size();i++){
        cin>>interval[i].first>>interval[i].second;
    }
    vector<pair<int,int>> ans = Merge(interval);
    cout<<"merged"<<endl;
    for (auto it: ans) {
    cout << it.first << " " << it.second << "\n";
  }
}