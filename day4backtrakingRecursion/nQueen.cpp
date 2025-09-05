#include<bits/stdc++.h>
using namespace std;

class solution{
public:
    void solve(int ind , vector<int>& candidates, int target, vector<int> &temp, vector<vector<int>> &ans ){
        if(ind == candidates.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
        if(candidates[ind] <= target){
            temp.push_back(candidates[ind]);
            solve(ind , candidates, target - candidates[ind], temp, ans);
            temp.pop_back();

        }
        solve(ind + 1 , candidates, target, temp, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, candidates, target, temp, ans);
        return ans;
    }
}

int main(){
    solution sol;
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans = sol.combinationSum(candidates, target);
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}

int main(){
    solution sol;
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans = sol.combinationSum(candidates, target);
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}