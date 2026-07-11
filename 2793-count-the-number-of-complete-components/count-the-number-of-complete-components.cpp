class Solution {
public:
    void dfs(int st,vector<vector<int>> &adj,vector<bool>&vis,int &nodes,int &edges){
        vis[st]=1;
        nodes++;
        edges+=adj[st].size();
        for(int neigh:adj[st]){
            if(vis[neigh]==0){
                dfs(neigh,adj,vis,nodes,edges);
            }
        }

    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        int cnt=0;
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                int nodes=0,edgecnt=0;
                dfs(i,adj,vis,nodes,edgecnt);
                edgecnt/=2;
                if(edgecnt==nodes*(nodes-1)/2)
                  cnt++;
            }
        }
        return cnt;
    }
};