#include <bits/stdc++.h>
using namespace std;

/*
 * 1530. Number of Good Leaf Nodes Pairs
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
    vector<int> getLeafNodeDistances(TreeNode* root, int distance, int &totalPairs) {
        if(!root) {
            return {0};
        }

        if(!root->left && !root->right) {
            return {1};
        } 

        vector<int> leafNodeDistancesInLeftSubTree = getLeafNodeDistances(root->left, distance, totalPairs);
        vector<int> leafNodeDistancesInRightSubTree = getLeafNodeDistances(root->right, distance, totalPairs);

        for(int a: leafNodeDistancesInLeftSubTree) {
            for(int b: leafNodeDistancesInRightSubTree) {
                if(a > 0 && b > 0 && a + b <= distance) {
                    totalPairs++;
                }
            }
        }

        vector<int> leafNodeDistances;
        for(int d: leafNodeDistancesInLeftSubTree){
            if(d > 0 && d < distance){
                leafNodeDistances.push_back(d+1);
            }
        }
        for(int d: leafNodeDistancesInRightSubTree){
            if(d > 0 && d < distance){
                leafNodeDistances.push_back(d+1);
            }
        }
        return leafNodeDistances;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        int totalPairs = 0;
        getLeafNodeDistances(root, distance, totalPairs);
        return totalPairs;
    }
};