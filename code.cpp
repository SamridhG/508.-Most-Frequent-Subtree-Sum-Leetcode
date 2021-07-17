/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int,int>freq;
    int sumsub(TreeNode *root)
    {
        if(root==NULL)return 0;
        int sum=root->val+sumsub(root->left)+sumsub(root->right);
        freq[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        sumsub(root);
        vector<int>res;
        int max=0;
        for(auto s:freq)
        {
            if(s.second>max)
            {
                max=s.second;
            }
        }
        for(auto s:freq)
        {
            if(s.second==max)
            {
                res.push_back(s.first);
            }
        }
        return res;
    }
};
