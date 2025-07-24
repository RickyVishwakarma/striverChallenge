#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class  Solution {
    public:
        int nextPermutation(vector<int>&nums){
            int n = nums.size();

            int ind = -1;
            // finding the breakpoint
            for(int i = n - 2; i  >= 0  ; --i){
                if(nums[i] < nums[i + 1]){
                    ind = i;
                    break;

                }
            }


            // if no breakpoint found, reverse the entire array
            if(ind == -1){
                reverse(nums.begin(), nums.end());
            }

            // now swap the  val of the indx with the next greater element
            
            for(int i = n - 1 ; i >ind ; --i){
                if(nums[i] > nums[ind]){
                    swap(nums[i], nums[ind]);
                    break;
                }
            }

            reverse(nums.begin() + ind + 1, nums.end());
            return 0;
        }
};

int main() {
    Solution sol;
    vector<int>nums = {2,1,5,4,3,0,0};
    int n = nums.size();    

    sol.nextPermutation(nums);
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;



    

}