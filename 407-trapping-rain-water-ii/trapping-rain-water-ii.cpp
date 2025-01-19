#define p1 pair<int,int>
#define p2 pair<int,p1>

class Solution {
public:
    int m,n;
    bool isValid(int x,int y){
        return min(x,y)>=0 && x<m && y<n;
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        m=heightMap.size();
        n=heightMap[0].size();
        vector<vector<bool>> visited(m+1,vector<bool>(n+1,false));
        priority_queue<p2,vector<p2>,greater<p2>> pq;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    pq.push({heightMap[i][j],{i,j}});
                }

            }
        } 
        int ans=0;
        while(!pq.empty()){
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            int h=pq.top().first;
            pq.pop();
            if(visited[i][j]) continue;
            visited[i][j]=1;
            ans+=h-heightMap[i][j];

            for(int k=0;k<4;k++){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(isValid(nx,ny) && !visited[nx][ny]){
                    pq.push({max(h,heightMap[nx][ny]),{nx,ny}});
                }
            }
        }      
        return ans;
    }
};