//Tags: String
//Difficulty: Easy
//Problem Link: https://leetcode.com/problems/defanging-an-ip-address/
//Time Complexity: O(n)   (time complexity of push_back function is O(1))

//Solution (I thought)

class Solution
{
public:
    string defangIPaddr(string address)
    {
        string defangedIPaddr = "";
        int n = address.length();
        for (int i = 0; i < n; i++)
        {
            if (address[i] == '.')
            {
                defangedIPaddr.push_back('[');
                defangedIPaddr.push_back('.');
                defangedIPaddr.push_back(']');
            }
            else
                defangedIPaddr.push_back(address[i]);
        }
        return defangedIPaddr;
    }
};

//Reasons to use push_back rather than += operator:
// Source Stackoverflow:https://stackoverflow.com/questions/15082170/c-stdstring-append-vs-push-back
// I had the same doubt, so I made a small test to check this (g++ 4.8.5 with C++11 profile on Linux, Intel, 64 bit under VmWare Fusion).
// push :19
// append :21
// += :34
// Could be possible this is because of the string length (big), but the operator + is very expensive compared with the push_back and the append.