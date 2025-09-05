#include <bits/stdc++.h>
using namespace std;

class solution {
public : 
    vector<int>maxSlidingWindow(vector<int>&nums , int k){
        int n= nums.size();
        vector<int>ans;
        deque<int>dq;
        for(int i = 0 ; i < n ; i++){
            if(!dq.empty() && dq.front() <= i - k){
                dq.pop_back();
            }
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= k - 1){
                ans.push_back(nums[dq.front()]);
            }

        }
        return ans;


        // this is the brute force app
        // int n = nums.size();
        // vector<int>ans;
        // for(int i = 0 ; i <= n ; i++){
        //     int maxi = nums[i];
        //     for(int j = i ; j < i + k ; j++){
        //         maxi = max(maxi , nums[j]);
        //     }
        //     ans.push_back(maxi);
        // }
        // return ans;
    }
}

int main() {
    

    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    solution obj;
    vector<int> ans = obj.maxSlidingWindow(nums , k);
    for(auto i : ans){
        cout<<i<<" ";
    }

    return 0;
}