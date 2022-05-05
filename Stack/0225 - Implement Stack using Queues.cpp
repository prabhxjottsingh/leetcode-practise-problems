// Problem Link: https://leetcode.com/problems/implement-stack-using-queues/

class MyStack
{
private:
    queue<int> queueFirst, queueSecond;

public:
    MyStack()
    {
        // Initalize both the queue with empty
    }

    void push(int x)
    {
        queueFirst.push(x);
    }

    int pop()
    {
        while (queueFirst.size() > 1)
        {
            queueSecond.push(queueFirst.front());
            queueFirst.pop();
        }
        int res = queueFirst.front();
        queueFirst.pop();
        while (!queueSecond.empty())
        {
            queueFirst.push(queueSecond.front());
            queueSecond.pop();
        }
        return res;
    }

    int top()
    {
        while (queueFirst.size() > 1)
        {
            queueSecond.push(queueFirst.front());
            queueFirst.pop();
        }
        int res = queueFirst.front();
        queueSecond.push(res);
        queueFirst.pop();
        while (!queueSecond.empty())
        {
            queueFirst.push(queueSecond.front());
            queueSecond.pop();
        }
        return res;
    }

    bool empty()
    {
        return queueFirst.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */