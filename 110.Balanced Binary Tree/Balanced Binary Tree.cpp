/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int judge(TreeNode* root, bool &ans){
        if(root){
            int leftnum = judge(root->left, ans);
            int rightnum = judge(root->right, ans);
            if(abs(leftnum - rightnum)>1)
            {
                ans = false;
            }
            return max(leftnum, rightnum) + 1;
        }
        return 0;
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        judge(root, ans);
        return ans;
    }
};