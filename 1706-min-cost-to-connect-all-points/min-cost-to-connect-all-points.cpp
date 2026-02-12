class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>>adj(n);
        vector<int>visited(n,0);
        int sum=0;

        for(int i=0;i<n;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=0;j<n;j++){
                if(j==i)continue;
                int x2=points[j][0];
                int y2=points[j][1];

                int dis=abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({j,dis});
                 adj[j].push_back({i,dis});
            }
        }
             priority_queue<pair<int, int>,
		               vector<pair<int, int> >, greater<pair<int, int>>> pq;
                       visited[0] = 1;
                for (auto &it : adj[0]) {
                       pq.push({it.second, it.first});
                       }

		               
		 while(!pq.empty()){
		     auto it=pq.top();
		     pq.pop();
		     int edw=it.first;
		     int node=it.second;
		      if(visited[node]==1)continue;
		     
		     visited[node]=1;
		     sum+=edw;
		    
		     
		     for(auto &it:adj[node]){
		         int adj1=it.first;
		         int wt=it.second;
		         if(!visited[adj1]){
		             pq.push({wt,adj1});
		             
		         }
		     }
		 }
        
        
        return sum;
    }
};