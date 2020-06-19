#include<iostream> 
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define N 200010
char getc(){char c=getchar();while ((c<'A'||c>'Z')&&(c<'a'||c>'z')&&(c<'0'||c>'9')) c=getchar();return c;}
int read()
{
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
int n,m,cnt[N],id[N],ans[N];
struct data
{
	int x,y;
	bool operator <(const data&a) const
	{
		return y>a.y;
	}
}a[N],b[N];
bool check(int k)
{
	for (int i=1;i<=200000;i++) b[i]=a[i];
	int s=0;
	for (int i=1;i<=200000;i++)
	while (b[i].y>=k&&s<m) id[++s]=b[i].x,b[i].y-=k;
	return s>=m;
}
int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) cnt[read()]++;
	for (int i=1;i<=200000;i++) a[i].x=i,a[i].y=cnt[i];
	sort(a+1,a+200001);
	int l=0,r=n/m;
	while (l<=r)
	{
		int mid=l+r>>1;
		if (check(mid)) {for (int i=1;i<=m;i++) ans[i]=id[i];l=mid+1;}
		else r=mid-1;
	}
	for (int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
