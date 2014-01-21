#include <cstdio>
#include <cstring>
#include <algorithm>
bool flag[10000];
int p[110], pn, a[100][110];
void init() {
  for(int i = 2; ; i++) {
    if(!flag[i]) p[pn++] = i;
    if(pn == 100) break;
    for(int j = 0; j < pn && i * p[j] < 10000; j++) {
      flag[i*p[j]] = true;
      if(i % p[j] == 0) break;
    }
  }
}
void print(int p) {
  if(p == 0) {
    printf("0\n");
    return ;
  }
  static int a[110], b[110];
  a[0] = 2;
  for(int i = 0; i < p - 1; i++) {
    for(int j = 0; j < 100; j++) {
      b[j] = b[j] + (a[j] + a[j]) % 10;
      b[j + 1] += (a[j] + a[j]) / 10;
    }
    memcpy(a, b, sizeof(b));
    memset(b, 0, sizeof(b));
  }
  int takeover = 0;
  if(a[0] >= 1) {
    a[0] -= 1;
  } else {
    a[0] = 9;
    takeover = 1;
  }
  for(int i = 1; i < 100 && takeover; i++) {
    if(a[i] >= 1) {
      a[i] -= 1;
      takeover = 0;
    } else {
      a[i] = 9;
    }
  }
  int j = 100;
  while(a[j] == 0) j--;
  for(int i = j; i >= 0; i--) {
    printf("%d",a[i]);
  }
  puts("");
}
void gauss(int a[][110],int equation, int variable) {
  int col = 0, row = 0;
  for(;row < equation && col < variable; row++, col++) {
    int max_row = row;
    for(int i = row + 1; i < equation; i++) {
      if(a[i][col]) {
        max_row = i;
      }
    }
    if(a[max_row][col] == 0) {
      row --;
      continue;
    }
    if(max_row != row) {
      for(int i = col; i <= variable; i++) {
        std::swap(a[max_row][i], a[row][i]);
      }
    }
    for(int i = 0; i < equation; i++) {
      if(i != row) {
        if(!a[i][col]) continue;
        for(int j = col; j <= variable; j++) {
          a[i][j] ^= a[row][j];
        }
      }
    }
  }
  print(variable - row);
}
int main() {
  init();
  int n, m, v;
  scanf("%d%d",&n,&m);
  for(int i = 0; i < m; i++) {
    scanf("%d",&v);
    for(int j = 0; j < pn; j++) {
      if(v % p[j] == 0) {
        int f = 0;
        while(v % p[j] == 0) {
          v /= p[j];
          f ^= 1;
        }
        a[j][i] = f;
      }
    }
  }
  for(int i = 0; i < n; i++) a[i][m] = 0;
#ifdef wuyiqi
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      printf("%d ",a[i][j]);
    }
    puts("");
  }
#endif
  gauss(a, n, m);
}
