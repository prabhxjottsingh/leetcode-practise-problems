//Problem Link: https://leetcode.com/problems/product-of-the-last-k-numbers/
//Time Complexity: O(1) -> Constant
//Space Complexity: O(n) -> vector

class ProductOfNumbers
{
private:
    vector<int> v = {1};

public:
    ProductOfNumbers()
    {
        vector<int> v;
    }

    void add(int num)
    {
        if (num == 0)
            v = {1};
        else
            v.push_back(v.back() * num);
    }

    int getProduct(int k)
    {
        if (k >= v.size())
            return 0;
        return (v.back() / v[v.size() - 1 - k]);
    }
};
