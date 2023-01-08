#include<bits/stdc++.h>
#define vec vector
using namespace std ;
int m , n ; 
bool is_valid(int x , int y){
	if( x < 0 || x >= m || y < 0  || y >= n)return false ;
	return true ;
}
int main(){
	
	ios_base :: sync_with_stdio(0),cin.tie(0);
	cin >> m >> n; 
	int temp  = 1;
	double MIN = INT_MAX ;
	vec<vec<double>>table(m , vec<double>(n , 0));
	vec<vec<int>>find_index(m ,vec<int>(n , 0));
	vec<int>check = {- 1, 0 , 1};
	pair<int,int>pos ;
	for(int i  =0  ; i < m ; i ++)for(int j = 0 ; j < n ; j ++)cin >> table[i][j] ;
	for(int i  =0  ; i < m ; i ++)for(int j = 0 ; j < n ; j ++){
		find_index[i][j] = temp ;
		temp ++ ;
	}
	
	vec<int>x(m *n , 0);
	for(int i = 1 ; i <= m * n ; i ++)x[i - 1] = i ;
	
	do{
		double sum = 0 ;
		vec<vec<double>>temp = table ;
		for(auto k : x){
			for(int i = 0 ; i < m ; i ++ ){
				for(int j = 0 ; j < n ; j ++){
					if(find_index[i][j] == k)pos = {i , j};
				}
			}
			sum += temp[pos.first][pos.second];
			for(int i = 0 ; i < 3 ; i ++){
				for(int j = 0 ; j < 3 ; j ++ ){
					if(i == 1 && j == 1)continue ;
					if(is_valid(pos.first + check[i] , pos.second + check[j] )){
						temp[pos.first + check[i]][pos.second + check[j]] += 0.1 * temp[pos.first][pos.second];
					}
				}
			}
		}
		if(MIN > sum)MIN = sum ;
	}
	while(next_permutation(x.begin()  , x.end() ));
	printf("%.2lf" , MIN );
	return 0 ;
}
