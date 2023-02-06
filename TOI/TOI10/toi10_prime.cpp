#include<bits/stdc++.h>
#define umap unordered_map 
#define endll '\n' 
#define ll long long 
#define vec vector
#define emb emplace_back
#define pii pair<int , int>
#define mts multiset
#define Debug 1
using namespace std;
const int N  = 7368800;
bitset<N>prime ;
void solve(){
    int n ; cin >> n ;
	int cnt = 0 ;
	
	for(int i = 2 ; i <= N ; i ++){
		if(i == 2 || !prime[i]){
			cnt ++ ;
			if(cnt == n){
				cout << i ;
				return  ;
			}
			for(int j = i + i ; j <= N ; j += i){
				prime[j] = true ;
			}
		}
	}
    return ;
}
int main(){
    //Solved By HexTex 
    ios_base::sync_with_stdio(0) , cin.tie(0);
	solve();
    
    return 0 ;
}