class Solution {
    
    bool isVowel(char ch) {
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }

public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        int n = words.size();
        int q = queries.size();

        vector<int> prefix(n,0);
        for(int i=0; i<n; i++) {
            int m = words[i].length();
            if(isVowel(words[i][0]) && isVowel(words[i][m-1])) {
                prefix[i] = 1;
            }
            if(i>0) prefix[i] += prefix[i-1];
        }

        vector<int> ans(q, 0);
        for(int i=0; i<q; i++) {
            ans[i] = prefix[queries[i][1]];
            if(queries[i][0] > 0) {
                ans[i] -= prefix[queries[i][0]-1];
            }
        }

        return ans;
    }
};