// https://cses.fi/problemset/task/1670
// A better way to do task 1670.

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
set<ll> perm;
void permute(string s,ll curr)
{
    if(curr==s.length()-1)
    perm.insert(stoll(s));
   ll i,j,k,l;
   for(i=curr;i<s.length();i++)
   {
       swap(s[curr],s[i]);
       permute(s,curr+1);
       swap(s[curr],s[i]);
   }
}
int dp[400001],vis[400001];
vector<pair<ll,ll>> path={{0,1},{0,3},{1,4},{1,2},{2,5},{3,6},{3,4},{4,7},{4,5},{6,7},{7,8},{5,8}};
ll arr[400001];
ll mip(ll val)
{
    ll start=1,end=362880,mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(arr[mid]>val)
        end=mid-1;
        else if(arr[mid]<val)
        {
            start=mid+1;
        }
        else 
        {
            return mid;
        }
    }
    return mid;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll i,j,k,l,m,n,o,p,q,r,t,b[10];
    b[0]=1;
    for(i=1;i<=9;i++)
    {
        b[i]=b[i-1]*11;
    }
    string a="123456789";
    for(i=0;i<=400000;i++)
    {
        dp[i]=INT_MAX;
        vis[i]=0;
    }
    for(i=0;i<9;i++)
    {
        cin>>a[i];
    }
    string s="123456789";
    permute(s,0);
    l=1;
    for(auto it:perm)
    {
        arr[l]=it;
        l++;
    }
    dp[1]=0;
    queue<string> pq;
    pq.push(s);
    vis[1]=1;
    r=mip(stoll(a));
    while(!pq.empty())
    {
        string aa=pq.front();
        pq.pop();
        ll u=mip(stoll(aa));
                 if(u==r)
                 {
                     cout<<dp[u]<<endl;
                     return 0;
                 }
        for(auto it:path)
        {
             swap(aa[it.first],aa[it.second]);
             p=mip(stoll(aa));
             if(!vis[p])
             {
                 vis[p]=1;
                 dp[p]=min(dp[p],dp[u]+1);
                 pq.push(aa);
                 if(p==r)
                 {
                     cout<<dp[p]<<endl;
                     return 0;
                 }
             }
             swap(aa[it.first],aa[it.second]);
        }
    }
    return 0;
}

/*#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using vi = vector<int>;

int n = 9*8*7*6*5*4*3*2;

int index(vi &v) {
  int m = 1, r = 0, k = n / 9;
  for (int i = 0; i < 8; i++) {
    int d = v[i];
    int e = (d - __builtin_popcount(m & ((1 << d) - 1)));
    r += e * k;
    k /= 8 - i;
    m |= (1 << d);
  }
  return r;
}

vi permutation(int r) {
  vi v(9);
  int m = 1, k = n / 9;
  for (int i = 0; i <= 8; i++) {
    int d = r / k;
    int j = 0, l = 1;
    while (j <= d) {
      if (!(m & (1 << l))) j++;
      if (j > d) break;
      l++;
    }
    v[i] = l;
    if (i == 8) break;
    r %= k;
    k /= 8 - i;
    m |= (1 << l);
  }
  return v;
}

int main() {
  int x, a, b;
  vi v(9, 0);
  for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) cin >> x, v[i*3+j] = x;
  int t = index(v);
  vi d(n);
  d[0] = 1;
  queue<int> q;
  q.push(0);
  while (1) {
    tie(x) = q.front();
    q.pop();
    if (t == x) {
      cout << d[x] - 1 << "\n";
      break;
    }
    ii z[] = {{0,1},{1,2},{3,4},{4,5},{6,7},{7,8},{0,3},{1,4},{2,5},{3,6},{4,7},{5,8}};
    vi v = permutation(x);
    for (ii y : z) {
      tie(a, b) = y;
      swap(v[a], v[b]);
      int i = index(v);
      if (!d[i]) {
        d[i] = d[x] + 1;
        q.push(i);
      }
      swap(v[a], v[b]);
    }
  }
}
*/