class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int count = 0;
        vector<int> idxChar[26];
        for (int i = 0; i < (int)s.size(); i++)
        {
            idxChar[s[i] - 'a'].push_back(i);
        }
        for (auto &word : words)
        {
            int lastPos = -1;
            bool notFound = false;
            char prevChar = '?';
            for (auto &ch : word)
            {
                if (prevChar == ch)
                    lastPos++;
                vector<int> &vec = idxChar[ch - 'a'];
                auto itr = lower_bound(vec.begin(), vec.end(), lastPos);
                if (itr == vec.end())
                {
                    notFound = true;
                    break;
                }
                else
                {
                    lastPos = *itr;
                }
                prevChar = ch;
            }
            if (!notFound)
                count++;
        }
        return count;
    }
};