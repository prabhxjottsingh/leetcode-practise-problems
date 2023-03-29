//time Complexity: O(2 ^ n)
//space Complexity: O(2 ^ n)

class Solution {
private:
    int stringToInt(string x){
        int n = x.size();
        int rVal = 0;
        for(int i = 0; i < n; i++){
            if( x[i] == '1' )
                rVal += 1 << i;
        }
        return rVal;
    }

    vector<string> generateGrayCode(int n){
        if( n == 0 )
            return {};
        if( n == 1 )
            return {"0", "1"};
        vector<string> rArr;
        vector<string> arr = generateGrayCode(n - 1);
        int x = arr.size();
        for(int i = 0; i < x; i++)
            rArr.push_back("0" + arr[i]);
        for(int i = x - 1; i > -1; i--)
            rArr.push_back("1" + arr[i]);
        return rArr;
    }

public:
    vector<int> grayCode(int n) {
        vector<int> arr;
        for(auto &a : generateGrayCode(n))
            arr.push_back(stringToInt(a));
        return arr;
    }
};
