#include<bits/stdc++.h>
using namespace std;
class Longest{
    public:
    int consecutive(vector<int> &arr){
        set<int> hashSet;
        for(int i : arr){
            hashSet.insert(i);
        }
            int length =0;
        for(auto i : arr){
            if(!hashSet.count(i-1)){
                int currenti = i;
            int currlength = 1;
            while(hashSet.count(currenti+1)){
                currenti++;
                currlength++;
            }
            length = max(length,currlength);
        }
        }
    return length;
    }
    int withSum0(vector<int> &Arr ){
        int sum =0;
        int maxi =0;
        unordered_map<int,int> mpp;
        for(int i=0;i < Arr.size();i++){
            sum += Arr[i];
            if(sum == 0){
                maxi = i+1;
            }else{
            if(mpp.find(sum) != mpp.end()){
                maxi = max(maxi , i - mpp[sum]);
            }else{
                mpp[sum] = i;
            }
            }
        }
        return maxi;
    }
};

int main(){
    Longest obj;
    vector<int> arr;
    arr = {9, -3, 3, -1, 6, -5};
    //int length = obj.consecutive(arr);
    int length = obj.withSum0(arr);
    cout<<length;
}