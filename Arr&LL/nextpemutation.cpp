#include<bits/stdc++.h>
using namespace std;

void nextpermutation(vector<int> &nums){
    int n = nums.size(),k,l;
    for(k=n-2;k>=0;k--){//increasing first
        if(nums[k] < nums[k+1])
            break;
    }
    if(k < 0){
        reverse(nums.begin(),nums.end());//if index crossing eachother  
    }else{
        for(l=n-1;l>k;l--){//take another pointer from last and compare it with fisrt for greater swap, rever  
            if(nums[l] > nums[k]){
                break;
            }
        }
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());
    }
}
int main() {
    int n;
    cout<<"enter Size"<<endl;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    nextpermutation(nums);
    for(int i=0;i<n;i++)
    cout<<nums[i];
    cout<<endl;
    return 0;
}