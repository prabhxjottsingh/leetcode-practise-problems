//tc: O(n * n)
//sc: O(n)

class DSUst{
public:
    vector<int> par;
    DSUst(int n){
        par.resize(n);
        for(int i = 0; i < n; i++) par[i] = i;
    }
    int findPar(int n){
        return ((n == par[n]) ? n : (par[n] = findPar(par[n])));
    }
    void merge(int a, int b){
        a = findPar(a), b = findPar(b);
        if( a == b ) return;
        par[a] = b;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        set<int> sets;
        for(auto &a : edges){
            sets.insert(a[0]);
            sets.insert(a[1]);
        }
        for(int i = n - 1; i > -1; i--){
            DSUst st(1001);

            for(int j = n - 1; j > -1; j--){
                if( i == j ) continue;
                int a = edges[j][0];
                int b = edges[j][1];
                if( st.findPar(a) == st.findPar(b) ) continue;
                st.merge(a, b);
            }
            int leader = st.findPar(*sets.begin());
            bool flag = 1;
            for(auto &a : sets)
                flag &= (st.findPar(a) == leader);
            if( flag ) return {edges[i][0], edges[i][1]};
        }
        return {};
    }
};

//tc: O(n)
//sc: O(n)
class DSUst{
public:
    vector<int> par;
    DSUst(int n){
        par.resize(n);
        for(int i = 0; i < n; i++) par[i] = i;
    }
    int findPar(int n){
        return ((n == par[n]) ? n : (par[n] = findPar(par[n])));
    }
    void merge(int a, int b){
        a = findPar(a), b = findPar(b);
        if( a == b ) return;
        par[a] = b;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSUst st(1001);
        for(int i = 0; i < n; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            if( st.findPar(a) == st.findPar(b) ) return {a, b};
            st.merge(a, b);
        }
        return {};
    }
};
