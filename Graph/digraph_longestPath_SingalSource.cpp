#include <stdc++.h>
using namespace std;

#define NINF -100
vector<int> ansList;
void toplogicalSortUtil(int u, vector<vector<int>> & diGraph, vector<bool>& visited, stack<int> & st){
	visited[u] = true;
	for(int j = 0;j<diGraph[u].size();j++){
		int v = diGraph[u][j];
		if (!visited[v]){
			toplogicalSortUtil(v, diGraph, visited, st);
		}
	}
	st.push(u);
}	


stack<int> toplogicalSort(vector<vector<int>> & diGraph, vector<bool>& visited){
	stack<int> st;
	for(int i=0; i<diGraph.size();i++){
		if(!visited[i]){
			toplogicalSortUtil(i, diGraph, visited, st);
		}
	}
	return st;
}

int longestPath(vector<vector<int>> & diGraph, int startNode){
	// distance from startNode to others nodes
	vector<int> dist(diGraph.size(), NINF);
	dist[startNode] = 0;
	//flag
	vector<bool> visited(diGraph.size(),false);

	//toplogical ordering stack
	stack<int> st = toplogicalSort(diGraph, visited);

	//dp
	while(!st.empty()){
		int u = st.top();
		st.pop();

		// First, we need to make sure we can reach u from start node
		if(dist[u]!=NINF){
			for(int i=0;i<diGraph[u].size();i++){
				int v = diGraph[u][i];
				if(dist[v]<dist[u]+1){
					dist[v] = dist[u]+1;
				}
			}
		}

	}

	int max=NINF;
	cout<<endl;
	for(int i=0;i<dist.size();i++){
		max = max<dist[i]?dist[i]:max;
		dist[i]==NINF? cout<<"Unreachable ": cout<<dist[i]<<" ";
	}
	cout<<endl;
	return max;
}

int main(int argc, char const *argv[])
{
	int order;cin>>order;
	getchar();	// take the \n
	while(order!=0){

		//Use adjacency list to storage the graph
		vector<vector<int>> diGraph(order);
		vector<int> inOrder(order, 0);

		//read by line
		for(int node=0;node<order;node++){
			string str;
			getline(cin, str);
			//split str
			istringstream is(str);
			int out_node;
			while(is>>out_node){
				// add the node to the digraph
				diGraph[node].push_back(out_node);
				// fix the inoder if the out node
				inOrder[out_node]++;
			}
		}

		// determine the longest path starting from node 0
		int ans = longestPath(diGraph, 0);
		ansList.push_back(ans);
		cout<<"------Longest path starting from node0 in this digraph is :"<< ans <<"----------------"<<endl;
		cin>>order;
		getchar();
	}
	cout<<"Output in Format:"<<endl;
	for(auto & ans: ansList){
		cout<<ans<<endl;
	}
	return 0;
}