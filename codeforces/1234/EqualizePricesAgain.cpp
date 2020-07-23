#include <bits/stdc++.h>
using namespace std;

main(){
	int t,m,n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		long long total=0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &m);
			total += m;
		}
		if (total%n==0)
			cout<<total/n<<endl;
		else
			cout<<total/n+1<<endl;
	}
	return 0;
}