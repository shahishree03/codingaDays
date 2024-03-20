class Solution {
public:
    void sortColors(vector<int>& nums) {
         int c0 = 0;
        int c1 = 0;
        int c2 = 0;
        
        // Count the occurrences of each number
        for (int num : nums) {
            if (num == 0)
                c0++;
            else if (num == 1)
                c1++;
            else
                c2++;
        }

        // Fill the vector with the sorted order of 0s, 1s, and 2s
        std::fill(nums.begin(), nums.begin() + c0, 0);
        std::fill(nums.begin() + c0, nums.begin() + c0 + c1, 1);
        std::fill(nums.begin() + c0 + c1, nums.end(), 2);
    }
};
