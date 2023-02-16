#include<bits/stdc++.h>
#define endll '\n'
#define vec vector
#define umap unordered_map
#define ll long long 
using namespace std;
struct path {
	ll height , hole ;
	bool operator <(const path & p2)const {
		return hole < p2.hole ;
	}
};
int main(){
	
	ios_base :: sync_with_stdio(0),cin.tie(0);
	int n ; cin >> n ;
	path boxes[n + 1] ;
	ll qs[n + 1];
	memset(qs , 0 , sizeof(qs));
	boxes[0] = {0,0};
	ll MIN = LLONG_MAX ,  sum = 0 ;
	
	for(int i = 1 ; i < n + 1; i ++ )
	{
		cin >> boxes[i].height ;
		MIN = min(MIN , boxes[i].height);
	}
	
	for(int i = 1 ; i < n + 1; i ++ ){
		cin >> boxes[i].hole ;
		sum += boxes[i].hole ;
	}
	
	sort(boxes +1 , boxes + n + 1);
	for(int i = 1 ;  i <= n ; i ++ ){
		qs[i] += qs[i - 1] + boxes[i - 1].height ;
	}
	
	ll MINN = LLONG_MAX ;
	ll ind  ;
	for(int i = 0 ; i <= n ; i ++ ){
		if(boxes[i].hole > MIN )break ;
		if( sum - (boxes[i].hole * n) + qs[i] < MINN){
			MINN = sum - (boxes[i].hole * n) + qs[i] ;
			ind = boxes[i].hole ;
		}
	}
	cout << ind << ' ' << MINN ;
	
	return 0;
}