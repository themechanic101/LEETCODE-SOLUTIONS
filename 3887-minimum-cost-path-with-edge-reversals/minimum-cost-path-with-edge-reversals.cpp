class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
       
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n,INT_MAX);
        dist[0]=0;
        //{cost,node}
        pq.push({0,0});

        while(!pq.empty()){
            auto[cost,u]=pq.top();
            pq.pop();

            for(auto e:adj[u]){
                int v=e.first;
                int w=e.second;

                int cv=cost+w;

                if(cv<dist[v]){
                    dist[v]=cv;
                    pq.push({cv,v});
                }
            }
        }
        return dist[n-1]==INT_MAX?-1:dist[n-1];
    }
};