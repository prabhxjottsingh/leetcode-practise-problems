//tc: O(N * M)
//sc: O(n * M)

class Solution {
private:
private:
        class Node{
        public:
            Node* next[26];
            bool isEnd;

            Node(){
                for(int i = 0; i < 26; i++)
                    next[i] = NULL;
                isEnd = false;
            }
        };

        class Trie{
        public:

            Node* root;

            Trie(){
                root = new Node();
            }

            void init(string word){
                Node* tRoot = root;
                for(auto &a : word){
                    if( tRoot->next[a - 'a'] == NULL )
                        tRoot->next[a - 'a'] = new Node();

                    tRoot = tRoot->next[a - 'a'];
                }
                tRoot->isEnd = true;
            }


        };

        vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        bool isSafe(int i, int j, int n, int m){
            if( i < 0 || i >= n ) return 0;
            if( j < 0 || j >= m ) return 0;
            return 1;
        }

        void func(int i, int j, string &tStr, vector<vector<char>> &board, vector<string> &resVec, Node* curr, vector<vector<bool>> &isVis){
            isVis[i][j] = 1;
            int n = board.size();
            int  m = board[0].size();
            if( curr->isEnd ){
                resVec.push_back(tStr);
                curr->isEnd = false;
            }
            for(auto &a : moves){
                int ni = i + a.first;
                int nj = j + a.second;
                if( isSafe(ni, nj, n, m) && !isVis[ni][nj] ){
                    char &ch = board[ni][nj];
                    if( curr->next[ch - 'a'] ){
                        tStr.push_back(ch);
                        func(ni, nj, tStr, board, resVec, curr->next[ch - 'a'], isVis);
                        tStr.pop_back();
                    }
                }
            }
            isVis[i][j] = 0;
        }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            Trie tr;
            for(auto &a : words)
                tr.init(a);
            vector<string> resVec;
            Node* curr = tr.root;
            int n = board.size();
            int m = board[0].size();
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    vector<vector<bool>> isVis(n, vector<bool> (m, 0));
                    if( curr->next[board[i][j] - 'a'] ){
                        string tStr = "";
                        tStr += board[i][j];
                        func(i, j, tStr, board, resVec, curr->next[(board[i][j]) - 'a'], isVis);
                    }
                }
            }
            return resVec;
        }
};
