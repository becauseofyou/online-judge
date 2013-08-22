#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int pt[110],n;
double f[110];
int main()
{
	int t,ca=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i = 1; i <= n; i++) scanf("%d",&pt[i]);
		memset(f,0,sizeof(f));
		f[n] = pt[n]; 
		for(int i = n-1; i >= 1; i--)
		{
			f[i] = pt[i];
			for(int j = 1; j <= 6; j++)
			{
				f[i] += f[i+j]*1.0/min(6,n-i);
			}
		}
		printf("Case %d: %lf\n",ca++,f[1]);
	}
	return 0;
}