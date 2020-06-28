#include<bits/stdc++.h>
using namespace std;
struct resources{
	int a,b,c,d;
};
void print_table(resources allocation[],resources max[],resources available,resources need[],int n){
	cout<<"Process No.\tAvailable\tMax\t\tAvailable\tNeed\n";
	cout<<"\t\tA  B  C  D\tA  B  C  D\tA  B  C  D\tA  B  C  D\n";
	for(int i=0;i<n;i++){
		cout<<i<<"\t\t"<<allocation[i].a<<"  "<<allocation[i].b<<"  "<<allocation[i].c<<"  "<<allocation[i].d;
		cout<<"\t"<<max[i].a<<"  "<<max[i].b<<"  "<<max[i].c<<"  "<<max[i].d<<"\t";
		if(i==0){
			cout<<available.a<<"  "<<available.b<<"  "<<available.c<<"  "<<available.d<<"\t";
		}
		else{
			cout<<"\t\t";
		}
		cout<<need[i].a<<"  "<<need[i].b<<"  "<<need[i].c<<"  "<<need[i].d<<"\n";
	}
}
int main(){
	cout<<"Enter number of processes: ";
	int n;
	cin>>n;
	resources need[n],allocated[n],max[n],available,work;
	for(int i=0;i<n;i++){
		cout<<"Enter allocated resources: ";
		cin>>allocated[i].a>>allocated[i].b>>allocated[i].c>>allocated[i].d;
		cout<<"Enter max number of resources required: ";
		cin>>max[i].a>>max[i].b>>max[i].c>>max[i].d;	
		need[i].a=max[i].a-allocated[i].a;
		need[i].b=max[i].b-allocated[i].b;
		need[i].c=max[i].c-allocated[i].c;
		need[i].d=max[i].d-allocated[i].d;
	}
	cout<<"Enter available resources: ";
	cin>>available.a>>available.b>>available.c>>available.d;
	work.a=available.a;
	work.b=available.b;
	work.c=available.c;
	work.d=available.d;
	print_table(allocated,max,available,need,n);
	bool deadlock=false;
	int i=0,unfinish=5,prev;
	bool ar[n];
	for(int i=0;i<n;i++){
		ar[i]=false;
	}
	vector<int> safe_state;
	while (!deadlock){
		prev=unfinish;
		for(int i=0;i<n;i++){
			if(ar[i]){
				continue;
			}
			if (need[i].a<=work.a && need[i].b<=work.b && need[i].c<=work.c && need[i].d<=work.d){
				//cout<<i<<endl;
				work.a+=allocated[i].a;
				work.b+=allocated[i].b;
				work.c+=allocated[i].c;
				work.d+=allocated[i].d;
				unfinish--;
				ar[i]=true;
				safe_state.push_back(i);
			}
		}
		if(prev==unfinish){
			deadlock=true;
		}
		if(unfinish==0){
			break;
		}
	}
	if(deadlock){
		cout<<"DEADLOCK!!!.There is no safe sequence.";
	}
	else{
		cout<<"Safe State:\n";
		cout<<"< ";
		for(int i=0;i<n;i++){
			cout<<safe_state[i]<<" ";
		}
		cout<<">\n";
	}
}
