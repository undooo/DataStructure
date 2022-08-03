#include <stdc++.h>
using namespace std;

int f(int n ){
	if (n == 1){
		return 1;
	}

	int a0=1,a1=1,sum=0;
	for(int i =2;i <= n;i++){
		sum=a0+a1;
		a0=a1;
		a1=sum;
	}
	return sum;
}

int recursive(int n){
	if(n==1){return 1;}
	if(n==2){return 2;}
	return recursive(n-1)+recursive(n-2);
}

int main(int argc, char const *argv[])
{
	cout<<recursive(18)<<" "<<f(18);
	return 0;
}