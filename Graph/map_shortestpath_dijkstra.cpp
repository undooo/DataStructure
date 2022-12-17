#include <stdc++.h>
using namespace std;

# define MAX_DIS 10000

// 1 	1 	1 	1 	1 	99 	99
// 99 	99 	99 	99 	1 	99 	99
// 1 	1 	1 	99 	1 	99 	99
// 1 	99 	1 	1 	1 	99 	99
// 1 	99 	99 	99 	99 	99 	99
// 1 	1 	1 	1 	1 	1 	1

int n,m; // the size of the map


int djsk(vector<vector<int>>& mp, int v)
{
	int nodeNum = n*m+2;

	vector<int> dis(nodeNum,MAX_DIS);
	vector<int> bj(nodeNum,0);

    for(int i=0;i<=nodeNum;i++){
    	dis[i]=mp[v][i];	//Initialize the dis array represent the shortest path to i
    }
    
    dis[v]=0;// the distance from source to source is 0
    bj[v]=1;// flag, indicating the shortest path is founded 
    for(int i=0;i<nodeNum;i++){// i indicating the shortest path already been found
        int min=MAX_DIS;
        int k=0; 

        for(int j=0;j<nodeNum;j++){//从未找到最短路径元素中找一个路径最短的 
			if(!bj[j] && dis[j]<min){
				min=dis[j];
				k=j;
			}
		}
        
        bj[k]=1;// find the shortest path 
        
        for(int j=0;j<nodeNum;j++){//update the distance using the current shortest node
        	if(!bj[j] && dis[j]>(dis[k]+mp[k][j])){
          		dis[j]=dis[k]+mp[k][j];
       		}
        } 
     }
     return dis[nodeNum-1];
}

int main(int argc, char const *argv[])
{
	cout<<"Please enter the height n and width m of the matrix (seperated by space):"<<endl;
	cin>>n>>m;

	// Adjacent matrix
	vector<vector<int>> graph(n*m+2, vector<int>(n*m+2,MAX_DIS));
	
	// set diagonal weight to be 0
	for(int i=0; i<n*m+2; i++){
		graph[i][i] = 0;
	}
	// and the edge of two additional node
	graph[0][1] = 0;graph[1][0] = 0;
	graph[n*m+1][n*m] = 0;

	// read the matrix and set the weight of others edge
	cout<<"Please enter the matrix:"<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int weight;cin>>weight;

			// calculate the corresponding index
			int index = (i-1)*m + j;

			// update the weight of out-edge
			if(i==1 && j==1){// top-left node
				graph[index][index+m] = weight;
				graph[index][index+1] = weight;

			}else if(i==1 && j==m){//top-right node
				graph[index][index-1] = weight;
				graph[index][index+m] = weight;

			}else if(i==n && j==1){ //bottom-left node
				graph[index][index+1] = weight;
				graph[index][index-m] = weight;

			}else if(i==n && j==m){ // bottom-right node
				graph[index][index-1] = weight;
				graph[index][index-m] = weight;
				graph[index][index+1] = weight;
			}else if(i==1){ // top
				graph[index][index-1] = weight;
				graph[index][index+1] = weight;
				graph[index][index+m] = weight;
			}else if(j==1){ // left
				graph[index][index+1] = weight;
				graph[index][index-m] = weight;
				graph[index][index+m] = weight;

			}else if(j==m){// right
				graph[index][index-1] = weight;
				graph[index][index-m] = weight;
				graph[index][index+m] = weight;

			}else if(i==n){// bottom
				graph[index][index-1] = weight;
				graph[index][index+1] = weight;
				graph[index][index-m] = weight;
			}else{ //other wise
				graph[index][index+1] = weight;
				graph[index][index-1] = weight;
				graph[index][index-m] = weight;
				graph[index][index+m] = weight;
			}
		}
	}
	
	int ans = djsk(graph, 0);
	cout<< "The shortest length from the top left to the bottom right is :"<<ans<<endl;
	return 0;
}