//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool II(int arr[], int n)
    {
        int i = 0;
        while (i < n - 1 and arr[i] <= arr[i + 1])
            i++;

        if (i == n - 1)
            return false;

        i++;
        while (i < n - 1 and arr[i] <= arr[i + 1])
            i++;

        if (i == n - 1 and arr[n - 1] <= arr[0])
            return true;
        else
            return false;
    }

    bool DD(int arr[], int n)
    {
        int i = 0;
        while (i < n - 1 and arr[i] >= arr[i + 1])
            i++;

        if (i == n - 1)
            return false;

        i++;
        while (i < n - 1 and arr[i] >= arr[i + 1])
            i++;

        if (i == n - 1 and arr[n - 1] >= arr[0])
            return true;
        else
            return false;
    }

    bool checkRotatedAndSorted(int arr[], int num)
    {
        return (II(arr, num) || DD(arr, num));
    }
};

int main()
{
    int T;
    // testcases
    cin >> T;

    while (T--)
    {
        int num;
        // size of array
        cin >> num;
        int arr[num];

        // inserting elements
        for (int i = 0; i < num; ++i)
            cin >> arr[i];

        bool flag = false;
        Solution ob;

        // function call
        flag = ob.checkRotatedAndSorted(arr, num);

        // printing "No" if not sorted and
        // rotated else "Yes"
        if (!flag)
        {
            cout << "No" << endl;
        }
        else
            cout << "Yes" << endl;
    }

    return 0;
}
// } Driver Code Ends