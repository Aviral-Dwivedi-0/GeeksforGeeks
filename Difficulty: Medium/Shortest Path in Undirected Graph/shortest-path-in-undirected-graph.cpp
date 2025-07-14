class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        vector<int> visited(adj.size(),INT_MAX);
        visited[src]=0;
        queue<pair<int,int>> q;
        q.push({src,0});
        while(!q.empty()){
            int node=q.front().first;
            int distance=q.front().second;
            q.pop();
            for(auto i:adj[node]){
                // if(visited[i]==INT_MAX){
                //     q.push({i,distance+1});
                //     continue;
                // }
                // visited[i]=min(visited[i],distance+1);
                if(visited[i]> distance+1){
                    visited[i]=distance+1;
                    q.push({i,distance+1});
                }
            }
            distance++;
        }
        for(int i=0;i<visited.size();i++){
            if(visited[i]==INT_MAX) visited[i]=-1;
        }
        return visited;
    }
};