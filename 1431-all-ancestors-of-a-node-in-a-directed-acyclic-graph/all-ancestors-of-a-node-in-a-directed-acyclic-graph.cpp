class Solution {
public:
void dfs(vector<vector<int>>&adj,vector<int>&temp,int node,vector<int>&visited){

    for(auto x:adj[node]){
       if(!visited[x]){
        visited[x]=1;
         temp.push_back(x);
        dfs(adj,temp,x,visited);
       }
    }

//ans.push_back(temp);
}
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<vector<int>>ans;

        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            adj[v].push_back(u);
        }

        for(int i=0;i<n;i++){
            vector<int>visited(n,0);
             vector<int>temp;
             dfs(adj,temp,i,visited);
             sort(temp.begin(),temp.end());
             ans.push_back(temp);
        }

        return ans;
    }
};