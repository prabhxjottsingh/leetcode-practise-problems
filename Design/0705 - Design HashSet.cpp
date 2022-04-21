// Problem Link: https://leetcode.com/problems/design-hashset/

class MyHashSet
{
private:
    bool arr[1000001] = {0};

public:
    MyHashSet()
    {
    }

    void add(int key)
    {
        arr[key] = 1;
    }

    void remove(int key)
    {
        arr[key] = 0;
    }

    bool contains(int key)
    {
        if (arr[key] == 0)
            return false;
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */