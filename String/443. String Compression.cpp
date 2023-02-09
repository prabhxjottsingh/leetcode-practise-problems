//tc: O(n)
//sc: O(1)

class Solution {
private:
    void swapFunc(vector<char> &nums, int i, int j){
        if( j <= i ) return;
        std::swap(nums[i], nums[j]);
        swapFunc(nums, i + 1, j - 1);
    }

public:
    int compress(vector<char>& chars) {
        char prev = chars[0];
        int idx = 1;
        int n = chars.size();
        if( n == 1 ) return 1;
        int currCount = 1;
        for(int i = 1; i < n; i++){
            if( chars[i] == prev ){
                currCount += 1;
            }
            else{
                if( currCount == 1 ){
                    chars[idx] = chars[i];
                    idx += 1;
                    prev = chars[i];
                    currCount = 1;
                    continue;
                }
                int start = idx;
                int end = idx;
                while( currCount ){
                    chars[idx] = (currCount % 10) + '0';
                    currCount /= 10;
                    idx += 1;
                    end++;
                }
                swapFunc(chars, start, end - 1);
                currCount = 1;
                chars[idx] = chars[i];
                idx += 1;
            }
            prev = chars[i];
        }
        if( currCount == 1 ){
            chars[idx] = chars[n - 1];
            return idx;
        }
        int start = idx;
        int end = idx;

        //tc: O(4)
        while( currCount ){
            chars[idx] = (currCount % 10) + '0';
            currCount /= 10;
            idx += 1;
            end++;
        }

        //tc: O(k) , k = integer length, max(k) = 4
        swapFunc(chars, start, end - 1);
        return idx;
    }
};
