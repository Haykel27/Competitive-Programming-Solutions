#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define N 5010
char getc(){char c=getchar();while ((c<'A'||c>'Z')&&(c<'a'||c>'z')&&(c<'0'||c>'9')) c=getchar();return c;}
int gcd(int n,int m){return m==0?n:gcd(m,n%m);}
int read()
{
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
int n,m,k,a[N],q[N],head,tail;
ll f[N][N];
int main()
{
	n=read(),k=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	memset(f,200,sizeof(f));
	f[0][0]=0;
	for (int j=1;j<=m;j++)
	{
		head=1,tail=1;q[1]=0;
		for (int i=1;i<=n;i++)
		{
			while (head<tail&&q[head]<i-k) head++;
			f[i][j]=f[q[head]][j-1]+a[i];
			while (head<=tail&&f[q[tail]][j-1]<=f[i][j-1]) tail--;
			q[++tail]=i;
			//for (int x=i-1;x>=max(0,i-k);x--)
			//f[i][j]=max(f[i][j],f[x][j-1]+a[i]);
		}
	}
	for (int i=n-1;i>=max(0,n-k+1);i--) f[n][m]=max(f[n][m],f[i][m]);
	if (f[n][m]<0) cout<<-1;
	else cout<<f[n][m];
	return 0;
}
