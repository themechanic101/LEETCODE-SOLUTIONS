class Solution {
public:

void dfs(int node, vector<int>&visited, vector<vector<int>>&adj){
    visited[node]=1;

    for(auto it:adj[node]){
        if(!visited[it])dfs(it,visited,adj);
    }
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cnt=0;
        int edges=connections.size();
        if(edges<n-1)return -1;
       vector<vector<int>>adj(n);

       for(auto i:connections){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
       }

       vector<int>visited(n,0);

       for(int i=0;i<n;i++){
        if(!visited[i]){
            cnt++;
            dfs(i,visited,adj);
        }
       }

       return cnt-1;
    }
};