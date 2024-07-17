#include <bits/stdc++.h>
using namespace std;

/*
 * 1110. Delete Nodes And Return Forest
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
    vector<TreeNode*> ans;
    unordered_set<int> nodesToDelete;
    void deleteNode(TreeNode* &root){
        if(root){
            deleteNode(root->left);
            deleteNode(root->right);
            if(nodesToDelete.find(root->val) != nodesToDelete.end()){
                if(root->left){
                    ans.push_back(root->left);
                } 
                if(root->right){
                    ans.push_back(root->right);
                }
                
                root=NULL;
                delete root;
            }
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i = 0;i < to_delete.size();i++){
            nodesToDelete.insert(to_delete[i]);
        }

        deleteNode(root);

        // root is still non-null then insert it as well in ans list
        if(root){
            ans.push_back(root);
        }
        return ans;
    }
};