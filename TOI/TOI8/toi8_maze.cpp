#include<bits/stdc++.h>
#define vec vector
#define umap unordered_map
#define endll '\n'
using namespace std ;
int m , n ;
bool is_valid(int x , int y){
	if(x < 0 || x >= m || y < 0 || y >= n)return false ;
	return true ;
}
struct path {
	int x , y , t , q;
};
int main(){
	ios_base :: sync_with_stdio(0),cin.tie(0);
	
	cin >> m >> n ;
	
	path str , stp ; cin >> str.x >> str.y >> stp.x >> stp.y ;
	str.x -- , str.y -- , stp.x -- , stp.y -- ;
	str.t = 1 ; str.q = 0 ; stp.t = 1 ; stp.q = 0;
	int count = 0 ;
	
	vec<vec<int>>graph(m , vec<int>(n , 0)) ; for(int i = 0  ; i < m ; i ++)for(int j = 0 ; j < n ; j ++) cin >> graph[i][j] ;
	vec<vec<bool>>visited(m ,vec<bool>(n , false));
	vec<vec<bool>>visited1( m ,vec<bool>(n , false));
	vec<vec<int>>visited2( m ,vec<int>(n , INT_MAX));
	vec<vec<bool>>cnt(m , vec<bool>(n , false));
	vec<int>dir = {0 ,0 ,- 1, 1};
	
	queue<path>q ;
	q.push(str);
	
	while(!q.empty()){
		auto temp = q.front();
		q.pop();
		
		if(visited[temp.x][temp.y])continue;
		visited[temp.x][temp.y] = true ;
		
		for(int i = 0 ; i< 4 ; i ++){
			int nowx = temp.x + dir[i] , nowy = temp.y + dir[3 - i];
			if(!is_valid(nowx,nowy))continue ;
			if(graph[nowx][nowy])q.push({nowx,nowy,temp.t + 1 , temp.q});
			else cnt[nowx][nowy] = true ;
		}
	}
	
	q.push(stp);
	while(!q.empty()){
		auto temp = q.front();
		q.pop();
		
		if(visited1[temp.x][temp.y])continue;
		visited1[temp.x][temp.y] = true ;
		
		
		for(int i = 0 ; i< 4 ; i ++){
			int nowx = temp.x + dir[i] , nowy = temp.y + dir[3 - i];
			if(!is_valid(nowx,nowy))continue ;
			if(graph[nowx][nowy])q.push({nowx,nowy,temp.t,temp.q});
			else if(!visited1[nowx][nowy] && cnt[nowx][nowy] ){
				visited1[nowx][nowy] = true ;
				count ++ ;
			}
		}
	}
	
	int MIN = INT_MAX ;
	
	q.push(str);
	
	while(!q.empty()){
		auto temp = q.front();
		q.pop();
		if(temp.x == stp.x && temp.y == stp.y){
			cout << count << endll << temp.t ;
			return 0 ;
		}
		if(temp.q >= visited2[temp.x][temp.y])continue;
		visited2[temp.x][temp.y] = temp.q ;
		
		for(int i = 0 ; i < 4 ; i ++){
			int nowx = temp.x + dir[i] , nowy = temp.y + dir[3 - i];
			if(!is_valid(nowx,nowy))continue ;
			
			if(graph[nowx][nowy] == 1)q.push({nowx,nowy,temp.t + 1, temp.q});
			if(graph[nowx][nowy] == 0 && temp.q == 0){
				q.push({nowx, nowy , temp.t + 1 , temp.q + 1});
			}
		}
	}
	
	
	return 0 ;
}