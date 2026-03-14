class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pv] > rank[pu]) {
            parent[pu] = pv;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
        return true;
    }
};
class Solution {
public:

void dfs(int node,vector<vector<int>>&adj,long long &cnt,vector<int>&visited){
    visited[node]=1;
    cnt++;

    for(auto &it:adj[node]){
        if(!visited[it])dfs(it,adj,cnt,visited);
    }
}
    long long countPairs(int n, vector<vector<int>>& edges) {
       
long long ans=1LL*n*(n-1)/2;
        vector<vector<int>>adj(n);

        for(auto &e:edges){
           adj[e[0]].push_back(e[1]);
           adj[e[1]].push_back(e[0]);
        }
    vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                long long cnt=0;
                dfs(i,adj,cnt,visited);
                ans-=cnt*(cnt-1)/2;
            }
        }

  return ans;
    }
};