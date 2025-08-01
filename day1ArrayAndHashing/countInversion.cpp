#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// this is the optimai


// /this is the brute force solution of the inversion with complexity O(n^2) 



int merge(vector<int>&nums , int low ,int mid , int high){
    vector<int>temp;
    int left = low ;
    int right = mid + 1;
    int count = 0;
    while(left <= mid && right <= high){
        if(nums[left] <= nums[right]){
            temp.push_back(nums[left]);
            left++;
        }else{
            temp.push_back(nums[right]);
            count += (mid - left + 1);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(nums[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(nums[right]);
        right++;
    }
    for(int i = low ; i <= high ; i++){
        nums[i] = temp[i - low];
    }
    return count;

}

int mergeSort(vector<int>&nums, int low, int high) {
    if(low >= high) {
        return 0;
    }
    int mid = (low + high) / 2;
    int count = 0;
    count += mergeSort(nums, low, mid);
    count += mergeSort(nums, mid + 1, high);
    count += merge(nums, low, mid, high);
    return count;

}

int noOfInversions(vector<int>&nums){
    int n = nums.size();
    int count = 0;

    // for(int i = 0 ; i < n ; i++){
    //     for(int j = i + 1 ; j <n ; j++){
    //         if(nums[i] > nums[j]){
    //             count++;
    //         }
    //     }
    // }
    // return count;

    return mergeSort(nums, 0, n - 1);
}

int main() {
    vector<int> nums = {2, 3, 8, 6, 1};
    int result = noOfInversions(nums);
    cout << "Number of inversions: " << result << endl;

    return 0;
}