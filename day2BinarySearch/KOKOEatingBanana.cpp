#include <iostream>
#include <vector>
#include <climits>

#include <algorithm>
using namespace std;



// this the mathematical approach of solving this where we travaerse on the basis of the max element to get an idea how long we can go 

// this is required the time complexity of O(maxElement * number of element)

// int fn(const vector<int>& nums, int hourly) {
//     int total = 0;
//     for (int i = 0; i < nums.size(); i++) {
//         total += (nums[i] + hourly - 1) / hourly;  
//     }
//     return total;
// }


// int solve(vector<int>& nums, int h) {
//     int maxElement = *max_element(nums.begin(), nums.end());

//     for (int i = 1; i <= maxElement; i++) {
//         int reqTime = fn(nums, i);

//         if (reqTime <= h) {
//             return i;
//         }
//     }


//     return -1;
// }

int banana(const vector<int>& nums, int hourly) {
    int total = 0;
    for (int i = 0; i < nums.size(); i++) {
        total += (nums[i] + hourly - 1) / hourly;  
    }
    return total;
}

int solve(vector<int>& nums, int h) {
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    int ans = INT_MAX;

    while (low <= high) {
        int mid = (low + high) / 2;
        int totalBananas = banana(nums, mid);

        if (totalBananas <= h) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {3, 6, 7, 11};
    int h = 8;

    int result = solve(nums, h);
    cout << result << endl;

    return 0;
}
