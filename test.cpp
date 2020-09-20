//
// Created by 孙一恒 on 2020/1/30.
//
#include "util.h"
using namespace std;

class Solution {
public:
    /**
     * 将四数之和问题利用三数之和问题求解,时间复杂度O(N^3)
     */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) {
            return result;
        }
        sort(nums.begin(), nums.end());
        int previous = 0;
        int size = nums.size() - 3;
        for (int i = 0; i < size; i++) {
            if (i > 0 && nums[0] == previous) {
                nums.erase(nums.begin());
                continue;
            }
            previous = nums[0];
            nums.erase(nums.begin());
            vector<vector<int>> three_result = threeSum(nums, target - previous);
            for (vector<int> v : three_result) {
                v.insert(v.begin(), previous);
                result.push_back(v);
            }
        }
        return result;
    }

    vector<vector<int>> threeSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i - 1 >= 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int right = nums.size() - 1;
            int left = i + 1;
            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right] - target;
                if (current_sum > 0) {
                    right--;
                } else if (current_sum < 0) {
                    left++;
                } else {
                    vector<int> r = {nums[i], nums[left], nums[right]};
                    result.push_back(r);
                    left++;
                    while (left < nums.size() && nums[left] == nums[left - 1]) {
                        left++;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> v = {-1,-3,-2,2,3,-3,0,-4};
    vector<vector<int>> result = s.fourSum(v, 4);
    cout << endl;
    return 0;
}