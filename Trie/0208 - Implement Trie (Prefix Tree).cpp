struct Node
{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        if (links[ch - 'a'] != NULL)
            return true;
        return false;
    }

    void putsKey(char ch, Node *node)
    {
        node->links[ch - 'a'] = new Node();
    }

    Node *gets(char ch)
    {
        return links[ch - 'a'];
    }

    void putsEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *curr = root;
        for (auto &ch : word)
        {
            if (!curr->containsKey(ch))
                curr->putsKey(ch, curr);
            curr = curr->gets(ch);
        }
        curr->putsEnd();
    }

    bool search(string word)
    {
        Node *curr = root;
        for (auto ch : word)
        {
            if (!curr->containsKey(ch))
                return false;
            curr = curr->gets(ch);
        }
        return curr->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *curr = root;
        for (auto &ch : prefix)
        {
            if (!curr->containsKey(ch))
                return false;
            curr = curr->gets(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */