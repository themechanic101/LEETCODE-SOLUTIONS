class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);

        for(auto &e:invocations){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
        }


        vector<int>vis(n,0);
        vis[k]=1;

        queue<int>q;
        q.push(k);

        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(int v:adj[u]){
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }

        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if (vis[u] == 0 && vis[v] == 1) {
                
                vector<int> ans;

                for (int i = 0; i < n; i++)
                    ans.push_back(i);

                return ans;
            }
        }


        vector<int>ans;

        for(int i=0;i<n;i++){
            if(vis[i]==0)ans.push_back(i);
        }

        return ans;
    }
};