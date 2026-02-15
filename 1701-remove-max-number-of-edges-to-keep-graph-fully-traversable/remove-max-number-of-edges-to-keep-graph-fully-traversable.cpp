class DSU {
public:
    vector<int> parent, rank,size;
    int component;


    DSU(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        size.resize(n+1);
        component = n;
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

        component--;
    }
    bool single(){
        return (component==1);
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n);
        DSU bob(n);
        auto lambda=[&](vector<int>&v1,vector<int>&v2){
            return v1[0]>v2[0];
        };
        sort(edges.begin(),edges.end(),lambda);
        int edgecount=0;

        for(auto &e:edges){
            int type=e[0];
            int u=e[1];
            int v=e[2];
            bool check=false;

            if(type==3){

                if(alice.find(u)!=alice.find(v)){
                    alice.unite(u,v);
                    check=true;
                }

                if(bob.find(u)!=bob.find(v)){
                    bob.unite(u,v);
                    check=true;
                }
                if(check==true)edgecount++;
            }else if(type==2){
                if(bob.find(u)!=bob.find(v)){
                bob.unite(u,v);
                edgecount++;
                }
            }else{
                if(alice.find(u)!=alice.find(v)){
                alice.unite(u,v);
                edgecount++;
                }
            }
        }

        if(alice.single()==true &&  bob.single()==true)return edges.size()-edgecount;

        return -1;
    }
};