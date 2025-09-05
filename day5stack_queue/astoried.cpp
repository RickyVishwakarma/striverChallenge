#include <bits/stdc++.h>
using namespace std;

class solution {
public : 

    vector<int>astorid(vector<int>&nums){
        // this is an another app
        vector<int>st;
        for(int a : nums){
            bool des = false;
            while(!st.empty() && st.back() > 0 && a < 0){
                if(st.back() < -a){
                    st.pop_back();
                    continue;
                }else if(st.back() == -a){
                    st.pop_back();
                }
                des = true;
                break;
            }
            if(!des){
                st.push_back(a);
            }
        }
        return st;

        // int n = asteroids.size();
        // vector<int> st;
        // for (int i = 0; i < n; i++) { 
        //     if (asteroids[i] > 0) {
        //         st.push_back(asteroids[i]);
        //     } else {
        //         while (!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])) {
        //             st.pop_back();  
        //         }
        //         if (!st.empty() && st.back() > 0) {
        //             if (st.back() == abs(asteroids[i])) {
        //                 st.pop_back(); 
        //             }
        //         } else {
        //             st.push_back(asteroids[i]); 
        //         }
        //     }
        // }
        // return st;
    }
}


int main() {


    vector<int> nums = {5, 10, -5};

    solution obj;
    vector<int> ans = obj.astorid(nums);
    for(auto i : ans){
        cout<<i<<" ";
    }

    return 0;
}