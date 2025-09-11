#include <bits/stdc++.h>
using namespace std;

class Solution{
    int width(TreeNode * root){
        if(!root)return 0;
        long long ans = 0;

        queue<pair<TreeNode *, long long>>q;
        q.push({root , 0});
        while(!q.empty()){
            int size = q.size();
            long long mInd = q.front().second;
            long long first =0, last=0;
            
            for(int i = 0 ; i < size ; i++){
                long long curr =  q.front().second - mInd;
                TreeNode * node = q.front().first;
                q.pop();
                if(i == 0)first = curr;
                if(i == size - 1)last = curr;
                if(node -> left){
                    q.push({node -> left , curr * 2 + 1});
                }
                if(node -> right){
                    q.push({node -> right , curr * 2 + 2});
                }
            }
            ans = max(ans , last - first + 1);

        }
        return (int)ans;
    }
}

int main() {
    
    
    return 0;
}