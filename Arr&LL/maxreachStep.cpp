#include<bits/stdc++.h>
using namespace std;
int solve(int arr[] , int n){
    // first taken arr
    int maxreach = arr[0];
    int steps = arr[0];
    int jumps=1;
    // size of arr == 0
    if(n == 0) return  0;
    //no possible steps
    else if(arr[0] == 0){
        return -1;
    }
    //some posibile steps
    else{
        for(int i=1;i<n;i++){
            if(i == n-1){
                return jumps;
            }
             maxreach = max(maxreach,i+arr[i]);
             steps--;
             if(steps == 0){
                 //maxreach piche hai no possible ans exist
                 if(i >= maxreach){
                     return -1;
                 }
                 jumps++;
                 // update steps
                 // how much step are possible in the arr
                 steps=maxreach -1 ;
             }
        }
    }
    return jumps;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int count = solve(arr,n);
    if(count != -1){
    cout<<"Minimum number of jumps"<<" "<<count<<endl;
    }else{
        cout<<"no possible ans exist"<<endl;
    }
}