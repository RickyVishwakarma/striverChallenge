#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 
using namespace std;

// the linear  solution have the compleity of the O(summaztion - max + 1) * O(n);
// 
// this is the binary solution of the book allocation which have the complexity of the -> O(summaztion - max + 1) * O(n);

int isSafe(vector<int>& nums, int pages, int n) {
    int student = 1;
    int studentPages = 0;

    for (int i = 0; i < n; i++) { 
        if (studentPages + nums[i] <= pages) {
            studentPages += nums[i];
        } else {
            student++;
            studentPages = nums[i];
        }
    }

    return student;
}

int solve(vector<int>& books, int k) {
    int n = books.size();
    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0); 

    // int result = high;

    while (low <= high) { 
        int mid = (low + high) / 2;
        int countStudent = isSafe(books, mid, n);

        if (countStudent <= k) {
            // result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

int main() {
    vector<int> books = {12, 34, 67, 90};
    int k = 2;
    
    int result = solve(books, k);
    cout << result << endl;

    return 0;
}
