class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusts(n + 1, 0);
        
        for (const auto& pair : trust) {
            trusts[pair[0]] -= 1;
            trusts[pair[1]] += 1;
        }
        for (int i = 1; i <= n; i++) {
            if (trusts[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
};
