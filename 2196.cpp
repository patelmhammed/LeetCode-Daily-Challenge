#include <bits/stdc++.h>
using namespace std;

/*
 * 2196. Create Binary Tree From Descriptions
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* valueToNode[100001] = {};
        bool isChildNode[100001] = {};
        for (auto& d : descriptions){
            if (parentToChildMap[d[0]] == nullptr) parentToChildMap[d[0]] = new TreeNode(d[0]);
            TreeNode* node = (parentToChildMap[d[1]] == nullptr ? new TreeNode(d[1]) : parentToChildMap[d[1]]);
            if (d[2])
                parentToChildMap[d[0]]->left = node;
            else
                parentToChildMap[d[0]]->right = node;
            parentToChildMap[node->val] = node;
            isChildNode[d[1]] = true;
        }
        for (auto& d : descriptions)
            if (!isChildNode[d[0]])
                return parentToChildMap[d[0]];
        return nullptr;
    }
};