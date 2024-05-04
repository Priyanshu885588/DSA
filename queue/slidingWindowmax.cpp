// class Solution
// {
// public:
//     vector<int> maxSlidingWindow(vector<int> &nums, int k)
//     {
//         deque<int> dk;
//         vector<int> ans;
//         int currentmax = INT_MIN;
//         for (int i = 0; i < k; i++)
//         {
//             dk.push_back(nums[i]);
//             currentmax = max(currentmax, nums[i]);
//         }

//         ans.push_back(currentmax);
//         int j = 1;
//         for (int i = k; i < nums.size(); i++)
//         {
//             int old = dk.front();
//             dk.pop_front();
//             dk.push_back(nums[i]);
//             cout << i << endl;
//             if (old == currentmax)
//             {
//                 currentmax = INT_MIN;
//                 for (int i = 0; i < k; i++)
//                 {
//                     int ele = dk.front();
//                     dk.pop_front();
//                     currentmax = max(currentmax, ele);
//                     dk.push_back(ele);
//                 }
//             }
//             else
//             {
//                 currentmax = max(currentmax, nums[i]);
//             }

//             ans.push_back(currentmax);
//         }
//         return ans;
//     }
// };
// for above solution on leetcode time limit exccded;