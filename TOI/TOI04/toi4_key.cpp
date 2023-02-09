#include<bits/stdc++.h>
#define vec vector
#define umap unordered_map
#define endll '\n'
using namespace std ;
int main(){
	ios_base :: sync_with_stdio(0),cin.tie(0);
	int n, k ; cin >> n >> k ;
	string a , b , key ; cin >> a >> b >> key ;
	
	for(int i = 0 ; i < k ; i ++){
		char temp = key[i];
		for(int j = 0 ;  j < n ; j ++){
			vec<char>decode = {a[j] , b[j] , temp};
			sort(decode.begin() , decode.end());
			temp = decode[1];
		}
		key[i] = temp ;
	}
	cout << key ;
	return 0;
}
