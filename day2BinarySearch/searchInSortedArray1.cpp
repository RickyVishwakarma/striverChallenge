#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// this type of  // problem is solved using binary search and does not have the duplicated elemesmt
// the way is the wefind the which part is the sorted and then we check if the target is in that part or not
// the part with the left or rght 


int solve(vector<int>& nums, int target) {
        // Optimal solution using vinary serch 

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = (high + low) / 2;
            if(nums[mid] == target) return mid;

            if(nums[low] <= nums[mid]){
                if(target >= nums[low] && target <= nums[mid]){
                    high = mid -1;
                }else{
                    low = mid + 1;
                }
            }else{
                if(target >= nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }else{
                    high = mid - 1 ;
                }
            }
        }
        return -1;
    }        


int main() {
    
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int result = solve(nums, target);
    if(result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }
    return 0;
}