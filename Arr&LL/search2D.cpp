#include<bits/stdc++.h>
using namespace std;
bool search_mat(vector<vector<int>> &matrix,int ele){
    bool isfound = false;
    int low = 0;
    if(!matrix.size()) return isfound;
    int high =( matrix.size()*matrix[0].size()) - 1;
    while(low <= high){
        int mid = (low + (high - low)/2);
        if( matrix[mid/matrix[0].size()][mid % matrix[0].size()] == ele){
            isfound = 1;
        }else if( matrix[mid/matrix[0].size()][mid % matrix[0].size()] < ele ){
            low = mid+1;
        }else{
            high = mid - 1;
        }
    } 
    return isfound;
}
int main(){
    vector<vector<int>> matrix;
    int element;
    cin>>element;
    matrix = {{1,3,5,7,},{10,11,16,20},{23,30,34,60}};
    cout<<search_mat(matrix,element);
}