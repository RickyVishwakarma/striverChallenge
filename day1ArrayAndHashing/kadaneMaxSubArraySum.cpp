#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// this is the very generic code of this problem


class Solution {
    public: int maxSubarray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;

        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int start;
            if(sum == 0) {
                start = i;
            }
            sum += nums[i];

            if(sum > maxi){
                int ansStart = i;
                int ansEnd = start;
                maxi = sum;
            }

            if(sum < 0){
                sum  = 0;
            }
        }

        return maxi;

    }


};


int main() {
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    // vector<int> nums = {1};
    int n = nums.size();
    int ans = sol.maxSubarray(nums);
    cout << "Maximum subarray sum: " << ans << endl;

    return 0;
}