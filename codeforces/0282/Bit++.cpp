#include <bits/stdc++.h>
using namespace std;

main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int n, plus=0, minus=0;
	string s;
	scanf("%d", &n);
	while(n--){
		cin>>s;
		if(s[1]=='+')
			plus++;
		else
			minus++;
	}

	cout<<plus-minus<<endl;
	return 0;
}