#include<iostream>
#include<bits/stdc++.h>
#include<queue>

using namespace std;

queue <int> RR;
queue <int> PR;
queue <int> FCFS;

class process{
	
	public:
		int p_a; //To access the process
		int prio,burst,arival;
};

process p[100];
int n,t_t = 0;

process get_process(int p_a){
	
	int i;
	for(i=0;i<n;i++){
		if(p[i].p_a == p_a){
			return p[i];
		}
	}
}

void process_detail(int n){
	
	for(int i=0; i<n; i++)
	{
		cout<<"Priority: ";
		cin>>p[i].prio;
		cout<<"Arival: ";
		cin>>p[i].arival;
		cout<<"Burst: ";
		cin>>p[i].burst;
		p[i].p_a=i;
		
		cout<<'\n';
	}
}

//Entry into Queue - at Arrival Time

queue_entry(int t){
	
	for(int i=0;i<n;i++)
	{
		if(p[i].arival==t)
		{
			if(p[i].prio>=1 && p[i].prio<=5)
				RR.push(p[i].p_a);
				
			else if(p[i].prio>=6 && p[i].prio<=10)
				PR.push(p[i].p_a);
			
			else if(p[i].prio>=11 && p[i].prio<=15)
				FCFS.push(p[i].p_a);
		}
	}
}

void show(queue <int> a){
	
	queue <int> a1 = a;
	while(!a1.empty()){
		cout<<'\t'<<a1.front();
		a1.pop();
	}
	cout<<'\n';
}

void burst(int b_l, int p_a){
	
	int i;
	for(i=0;i<n;i++){
		if(p[i].p_a == p_a)
		p[i].burst = b_l;
	}
}

int main(){
	
	cout<<"Enter Number of process : ";
	cin>>n;
	cout<<'\n';
	
	process_detail(n);
	queue_entry(t_t);
	
	process p1;
	int RR_10 = 0,b_l;
	int n1 = 1;
	
	while(RR.size()!=0){
		
		int RR_4 = 0,x;
		if(!RR.empty()){
			
			x = RR.front();
			p1 = get_process(x);
			b_l = p1.burst;
		}
		
		while(RR_10 < 10){
			
			cout<<"\n Running Process : "<<RR.front();
			RR_10++;
			RR_4++;
			t_t++;
			b_l--;
			
			queue_entry(t_t);
			
			if(RR_10 == 10 && b_l!=0){
				
				burst(b_l,RR.front());
				int temp = RR.front();
				RR.pop();
				RR.push(temp);
			}
			
			if(RR_4 == 4){
				
				if(b_l == 0)
				RR.pop();
				
				else{
					
					burst(b_l,RR.front());
					int temp = RR.front();
					RR.pop();
					RR.push(temp);
				}
				 
				//If Queue is not yet Empty
				
				if(RR.size()!=0){
					
					x = RR.front();
					p1 = get_process(x);
					b_l = p1.burst;
					RR_4 = 0;
				}
				
				else { RR_10 = 10 ; }
			}
		}
	}		
}
