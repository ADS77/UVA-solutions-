#include <bits/stdc++.h>
using namespace std;
int grid [1000][1000];
bool vis[1000][1000];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int dist[1000][1000];
int row,col;
#define pi pair<int,int>
bool isvalid(int x, int y)
{
    if(x<row && x>=0 && y<col && y>=0 && vis[x][y]!=1)
        return true;
    else return false;
}
void bfs(int x,int y)
{
    queue<pi>q;
    q.push({x,y});
    vis[x][y]=1;
    while(!q.empty())
    {
        pi curr = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = curr.first+dx[i];
            int ny = curr.second+dy[i];
            if(isvalid(nx,ny))
            {
                q.push({nx,ny});
                vis[nx][ny]=1;
                dist[nx][ny]=dist[curr.first][curr.second]+1;
            }
        }
    }

}
int main()
{
 while(cin>>row>>col)
 {
           int bmb;

     if(row == 0 && col == 0)break;
      cin>>bmb;
      int rown,coln,bmbn;
        memset(dist,0,sizeof(dist));
        memset(vis,0,sizeof(vis));
      for(int i=0;i<bmb;i++)
      {
          cin>>rown>>bmbn;
          for(int j=0;j<bmbn;j++)
          {
              cin>>coln;
              vis[rown][coln]=1;
          }
      }
        int startx,starty,endx,endy;
  cin>>startx>>starty>>endx>>endy;
  bfs(startx,starty);
  cout<<dist[endx][endy]<<endl;;

 }


}
