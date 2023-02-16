#include<bits/stdc++.h>
#define endll '\n'
#define vec vector
#define umap unordered_map
#define ll long long
using namespace std;
struct path{
	int v ;
	ll w ;
	int t ;
	bool operator <(const path & p2)const{
		return p2.w < w ;
	}
};
priority_queue<path>pq ;
bitset<2001>visited[2001];
vec<pair<ll ,ll>>ans ;
vec<vec<path>>graph(2001) ;
	
int main(){
	
	ios_base :: sync_with_stdio(0),cin.tie(0);
	
	int n , str , stp , e , q , U , V   ; 
	ll W ; ll maxw = INT_MAX ; int maxt = INT_MAX ;
	
	cin >> n >> str >> stp >> e ;
	while(e--){
		cin >> U >> V >> W ;
		graph[U].push_back({V , W , 0});
	}
	pq.push({str ,0 ,0});
	while(!pq.empty()){
		
		auto temp = pq.top();
		pq.pop();
		
		if(visited[temp.v][temp.t] || (temp.t > maxt && temp.w > maxw) )continue ;
		visited[temp.v][temp.t] = true ;
		
		if(temp.v == stp){
			if(temp.t > maxt && temp.w > maxw)continue ;
			if(temp.t < maxt)maxt = temp.t ;
			if(temp.w < maxw)maxw = temp.w ;
			
			ans.push_back({temp.w , temp.t});
			continue ;
		}
		for(auto i : graph[temp.v]){
			if(visited[i.v][temp.t + 1])continue ;
			pq.push({i.v , temp.w + i.w , temp.t + 1});
		}
		
	}
	
	cin >> q ;
	ll MIN = INT_MAX ;
	ll dis ;
	while(q--){
		MIN = INT_MAX ;
		cin >> dis ;
		for(auto i : ans){
			MIN = min(MIN , i.first + (i.second - 1)*dis );
		}
		cout << MIN << ' ';
	}
	return 0;
}