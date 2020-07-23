#include<bits/stdc++.h>
using namespace std;

main(){
	string s;
	cin>>s;
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());

	if(s.length()%2==0)
		cout<<"CHAT WITH HER!"<<endl;
	else
		cout<<"IGNORE HIM!"<<endl;
	return 0;
}