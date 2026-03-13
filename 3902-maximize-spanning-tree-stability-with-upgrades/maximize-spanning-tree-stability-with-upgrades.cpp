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
    bool check(int n, vector<vector<int>>& edges, int k, int stability) {
    DSU dsu(n);
    int upgradeused=0;
    vector<tuple<int,int,int,bool>>optionaledges;

    for(auto &e:edges){
        int u=e[0],v=e[1],s=e[2],must=e[3];


        if(must==1){
            if(s<stability)return false;
            dsu.unite(u,v);
        }else{
            if(s>=stability){
                dsu.unite(u,v);
            }else if(2*s>=stability){
               optionaledges.emplace_back(2*s,u,v,true);
            }
        }
    }

    for(auto &[s,u,v,upgraded] :optionaledges){
        if(dsu.find(u)!=dsu.find(v)){
            if(upgradeused>=k)return false;

            dsu.unite(u,v);
            upgradeused++;
        }

    }

    int root=dsu.find(0);
    for(int i=1;i<n;i++)
        if(dsu.find(i)!=root)
            return false;

    return true;
}

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU dsu(n);
      

        int ans = -1;
        int l = 1, r = 0;
        for (auto &e : edges) {
            int u=e[0];
            int v=e[1];
            int s=e[2];
            int m=e[3];

            if(m==1){
                if(!dsu.unite(u,v))return -1;
                r=max(r,s);
            }else{
                 r=max(r,2*s);
            }
        }

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(n, edges, k, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return ans;
    }
};