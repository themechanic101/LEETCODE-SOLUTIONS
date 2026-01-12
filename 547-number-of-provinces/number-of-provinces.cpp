class Solution {
public:
    void dfs( vector<vector<int>>&list, int s_node,vector<int>&vis) {
        vis[s_node] = 1;
        for (auto it : list[s_node]) {
            if (!vis[it]) {
                dfs(list, it, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>list(n);
        // adj matrix to list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    list[i].push_back(j);
                    list[j].push_back(i);
                }
            }
        }

        vector<int>vis(n,0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(list, i, vis);
            }
        }
        return cnt;
    }
};