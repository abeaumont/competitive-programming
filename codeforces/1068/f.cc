// https://codeforces.com/contest/1068/problem/F
#include <cstdio>

int main() {
  int n; scanf("%d",&n);
  for (int i=0,m=0; m<n && i<3; i++)
    for (int j=0; m<n && j<=n/3; j++,m++)
      printf("%d %d\n",i/3*8+1+(i%3==1)*3,j*2+1+(i!=0));
}
