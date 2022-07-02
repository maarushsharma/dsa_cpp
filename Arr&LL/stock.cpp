//best time to sell stock 

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int mini =INT_MAX;
    int maxi=0;
    for(int i=0;i<n;i++){
        mini = min(mini, v[i]);
        maxi = max(maxi ,v[i]-mini);
    }

    cout<<maxi<<endl;
}