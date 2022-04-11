#include <bits/stdc++.h>
using namespace std;
typedef pair<long long,string> mytype;
long long a[15][105];
mytype dp[15][105],sm;
int n,m,num;
string tmp;
int mod1(long long a,long long b){
	return (((a%b)+b)%b);
}
mytype mini(mytype f,mytype s){
	if(f.first<s.first)return f;
	else if(f.first>s.first)return s;
	if(f.second.size()<s.second.size())return f;
	else if(s.second.size()<f.second.size())return s;
	else{
		if(s.second<f.second)return s;
		return f;
	}
}
void formulate(string k){
	string tmp="";
	for(int i=0;i<k.size();i++){
		if(k[i]!=' ')tmp+=k[i];
		else if(k[i]==' '||i==k.size()-1){
			int num=stoi(tmp);
			if(i==k.size()-1)cout<<num+1;
			else
			cout<<num+1<<' ';
			tmp.clear();
		}
	}
	cout<<'\n';
}
mytype solve(int i,int j){
	if(j>=m||j<0)return {0,tmp=""};
	mytype &mk=dp[i][j];
	if(mk.first!=(long long)1e19)return mk;
	mytype option1,option2,option3;
	 option1={a[i][j]+solve(mod1(i+1,n),j+1).first,to_string(i)+" "+solve(mod1(i+1,n),j+1).second};
	 option2={a[i][j]+solve(i,j+1).first,to_string(i)+" "+solve(i,j+1).second};
	 option3={a[i][j]+solve(mod1(i-1,n),j+1).first,to_string(i)+" "+solve(mod1(i-1,n),j+1).second};
	sm=mini(option2,option1);
	sm=mini(sm,option3);
	mk=sm;
	return mk;
}
int main(int argc, char **argv)
{
	while(cin>>n>>m){
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	cin>>a[i][j];
	
	long long mn=(long long)1e19;string g="";
	
		for(int i=0;i<n;i++){
		for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			dp[i][j].first=(long long)1e19;
		}
	}
	long long cur=(long long)solve(i,0).first;
	string s=solve(i,0).second;
	if(cur<mn){
		mn=cur;
		g=s;
	}else if(cur==mn&&g>s){g=s;}
}
formulate(g);
cout<<mn<<'\n';
}
	
	
	return 0;
}


