
#include <bits/stdc++.h>
using namespace std;

class Solutio {
    int solve(TreeNode* root, int &maxi) {
        if(node == NULL) return 0;
        int left = max(0 , solve(root -> left , maxi));
        int right = max(0 , solve(root -> right , maxi))    ;
        maxi = max(maxi , left + right + root -> val);
        return root -> val + max(left , right);
    }

    int maxPath(TreeNode * root){
        int maxi = INT_MIN;
        solve(root , maxi);
        return maxi;
    }
}

int main() {
    
    
    return 0;
}