#include<bits/stdc++.h>
using namespace std;

long int solve(long int n, long int m, vector<pair<long int, long int> >q)
{
    long int row[n] = {0};
    long int col[m] = {0};
    long int row_odd = 0;
    long int row_even = 0;
    long int col_odd = 0;
    long int col_even = 0;
    vector<pair<long int, long int> >::iterator qt;
    for(qt = q.begin();qt!=q.end();qt++)
    {
        row[(qt->first)-1] += 1;
        col[(qt->second)-1] += 1;
    }
    for(int i=0;i<=n-1;i++)
    {
        if(row[i]%2==0)
            row_even+=1;
        else
            row_odd+=1;
    }
    for(int i=0;i<=m-1;i++)
    {
        if(col[i]%2==0)
            col_even+=1;
        else
            col_odd+=1;
    }
    return row_even*col_odd + row_odd*col_even;
}

int main()
{
long int test, n, m, k, t1, t2;
vector<pair<long int, long int> >q;
cin>>test;
while(test--)
{
    cin>>n>>m>>k;
    for(int i=0;i<=k-1;i++)
    {
        cin>>t1>>t2;
        q.push_back(make_pair(t1, t2));
    }
    cout<<solve(n, m, q)<<endl;
}
}
