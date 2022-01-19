//Tags: Medium, Design
//Problem Link: https://leetcode.com/problems/seat-reservation-manager/
//Time Complexity: O(n)
//Space Complexity: O(n)

class SeatManager
{
private:
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    SeatManager(int n)
    {
        for (int i = 0; i < n; i++)
            pq.push(i + 1);
    }

    int reserve()
    {
        int x = pq.top();
        pq.pop();
        return x;
    }

    void unreserve(int seatNumber)
    {
        pq.push(seatNumber);
    }
};
