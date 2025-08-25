#include<bits/stdc++.h>
using namespace std;

class solution{
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        // this is my favourite bitmasking method
        int n = nums.size();
        vector<vector<int>>result;
        for(int mask = 0 ; mask < (1 << n) ; mask++){
            vector<int>subset;
            for(int i = 0 ; i < n ; i++){
                if(mask & (1 << i)){
                    subset.push_back(nums[i]);
                }
            }
            result.push_back(subset);
        }
        return result;

        // vector<vector<int>> ans;
        // vector<int> temp;
        // backtrack(0, nums, temp, ans);
        // return ans;
        
    }

    // void backtrack(int index, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
    //     ans.push_back(temp);

    //     for (int i = index; i < nums.size(); i++) {
    //         temp.push_back(nums[i]);
    //         backtrack(i + 1, nums, temp, ans);
    //         temp.pop_back();
    //     }
    // };
};    

int main() {
    solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.subsets(nums);

    cout << "Power Set:" << endl;
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}