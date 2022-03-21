// Problem Link: https://leetcode.com/problems/count-collisions-on-a-road/

// Time Complexity: O(N)
// Space Complexity: O(N)

/*
Explanation: Cars collide only if "LR", "RS" and "SL", once a pair of car collide they become "S", this can easily be solved by Stack.
*/

class Solution
{
public:
    int countCollisions(string directions)
    {
        int n = directions.size(), collisions = 0;
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                st.push(directions[i]);
            }
            else
            {
                char dir = directions[i];
                while (!st.empty() && ((st.top() == 'R' && dir == 'L') || (dir == 'L' && st.top() == 'S') || (st.top() == 'R' && dir == 'S')))
                {
                    if (st.top() == 'R' && dir == 'L')
                        collisions += 2;
                    else
                        collisions++;
                    st.pop();
                    dir = 'S';
                }
                st.push(dir);
            }
        }
        return collisions;
    }
};