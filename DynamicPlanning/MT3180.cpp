/*
	现有n个红球，m个黑球
	谁先摸到红球谁获胜

	甲先摸，一次摸一颗
	乙会作弊，在拿出一颗球之后，还会偷偷拿一颗球
	问甲获胜的概率是多少
 */

#include<bits/stdc++.h> 

using namespace std;

map<pair<double,double>, double> map_fir;
map<pair<double,double>, double> map_sec;

double dp_sec(double a,double b);
double dp_fir(double a, double b){
    
    if( map_fir.count({a,b}) == 1) return map_fir[{a,b}];
    if(b==0){
        map_fir[{a,b}] = 1.0;
        return 1.0;
    } 
    if(a==0){
        map_fir[{a,b}] = 0.0;
        return 0.0;
    } 
    

    //条件概率，摸到a+摸到b但后手的人没摸到
    map_fir[{a,b}] = a/(a+b) + b/(a+b)*(1-dp_sec(a,b-1));
    return a/(a+b) + b/(a+b)*(1-dp_sec(a,b-1));
}
double dp_sec(double a, double b){
    if( map_sec.count({a,b}) == 1) return map_sec[{a,b}];

    if (b==0){
        map_sec[{a,b}] = 1.0;
        return 1.0;
    } 
    if (a==0){
        map_sec[{a,b}] = 0.0;
        return 0.0;
    } 
    

    //首先，读取摸到红球的概率
    double ans = a/(a+b);

    //若摸到的是黑球
    double K_Black = b/(a+b);
    b-=1;

    //偷走的是a，获胜概率
    ans += K_Black*a/(a+b)*(1-dp_fir(a-1,b));

    //偷走的是b
    if(b>0){
        ans += K_Black*b/(a+b)*(1-dp_fir(a, b-1));
    }
    map_sec[{a,b}] = ans;
    return ans;
}



int main( )
{
    int a,b;
    cin>>a>>b;
    double ans = dp_fir(a, b);
    printf("%.10f",ans);
    return 0;
}