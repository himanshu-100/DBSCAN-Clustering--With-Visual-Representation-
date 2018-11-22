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
#define eps 5
#define siz 100
#define minp 2
using namespace std;
struct node{
	int x;
	int y;
};
inline bool operator<(const node& lhs, const node& rhs)
{
  return lhs.x < rhs.x;
}
bool ac(int x,int y)
{
	return x>y;
}
node d[siz];
string ns(int n)
{
	string r;
	while(n>0)
	{
		r=char((n%10)+48)+r;
		n/=10;
	}
	return r;
}
map<node, int> vis;
double dist(node a,node b)
{
	double x1,x2,y1,y2;
	x1=a.x;
	x2=b.x;
	y1=a.y;
	y2=b.y;
	return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}
bool eps_neigh(node d1)
{
	int cnt=0;
	f(siz)
	{
		if(dist(d1,d[i])<=2.8)
		{
			cnt++;
		}
	}
	if(cnt<eps) return false;
	else return true;
}
vector<node> neigh(node d1)
{
	vector<node> ans;
	f(siz)
	{
		if(dist(d1,d[i])<=2.8&&vis[d[i]]==0)
		{
			ans.pb(d[i]);
		}
	}
	return ans;
}
int main()
{
	ifstream in;
	in.open("f17.txt");
	f(siz)
	{
		in>>d[i].x;
		in>>d[i].y;
	}
	f(siz)
	{
		vis[d[i]]=0;
	}
	map<int,vector<node> > cl;
	map<node,int> cn;
	int c=0;
	for(int r1=0;r1<siz;r1++)
	{
		if(vis[d[r1]]==0)
		{
			vis[d[r1]]=1;
			if(eps_neigh(d[r1]))
			{
				c++;
				cn[d[r1]]=c;
				cl[c].pb(d[r1]);
				vector<node> w=neigh(d[r1]);
				f(w.size())
				{
					cn[w[i]]=c;
					cl[c].pb(w[i]);
					if(vis[w[i]]==0)
					{
						vis[w[i]]=1;
						if(eps_neigh(w[i]))
						{
							vector<node> q=neigh(w[i]);
							for(int z=0;z<q.size();z++)
							{
								w.pb(q[z]);
							}
						}
					}
					if(cn.find(w[i])==cn.end())
					{
						cn[w[i]]=c;
					}
				}
				cout<<c<<endl;
				ofstream out;
				string st="fd"+ns(c);
				st+=".txt";
				out.open(st.c_str());
				f(cl[c].size())
				{
					out<<cl[c][i].x<<" "<<cl[c][i].y<<endl;
					cout<<cl[c][i].x<<" "<<cl[c][i].y<<endl;
				}
				out.close();
			}
			else
			{
				vis[d[r1]]=2;
			}
		}
	}
	cout<<c<<endl;
	in.close();
	return 0;
}


