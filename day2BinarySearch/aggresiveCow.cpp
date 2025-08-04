#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// bool isSafe(vector<int>& nums, int dist, int cows) {
//     int cowCount = 1;
//     int last = nums[0];

//     for (int i = 1; i < nums.size(); i++) {
//         if (nums[i] - last >= dist) {
//             cowCount++;
//             last = nums[i];
//         }
//     }

//     if (cowCount >= cows)
//         return true;
//     else
//         return false;
// }

// int solve(vector<int>& stalls, int cows) {
//     int n = stalls.size();
//     sort(stalls.begin(), stalls.end());

//     int mini = stalls[0];
//     int maxi = stalls[n - 1];

//     // Loop through all possible distances (brute-force)
//     for (int i = 1; i <= (maxi - mini); i++) {
//         if (!isSafe(stalls, i, cows)) {
//             return i - 1;
//         }
//     }

//     return maxi - mini;
// }

bool isSafe(vector<int>& nums, int dist, int cows) {
    int cowCount = 1;
    int last = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] - last >= dist) {
            cowCount++;
            last = nums[i];
        }
    }

    if (cowCount >= cows)
        return true;
    else
        return false;
}

int solve(vector<int>& stalls, int cows) {
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());

    int low = 0;
    int high = stalls[n - 1] - stalls[0];


    while(low <= high) {
        int mid = (low + high ) / 2;

        if (isSafe(stalls , mid , cows) == true) {
            int ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;;
        }
    }

    return high;
}

int main() {
    vector<int> stall = {0, 3, 4, 7, 10, 9};
    int cows = 4;
    int result = solve(stall, cows);

    cout << result << endl;

    return 0;
}