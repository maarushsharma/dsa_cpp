#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<vector<int>> fourSum(vector<int> &num,int target){
        vector<vector<int>> res;
        if(num.empty()) return res;
        
        sort(num.begin() , num.end());
        int n =num.size();
        for(int i=0; i<n;i++){
            int target_3 = target -num[i];
            for(int j=i+1;j<n;j++){
                int target_2 = target_3 - num[j];
                int front =j +1;
                int back = n-1;
                while (front < back)
                {
                    int two_sum = num[front] + num[back];
                    if(two_sum < target_2) front++;
                    else if(two_sum > target_2) back--;
                    else{
                        vector<int> quadraple(4,0);
                        quadraple[0] = num[i];
                        quadraple[1] =num[j];
                        quadraple[2] =num[front];
                        quadraple[3] =num[back];
                        res.push_back(quadraple);

                        //rest processinr duplicate
                        while(front < back and num[front] == quadraple[2]) ++front;
                        while(front < back and num[back] == quadraple[3]) --back;
                    }
                }
                while(j+1 < n and num[j] == num[j+1]) ++j;
            }
            while(i+1<n and num[i+1] == num[i]) ++i;
        }
        return res;
    }
};
int main()
{
    Solution obj;
    vector<int> v{0};
    
    vector<vector<int>> sum=obj.fourSum(v,0);
    cout<<"The unique quadrapleruplets are"<<endl;
    for (int i = 0; i < sum.size(); i++) {
        for (int j = 0; j < sum[i].size(); j++)
            cout << sum[i][j] << " ";
        cout << endl;
    }
}