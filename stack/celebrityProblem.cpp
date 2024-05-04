
#include <bits/stdc++.h>
using namespace std;

// my own solution
// class Solution
// {
// public:
//     // Function to find if there is a celebrity in the party or not.
//     int celebrity(vector<vector<int>> &M, int n)
//     {
//         // code here

//         bool tt = 0;
//         for (int i = 0; i < n; i++)
//         {
//             tt = 0;
//             for (int j = 0; j < n; i++)
//             {
//                 if (M[i][j] == 1)
//                 {
//                     tt = 0;
//                     break;
//                 }
//                 else
//                 {
//                     tt = 1;
//                 }
//             }
//             for (int k = 0; k < n; k++)
//             {
//                 if (M[k][i] == 1)
//                 {
//                     tt = 0;
//                     break;
//                 }
//                 else
//                 {
//                     tt = 2;
//                 }
//             }
//             if (tt == 2)
//             {
//                 return i;
//             }
//         }

//         if (tt == 0)
//         {
//             return -1;
//         }
//     }
// };

// two pointer approach

// Back-end complete function template for C++

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        // initializing two pointers for two corners.
        int a = 0;
        int b = n - 1;

        // we keep moving till the a<b.
        while (a < b)
        {
            if (M[a][b])
                a++;
            else
                b--;
        }

        // checking if a is actually a celebrity or not.
        for (int i = 0; i < n; i++)
        {
            // if any person doesn't know a or a knows any person, we return -1.
            if ((i != a) && (M[a][i] || !M[i][a]))
                return -1;
        }
        // if we reach here a is celebrity so we retun a.
        return a;
    }
};

// stack approach

class Solution2
{
private:
    bool knows(vector<vector<int>> &M, int a, int b, int n)
    {
        if (M[a][b] == 1)
            return true;
        else
            return false;
    }

public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> s;
        // step1: push all element in stack
        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }

        // step2: get 2 elements and copare them

        while (s.size() > 1)
        {

            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            if (knows(M, a, b, n))
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }
        int ans = s.top();
        // step3: single element in stack is potential celeb
        // so verify it

        int zeroCount = 0;

        for (int i = 0; i < n; i++)
        {
            if (M[ans][i] == 0)
                zeroCount++;
        }

        // all zeroes
        if (zeroCount != n)
            return -1;

        // column check
        int oneCount = 0;

        for (int i = 0; i < n; i++)
        {
            if (M[i][ans] == 1)
                oneCount++;
        }

        if (oneCount != n - 1)
            return -1;

        return ans;
    }
};