class DSU {
public:
    vector<int> parent, rank,size;


    DSU(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        size.resize(n+1);
    
        for (int i = 0; i <=n; i++){
            parent[i] = i;
            size[i]=1;   
    }}

   
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

   
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;   

        if (rank[px] < rank[py]) {
            parent[px] = py;
        } 
        else if (rank[px] > rank[py]) {
            parent[py] = px;
        } 
        else {
            parent[py] = px;
            rank[px]++;
        }

    
    }
   

    void unionbysize(int u,int v){
        int pu=find(u);
        int pv=find(v);

        if(pu==pv)return;

        if(size[pu]<size[pv]){
            size[pv]+=size[pu];
            parent[pu]=pv;
        }else{
            size[pu]+=size[pv];
            parent[pv]=pu;
        }
    }
    
};
class Solution {
public:
bool areSimilar(const string &a, const string &b) {
    if (a == b) return true;
    if (a.size() != b.size()) return false;

    vector<int> diff;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) diff.push_back(i);
    }

    if (diff.size() == 2) {
        return (a[diff[0]] == b[diff[1]] && a[diff[1]] == b[diff[0]]);
    }
    return false;
}
void dfs(int u, vector<vector<int>> &adj, vector<int> &visited, vector<int> &group) {
    visited[u] = 1;
    group.push_back(u);
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v, adj, visited, group);
    }
}

    int numSimilarGroups(vector<string>& strs) {
        vector<vector<int>>adj(strs.size());

        for(int i=0;i<strs.size();i++){
            for(int j=i+1;j<strs.size();j++){
                if(areSimilar(strs[i],strs[j])){
                    adj[i].push_back(j);
                     adj[j].push_back(i);
                }
            }
        }
        vector<vector<string>>group;
        vector<int>visited(strs.size(),0);
        for(int i=0;i<strs.size();i++){
            if(!visited[i]){
                vector<int>temp;
                dfs(i,adj,visited,temp);
                vector<string>g;
                for(auto idx:temp)g.push_back(strs[idx]);
                group.push_back(g);
            }
        }
   return group.size();
    }
};