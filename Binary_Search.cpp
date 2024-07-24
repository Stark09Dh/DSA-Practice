#include <bits/stdc++.h>

using namespace std;

int binary_search(vector<int> &arr, int l, int r, int element)
{
    if (l > r)
        return l;
    int middle = l + (r - l) / 2;

    if (arr[middle] == element)
        return middle;

    else if (arr[middle] > element)
    {
        return binary_search(arr, l, middle - 1, element);
    }
    else
    {
        return binary_search(arr, middle + 1, r, element);
    }
}

int main()
{

    vector<int> arr = {2, 3, 4, 5, 6, 7, 12, 34, 45, 67, 78};
    int element = 12;
    int l = 0, r = arr.size() - 1;

    int present = binary_search(arr, l, r, element);
    cout << present;
    return 0;
}