#include<bits/stdc++.h>
using namespace std;

bool tab[2000][2000];
bool subsetSum(int a[],int n, int sum){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++)
        {
            if(i == 0) tab[i][j]=false;
            if(j == 0) tab[i][j]=true;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++)
        {
            if(a[i-1] <= j){
                tab[i][j] = tab[i][j-a[i-1]] || tab[i-1][j];
            }else{
                tab[i][j] = tab[i-1][j];
            }
        }
    }
    return tab[n][sum];
}
int main()
{
    // Storing the value -1 to the matrix
    memset(tab, -1, sizeof(tab));
    int n = 5;
    int a[] = {1, 5, 3, 7, 4};
    int sum = 12;
 
    if (subsetSum(a, n, sum))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
   
    /* This Code is Contributed by Ankit Kumar*/
}