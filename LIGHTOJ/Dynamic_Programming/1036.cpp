#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int a[510][510],b[510][510];   
int dp[510][510];
int sa[510][510] , sb[510][510];
int n , m;
void input()
{
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    //memset(dp,0,sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
        for(int j = 1; j <= m; j++)
        {
            dp[i][j] = 0;
            scanf("%d",&b[i][j]);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            sa[i][j] = sa[i-1][j] + sa[i][j-1] + a[i][j] - sa[i-1][j-1];
            sb[i][j] = sb[i-1][j] + sb[i][j-1] + b[i][j] - sb[i-1][j-1];
        }
    }
}
inline int get(int sa[][510],int i,int j,int pre)
{
    return sa[n][j]-sa[i-1][j]-sa[n][pre]+sa[i-1][pre];
}
int main()
{
//#ifdef ONLINE_JUDGE
//	freopen("a.txt","r",stdin);
//	freopen("bcmp.txt","w",stdout);
//#endif
    int t,ca=1;
    scanf("%d",&t);
    while(t--)
    {
		//scanf("%*s%*s");
        input();
        for(int i = 1; i <= n; i++) dp[i][0] = sb[n][m] , dp[i][1] = sb[n][m]-(sb[n][1]-sb[i-1][1])+(sa[n][1]-sa[i-1][1]);
        //printf("%d\n",-(sb[n][1]-sb[0][1])+(sa[n][1]-sa[0][1]));
        //printf("%d\n",dp[1][1]);
        for(int i = 1; i <= m; i++)
        {
            dp[1][i] = sb[n][m] - sb[n][i] + sa[n][i];
        }
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                dp[i][j] = dp[i-1][j];
                dp[i][j] = max(dp[i][j],dp[i-1][0]-(sb[n][j]-sb[i-1][j])+sa[n][j]-sa[i-1][j]);
                for(int pre = 1; pre < j; pre++)
                {
                    dp[i][j] = max(dp[i][j],dp[i-1][pre]+get(sa,i,j,pre)-get(sb,i,j,pre));
                    //printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
                }
            }
        }
		//printf("%d\n",dp[2][2]);
    //  printf("%d %d\n",sa[n][m],sb[n][m]);
        int ans = max(sa[n][m],sb[n][m]);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
             // if(dp[i][j] > ans) printf("i=%d j=%d\n",i,j);
                ans = max(ans,dp[i][j]);
            }
        }
        printf("Case %d: %d\n",ca++,ans);
    }
    return 0;
}
/*
 
5
2 4
1 5 6 4
11 4 4 6
1 22 1 54
1 212 11 13
 
325
 
 
5
4 4
1 5 6 8
9 8 6 5
2 6 8 7
6 5 5 4
 
4 5 6 3
1 2 3 4
1 1 4 9
1 5 9 7
93
*/