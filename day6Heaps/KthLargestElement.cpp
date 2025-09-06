#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    int findKthLargets(vector<int>&nums , int k){
        priority_queue<int, vector<int>, greater<int>>minHeap;
        for(int num : nums){
            minHeap.push(num);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        

        return minHeap.top();
    }    
}



int main() {
    
    Solution sol;
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout<<sol.findKthLargets(nums , k);
    
    return 0;
}