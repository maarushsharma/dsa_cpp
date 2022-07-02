#include<bits/stdc++.h>
using namespace std;
int majoritylement(vector<int> &nums){
    int count =0;
    int element = 0;

    for(int num :  nums){
        if(count == 0 ){
            element = num;
        }

        if(num == element) count++;
        else count--;
    }
    return element;
}
int main(){
    vector<int> nums;
    nums = {4,4,2,4,3,4,4,3,2,4};
    cout<<majoritylement(nums);
}