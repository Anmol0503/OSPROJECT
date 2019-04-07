#include<stdio.h>

int n;
int wt_fcfs[30],turn_around_fcfs[30];
int wt_prio[30],turn_around_prio[30];
int i=0,j=0,k=0,l=0;
int Total_time=0,t1=0,t2=0,t3=0;
int at_t[30],bt_t[30],pr[30],pr_2[30];
int at_1[30],bt_1[30],at_2[30],bt_2[30],at_3[30],bt_3[30];

int main()
{
	printf(" Enter the number of Processes : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf(" Enter the details of Process %d : \n",i+1);
		printf(" Enter the Arrival Time : ");
		scanf("%d",&at_t[i]);
		printf(" Enter the Burst Time : ");
		scanf("%d",&bt_t[i]);
		printf(" Priority(1 to 30):");
		scanf("%d",&pr[i]);
		Total_time = Total_time + bt_t[i];
	}
	
//To store process belonging to each queue

	int s1[10],s2[10],s3[10];
	
	for(i=0;i<n;i++)
	{	
		//Queue - 1

		if(pr[i]>=1 && pr[i]<=10)
		{
			s1[j] = i+1;
			at_1[j] = at_t[i];
			bt_1[j] = bt_t[i];
			j++;
			t1=t1+bt_t[i];
		}
		
		//Queue - 2
		
		else if(pr[i]>=11 && pr[i]<=20)
		{
			s2[k] = i+1;
			at_2[k] = at_t[i];
			bt_2[k] = bt_t[i];
			pr_2[k]=pr[i];
			k++;
			t2=t2+bt_t[i];
		}
		
		//Queue - 3
		
		else if(pr[i]>=21 && pr[i]<=30)
		{
			s3[l] = i+1;
			at_3[l] = at_t[i];
			bt_3[l] = bt_t[i];
			l++;
			t3=t3+bt_t[i];
		}
	}
	
	//Processes in Each Queue
	
	printf("\n\tIn Queue 1 : \n");
	for(i=0;i<j;i++)
	printf("\t    - > Process %d\n",s1[i]);
	
	printf("\tIn Queue 2 : \n");
	for(i=0;i<k;i++)
	printf("\t    - > Process %d\n",s2[i]);
	
	printf("\tIn Queue 3 : \n");
	for(i=0;i<l;i++)
	printf("\t    - > Process %d\n",s3[i]);
	printf("\n");	
	
	//Round Robin with Time Quantum : 10
	//For the 3 Queues
	
	printf("\n Processing of Round Robin with Time Quantum : 10\n\n");
	for(i=1;i<=Total_time;i=i+10)
	{
		if(t1>10)
		{
			printf("  - > Queue1 is running for 10 units\n");
			t1=t1-10;
		}
		else if(t1<=10 && t1!=0)
		{
			printf("  - > Queue1 is running for %d units\n",t1);
			printf("  - > In Queue 1 all the Processes are Finished\n\n");
			t1=0;
		}
		
		if(t2>10)
		{
			printf("  - > Queue2 is running for 10 units\n");
			t2=t2-10;
		}
		else if(t2<=10&&t2!=0)
		{
			printf("  - > Queue2 is running for %d units\n",t2);
			printf("  - > In Queue 2 all the Processes are Finished\n\n");
			t2=0;
		}
		
		if(t3>10)
		{
			printf("  - > Queue3 is running for 10 units\n");
			t3=t3-10;
		}
		else if(t3<=10&&t3!=0)
		{
			printf("  - > Queue3 is running for %d units\n",t3);
			printf("  - > In Queue 3 all the Processes are Finished\n\n");
			t3=0;
		}
	}
	
	//Round Robin - Time Quantum : 4
	//For Queue - 1
	
	int t[30];
	float wait_time=0,turnaround_time=0;
	printf("\n Processing of Round Robin with Time Quantum : 4 \n");
	for(i=0;i<j;i++)
	{
		t[i] = bt_1[i];
	} 
	
	printf("\n Process ID\tBurst Time\t Turnaround Time\t Waiting Time");

	int remain = j;
	int total_r,flag;
	
    for(i=0,total_r=0;remain!=0;) 
    { 
    	if(t[i]<=4 && t[i]>0) 
        { 
            total_r = total_r + t[i]; 
            t[i]=0; 
            flag=1; 
        } 
        else if(t[i]>0) 
        { 
            t[i] = t[i]-4; 
            total_r = total_r+4; 
        } 
        if(t[i]==0 && flag==1) 
        { 
            remain--; 
            printf("\n Process %d \t      %d    \t       %d       \t\t%d     ",i+1,bt_1[i],total_r-at_1[i],total_r-at_1[i]-bt_1[i]);
            wait_time = wait_time + total_r - at_1[i] - bt_1[i]; 
            turnaround_time=turnaround_time+total_r - at_1[i]; 
            flag = 0; 
        } 
        if(i==j-1) 
        {
            i=0; 
        }
        else if(at_1[i+1]<=total_r) 
        {
            i++;
        }
        else 
        {
            i=0;
        }
    } 
    
    wait_time=wait_time/j;
    turnaround_time=turnaround_time/j;
    printf("\n\n Average Waiting Time:%f",wait_time); 
    printf("\n Average Turnaround Time:%f\n",turnaround_time);
	
	//FCFS (First Come First Serve) 
	//For Queue 3
	
	float wait_time1=0,turnaround_time1=0;
	
	wt_fcfs[0] = 0;
	
	//Waiting Time of Each Process
	   
    for(i=1;i<l;i++)
    {
        wt_fcfs[i] = 0;
        for(j=0;j<l;j++)
        {
            wt_fcfs[i] += bt_3[j];
        }
    }
    printf("\n Processing of FCFS : \n");
    printf("\n Process ID\tBurst Time\t Turnaround Time\t Waiting Time");
    for(i=0;i<l;i++)
    {
        turn_around_fcfs[i]=bt_3[i]+wt_fcfs[i];
        wait_time1 += wt_fcfs[i];
        turnaround_time1 += turn_around_fcfs[i];
        printf("\n Process %d \t      %d    \t       %d       \t\t%d     ",i+1,bt_3[i],turn_around_fcfs[i],wt_fcfs[i]);
    }
    
    wait_time1=wait_time1/l;
	turnaround_time1=turnaround_time1/l;
    printf("\n\n Average Waiting Time=%f",wait_time1);
    printf("\n Average Turnaround Time=%f\n",turnaround_time1);
    
    //Processing of FCFS according to RR of TQ - 10
    printf("\n Processing of FCFS according to RR of TQ - 10");
    for(i=0;i<l;i++)
    {
    	while(bt_3[i]!=0)
    	{
    		if(bt_3[i]>10)
    		{
				printf("\n Process %d of Queue3 is running for 10 units",i+1);
				bt_3[i] -= 10;
			}
			else if(bt_3[i]<=10)
			{
				printf("\n Process %d of Queue3 is running for %d units",i+1,bt_3[i]);
				bt_3[i]=0;
			}
		}
	}
	
	//Processing of Priority Scheduling
	//For Queue 2
	
	float wait_time2=0,turnaround_time2=0;
	
	for(i=0;i<k;i++)
    {
        position=i;
        for(q=i+1;q<k;q++)
        {
            if(priority2[q]<priority2[position])
            {
                position=q;
            }
        }
        temp1=priority2[i];
        priority2[i]=priority2[position];
        priority2[position]=temp1; 
        
        temp1=burst_time2[i];
        burst_time2[i]=burst_time2[position];
        burst_time2[position]=temp1;
        
        temp1=process2[i];
        process2[i]=process2[position];
        process2[position]=temp1;
    }
    
    waiting_time2[0]=0;
    for(i=1;i<k;i++)
    {
        waiting_time2[i]=0;
        for(q=0;q<i;q++)
        {
            waiting_time2[i]=waiting_time2[i]+burst_time2[j];
        }
        sum=sum+waiting_time2[i];
    }
    avg_waiting_time2=sum/k;
    int sum=0;
    printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
    for(i=0;i<k;i++)
    {
    	turnaround_time2[i]=burst_time2[i]+waiting_time2[i];
        sum=sum+turnaround_time2[i];
        printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n",process2[i],bt_2[i],waiting_time2[i],turnaround_time2[i]);
    }
    
    turn_around_prio =sum/k;
    printf("\nAverage Waiting Time :\t%f",waiting_prio);
    printf("\nAverage Turnaround Time :\t%f\n",turn_around_prio);
    
    for(i=0;i<k;i++)
    {
    	while(bt_2[i]!=0)
    	{
    		if(bt_2[i]>10)
    		{
				printf("\nProcess %d of Queue2 is running for 10 units",i+1);
				bt_2[i]=bt_2[i]-10;
			}
			else if(bt_2[i]<=10)
			{
				printf("\nProcess %d of Queue2 is running for %d units",i+1,bt_2[i]);
				bt_2[i]=0;
			}
		}
	}
	 
	return 0;
}
