// Problem Link: https://leetcode.com/problems/design-underground-system/

class UndergroundSystem
{
private:
    map<pair<string, string>, vector<int>> avgTime;
    map<int, string> checkInStation;
    map<int, int> checkInTime;

    double avgTimeCalcFunction(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];
        double res = (sum * 1.0) / n;
        return res;
    }

public:
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        checkInStation[id] = stationName;
        checkInTime[id] = t;
    }

    void checkOut(int id, string stationName, int t)
    {
        avgTime[{checkInStation[id], stationName}].push_back(t - checkInTime[id]);
        checkInStation.erase(id);
        checkInTime.erase(id);
    }

    double getAverageTime(string startStation, string endStation)
    {
        int totalVal = avgTime[{startStation, endStation}].size();
        vector<int> nums = avgTime[{startStation, endStation}];
        double finalAvgTime = avgTimeCalcFunction(nums);
        return finalAvgTime;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */