#include <bits/stdc++.h>
using namespace std;


// the answer list
vector<int> ansList;

//Toplogical ordering
int determineCycle(vector<vector<int>> & diGraph, vector<int>& inOrder){
	int num = 0;

	queue<int> que;
	for(int i=0;i<inOrder.size();i++){
		if(inOrder[i]==0) que.push(i);
	}

	while(!que.empty()){
		int v = que.front();
		que.pop();
		num++;
		for(int i=0; i<diGraph[v].size(); i++){	
			if(--inOrder[diGraph[v][i]] == 0){
				que.push(diGraph[v][i]);
			}
		}
	}

	return num!=diGraph.size();
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
				cout<<"node: "<<node<<" out_node:"<<out_node<<endl;
				// fix the inoder if the out node
				inOrder[out_node]++;
			}
		}
		// determine whether the digraph contains a cycle
		int ans = determineCycle(diGraph, inOrder);
		ansList.push_back(ans);
		cout<<"------Ans for this diGraph:"<< ans <<"----------------"<<endl;
		cin>>order;
		getchar();
	}
	cout<<"Output in Format:"<<endl;
	for(auto & ans: ansList){
		cout<<ans<<endl;
	}

	return 0;
}