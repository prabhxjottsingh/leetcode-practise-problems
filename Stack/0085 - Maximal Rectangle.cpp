class Solution
{
private:
    vector<int> prevSmallerElem(vector<int> &v)
    {
        stack<int> st;
        vector<int> res;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                res.push_back(-1);
            }
            else
            {
                while (!st.empty() && v[st.top()] >= v[i])
                    st.pop();

                if (st.empty())
                    res.push_back(-1);
                else
                    res.push_back(st.top());
            }
            st.push(i);
        }
        return res;
    }

    vector<int> nextSmallerElem(vector<int> &v)
    {
        stack<int> st;
        vector<int> res;
        int n = v.size();
        for (int i = n - 1; i > -1; i--)
        {
            if (st.empty())
                res.push_back(n);
            else
            {
                while (!st.empty() && v[st.top()] >= v[i])
                    st.pop();

                if (st.empty())
                    res.push_back(n);
                else
                    res.push_back(st.top());
            }
            st.push(i);
        }
        reverse(res.begin(), res.end());
        return res;
    }

    int helperFunc(vector<int> &v)
    {
        vector<int> prevSmaller = prevSmallerElem(v);
        vector<int> nextSmaller = nextSmallerElem(v);
        int maxArea = 0;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            int height = v[i];
            int width = nextSmaller[i] - prevSmaller[i] - 1;
            int area = height * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        vector<int> heights(m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            maxArea = max(maxArea, helperFunc(heights));
        }
        return maxArea;
    }
};