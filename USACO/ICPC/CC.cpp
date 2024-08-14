#include <bits/stdc++.h>

using namespace std;

#define int long long

inline int read(){

	int x=0,f=1; char s;

	while((s=getchar())<'0'||s>'9') if(s=='-') f=-1;

	while(s>='0'&&s<='9') x=(x<<3)+(x<<1)+(s^'0'),s=getchar();

	return x*f;

}

const int N=3005;

int n,k,p[N],w[N][15];

int f[N][2];

signed main(){


	n=read(),k=read();

	int sum=0;

	for(int i=1;i<=n;++i){

		p[i]=read();

		sum+=p[i];

		for(int j=1;j<=p[i];++j){

			w[i][j]=read();

		}

	}


	memset(f,-0x3f,sizeof(f));

	f[0][0]=0;

	for(int i=1;i<=n;++i){

		for(int j=k;j>=1;--j){

			if(j>=p[i]){

				f[j][0]=max(f[j][0],f[j-p[i]][0]+w[i][p[i]]);

				f[j][1]=max(f[j][1],f[j-p[i]][1]+w[i][p[i]]);

			}

			for(int o=p[i]-1;o>=1;--o){

				if(j>=o) f[j][1]=max(f[j][1],f[j-o][0]+w[i][o]);	

			}

		}

	}

	if(sum>=k)cout<<max(f[k][0],f[k][1]);

	else cout<<f[sum][0];

	return 0;

}