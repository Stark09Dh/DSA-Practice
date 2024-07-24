#include <bits/stdc++.h>

using namespace std;

vector<string> sortPeople(vector<string> &names, vector<int> &heights)
{
    vector<string> res;

    map<int, string> mp;

    for (int i = 0; i < names.size(); i++)
    {
        mp[heights[i]] = names[i];
    }

    for (auto it : mp)
    {
        res.push_back(it.second);
    }
    reverse(res.begin(), res.end());
    return res;
}
int main()
{

    vector<string> names = {"Alice", "Bob", "Bum"};
    vector<int> heights = {155, 185, 150};
    vector<string> ans = sortPeople(names, heights);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}