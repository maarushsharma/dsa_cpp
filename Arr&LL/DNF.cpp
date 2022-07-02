#include<bits/stdc++.h>
using namespace std;

void dutchnationalflag(vector<int> &nums , int n){
    int low = 0, high = n-1,mid = 0;
    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[low], nums[mid]);
            low++,mid++;
        }else if(nums[mid] == 1){
            mid++;
        }else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }
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
    dutchnationalflag(nums,n);
for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }    
    cout<<endl;
    return 0;
}