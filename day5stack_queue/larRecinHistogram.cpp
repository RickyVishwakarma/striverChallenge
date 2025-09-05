#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangle(vector<int>& nums) {
        int n = nums.size();
        int maxArea = 0;
        stack<int> st;
        int nse, pse;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                int element = nums[st.top()];
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, element * (nse - pse - 1));
            }
            st.push(i);
        }

        while (!st.empty()) {
            int element = nums[st.top()];
            st.pop();
            nse = n;
            pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, element * (nse - pse - 1));
        }
        return maxArea;
    }
};

int main() {
    vector<int> nums = {2,1,5,6,2,3};
    Solution obj;
    cout << obj.largestRectangle(nums) << endl;
    return 0;
}