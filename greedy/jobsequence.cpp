#include<bits/stdc++.h>
using namespace std;
struct Job {
   int id; // Job Id 
   int dead; // Deadline of job 
   int profit; // Profit if job is over before or on deadline 
};
class Solution{
    public:
    bool static comp(Job a ,Job b){
        return (a.profit> b.profit);
    }
    pair<int,int> JobScheduling(Job arr[] , int n ){
        sort(arr,arr+n,comp);
        int maxi = arr[0].dead;
        for(int i=1;i<n;i++){
            maxi= max(maxi,arr[i].dead);
        }

        int slot[maxi];
        for(int i=0;i<=maxi;i++) slot[i] = -1;
        int count =0 ,cprofit=0;
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                if(slot[j] == -1){
                    slot[j] =i;
                    count++;
                    cprofit+=arr[i].profit;
                    break;
                }
            }
        }
        return {cprofit,count};
    }
};
int main(){
    int n = 4;
   Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

   Solution ob;
   //function call
   pair < int, int > ans = ob.JobScheduling(arr, n);
   cout << ans.first << " " << ans.second << endl;

   return 0;
}