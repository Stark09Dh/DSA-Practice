#include <bits/stdc++.h>

using namespace std;

// using Lower bound and upper bound
pair<int, int> solve(vector<int> &arr, int n, int k)
{
    int lb = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
    if (lb == n || lb == -1)
        return {-1, -1};
    int ub = upper_bound(arr.begin(), arr.end(), k) - arr.begin();

    return {lb, ub - 1};
}

int firstOccurence(vector<int> &arr, int n, int k)
{
    int low = 0, high = n - 1, first = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == k)
        {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] > k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return first;
}

int lastOccurence(vector<int> &arr, int n, int k)
{
    int low = 0, high = n - 1, last = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == k)
        {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] > k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return last;
}

int main()
{

    vector<int> arr = {2, 4, 5, 6, 8, 8, 8, 8, 11, 13};
    int k = 11;
    int first = firstOccurence(arr, arr.size(), k);
    cout << first;
    int last = lastOccurence(arr, arr.size(), k);
    cout << last;
    // pair<int,int> ans = solve(arr,arr.size(),k);
    // cout << "{" << ans.first <<" "<< ans.second <<"}" ;
    return 0;
}