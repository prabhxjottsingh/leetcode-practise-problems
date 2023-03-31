//time Complexity: O(n)
//space Complexity: O(1)

class StockSpanner {
private:
    stack<pair<int, int>> st;

public:
    StockSpanner() {

    }

    int next(int price) {
        int cnt = 1;
        while( !st.empty() && st.top().first <= price ){
            cnt += st.top().second;
            st.pop();
        }
        st.push({price, cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
