#include <bits/stdc++.h>

using namespace std;

class Solution {

    TreeNode* buildT(vector<int>& preorder, int pstart, int pend, vector<int>& inorder, int istart, int iend, map<int,int>& mp) {  
        if (pstart > pend || istart > iend) return nullptr;

        TreeNode* root = new TreeNode(preorder[pstart]);
        
        int iRoot = mp[root->val];  
        int numsLeft = iRoot - istart;

        root->left = buildT(preorder, pstart + 1, pstart + numsLeft,  inorder, istart, iRoot - 1, mp);

        root->right = buildT(preorder, pstart + numsLeft + 1, pend, inorder, iRoot + 1, iend, mp);

        return root;
    }

    TreeNode * buildTree(vector<int>& preOrder , vector<int>&inorder){
        map<int , int>mp;
        for(int i = 0 ; i < inorder.size() ; i++){
            mp[inorder[i]] = i;

        }
        return buildT(preorder, 0, preorder.size() - 1,inorder, 0, inorder.size() - 1, mp);
    }
}

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}