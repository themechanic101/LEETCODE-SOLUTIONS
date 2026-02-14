class DSU {
public:
    vector<int> parent, rank,size;


    DSU(int n) {
        parent.resize(n);
        rank.resize(n+1, 0);
        size.resize(n+1,0);
        for (int i = 0; i <n; i++){
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
 vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
    DSU dsu(n);
        for( int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }

        auto lambda=[&](vector<int>& v1,vector<int>& v2){
            return v1[2]<v2[2];
        };

        sort(queries.begin(),queries.end(),lambda);
        sort(edgeList.begin(),edgeList.end(),lambda);

        vector<bool>ans(queries.size());

        int j=0;//points to edges

        for(int i=0;i<queries.size();i++){
           vector<int>q=queries[i];

           int u=q[0];
           int v=q[1];
           int l=q[2];
           int index=q[3];

           while(j<edgeList.size() && edgeList[j][2]<l){
             dsu.unite(edgeList[j][0],edgeList[j][1]);
             j++;
           }

           if(dsu.find(u)==dsu.find(v))ans[index]=true;
           else ans[index]=false;
        }


        return ans;


      
    }
};