#include<bits/stdc++.h>
#define vec vector 
#define umap unordered_map 
#define endll '\n'
using namespace std ;
float med(vec<float>a){
	sort(a.begin() , a.end());
	if(a.size() & 1)return a[a.size() / 2] ;
	else return (a[a.size() / 2 - 1] + a[a.size() / 2] ) / 2.0 ;
}
int main(){
	
	ios_base :: sync_with_stdio(0), cin.tie(0);
	umap<char , vec<pair<char , float>>>graph ;
	umap<char , bool>visited ;
	bool yes = false ;
	float sum = 0;
	int t ; cin >> t ;
	char str , stp ; int w ;
	while(t--){
		cin >> str >> stp >> w ;
		graph[str].push_back({stp,w});
		graph[stp].push_back({str,w});
	}
	
	queue<pair<char,float>>q ;
	q.push({'X' , 0});
	
	
	while(!q.empty()){
		auto temp = q.front();
		q.pop();
		if(visited[temp.first])continue ;
		visited[temp.first] = 1;
		if(temp.first == 'Y'){
			yes = true ;
			break;
		}
		for(auto i : graph[temp.first]){
			q.push(i);
		}
	}
	if(!yes){
		cout << "broken";
		return 0 ;
	}
	else {
		
	queue<pair<char,float>>q ;
	umap<char , bool>visited ;
	q.push({'X' , 0});
	
	vec<float>cal ;
	
	while(!q.empty()){
		auto temp = q.front();
		q.pop();
		char to ;
		if(visited[temp.first])continue ;
		visited[temp.first] = 1;
		
		cal = {};
		if(temp.first == 'Y'){
			yes = true ;
			break;
		}
		for(auto i : graph[temp.first]){
			if(visited[i.first])continue ;
			q.push(i);
			cal.push_back(i.second);
			to = i.first;
		}
		sum += med(cal);
		printf("%c %c %.1f\n" , temp.first , to , med(cal));
	}
	printf("%.1f",sum);
	}
	return 0 ;
}