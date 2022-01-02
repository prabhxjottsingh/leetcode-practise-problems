//Tags: Medium
//Problem Link: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
//Time Complexity: O(n*m)

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int prevBeam = 0, newBeam = 0, n = bank.size(), totalBeam = 0;
        for (int i = 0; i < n; i++)
        {
            newBeam = 0;
            int m = bank[i].size();
            for (int j = 0; j < m; j++)
            {
                if (bank[i][j] == '1')
                    newBeam++;
            }
            if (newBeam == 0)
                continue;
            totalBeam += (prevBeam * newBeam);
            prevBeam = newBeam;
        }
        return totalBeam;
    }
};