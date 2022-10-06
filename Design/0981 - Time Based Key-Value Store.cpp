// Problem Link: https://leetcode.com/problems/time-based-key-value-store/

// Time Complexity: O(N * log N)
// Space Complexity: O(N * log N)

class TimeMap
{
private:
    map<string, set<int>> timeStampSet;
    map<string, map<int, string>> hsh;

public:
    TimeMap()
    {
        
    }

    void set(string key, string value, int timestamp)
    {
        timeStampSet[key].insert(timestamp);
        hsh[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        std::set<int> &st = timeStampSet[key];
        auto itr = st.lower_bound(timestamp);
        if (itr == st.end() || *itr != timestamp)
        {
            if (itr == st.begin())
                return "";
            itr--;
        }
        string resStr = hsh[key][*itr];
        return resStr;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */