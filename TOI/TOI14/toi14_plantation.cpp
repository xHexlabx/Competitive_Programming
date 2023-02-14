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
struct point {
	int x , y ;
};
bool cmp_x(point a , point b){
	return a.x < b.x ;
}
bool cmp_y(point a , point b){
	return a.y < b.y ;
}
point arr[100001];
point temp[100001];
float dis(point a , point b){
	return sqrt(pow( (a.x - b.x), 2) + pow( (a.y - b.y) ,2)) ;
}
float closest(int l , int r){
	if(l == r)return INT_MAX ;
	if(r - l == 1)return dis(arr[l] , arr[r]) ;
	int mid = (l + r) >> 1 ;
	float d = min(closest(l , mid) , closest(mid + 1 , r));
	int cnt = 0;
	for(int i = l ; i <= r ; i ++ ){
		if(arr[i].x >= arr[mid].x - d && arr[i].x <= arr[mid].x + d){
			temp[cnt ++ ] = arr[i] ;
		}
	}
	sort(temp , temp + cnt , cmp_y) ;
	for(int i = 0 ; i < cnt ; i ++ ){
		for(int j = i + 1 ; j < cnt && temp[j].y - temp[i].y < d ; j ++){
			d = min(d , dis(temp[i] , temp[j]));
		}
	}
	return d ;
}
void solve(){
	int N , R , D ;
	cin >> N >> R >> D ;
	for(int i = 0 ; i < N ; i ++){
		cin >> arr[i].x >> arr[i].y ;
	}
	sort(arr , arr + N , cmp_x);
	(closest(0 , N - 1) - (R << 1) >= D) ? cout << "Y\n" : cout << "N\n";
    return ;
}
int main(){
    //Solved By HexTex 
    ios_base::sync_with_stdio(0) , cin.tie(0);
	int q ; cin >> q;
    while(q -- )solve();
    
    return 0 ;
}