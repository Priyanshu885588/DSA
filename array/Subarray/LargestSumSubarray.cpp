#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_so_far = INT_MIN;
        int max_ending_here = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            max_ending_here += nums[i];

            // Handle the case where all elements are negative
            if (max_so_far < max_ending_here)
            {
                max_so_far = max_ending_here;
            }
            if (max_ending_here < 0)
            {
                max_ending_here = 0;
            }

            // Update max_so_far only if the current sum is greater
        }

        return max_so_far;
    }
};