#include <bits/stdc++.h>

using namespace std;

bool comp(const pair<int, vector<int>> &a, const pair<int, vector<int>> &b)
{
    if (a.second.size() == b.second.size())
    {
        return a.first < b.first; // If sizes are equal, sort by key in descending order
    }
    return a.second.size() > b.second.size(); // Otherwise, sort by vector size
}

vector<int> frequencySort(vector<int> &nums)
{

    unordered_map<int, vector<int>> mp;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        mp[nums[i]].push_back(nums[i]);
    }

    vector<int> ans;
    vector<pair<int, vector<int>>> vec(mp.begin(), mp.end());

    // Sort the vector with a custom comparator
    sort(vec.begin(), vec.end(), comp);

    for (const auto &it : vec)
    {
        int size = it.second.size();
        for (int i = 0; i < size; i++)
        {
            ans.push_back(it.second[i]);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{

    vector<int> nums = {1, 1, 2, 2, 2, 3};
    vector<int> ans = frequencySort(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}

// Input: nums = [1,1,2,2,2,3]
// Output: [3,1,1,2,2,2]
// Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
// Example 2:

// Input: nums = [2,3,1,3,2]
// Output: [1,3,3,2,2]
// Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.