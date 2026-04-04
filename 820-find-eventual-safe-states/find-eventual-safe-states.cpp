class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
         vector<vector<int>>adj(V);  
        vector<int>indegree(V,0);  

        for (int i = 0; i < V; i++) {
            for (auto it : graph[i]) {
                adj[it].push_back(i);  
                indegree[i]++;  
            }
        }


        vector<int>ans;
        queue<int>q;

        for(int i=0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }

        
        while(!q.empty()){
             auto a=q.front();
             ans.push_back(a);
             q.pop();

             for(auto e:adj[a]){
                indegree[e]--;
                if(indegree[e]==0)q.push(e);
             }
        }
       sort(ans.begin(),ans.end());
        return ans;
    }
};