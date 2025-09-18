#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q){
            return root;
        }
        TreeNode * left = lowestCommonAncestor(root->left , p , q);
        TreeNode * right =lowestCommonAncestor(root->right , p , q);
        if(left == NULL) return right; 
        else if(right == NULL) return left;
        else return root;
    }
};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}