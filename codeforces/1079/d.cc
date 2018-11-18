// https://codeforces.com/contest/1079/problem/D
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
  double a,b,c,x1,y1,x2,y2;
  cin>>a>>b>>c>>x1>>y1>>x2>>y2;
  double d=fabs(x1-x2)+fabs(y2-y1);
  if(a!=0&&b!=0){
    double ya1=(double(-c)-double(a)*double(x1))/double(b);
    double xa1=(double(-c)-double(b)*double(y1))/double(a);
    double ya2=(double(-c)-double(a)*double(x2))/double(b);
    double xa2=(double(-c)-double(b)*double(y2))/double(a);
    double d1=fabs(y1-ya1)+fabs(y2-ya2)+sqrt((x2-x1)*(x2-x1)+(ya2-ya1)*(ya2-ya1));
    double d2=fabs(y1-ya1)+fabs(x2-xa2)+sqrt((xa2-x1)*(xa2-x1)+(y2-ya1)*(y2-ya1));
    double d3=fabs(x1-xa1)+fabs(y2-ya2)+sqrt((x2-xa1)*(x2-xa1)+(ya2-y1)*(ya2-y1));
    double d4=fabs(x1-xa1)+fabs(x2-xa2)+sqrt((xa2-xa1)*(xa2-xa1)+(y2-y1)*(y2-y1));
    d=min(d,d1);
    d=min(d,d2);
    d=min(d,d3);
    d=min(d,d4);
  }
  cout<<setprecision(20)<<d<<endl;
}
