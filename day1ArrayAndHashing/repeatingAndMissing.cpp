#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// /we are going to solve the problem find the missing and the repeating element in the given a array 

// Approach 1 

// pair<int, int> findMissingAndRepeating(vector<int>& nums) {
//     int n = nums.size();
//     int repeating = -1;
//     int missing = -1;

//     for (int i = 1; i <= n; i++) {
//         int count = 0;
//         for (int j = 0; j < n; j++) {
//             if (nums[j] == i) {
//                 count++;
//             }
//         }

//         if (count == 0) {
//             missing = i;
//         } else if (count > 1) {
//             repeating = i;
//         }

//         if (repeating != -1 && missing != -1) {
//             break;
//         }
//     }

//     return {missing, repeating};
// }

// Approach 2: Using Hashing

// pair<int ,int>findMissingAndRepeating(vector<int>&nums){
//     int n= nums.size();
//     vector<int> hash(n + 1, 0);
//     int repeating = -1;

//     int missing = -1;
//     for(int i = 0; i < n; i++) {
//         hash[nums[i]]++;

//     }

//     for(int i= 1 ; i <=  n ; i++){
//         if(hash[i] == 0){
//             missing = i;
//         }else if(hash[i] ==  2){
//             repeating = i;

//         }

//         if(repeating != -1 && missing != -1) {
//             break;
//         }
//     }

//     return {missing, repeating};
// }


// Approach 3: Using linear maths

pair<int , int>findMissingAndRepeating(vector<int>& nums) {

    // s - sn 
    // s2 - s2n
    int n = nums.size();

    long long sn = (n * (n + 1)) / 2;

    long long sn2  = ( n * (n + 1 ) * (2 *n + 1)) / 6;

    long long s = 0;
    long long s2 = 0;

    for(int i = 0 ; i < n ; i++){
        s += nums[i];
        s2 += (long long)nums[i] * (long long)nums[i];
    }
    int val1 = s - sn;
    int val2 = s2 - sn2;

    val2 = val2 / val1;

    int repeating = (val1 + val2) / 2;
    int missing = val2 - repeating;
    return {missing, repeating};

};



int main() {
    vector<int> arr = {4, 3, 6, 2, 1, 1};
    auto result = findMissingAndRepeating(arr);

    cout << "Missing number: " << result.first << endl;
    cout << "Repeating number: " << result.second << endl;
    return 0;
}