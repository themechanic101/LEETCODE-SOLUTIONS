class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>ans;
        vector<int>indegree(numCourses,0);

        for(auto x:prerequisites){
            int u=x[0];
            int v=x[1];
            adj[v].push_back(u);
            indegree[x[0]]++;
        }

    queue<int>q;
        for(int i=0;i<numCourses;i++){
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

        return ans.size()==numCourses;
    }
};