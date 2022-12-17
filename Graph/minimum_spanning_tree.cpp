#include<stdc++.h>
using namespace std;

#define MAX_DIS 10000
int order;

// 0 1 1
// 0 2 2
// 0 3 3
// 0 4 4
// 1 2 5
// 1 4 7
// 2 3 6

int prim(vector<vector<int>> & graph){
	int cost = 0;
	int n = graph.size();
	vector<int> dist(n, MAX_DIS);
	vector<int> visited(n, 0);
	dist[0] = 0; visited[0] = 1;

	//update the dist by first city
	for(int i=1;i<n;i++){
		dist[i] = min(dist[i], graph[0][i]);
	}

	//update all the city
	for(int i=1;i<n;i++){
		int temp = MAX_DIS;
		int index = -1;
		for(int j=1;j<n;j++){ // find the closest city which has not been visited
			if(!visited[j] && dist[j]<temp){
				temp = dist[j];
				index = j;
			}
		}
		// if we can not find closest city, it means we can't form a spanning tree
		if(index == -1){
			return -1;
		}
		cost += dist[index];
		visited[index] = 1;

		// update the dist by the closest city just been found
		for(int j=1;j<n;j++){
			dist[j] = min(dist[j], graph[index][j]);
		}
	}
	return cost;
}

int main(int argc, char const *argv[])
{
	cout<<"Please enter the order of tha graph "<<endl;
	cin>>order;
	cout<<"Please enter the number of edges: "<<endl;
	int edges;cin>>edges;
	cout<<"Please enter the edge information: u,v,weight (seperated by space):"<<endl;
	
	vector<vector<int>> graph(order, vector<int>(order, MAX_DIS));

	for(int i=0; i<edges;i++){
		int u,v,weight;cin>>u>>v>>weight;
		graph[u][v] = weight;
		graph[v][u] = weight;
	}
	int cost = prim(graph);

	if(cost == -1){
		cout<<"We can't connect all the city together!"<<endl;
	}else{
		cout<<"The minimum cost to connect all the city together is: "<<cost<<endl;
	}
	return 0;
}