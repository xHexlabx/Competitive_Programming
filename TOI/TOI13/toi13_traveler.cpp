#include<bits/stdc++.h>
#define vec vector 
#define umap unordered_map
using namespace std ;
struct path {
	int v,w ;	
	bool operator <(const path & p2)const{
		return w > p2.w ;
	}
};
int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	umap<int , vec<path> >graph ;
	
	int m , n ; 
	int str , stp , maximum ;
	
	cin >> m >> n >> str >> stp >> maximum ;
	
	for(int i = 0 ; i < n ; i ++){
		int U , V , W ;
		cin >> U >> V >> W ;
		
		graph[U].push_back({V,W});
		graph[V].push_back({U,W});
		
	} 
	
	vec<int>shortest(m , INT_MAX);
	shortest[str] = 0 ;
	priority_queue<path>pq ;
	
	pq.push({str,0});
	
	while(!pq.empty()){
		auto temp = pq.top();
		pq.pop();
		
		if(temp.v == stp)continue ;
		for(auto i : graph[temp.v]){
			if(temp.w + i.w < shortest[i.v] && temp.w + i.w <= maximum ){
				shortest[i.v] = temp.w + i.w ;
				pq.push({i.v , shortest[i.v]});
			}
		}
	}
	
	if(shortest[stp] <= maximum){
		printf("%d %d %d" , stp , shortest[stp] , 0);
	}
	else {
		vec<int>shortest2(m , INT_MAX);
		shortest2[stp] = 0 ;
		
		pq.push({stp,0});
		
		while(!pq.empty()){
			
			auto temp = pq.top();
			pq.pop();
			
			for(auto i : graph[temp.v]){
				if(temp.w + i.w < shortest2[i.v]){
					shortest2[i.v] = temp.w + i.w;
					pq.push({ i.v , shortest2[i.v]});
				} 
			}
		}
		
		int MIN = INT_MAX ;
		int index ;
		
		for(int i = 0 ; i < m ;i  ++){
			if(shortest[i] != INT_MAX && shortest2[i] < MIN){
				MIN = shortest2[i];
				index = i;
			}
		}
		printf("%d %d %d" , index , shortest[index] , shortest2[index]);
	}
	
	return 0 ;
}
