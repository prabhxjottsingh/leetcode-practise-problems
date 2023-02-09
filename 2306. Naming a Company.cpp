
//time Complexity: O(n * 26 * log N + 26 * 26)
//sc: O(N)
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long count = 0;
        int dict[26][26];
        memset(dict, 0,sizeof(dict));
        unordered_set<string> st;
        for(auto &a : ideas)
            st.insert(a);
        for(auto &a : ideas){
            char cha = a[0];
            string tStr = a.substr(1);
            for(char ch = 'a'; ch <= 'z'; ch++){
                string nStr = ch + tStr;
                if( !st.count(nStr) )
                    dict[cha - 'a'][ch - 'a'] += 1;
            }
        }
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                if( i == j ) continue;
                count += dict[i][j] * dict[j][i];
            }
        }
        return count;
    }
};

//another Sol:
//tc: O(N * 10)
//sc: O(n)

class Solution {
private:
        class Node{
    public:
        Node* links[26];
        bool endNode = false;

        Node(){
            for(int i = 0; i < 26; i++)
                links[i] = NULL;
            endNode = false;
        }

    };

    class Trie{

    public:
        Node* root;

        Trie(){
            root = new Node();
        }

        void init(string &word){
            Node* tRoot = root;
            for(auto &a : word){
                int val = a - 'a';
                if( !tRoot->links[val] )
                    tRoot->links[val] = new Node();
                tRoot = tRoot->links[val];
            }
            tRoot->endNode = true;
        }

        bool compare(char one, int idx, string str){
            if( !root->links[one - 'a'] ) return 1;
            Node* tRoot = root->links[one - 'a'];
            while( idx < str.size() ){
                if( !tRoot->links[str[idx] - 'a'] ) return 1;
                tRoot = tRoot->links[str[idx] - 'a'];
                idx++;
            }
            return !tRoot->endNode;
        }

    };
public:
    long long distinctNames(vector<string>& ideas) {
        long long count = 0;
        int dict[26][26];
        memset(dict, 0,sizeof(dict));
        Trie tr;
        for(auto &a : ideas)
            tr.init(a);
        for(auto &a : ideas){
            for(char ch = 'a'; ch <= 'z'; ch++){
                if( ch == a[0] ) continue;
                if( tr.compare(ch, 1, a) ){
                    dict[a[0] - 'a'][ch - 'a'] += 1;
                }
            }
        }
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                if( i == j ) continue;
                count += dict[i][j] * dict[j][i];
            }
        }
        return count;
    }
};
