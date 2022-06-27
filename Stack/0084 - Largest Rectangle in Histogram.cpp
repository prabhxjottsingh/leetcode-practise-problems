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

public:
    int largestRectangleArea(vector<int> &v)
    {
        vector<int> prevSmaller = prevSmallerElem(v);
        vector<int> nextSmaller = nextSmallerElem(v);
        int n = v.size();
        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            int height = v[i];
            int width = nextSmaller[i] - prevSmaller[i] - 1;
            int area = height * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};