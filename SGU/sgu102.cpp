#include <cstdio>
#include <vector>
std::vector<int> pri;
int ans, n, nn;
void dfs(int d,int mul,int ones) {
  if(d == pri.size()) {
      ans += nn / mul * ((ones&1) ? -1 : 1 );
      return ;
  }
  dfs(d + 1, mul * pri[d], ones+1);
  dfs(d + 1, mul, ones);
}
int main() {
  scanf("%d",&n);
  nn = n;
  for(int i = 2; i * i <= n; i++) {
    int cnt = 0;
    while(n % i == 0) {
      n /= i;
      cnt++;
    }
    if(cnt) pri.push_back(i);
  }
  if(n > 1) pri.push_back(n);
  dfs(0, 1, 0);
  printf("%d\n", ans);
}
