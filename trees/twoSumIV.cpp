class Solution {
public:
    // void inorder(TreeNode* root, vector<int>& nums) {
    //     if (!root) return;
    //     inorder(root->left, nums);
    //     nums.push_back(root->val);
    //     inorder(root->right, nums);
    // }

    unordered_set<int> seen;

    bool dfs(TreeNode* root, int k) {
        if (!root) return false;
        if (seen.count(k - root->val)) return true;
        seen.insert(root->val);
        return dfs(root->left, k) || dfs(root->right, k);
    }

    bool findTarget(TreeNode* root, int k) {
        // vector<int> nums;
        // inorder(root, nums);
        // int l = 0, r = nums.size() - 1;
        // while (l < r) {
        //     int sum = nums[l] + nums[r];
        //     if (sum == k) return true;
        //     if (sum < k) l++;
        //     else r--;
        // }
        // return false;
        return dfs(root , k);
    }
};