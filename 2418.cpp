#include <bits/stdc++.h>
using namespace std;

/*
 * 2418. Sort the People
*/

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        const int n=names.size();
        for(int i=0; i<n; i++) 
            heights[i]=(heights[i]<<10)+i;        //Inserting index in the height value using bit manipulation
        sort(heights.begin(), heights.end(), greater<>());
        vector<string> ans(n);
        for(int i = 0; i < n; i++) 
            ans[i]=names[heights[i]&1023];        //Extracting Index from height value using bit manipulation
        return ans;
    }
};