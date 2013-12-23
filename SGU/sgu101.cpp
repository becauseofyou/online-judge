#include <cstdio>
#include <functional>
#include <vector>
const int N = 110;
struct node {
  int v;
  int id;
  char ch;
  node() {
  }
  node(int v,int id,char ch): v(v), id(id), ch(ch){}
};
std::vector<node> E[7];
bool vis[N];
std::vector<std::pair<int,char> > ans;
void add(int a,int b,int id) {
  E[a].push_back(node(b, id, '+'));
  E[b].push_back(node(a, id, '-'));
}
int in[N];
void dfs(int u,int id,char ch='*') {
  for(int i = 0; i < E[u].size(); i++) {
    if(!vis[E[u][i].id]) {
      vis[E[u][i].id] = true;
      dfs(E[u][i].v, E[u][i].id, E[u][i].ch);
    }
  }
  if(id != -1) ans.push_back(std::make_pair(id, ch));
}
int main() {
  int n, start;
  scanf("%d",&n);
  for(int i = 0, a, b; i < n; i++) {
    scanf("%d%d",&a,&b);
    add(a, b, i+1);
    in[a]++;
    in[b]++;
    start = a;
  }
  int cnt = 0;
  for(int i = 0; i <= 6; i++) 
    if(in[i]&1) cnt++, start = i; 
  if(cnt && cnt != 2) return puts("No solution");
  dfs(start,-1);
  for(int i = 1; i <= n; i++) if(!vis[i]) return puts("No solution"),0;
  for(int i = ans.size() - 1; i >= 0; i--) 
    printf("%d %c\n",ans[i].first,ans[i].second);
  return 0;
}
