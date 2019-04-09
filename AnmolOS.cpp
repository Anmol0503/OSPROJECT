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
		int prio,burst,arival,burst_1;
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
		cout<<" Priority: ";
		cin>>p[i].prio;
		cout<<" Arival: ";
		cin>>p[i].arival;
		cout<<" Burst: ";
		cin>>p[i].burst;
		p[i].burst_1 = p[i].burst;
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

void prio_sort(){
	
	int i;
	for(i=0;i<n;i++){
		
		if(p[i].prio>=6 && p[i].prio<=10){
			
			int z;
			if(p[i].prio > p[i+1].prio){
				
				z = p[i].prio;
				p[i].prio = p[i+1].prio;
				p[i+1].prio = z;
			}
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

int check1(){
	
	if(RR.size()==0 && PR.size()==0 && FCFS.size()==0){
		
		return 1;
	}
}

int check2(){
	
	int i;
	for(i=0;i<n;i++){
		
		if(p[i].burst!=0)
		return 0;
	}
	
	return 1;
}

int main(){
	
	cout<<" Enter Number of process : ";
	cin>>n;
	cout<<'\n';
	
	process_detail(n);
	queue_entry(t_t);
	
	process p1;
	int RR_10 = 0,b_l,extra = 0,count =0;
	int n1 = 1,access = 1,w_t = 0,b_w = 0,ta_t = 0;
	float avg_ta_t,avg_w_t,t_u;
	
	cout<<"\n                Number \t Processing time \n";
	
	while(access!=0){
		  
		int RR_4 = 0,x;
		
		RR_10 = 0;
		cout<<'\n';
		if(RR.size()!=0){
			
			count++;
			x = RR.front();
			p1 = get_process(x);
			b_l = p1.burst;
			b_w = p1.burst;
		}
		
		while(RR.size()!=0 && RR_4 < 4 && RR_10 < 10){
			
			cout<<"\n Running Process : "<<RR.front()<<'\t'<<"        "<<RR_10;
			RR_10++;
			RR_4++;
			t_t++;
			b_l--;
			
			burst(b_l,RR.front());
			queue_entry(t_t);
			
			if(RR_10 == 10){
				
				burst(b_l,RR.front());
			}
			
			if(b_l == 0 || RR_4 == 4){
				
				if(b_l == 0){
					
					x = RR.front();
					p1 = get_process(x);
					
					ta_t = t_t - p1.arival;
					avg_ta_t += ta_t;
					w_t = ta_t - p1.burst_1;
					avg_w_t += w_t;
				
					cout<<"\n Process "<<RR.front()<<" Completed at "<<t_t<<" and waiting time is : "<<w_t<<" and turn around time is : "<<ta_t<<'\n';
					RR.pop();
				}
				
				if(b_l!=0){
					
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
		
		RR_10 = 0;
		cout<<'\n';
		if(PR.size()!=0){
			
			x = PR.front();
			p1 = get_process(x);
			b_l = p1.burst;
			b_w = p1.burst;
		}
		
		while(RR_10 < 10 && PR.size()!=0){
			
			cout<<"\n Running Process : "<<PR.front()<<'\t'<<"        "<<RR_10;
			RR_10++;
			t_t++;
			b_l--;
			
			burst(b_l,PR.front());
			
			if(RR_10 == 10 && b_l>0)
			burst(b_l,PR.front());
			
			if(b_l == 0){
				
				x = PR.front();
				p1 = get_process(x);
					
				ta_t = t_t - p1.arival;
				avg_ta_t += ta_t;
				w_t = ta_t - p1.burst_1;
				avg_w_t += w_t;
				
				cout<<"\n Process "<<PR.front()<<" Completed at "<<t_t<<" and waiting time is : "<<w_t<<" and turn around time is : "<<ta_t<<'\n';
				PR.pop();
				//prio_sort();
					
				queue_entry(t_t);
				
				if(PR.size()!=0){
					
					x = PR.front();
					p1 = get_process(x);
					b_l = p1.burst;
				}
				
				else { RR_10 = 10; }
			}
			
			else{
				
				queue_entry(t_t);
			}
		}
		
		RR_10 = 0;
		cout<<'\n';
		if(FCFS.size()!=0){
			
			x = FCFS.front();
			p1 = get_process(x);
			b_l = p1.burst;
			b_w = p1.burst;
		}
		
		while(FCFS.size()!=0 && RR_10 < 10){
			
			cout<<"\n Running Process : "<<FCFS.front()<<'\t'<<"        "<<RR_10;
			RR_10++;
			t_t++;
			b_l--;
			
			burst(b_l,FCFS.front());
			queue_entry(t_t);
			
			if(RR_10 == 10){
				
				burst(b_l,FCFS.front());
			}
			
			if(b_l == 0){
				
				x = FCFS.front();
				p1 = get_process(x);
					
				ta_t = t_t - p1.arival;
				avg_ta_t += ta_t;
				w_t = ta_t - p1.burst_1;
				avg_w_t += w_t;
				
				cout<<"\n Process "<<FCFS.front()<<" Completed at "<<t_t<<" and waiting time is : "<<w_t<<" and turn around time is : "<<ta_t<<'\n';
				FCFS.pop();
			
				if(FCFS.size()!=0){
					
					x = FCFS.front();
					p1 = get_process(x);
					b_l = p1.burst;
				}
				
				else { RR_10 = 10; }
			}
		}
		
		if(check1()){
			
			if(check2()){
				
				t_u = t_t;
				cout<<" Average Waiting time : "<<avg_w_t/5;
				cout<<"\n Average Turn around time : "<<avg_ta_t/5;
				
				cout<<"\n CPU Utilization : "<<((t_u-extra)/t_u) * 100<<" %";
				cout<<"\n\n Scheduling Completed ";
				access = 0;
			}
			
			else{
				
				cout<<" No Process Has arrived yet : at "<<t_t;
				cout<<"\n\n                Number \t Processing time \n";
				t_t++;
				extra++;
				queue_entry(t_t);
			}
			
		}
	}		
}
