class Solution {
    void pairs(vector<int>& nums, vector<vector<int>>& res, int i, int j, int candi) {
        while (i < j) {
            if (nums[i] + nums[j] > candi) {
                j--;
            } else if (nums[i] + nums[j] < candi) {
                i++;
            } else {
                res.push_back({-candi, nums[i], nums[j]});
                i++;
                j--;
                while (i < j && nums[i] == nums[i - 1]) i++;
                while (i < j && nums[j] == nums[j + 1]) j--;
            }
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int candi = -nums[i];
            pairs(nums, res, i + 1, n - 1, candi);
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            unordered_set<int> seen;
            for (int j = i + 1; j < nums.size(); ++j) {
                int complement = -nums[i] - nums[j];
                if (seen.find(complement) != seen.end()) {
                    res.push_back({nums[i], complement, nums[j]});
                    while (j + 1 < nums.size() && nums[j] == nums[j + 1])
                        ++j;
                }
                seen.insert(nums[j]);
            }
        }
        return res;
    }
};
