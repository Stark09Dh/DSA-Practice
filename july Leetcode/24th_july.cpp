#include <bits/stdc++.h>

using namespace std;

vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
{
    int n = nums.size();
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        int number = nums[i];
        int transformed = 0;
        int multiplier = 1;
        if (number == 0)
        {
            transformed = mapping[0];
        }
        else
        {
            while (number)
            {
                int digit = number % 10;
                transformed = transformed + mapping[digit] * multiplier;
                multiplier *= 10;
                number /= 10;
            }
        }
        temp.push_back(transformed);
    }

    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]] = temp[i];
    }

    auto lambda = [&](int &a, int &b)
    {
        return mp[a] < mp[b];
    };

    sort(nums.begin(), nums.end(), lambda);

    return nums;
}

int main()
{

    vector<int> mapping = {
        8,
        9,
        4,
        0,
        2,
        1,
        3,
        5,
        7,
    };
    vector<int> nums = {991, 338, 38};

    vector<int> ans = sortJumbled(mapping, nums);


    for (int &it : ans)
    {
        cout << it << " ";
    }
    return 0;
}