#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// this is the another problem that is different from the above one is this it have the duplicated elements as well

// in this we have a problem of that we cant able to find the sorted part 

// like nums[low] = nums[mid] = nums[high]  this is the main problem here  



int solve(vector<int>&nums , int target){
    int low = 0;
    int high = nums.size() - 1;
    
    while(low <= high){
        int mid = (low + high) / 2;

        if(nums[mid] == target) return mid;
        
        // solving the main problem of the duplicated elements 
        if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }

        if(nums[low] <= nums[mid]){
            if(target >= nums[low] && target <= nums[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else{
            if(target >= nums[mid] && target <= nums[high]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }        
    }
    return -1;
}

int main() {
    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 2;
    int result = solve(nums, target);

    if(result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }
    return 0;
}