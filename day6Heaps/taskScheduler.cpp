
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // we can solve this througn the simulation 
        vector<int>freq(26, 0);
        for(char c : tasks){
            freq[c - 'A']++;
        }

        int maxFreq = *max_element(freq.begin() , freq.end());
        int maxCount = count(freq.begin() , freq.end(), maxFreq);

        int partCount = maxFreq - 1;
        int partLenght = n+1;
        int emptySlots = partCount * partLenght + maxCount;

        return max((int)tasks.size(), emptySlots);

    //     vector<int> freq(26, 0);
    //     for (char t : tasks) {
    //         freq[t - 'A']++;
    //     }

    //     priority_queue<int> pq;
    //     for (int f : freq) {
    //         if (f > 0) pq.push(f);
    //     }

    //     int time = 0;
    //     while (!pq.empty()) {
    //         int cycle = n + 1;
    //         vector<int> temp;
    //         for (int i = 0; i < cycle && !pq.empty(); i++) {
    //             temp.push_back(pq.top());
    //             pq.pop();
    //         }

    //         for (int f : temp) {
    //             if (f - 1 > 0) pq.push(f - 1);
    //         }

    //         time += pq.empty() ? temp.size() : cycle;
    //     }

    //     return time;
    }
};

int main() {
    Solution sol;
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    cout<<sol.leastInterval(tasks , n);
    
    return 0;
}