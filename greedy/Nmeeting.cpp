#include<bits/stdc++.h>
using  namespace std;

struct meeting{
    int start;
    int end;
    int pos;

};
class solution{
    public :

    bool static comp( struct meeting a,struct meeting b){
        if(a.end < b.end) return true;
        else if(a.end > b.end) return false;
        else if(a.pos < b.pos) return true;
        return false; 
    }

    vector<int> maxMeetings(int s[] , int e[],int n){
        struct meeting meet[n];
        for(int i=0;i<n;i++){
            meet[i].start = s[i];
            meet[i].end = e[i];
            meet[i].pos = i;
        }

        sort(meet,meet+n,comp);

        vector<int> answer;
        int limit = meet[0].end;
        answer.push_back(meet[0].pos);

        for(int i=1;i<n;i++){
            if(meet[i].start >limit){
                limit= meet[i].end;
                answer.push_back(meet[i].pos);
            } 
        }
        return answer;

    }

};int main(){
    solution obj;
   int n = 6;
   int start[] = {1,3,0,5,8,5};
   int end[] = {2,4,5,7,9,9};
   vector<int> answer= obj.maxMeetings(start, end, n);
   cout<<"The order in which the meetings will be performed is "<<endl;
    for(int i=0;i<answer.size();i++){
         cout<<answer[i]<<endl;
    }
   return 0;
}
