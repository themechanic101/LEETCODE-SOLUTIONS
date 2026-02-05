class Solution {
public:
long long min; 
void dfs(vector<vector<int>>&adj, int node ,vector<bool>&visited,vector<int>& quiet){
    visited[node]=true;

    for(auto i:adj[node]){
           if(!visited[i])dfs(adj,i,visited,quiet);
    }

    if(min ==-1 || quiet[node]<quiet[min])min=node;
}
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int v=quiet.size();
        vector<vector<int>>adj(v);
        for(auto &e:richer){
            int u=e[0];
            int k=e[1];
            adj[k].push_back(u);
        }
        vector<int>ans(v);
      for(int i=0;i<v;i++){
             min=-1;
            vector<bool>visited(v,false);
            dfs(adj,i,visited,quiet);
            ans[i]=min;
      }

      return ans;

    }
};