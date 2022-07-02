#include<bits/stdc++.h>
using namespace std;

struct Item {
   int value;
   int weight;
};
class Solution {
    public:
    bool static comp(Item a, Item b){
        double r1 = (double)a.value / (double)b.weight;
        double r2 = (double)b.value/(double)a.weight;
        return r1>r2;
    }
    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr , arr+n ,comp);
        int currWeight =0;
        double finalValue=0.0;
        for(int i=0;i<n;i++){
            if(currWeight + arr[i].weight <= W){
                currWeight+=arr[i].weight;
                finalValue+=arr[i].value;
            }else{
                int ram = W -currWeight;
                finalValue+= (arr[i].value/(double)arr[i].weight)*(double)ram;
                break;
            }
        }
        return finalValue;
    }
};
int main() {
   int n = 3, weight = 50;
   Item arr[n] = { {100,20},{60,10},{120,30} };
   Solution obj;
   double ans = obj.fractionalKnapsack(weight, arr, n);
   cout << "The maximum value is " << setprecision(2) << fixed << ans;
   return 0;
}