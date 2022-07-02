#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
    int A1 ;
    cin>>A1;
    int A2 ;
    cin>>A2;
    int A3 ;
    cin>>A3;
    int A4 ;
    cin>>A4;
    int A5 ;
    cin>>A5;
    int B1 ;
    cin>>B1;
    int B2 ;
    cin>>B2;
    int B3 ;
    cin>>B3;
    int B4 ;
    cin>>B4;
    int B5 ;
    cin>>B5;
    int perKM1 = (((A2/A1)*A4)+A5+A3)*60;
    int perKM2 = (((B2/B1)*B4)+B5+B3)*60;
    if(perKM1 < perKM2){
        cout<<"petrol"<<endl;
    }else{
        cout<<"diesel"<<endl;
    }
}
}