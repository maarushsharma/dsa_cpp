#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &Arr){
    int n = Arr.size();
    for(int i=0;i<n;i++){//inverse
        for(int j=0;j<i;j++){
            swap(Arr[i][j],Arr[j][i]);
        }
    }
    for(int i=0;i<n;i++){//reverse
        reverse(Arr[i].begin() ,Arr[i].end());
    }
}
int main(){
    vector<vector<int>> Arr;
    Arr = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(Arr);

    cout<<"Rotated Image"<<endl;
    
    for(int i=0;i<Arr.size();i++){
        for(int j=0;j<Arr[0].size();j++){
            cout<<Arr[i][j]<<" ";
        }
        cout<<endl;
    }
}