class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        isTerminal = false;
        childCount = 0;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertString(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int idx = word[0] - 'a';
        TrieNode *child;
        if (root->children[idx] != NULL)
            child = root->children[idx];
        else
        {
            child = new TrieNode(word[0]);
            root->childCount += 1;
            root->children[idx] = child;
        }
        insertString(child, word.substr(1));
    }

    void insertNewString(string str)
    {
        insertString(root, str);
    }

    string returnString(string str)
    {
        string resStr;
        int n = str.size();
        for (int i = 0; i < n && root->childCount == 1; i++)
        {
            if (root->isTerminal)
                break;
            resStr += str[i];
            int idx = str[i] - 'a';
            root = root->children[idx];
        }
        return resStr;
    }
};

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        Trie *tr = new Trie;
        for (auto &a : strs)
            tr->insertNewString(a);
        string resStr = "";
        resStr = tr->returnString(strs[0]);
        return resStr;
    }
};