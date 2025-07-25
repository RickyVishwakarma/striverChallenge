#include <iostream>
#include <vector>
#include <map>
using namespace std;

int Xorr(vector<int>& nums, int k) {

    // this is the optimal sol /

    int xr = 0;
    map<int ,int>mp;
    mp[xr]++;
    int count = 0;

    for(int i = 0 ; i < nums.size() ; i++ ){
        xr = xr ^ nums[i];
        int x = xr ^ k;
        count += mp[x];
        mp[xr]++;
    }


    return count;
    // int n = nums.size();
    // int count = 0;

    // for (int i = 0; i < n; i++) {
    //     int currentXor = 0;
    //     for (int j = i; j < n; j++) {
    //         currentXor ^= nums[j]; 
    //         if (currentXor == k) {
    //             count++;
    //         }
    //     }
    // }

    // return count;
}

int main() {
    vector<int> nums = {4,2,2,6,4};
    int k = 6;
    int result = Xorr(nums, k);
    cout << "Number of subarrays with XOR equal to " << k << ": " << result << endl;
    return 0;
}
