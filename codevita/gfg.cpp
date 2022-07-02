#include <bits/stdc++.h>
using namespace std;

int isGCD(int a,int b){
    return b==0?a:isGCD(b,a%b);
}
int main() {
	/*int t;
    cin>>t;
	while(t-- ){*/
	    int n;
	    cin>>n;
	    int count=0;
	    vector<int > v;
	    for(int i=0;i<=n;i++){
	        int ans =0;
	        int mul=1;
	        while(i>0){
	            int dev = i/10;
	            int rem = i - dev*10;
	            i=dev;
	            ans+=rem*rem*rem*rem;
	            mul*=rem;
	        }
	        int gdc=isGCD(ans,mul);
	        if(gdc >1){
	            count++;
	        v.push_back(i);
	        }
	    }
	    //cout<<count<<endl;
	    for(int i=0;i<v.size();i++){
	        cout<<v[i]<<endl;
	    //}
	}
	return 0;
}