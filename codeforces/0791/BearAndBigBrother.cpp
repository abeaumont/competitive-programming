#include <bits/stdc++.h>
using namespace std;

main(){
	int a,b, count=0;
	cin>>a>>b;

	while(!(a>b)){
		a*=3;
		b*=2;
		count++;
	}
	cout<<count<<endl;
	return 0;
}