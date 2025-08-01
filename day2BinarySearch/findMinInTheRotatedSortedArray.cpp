#include <iostream>
// #include <c++>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// so we can easily find the min element in the rotated sorted array  in the O(n)

// so the the questions is can we find the min in the rotated sorted array in O(logn) time complexity

// nums : [3,4,5,1,2]

// we have to find th rotating point 

// our ans is lie in the left half which is not sorted  nums[low] <= nums[mid]

// because the point of rotation of the nums is 1 at index = 3 

// if(nums[left] < nums[mid]){
//     ans = max(ans , nums[low]);
//     low = mid + 1
// }else{
//     ans = max(ans , nums[mid]);
//     high = mid - 1;
// }

// and hence we return the ans

int solve(vector<int>&nums){
    int low = 0;
    int high = nums.size() - 1;
    int ans = INT_MAX;

    while(low <= high){
        int mid = (low + high) / 2;

        if(nums[low] <= nums[mid]){
            ans = min(ans , nums[low]);
            low = mid + 1;
        }else{
            ans = min(ans , nums[mid]);
            high = mid - 1;
        }
    }
    return ans;
}


// int solve(vector<int>&nums){
//     int mini = INT_MAX;

//     for(int num : nums){
//         if(num < mini) {
//             mini = num;

//         }
//         // mini = min(mini, num);
//     }

//     return mini;
// }

int main() {

    vector<int>nums = {3,4,5,1,2};
    int result = solve(nums);
    cout << "Minimum element in the sorted rotated array: " << result << endl;


    return 0;
}