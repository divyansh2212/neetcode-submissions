class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        string ans = strs[0], curr = strs[0];
        for(int i=1; i<n; i++) {
            string curr = "";
            for(int j=0; j<strs[i].length() && ans.length(); j++) {
                if(ans[j]==strs[i][j]) {
                    curr.push_back(strs[i][j]);
                }
                else break;
            }
            ans = curr;
        }
        return ans;
    }
};