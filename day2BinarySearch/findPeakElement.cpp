#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// A peak element is an element that is strictly greater than its neighbors.

// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

// You must write an algorithm that runs in O(log n) time.

// [1,2,3,1]
// start - 1  end = 1
// mid =  2 

// if(mid < mid + 1)
//     start = mid + 1
// else{
//     end = mid;
// }
// mid = (start + end) / 2;

int solve(vector<int>& nums) {
    int n = nums.size();
    if(n ==1 ) return 0;
    if(nums[0] > nums[1]) return 0;
    if(nums[n - 1] > nums[n - 2]) return n - 1;

    int low = 1;
    int high = n - 2;

    while(low <= high){
        int mid = (low + high) / 2;

        // for the mid 

        if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]){
            return mid; 
        }else if (nums[mid] > nums[mid - 1] ){
            low = mid + 1;
        }else high = mid - 1;
    }

    return -1;
    // int low = 0;
    // int high = nums.size() - 1;

    // while (low < high) {
    //     int mid = low + (high - low) / 2;

    //     if (nums[mid] < nums[mid + 1]) {
    //         low = mid + 1;
    //     } else {
    //         high = mid;
    //     }
    // }

    // return low; 
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    int peakIndex = solve(nums);
    cout << "Peak index: " << peakIndex << endl;
    return 0;
}
