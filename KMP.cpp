#include<iostream>
#include<vector>
using namespace std;

void createlps(vector<int>&lps,vector<string>s){

int pre=0;
int suff=1;
while(suff<s.size()){
	if(s[pre]==s[suff]){
		lps[suff]=pre+1;
		pre++;suff++;
		
	}
	else{
		if(pre==0){
			lps[suff]=0;
			suff++;
		}
		else{
			pre=lps[pre-1];
			
		}
		
	}
	
}
	
}




int main(){
	vector<string>haystack{"ABCDEFG"};
	vector<string>needle{"BCD"};
	vector<int>lps(needle.size(),0);
	createlps(lps,needle);
	int first=0,second=0;
	while(first<haystack.size()&&second<needle.size()){
		if(haystack[first]==needle[second]){
			first++;second++;
		}
		else{
			if(second==0){
first++;
			}
			
			
			else
			second =lps[second-1];
		}
	}
	if(second==needle.size()){
		cout<<"found";
	}
	else{
		cout<<"Not found";
	}
	
	
}
	

