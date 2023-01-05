#include<bits/stdc++.h>
#define vec vector
#define umap unordered_map
#define endll '\n'
using namespace std ;
int n , m ;
bool is_valid(int x , int y){
	if(x < 0 || x >= m || y < 0  || y >= n)return false ;
	return true ;
}
int main(){
	ios_base :: sync_with_stdio(0),cin.tie(0);
	
	cin >> n >> m ;
	int maxl = min(n , m);
	
	int arr[m][n] = {0};
	
	for(int i = 0  ; i < m ; i ++ ){
		string temp ; cin >> temp ;
		for(int j = 0 ;  j < n ; j ++){
			if(temp[j] == 'S')arr[i][j] = 0 ;
			else if(temp[j] == 'P')arr[i][j] = 1 ;
			else arr[i][j] = -1 ;
		}
	}
	
	int cnt = 1 ;
	int visited[64][64] = {0};
	queue<pair<int,int>>q;
	
	for(int i = 0 ; i < m ; i ++){
		for(int j = 0 ;  j< n ;j ++){
			
			if(arr[i][j] == 1){
				q.push({i,j});
				cnt ++ ;
			}
			while(!q.empty()){
				auto temp = q.front();
				q.pop();
				visited[temp.first][temp.second] = 1;
				arr[temp.first][temp.second] = cnt ;
				if(is_valid(temp.first - 1 , temp.second) && !visited[temp.first-1][temp.second])if(arr[temp.first - 1][temp.second] == 1)q.push({temp.first - 1,temp.second});
				if(is_valid(temp.first , temp.second + 1) && !visited[temp.first][temp.second + 1])if(arr[temp.first][temp.second + 1] == 1)q.push({temp.first,temp.second + 1});
				if(is_valid(temp.first + 1 , temp.second) && !visited[temp.first+1][temp.second])if(arr[temp.first + 1][temp.second] == 1)q.push({temp.first + 1,temp.second});
				if(is_valid(temp.first  , temp.second-1) && !visited[temp.first][temp.second-1])if(arr[temp.first ][temp.second-1] == 1)q.push({temp.first ,temp.second-1});
			}
		}
	}
	int MAX = INT_MIN ;
	int MIN = INT_MAX ;
	int sum = 0 ;
	for(int k = maxl ; k >= 0 ; k --){
		for(int a  = 0 ; a <= m - k ; a++){
			for(int b = 0 ; b <= n - k ; b++){
				int count_t = 0;
				vec<int>cntt(cnt + 1,0);
				sum = 0;
				for(int i = 0 + a ;  i < k + a ; i ++){
					for(int j = 0 + b ; j < k + b; j ++){
						
						if(arr[i][j] == -1){
							count_t ++;
							break;
						}
						if(arr[i][j] >= 1){
							cntt[arr[i][j]] = 1;
						}
					}
				}
				if(count_t == 0){
					for(int tmp = 0; tmp < cnt + 1 ; tmp ++){
						sum += cntt[tmp];
					}
					if(k * k >= MAX){
						MAX = k * k;
						MIN = min(MIN , sum);
					}
				}
			}
		}
	}
	cout << MAX << ' '<< MIN ;
	
	return 0 ;
}