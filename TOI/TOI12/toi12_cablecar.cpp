#include<bits/stdc++.h>
#define endll '\n'
#define vec vector
#define umap unordered_map
using namespace std;
struct path {
	int prev , v , w ;
	bool operator<(const path & p2)const{
		return p2.w > w ;
	}
};
vec<vec<path>>graph(2501) ;
int n , t , str , stp  , W , num;
int MAX = INT_MIN ;
int main(){
	ios_base :: sync_with_stdio(0),cin.tie(0);
	
	cin >> n >> t ;
	while(t--){
		cin >> str >> stp >> W ; 
		graph[str].push_back({0 ,stp , W});
		graph[stp].push_back({0 ,str , W}); 
	}
	cin >> str >> stp >> num ;
	vec<int>dis(n + 1, INT_MIN);
	priority_queue<path>pq;
	
	pq.push({0 , str , INT_MAX});
	
	while(!pq.empty()){
		auto temp = pq.top();
		pq.pop();
		
		if(temp.w <= dis[temp.v])continue ;
		dis[temp.v] = temp.w ;
		
		if(temp.v == stp){
			MAX = max(MAX , temp.w);
			break ;
		}
		for(auto i : graph[temp.v]){
			if(i.v == temp.prev)continue ;
			pq.push({temp.v , i.v , min(temp.w , i.w)});
		}
	}
	cout << ceil ((num + float(num) / float(MAX) + 1) / MAX);
	return 0;
}