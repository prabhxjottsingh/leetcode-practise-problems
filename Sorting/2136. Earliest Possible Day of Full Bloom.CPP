// Problem Link: https://leetcode.com/problems/earliest-possible-day-of-full-bloom/

// Time Complexity: O(N * log N)
// Space Complextiy: O(N)

class Flower{
public:
    int plntTime;
    int grwTime;
        
    Flower(int plntTime, int grwTime){
        this->plntTime = plntTime;
        this->grwTime = grwTime;
    }
};

class Solution {
private:
    static bool comp(const Flower &a, const Flower &b){
        return a.grwTime > b.grwTime;
    }
    
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<Flower> vec;
        for(int i = 0; i < n; i++)
            vec.push_back(Flower(plantTime[i], growTime[i]));
        sort(vec.begin(), vec.end(), comp);
        int currTime = 0;
        int maxTime = 0;
        for(int i = 0; i < n; i++){
            currTime += vec[i].plntTime;
            int bloomTime = currTime + vec[i].grwTime;
            maxTime = max(maxTime, bloomTime);
        }
        return maxTime;
    }
};