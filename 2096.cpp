#include <bits/stdc++.h>
using namespace std;

/*
 * 2096. Step-By-Step Directions From a Binary Tree Node to Another
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
private:
    bool findPath(TreeNode* root, int target, string &path){
        if(root -> val == target){
            return true;
        }

        if(root -> left && findPath(root -> left, target, path))
            path.push_back('L');
        else if(root -> right && findPath(root -> right, target, path))
            path.push_back('R');

        return !path.empty();
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startNodePath, destNodePath;
        findPath(root, startValue, startNodePath);
        findPath(root, destValue, destNodePath);
        while(!startNodePath.empty() && !destNodePath.empty() && startNodePath.back() == destNodePath.back()){
            startNodePath.pop_back();
            destNodePath.pop_back();
        }
        return string(startNodePath.size(), 'U') + string(rbegin(destNodePath), rend(destNodePath));
    }
};