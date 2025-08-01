#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>&nums){
    int n = nums.size(); 
    
    int maxi = INT_MIN;
    for(int i = 0 ; i  < n ; i++){
        int pd = 1 ;

        for(int j =i ; j < n ; j++){
            pd *= nums[j];

            maxi = max(maxi , pd);
        }
    }
    return maxi;

}

int main() {
    vector<int>nums = {2, 3, -2 , 4};

    int result = maxProduct(nums);
    cout << "Maximum product of subarray: " << result << endl;

    return 0;
}