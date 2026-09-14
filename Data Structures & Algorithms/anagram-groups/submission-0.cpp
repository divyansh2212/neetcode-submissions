class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<vector<string>> ans;
        map<vector<int>, int> mp;

        for(int i=0; i<n; i++) {
            int m = strs[i].length();
            vector<int> hsh(26,0);
            for(char &ch: strs[i]) {
                hsh[ch-'a']++;
            }

            if(mp.find(hsh)==mp.end()) {
                mp[hsh] = ans.size();
                ans.push_back({strs[i]});
            }
            else {
                ans[mp[hsh]].push_back(strs[i]);
            }
        }

        return ans;
    }
};
