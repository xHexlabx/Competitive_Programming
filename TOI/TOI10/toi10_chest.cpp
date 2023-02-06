#include<bits/stdc++.h>
#define endll '\n'
#define vec vector
#define umap unordered_map
#define ll long long 
#define ull unsigned long long 
#define pii pair<int , int>
using namespace std;
struct Data {
	int x , idx , stat ;
	bool operator <(const Data & d2)const{
		if(idx != d2.idx){
			return idx < d2.idx ;
		}
		else {
			return stat < d2.stat ;
		}
	} 
};
vec<Data>code ;
vec<int>unique_factor(8);
int main(){

	ios_base :: sync_with_stdio(0),cin.tie(0);
	ll MAX = 1 , cnt ;
	int m , n , x , str , stp ;
	ll cnt_factor ;
	
	cin >> m >> n ;
	
	for(int i = 0 ;  i < m  ;i ++ ){
		cin >> x >> str >> stp ;
		code.push_back({x , str , 1});
		code.push_back({x , stp + 1 , - 1});
	} 
	
	sort(code.begin() ,code.end());
	
	for(int i = 0 ; i < 2 * m - 1  ; i ++ ){
		
		auto temp = code[i] ;
		cnt_factor = 1 ;
		
		for(int j = 2 ; j <= 7 ; j ++ ){
			while(temp.x % j == 0){
				temp.x /= j ;
				unique_factor[j] += temp.stat ;
			}
		}
		
		if(temp.stat == - 1)continue ;
		
		for(int j = 2 ; j <= 7 ; j ++ ){
			cnt_factor *= (unique_factor[j] + 1);
		}
		
		if(cnt_factor > MAX){
			MAX = cnt_factor ;
			cnt = code[i + 1].idx - temp.idx ;
		}
		else if(cnt_factor == MAX){
			cnt += code[i + 1].idx - temp.idx ;
		}
	
	}
	cout << MAX << ' ' << cnt ;
	return 0;
}
