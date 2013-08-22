#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int inf = ~0u>>2;
int dp[20][20];
int n;
int f[1<<16];
struct point {
	int x,y;
}in[20];
int cross(point a,point b,point c){return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);}
bool col(int a,int b,int c){
	return cross(in[a],in[b],in[c])==0;
}
void init(){
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=0;k<n;k++){
				if(col(i,j,k)){
					dp[i][j]+=(1<<k);
				}
			}
		}
	}
}
int DP(int s)
{
	if(f[s]!=inf) return f[s];
	int cnt=0;
	for(int i=0;i<n;i++) if(s&(1<<i)) cnt++;
	if(cnt==0) return f[s]=0;
	if(cnt<=2) return f[s]=1;
	for(int i=0;i<n;i++)if(s&(1<<i))
	{
		for(int j=i+1;j<n;j++)if(s&(1<<j))
		{
			f[s]=min(f[s],DP(s-(s&dp[i][j]))+1);
		}
		break;
	}
	return f[s];
}
int main()
{
	int t,ca=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++) 
		{
			scanf("%d%d",&in[i].x,&in[i].y);
		}
		init();
		fill(f,f+(1<<16),inf);
		printf("Case %d: %d\n",ca++,DP((1<<n)-1));
	}
	return 0;
}