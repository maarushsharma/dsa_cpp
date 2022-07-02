#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int N,X;
	    cin>>N>>X;
	    int arr[N];
	    for(int i=0;i<N;i++){
	        cin>>arr[i];
	    }
	    int count=0;
	    int maxi = INT_MAX;
	    for(int j=0;j<N;j++){
	        
	            
	        if(arr[j] <= X ){
	            count=j-1;
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}