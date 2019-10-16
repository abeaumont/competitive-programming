#include<bits/stdc++.h>
using namespace std;

long int solve(long int arr[], long int n)
{
    long int count = 0;
    for(long int i=0;i<=n-1;i++)
    {
        long int j = i-1;
        long int flag = 0;
        while(j>=i-5 && j>=0)
        {
            if(arr[j] <= arr[i])
            {
                flag = 1;
                break;
            }
            j-=1;
        }
        if(flag == 0)
            count+=1;
    }
    return count;
}

int main()
{
    long int test, n, arr[1000];
    cin>>test;
    while(test--)
    {
        cin>>n;
        for(long int i=0;i<=n-1;i++)
            cin>>arr[i];
        cout<<solve(arr, n)<<endl;
    }
}
