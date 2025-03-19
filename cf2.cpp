#include <bits/stdc++.h>
using namespace std;
bool findAns(int lily,int alice,int bob)
{
	vector<int>v(lily,0);
	v[alice-1]=1;
	v[bob-1]=2;
	int first=-1;
	int second=-1;
	alice--;
	bob--;
	while(true)
	{
		first=-1;
		second=-1;
		for(int i=0;i<lily;i++)
		{
			if(first==-1 && v[i]==1)
			{
				first=i;
			}
			if(second==-1 && v[i]==2)
				second=i;
		}
		if(first<second)
		{
			if(v[first+1]==0)
			{
				v[alice]=0;
				v[first+1]=1;
				alice=first+1;
			}
			else{
				return false;
			}
			if(v[second-1]==0)
			{
				v[bob]=0;
				v[second-1]=2;
				bob=second-1;
			}
			else{
				return true;
			}
			first++;
			second--;
		}
		else{
			if(v[first-1]==0)
			{
				v[alice]=0;
				v[first-1]=1;
				alice=first-1;
			}
			else{
				return false;
			}
			if(v[second+1]==0)
			{
				v[bob]=0;
				v[second+1]=2;
				bob=second+1;
			}
			else{
				return true;
			}
			first--;
			second++;
		}
	}
}
int main()
{
	int x;
	cin>>x;
	for(int i=0;i<x;i++)
	{
		int lily,alice,bob;
		cin>>lily>>alice>>bob;
		bool func=findAns(lily,alice,bob);
		if(func) cout<<"YES"<<endl;
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
	
}