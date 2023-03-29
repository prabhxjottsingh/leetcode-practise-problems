//time Complexity: O(n)
//space complexity: O(N)

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int _xor = 0;
        for(auto &a : nums)
            _xor ^= a;

        /*
        if _xor ki bit set hai, toh dono mein se kisi ek ki hi woh waali bit set hogi
        if _xor ki bit unset hai, toh dono ki bits same hongi,
        find all the numbers jinki bits set hongi unhe grpOne mein daaldo and unset diffBit waalo ko grpTwo
        find _xor of both the grps then, that is youor ans
        */
        int diffBit = 0;
        for(int i = 0; i < 31; i++){
            if( (_xor & (1 << i)) != 0 ){
                diffBit = i;
                break;
            }
        }
        vector<int> grpOne, grpTwo;
        for(auto &a : nums){
            if( (a & (1 << diffBit)) != 0 )
                grpOne.push_back(a);
            else
                grpTwo.push_back(a);
        }
        int one = 0, two = 0;
        for(auto &a : grpOne)
            one ^= a;
        for(auto &a : grpTwo)
            two ^= a;
        return {one, two};
    }
};

//spcae Complexity: O(1)

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int _xor = 0;
        for(auto &a : nums)
            _xor ^= a;
        int one = 0;
        int two = 0;
        int diffBit = 0;
        for(int i = 0; i < 31; i++){
            if( (_xor & (1 << i)) != 0 )
                diffBit = i;
        }
        for(auto &a : nums){
            if( (a & (1 << diffBit)) )
                one ^= a;
            else
                two ^= a;
        }
        return {one, two};
    }
};
