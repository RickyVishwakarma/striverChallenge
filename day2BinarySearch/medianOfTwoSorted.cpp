#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int i = 0, j = 0, k = 0;
    int m = nums1.size();
    int n = nums2.size();
    vector<int> nums3(m + n);


    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            nums3[k++] = nums1[i++];
        } else {
            nums3[k++] = nums2[j++];
        }
    }

    
    while (i < m) nums3[k++] = nums1[i++];
    while (j < n) nums3[k++] = nums2[j++];

    int x = nums3.size();

    if (x % 2 == 0) {
        return (nums3[x / 2] + nums3[(x / 2) - 1]) / 2.0;
    } else {
        return nums3[x / 2];
    }
}

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << findMedianSortedArrays(nums1, nums2) << endl;

    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << findMedianSortedArrays(nums3, nums4) << endl;
}
