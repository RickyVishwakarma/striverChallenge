#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


class Solution {
    public:
        int triplet(vector<int>& nums , int n){
            set<vector<int>> st;
            for(int i = 0 ; i < n ; i++){
                set<int> hash;
                for(int j = i + 1 ; j < n ; j++){
                    int third = -(nums[i] + nums[j]);
                    if(hash.find(third) != hash.end()){
                        vector<int> temp = {nums[i], nums[j], third};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hash.insert(nums[j]);
                }
            }

            vector<vector<int>> ans(st.begin(), st.end());


            for (auto triplet : ans) {
                for (int num : triplet) {
                    cout << num << " ";
                }
                cout << endl;
            }

            return ans.size();  
        }
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4 };
    int n = nums.size();
    Solution sol;
    int ans = sol.triplet(nums, n); 
    cout << "Number of triplets: " << ans << endl;
    return 0;
}