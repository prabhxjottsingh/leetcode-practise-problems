// Problem Link: https://leetcode.com/problems/encode-and-decode-tinyurl/

class Solution
{
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return shortUrl;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

// Using HashMaps
class Solution
{
private:
    map<string, string> mp;
    int n = 0;
    string intToString(int n)
    {
        string res;
        while (n > 0)
        {
            res.push_back((n % 10) + '0');
            n /= 10;
        }
        return res;
    }

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        string res = "httlps://www.tinyurl.com" + intToString(n);
        n++;
        mp[res] = longUrl;
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        string res = mp[shortUrl];
        return res;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));