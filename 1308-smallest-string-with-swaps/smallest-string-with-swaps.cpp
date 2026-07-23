class DSU{
    public:

    vector<int>parent,size;

    DSU(int n){
        parent.resize(n);
        size.resize(n,1);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }


    int find(int x){
        if(parent[x]==x)return x;

        return parent[x]=find(parent[x]);
    }

    void unite( int u ,int v){
        int pu=find(u);
        int pv=find(v);

        if(pu==pv)return ;
   
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
     
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();

       DSU dsu(n);

       for(auto p:pairs){
        dsu.unite(p[0],p[1]);
       }

 unordered_map<int, vector<int>>groupidx;
        unordered_map<int,string>groupchars;
       for(int i=0;i<n;i++){
        int root=dsu.find(i);
        groupidx[root].push_back(i);
        groupchars[root].push_back(s[i]);
       }


       string res=s;
        for(auto x: groupidx)
        {
            int root= x.first;
            vector<int> indices= x.second;
            string chars= groupchars[root];
            sort(chars.begin(), chars.end());

            for(int k=0;k<indices.size();k++)
            {
                res[indices[k]]=chars[k];
            }

        }
        return res;
    }
};