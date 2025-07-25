#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    public: 
         vector<int> majorityElement(vector<int>& nums) {
            int n = nums.size();
            int mm = n / 3;
            vector<int> ans;
            unordered_map<int, int> mp;

            for (int i = 0; i < n; i++) {
                mp[nums[i]]++;
            }

            for (auto& pair : mp) {
                if (pair.second > mm) {
                    ans.push_back(pair.first);
                }
            }

            return ans;
        

            // for(int i = 0 ; i < n - 1 ; i++){
            //     if(ans.size() == 0 || ans[0] != nums[i]){
            //         int count = 0;

            //         for(int j = 0 ; j < n - 1 ; j++){
            //             if(nums[j] == nums[i]){
            //                 count++;
            //             }
            //         }
            //         if(count > n / 3){
            //             ans.push_back(nums[i]);

            //         }
            //     }
            //     if(ans.size() == 2) break;
            // }

            // return ans;
        }
};

int main() {
    Solution sol;
    // Example usage


    vector<int>nums= {3,2,3};
    vector<int>result = sol.majorityElement(nums);
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;


 
    return 0;
}