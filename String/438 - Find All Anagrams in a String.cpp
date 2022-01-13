//Using Sliding Window Approach

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        map<char, int> mps, mpp;
        int n = s.length(), m = p.length();
        vector<int> ans;
        for (int i = 0; i < m; i++)
            mpp[p[i]]++;
        for (int i = 0; i < m; i++)
            mps[s[i]]++;
        if (mps == mpp)
            ans.push_back(0);
        for (int i = m; i < n; i++)
        {
            if (mps[s[i - m]] == 1)
                mps.erase(s[i - m]);
            else
                mps[s[i - m]]--;
            mps[s[i]]++;
            // for(auto a:mps)
            //     cout << a.first << "=>" << a.second << "    ";
            // cout << endl;
            if (mps == mpp)
                ans.push_back(i - m + 1);
        }
        return ans;
    }
};