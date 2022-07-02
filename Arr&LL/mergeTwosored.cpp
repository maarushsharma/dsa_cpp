//Gap method 
#include<bits/stdc++.h>
using namespace std;
void ArrayMerged(int arr1[] , int arr2[] , int n1 , int n2){
    int gap = ceil((float)(n1+n2)/2);
    while(gap>0){
        int i=0,j=gap;
        while(j < (n1+n2)){
            if(j<n1 && arr1[i] > arr1[j])
                swap(arr1[i],arr1[j]);
            else if(i <n1 and j>=n1 and arr1[i] >arr2[j - n1])
                swap(arr1[i],arr2[j - n1]);
            else if(i>=n1 and j >= n1 and arr2[i-n1]  > arr2[j - n1])
                swap(arr2[i - n1],arr2[j - n1]); 

            i++;
            j++;           
        }
        if(gap == 1){
            gap = 0;

        }else{
            gap = ceil((float)gap/2);
        }
    }
}
int main(){
    int arr1[] = {1,2,3,8,10};
    int arr2[] = {4,7,9};
    ArrayMerged(arr1,arr2,5,3);
    for(int i=0;i<5;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<3;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
}