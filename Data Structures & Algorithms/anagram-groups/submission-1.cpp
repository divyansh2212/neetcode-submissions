class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<vector<string>> ans;
        unordered_map<string, int> mp;

        for(int i=0; i<n; i++) {
            int m = strs[i].length();
            vector<int> hsh(26,0);
            for(char &ch: strs[i]) {
                hsh[ch-'a']++;
            }
            string key="";
            for(int j=0; j<26; j++) {
                if(hsh[j]) {
                    key.push_back(char('a'+j));
                    key += to_string(hsh[j]);
                    key.push_back('_');
                }
            }

            if(mp.find(key)==mp.end()) {
                mp[key] = ans.size();
                ans.push_back({strs[i]});
            }
            else {
                ans[mp[key]].push_back(strs[i]);
            }
        }

        return ans;
    }
};
