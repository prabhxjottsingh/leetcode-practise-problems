// Not Complete Code
#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        isTerminal = false;
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

    void insertUtil(TrieNode *root, string word)
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
            root->children[idx] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insertNewWord(string word)
    {
        insertUtil(root, word);
    }

    vector<vector<string>> getSuggestionList(string &s)
    {
        TrieNode *prev = root;
        vector<vector<string>> out;
        string prefix = "";
        for (auto &a : s)
        {
            char lastCh = a;
            prefix.push_back(lastCh);
            TrieNode *curr = prev->children[lastCh - 'a'];
            if (curr)
            {
                vector<string> temp;
                printSuggestion(curr, temp, prev);
                out.push_back(temp);
                prev = curr;
            }
            else
            {
                break;
            }
        }
        return out;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    Trie *tr;
    for (auto &a : contactList)
        tr->insertNewWord(a);
    return getSuggestionList(queryStr);
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<string> contactList(n);
        for (auto &a : contactList)
            cin >> a;
        string queryStr;
        cin >> queryStr;
        vector<vector<string>> resStr = phoneDirectory(contactList, queryStr);
        for (auto &a : resStr)
        {
            for (auto &b : a)
                cout << b << " ";
            cout << endl;
        }
        cout << endl;
    }
}
