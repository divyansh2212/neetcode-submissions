class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int,int>mp;
        for(int i=0; i<n; i++) {
            int second_element = target-nums[i];
            if(mp.find(second_element) != mp.end()) {
                return {mp[second_element], i};
            }
            mp[nums[i]] = i;
        }
        return {-1,-1};
    }
};
