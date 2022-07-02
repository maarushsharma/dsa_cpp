//approches :
//1 -> sort both array in one array put the eles into both the arrays ==>> sc = o(n+m),tc =nolgn
//2 -> check smallest for each elements in arr1 tc = O(n) + O(m)2
//3: gap method tc=>O(nlogn) sc=O(1);

#include <bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> &arr1 ,vector<int> &arr2 ,int n,int m){
    int gap = ceil((n+m)/2);
    while(gap>0){
        int  i=0,j=gap;
        while(gap<n+m){
        if(j<n and arr1[i] > arr1[j]){
            swap(arr1[i],arr1[j]);
        }else if(i <n and j>=n and arr1[i] > arr2[j-n]){
            swap(arr1[i],arr2[j-n]);
        }else if(i>n and j>n and arr1[i-n] > arr2[j-n] ){
            swap(arr1[i-n],arr2[j-n]);
        }
        i++;
        j++;
        }
        if(gap == 1){
            gap = 0;

        }else{
            gap = ceil((float)gap/2);
        }
    }
        for(int k=0;k<m;k++){
            arr1[k+n]= arr2[k];
        }
    }
int main()
{
    int n,m;
    cin >> n>>m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    for (int i = 0; i < n; i++){
        cin >> arr1[i];
        cin>>arr2[i];
    }
    solve(arr1,arr2,n,m);
    cout << "the ele is " <<  endl;
}