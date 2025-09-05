#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nge(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;


        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                mp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        vector<int> result;
        for (int num : nums1) {
            if (mp.count(num)) {
                result.push_back(mp[num]);
            } else {
                result.push_back(-1);
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    Solution obj;
    vector<int> ans = obj.nge(nums1, nums2);
    for (int i : ans) {
        cout << i << " ";
    }
    return 0;
}