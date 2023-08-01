#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>
#include <functional>
int maxCoin(vector<int> &c, int M){
    for(int i=c.size()-1; i>=0; i--){
        if(M-c[i]>=0) return c[i];
	}
    return -1;
}

bool coinChanging(vector<int> &c, int M, vector<int> &v){
    int x;
	sort(c.begin(),c.end());
	while(M>0){
        x = maxCoin(c,M);
        if(x<0) return false;
        v.push_back(x);
        M -= x;
	}
    return true;
}

int main(){
	int C[]={1,5,10,20,50,100};
    int n=sizeof(C)/sizeof(int);
    vector<int> c(C,C+n);
    vector<int> v;
    int M = 186;

    coinChanging(c,M,v);

    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
        cout<<*it<<" ";


    return 0;
}
