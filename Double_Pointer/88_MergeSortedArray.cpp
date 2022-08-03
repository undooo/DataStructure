#include <stdc++.h>
using namespace std;

void Merge(vector<int> & v1, int len1, vector<int> & v2, int len2){
	int pos = --len1 + --len2 +1;
	while(len1>=0 && len2>=0){
		v1[pos--] = v1[len1]>v2[len2]?v1[len1--]:v2[len2--];
	}
	while(len2>=0){
		v1[pos--] = v2[len2--];
	}
}

int main(int argc, char const *argv[])
{
	vector<int> v1={1,2,3};
	vector<int> v2={2,5,6};
	v1.resize(v1.size()+v2.size());
	Merge(v1,3,v2,3);
	for(int i : v1){
		cout<< i << " ";
	}
	return 0;
}