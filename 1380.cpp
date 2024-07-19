#include <bits/stdc++.h>
using namespace std;

/*
 * Brute Force Approach
*/
class Solution1 {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> minimumInRow(n,1000000);
        vector<int> maximumInColIndex(m,0);

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                minimumInRow[i] = min(minimumInRow[i], matrix[i][j]);
                if(matrix[maximumInColIndex[j]][j] < matrix[i][j])
                    maximumInColIndex[j] = i;
            }
        }

        vector<int> ans;
        for(int idx = 0;idx < m;idx++){
            int rowIndex = maximumInColIndex[idx];
            if(matrix[rowIndex][idx] == minimumInRow[rowIndex])
                ans.push_back(matrix[rowIndex][idx]); 
        }
        return ans;
    }
};


/*
 * Greedy Approach
*/
class Solution2 {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int rowMinMax = -1, colMaxMin = 1e9;

        for(int i = 0;i < n;i++){
            int rowMin = 1e9;
            for(int j = 0;j < m;j++){
                rowMin = min(rowMin, matrix[i][j]);
            }
            rowMinMax = max(rowMinMax, rowMin);
        }

        for(int i = 0;i < m;i++){
            int colMax = -1;
            for(int j = 0;j < n;j++){
                colMax = max(colMax, matrix[j][i]);
            }
            colMaxMin = min(colMaxMin, colMax);
        }

        if(colMaxMin == rowMinMax){
            return {rowMinMax};
        }
        return {};
    }
};