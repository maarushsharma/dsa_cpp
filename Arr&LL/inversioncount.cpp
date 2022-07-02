#include<bits/stdc++.h>
using namespace std;
int Merge(int arr[],int temp[],int low,int mid,int high){
    int count_inver =0;
    int i=low;
    int j=mid;
    int k=low;
    while(i <= mid-1 and j <= high){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++]=arr[j++];
            count_inver=count_inver+(mid-1);
        }
    }
    while(i <= mid -1){
        temp[k++] = arr[i++];
    }
        while(j <= high){
            temp[k++] = arr[i++];
        }
    for( i = low;i<= high;i++){
        arr[i]=temp[i];
    }
    return count_inver;
}
int merge_Sort(int arr[],int temp[] ,int left , int right){
    int mid,inversion=0;
   if(left<right){ mid = (left+right)/2;

    inversion += merge_Sort(arr,temp,left,mid);
    inversion += merge_Sort(arr,temp,mid+1,right);
    inversion += Merge(arr,temp,left,mid+1,right);
    }
    return inversion;
}
int main(){
    int arr[] = {5,4,3,2,1};
    int n=5;
    int temp[n];
    int ans =  merge_Sort(arr,temp,0,n-1);
    cout<<ans<<endl;
}