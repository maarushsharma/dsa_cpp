#include<bits/stdc++.h>
using namespace std;
int findMax(int arr[] , int n, int k){
    int i=0;
    int j=0;
    int sum=0 , maxi = INT_MIN;
    while(j < n){
        if(j-i+1 < k ){
            sum=+arr[j];
            j++;
        }
        else if(j-i+1 == k){
            maxi = max(sum,maxi);
            sum -= arr[i];
            j++;
            i++;
        }
    }
    return maxi;
}
int main(){
    int n,k;
    cout<<"enter size of array and k";
    cin>>n;
    int arr[n-1];
    cin>>k;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The maximum sum of your sliding window: " << findMax(arr,n,k)<<endl;
}