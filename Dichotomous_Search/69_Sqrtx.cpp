#include <stdc++.h>
using namespace std;
// 给定一个非负整数，求它的开方，向下取整

int solve(int num){
	int l=0,r=num,mid = (l+r)/2;
	while(l<=r){
		mid = (l+r)/2;
		if(mid*mid <num){
			l=mid+1;
		}else if (mid*mid == num){
			return mid;
		}else{
			r=mid-1;
		}
	}
	return r;
}

int main(int argc, char const *argv[])
{
	cout<<solve(8);
	return 0;
}

