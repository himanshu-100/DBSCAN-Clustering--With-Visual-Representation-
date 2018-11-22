/*
	Author: @himkha_100
	Himanshu Khandelwal, NITW
*/
#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define s(t) scanf("%d",&t)
#define p(t) printf("%d\n",t)
#define pb push_back
#define f(t) for(int i=0;i<t;i++)
#define fi first
#define se second
#define all(t) t.begin(),t.end()
#define ci(t) cin>>t
#define co(t) cout<<t
#define mii map<int,int>
#define pii pair<int,int>
using namespace std;
struct node{
	int x;
	int y;
};
bool ac(node x,node y)
{
	return x.x<y.x;
}
inline bool operator<(const node& lhs, const node& rhs)
{
  return lhs.x < rhs.x;
}
int main()
{
	srand(time(NULL));
	ofstream out;
	node d[100];
	out.open("f17.txt");
	set<pii> s;
	f(100)
	{
		cout<<s.size()<<endl;
		d[i].x=rand()%20;
		d[i].y=rand()%20;
		pii temp;
		temp.fi=d[i].x;
		temp.se=d[i].y;
		if(s.count(temp)==1)
		{
			i--;
		}
		else
		{
			s.insert(temp);
		}
	}
	sort(d,d+100,ac);
	f(100)
	{
		out<<d[i].x<<" "<<d[i].y<<endl;
	}
	ifstream in;
	out.close();
	in.open("f17.txt");
	f(100)
	{
		in>>d[i].x;
		in>>d[i].y;
	}
	f(100)
	{
		cout<<d[i].x<<" "<<d[i].y<<endl;
	}
	in.close();
	return 0;
}


