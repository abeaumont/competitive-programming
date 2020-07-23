#include<bits/stdc++.h>
using namespace std;

main(){
	int arr[5][5],a,b;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j]==1)
			{
				a=i;
				b=j;
				break;
			}
		}
	}

	cout<<abs(a-2) + abs(b-2)<<endl;
	return 0;
}