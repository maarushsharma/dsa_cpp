#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &nums){
    int mini=INT_MAX,maxi=0;
    for(int i=0;i<nums.size();i++){
            mini=min(nums[i],mini);
            maxi=max(nums[i]-mini,maxi);

    }
    return maxi;
}
int main() {
    int n;
    cout<<"enter Size"<<endl;
    cin>>n;
    vector<int> nums(n);
    cout<<"elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    cout<<"The maximum profit" <<maxProfit(nums)<<endl;
}