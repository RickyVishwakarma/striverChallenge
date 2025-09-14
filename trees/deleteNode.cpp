class Solution {
public:
    TreeNode* findLastRight(TreeNode* root) {
        while(root->right) root = root->right;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(key < root->val) 
            root->left = deleteNode(root->left, key);
        else if(key > root->val) 
            root->right = deleteNode(root->right, key);
        else {
            // Node found
            if(!root->left) return root->right;
            if(!root->right) return root->left;

            TreeNode* leftSub = root->left;
            TreeNode* lastRight = findLastRight(leftSub);
            lastRight->right = root->right;
            return leftSub;
        }
        return root;
    }
};

