// maximum difference between increasing element
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maximumDifference(vector<int> &arr)
    {
        int max_diff = arr[1] - arr[0];
        int i = 0;
        for (i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i] >= arr[i + 1])
            {
                continue;
            }
            else
            {
                break;
            }
        }
        if (i == arr.size() - 1)
        {
            return -1;
        }
        // Minimum number visited so far
        int min_element = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - min_element > max_diff)
                max_diff = arr[i] - min_element;

            if (arr[i] < min_element)
                min_element = arr[i];
        }

        return max_diff;
    }
};