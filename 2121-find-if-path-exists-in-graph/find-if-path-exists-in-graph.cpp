class DSU {
public:
    vector<int> parent, rank;


    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;   
    }

   
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
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        DSU ds(n);

        for(auto e:edges){
            int u=e[0];
            int v=e[1];

            ds.unite(u,v);
        }

        if(ds.find(source)==ds.find(destination))return true;

        return false;
    }
};