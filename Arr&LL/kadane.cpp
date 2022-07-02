#include<bits/stdc++.h>
using namespace std;

int kadane(vector<int> &nums , int n){
    int sum =0;
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        if(sum > maxi) maxi = sum;
        if(sum < 0) sum=0;
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
    cout<<kadane(nums,n)<<endl;
    
    return 0;
}