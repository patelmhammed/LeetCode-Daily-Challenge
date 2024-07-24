#include <bits/stdc++.h>
using namespace std;

/*
 * 2191. Sort the Jumbled Numbers
*/

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int> > mappedNums;

        // Transform each number as per the mapping and associate it with its original index
        for (int i = 0; i < n; ++i) {
            int originalValue = nums[i];
            int mappedValue = originalValue == 0 ? mapping[0] : 0; // If the number is 0, directly map it
            int placeValue = 1; // Represents the place value in the mapped number

            // Decompose the number into its digits and transform it according to the mapping
            while (originalValue > 0) {
                int digit = originalValue % 10; // Get the last digit
                mappedValue += placeValue * mapping[digit]; // Map the digit and add to the mapped value
                originalValue /= 10; // Remove the last digit from the original value
                placeValue *= 10; // Move to the next place value
            }

            // Save the pair of mapped value and original index
            mappedNums.push_back({mappedValue, i});
        }

         sort(mappedNums.begin(), mappedNums.end());

        // Extract the numbers from the sorted pairs, preserving the new order
        vector<int> sortedNums;
        for (auto& pair : mappedNums) {
            sortedNums.push_back(nums[pair.second]);
        }

        // Return the sorted numbers as per the jumbled mapping order
        return sortedNums;
    }
};