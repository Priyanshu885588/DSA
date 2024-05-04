#include <bits/stdc++.h>
#include <stack>
using namespace std;
void sortedInsert(stack<int> &st, int num)
{
    if (st.empty() || (!st.empty() && st.top() < num))
    {
        st.push(num);
        return;
    }
    int topele = st.top();
    st.pop();

    sortedInsert(st, num);
    st.push(topele);
}
void sortStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int num = st.top();
    st.pop();

    sortStack(st);
    sortedInsert(st, num);
}
