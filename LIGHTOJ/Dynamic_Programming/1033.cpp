#include <cstdio>
#include <cstring>
#include <set>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <time.h>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair
#define foreach(it, x) for(typeof(x.begin()) it = x.begin(); it!=x.end();it++)

typedef __int64 lld;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;
#define rep(i,n) for(int i=0;i<n;i++)
#define For(i,a,b) for(int i=a;i<b;i++)
template <class T>  void Min(T &x, T y){if(y < x) x = y;}
template <class T>  void Max(T &x,T y){if(y > x) x = y;}
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn  =  100010;
const int inf  = ~0u>>2;
int dp[110][110];
inline int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int t,ca=1,i,j,k;
	scanf("%d",&t);
	char s1[110],s2[110];
	while(t--)
	{
		scanf("%s",s1+1);
        int len = strlen(s1+1);
		strcpy(s2+1,s1+1);
		reverse(s2+1,s2+len+1);
		fill(dp[0],dp[len+1],inf);
		for(i = 0; i <= len; i++)
		{
			for(j = 0; j <= len; j++)
			{
				if(i == 0 && j ==0) 
				{
					dp[i][j] = 0;
				}
                else if(i == 0)
				{
					dp[i][j] = j;
				}
				else if(j == 0)
				{
					dp[i][j] = i;
				} 
				else 
				{
					if(s1[i] == s2[j])
					{
						dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                        dp[i][j] = min(dp[i][j],min(dp[i-1][j]+1,dp[i][j-1]+1));
					}
					else 
					{
						dp[i][j] = min(dp[i-1][j]+1,dp[i][j-1]+1);
					}
				}
			}
		}
		printf("Case %d: %d\n",ca++,dp[len][len]/2);
	}
	return 0;
}