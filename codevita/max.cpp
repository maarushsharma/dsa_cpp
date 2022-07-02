#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:
    int largestRectangleArea(vector < int > & histo,int n,int l,int b) {
      stack < int > st;
      int maxA = 0;
      for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
          int height = histo[st.top()];
          st.pop();
          int width;
          if (st.empty())
            width = i;
          else
            width = i - st.top() - 1;
          maxA = max(maxA, width * height);
        }
        st.push(i);
      }
      int total=0;
      for(int i=0;i<n;i++){
          total+=histo[i];
      }
      return(total*l*b -  maxA*l*b);
    }
};
int main() {
    int n;
    cin>>n;
  vector < int > histo ;
for(int i=0;i<n;i++){
    cin>>histo[i];
}
int length , bredth;
cin>>length>>bredth;
  Solution obj;
  cout << obj.largestRectangleArea(histo,n,length,bredth) << endl;
  return 0;
}