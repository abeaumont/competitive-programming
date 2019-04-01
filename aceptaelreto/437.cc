// https://www.aceptaelreto.com/problem/statement.php?id=437
#include<bits/stdc++.h>
using namespace std;
int main(){ 
  int n,a,b,c;
  cin>>n;
  while(n--){
    scanf("%d:%d:%d\n",&a,&b,&c);
    int t=24*3600;
    t-=a*60*60+b*60+c;
    int h=t/3600;
    t=t%3600;
    int m=t/60;
    t=t%60;
    printf("%02d:%02d:%02d\n",h,m,t);
  }
}
