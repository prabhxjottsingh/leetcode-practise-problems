// problem Link: https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

//Dont remember what I did in contest but fs it was too much depressing :)

class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        int n = tasks.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[tasks[i]]++;
        }
        int count = 0;
        for (auto &a : mp)
        {
            if (a.second >= 2 || a.second >= 3)
            {
                if (a.second % 3 == 0)
                {
                    count += (a.second / 3);
                    a.second = 0;
                }
                else if (a.second % 2 == 0)
                {
                    while (a.second % 3 != 0 && a.second > 0)
                    {
                        count++;
                        a.second -= 2;
                    }
                    if (a.second != 0 && a.second % 3 == 0)
                    {
                        count += a.second / 3;
                    }
                }
                else if (a.second > 1)
                {
                    while (a.second > 3 || a.second > 2)
                    {
                        if (a.second % 3 != 0)
                        {
                            a.second -= 2;
                            count++;
                        }
                        else
                        {
                            count += a.second / 3;
                            a.second = 0;
                        }
                    }
                }
            }
            if (a.second < 2 && a.second != 0)
            {
                return -1;
            }
        }
        return count;
    }
};