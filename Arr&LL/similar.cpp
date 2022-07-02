#include <bits/stdc++.h>
using namespace std;
int solve(int arr[], int n)
{
    int slow = arr[0];
    int fast = arr[0];
    // if while(slow != fast ) loop nerver execute
    // then do while for fisrt time
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    fast = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "the ele is " << solve(arr,n) << endl;
}