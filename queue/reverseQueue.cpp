#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
    // queue<int> rev(queue<int> q)
    // {
    //     // without recurrsion
    //     // stack<int> s;
    //     // while(!q.empty()){
    //     //     s.push(q.front());
    //     //     q.pop();
    //     // }

    //     // while(!s.empty()){
    //     //     q.push(s.top());
    //     //     s.pop();
    //     // }
    //     // return q;

    //     // with recurrsion
    // }

    void reverseQueue(queue<int> &q)
    {
        // base case
        if (q.size() == 0)
            return;

        int fr = q.front();
        q.pop();

        reverseQueue(q);
        q.push(fr);
    }
    queue<int> rev(queue<int> q)
    {
        reverseQueue(q);
        return q; // add code here.
    }
};