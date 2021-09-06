#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct node
{
	char name[5];
	float arrival_time;
	float burst_time;
	int priority;
	struct node *next;
}NODE;
NODE *insert(NODE *first)
{
	NODE *newnode,*temp,*prev;
	newnode=(NODE*)malloc(sizeof(NODE));
	scanf("%s",newnode->name);
	printf("Enter arrival time of time of process : ");
	scanf("%f",&newnode->arrival_time);
	printf("Enter burst time of time of process : ");
	scanf("%f",&newnode->burst_time);
	if(first==NULL||newnode->arrival_time<first->arrival_time)
	{
		newnode->next=first;
		first=newnode;
	}
	else
	{
		temp=first;
		while(temp!=NULL&&newnode->arrival_time>=temp->arrival_time)
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=newnode;
		newnode->next=temp;
	}
	return(first);
}
NODE *insert1(NODE *first)
{
	NODE *newnode,*temp,*prev;
	newnode=(NODE*)malloc(sizeof(NODE));
	scanf("%s",newnode->name);
	printf("Enter arrival time of time of process : ");
	scanf("%f",&newnode->arrival_time);
	printf("Enter burst time of time of process : ");
	scanf("%f",&newnode->burst_time);
	printf("Enter priority of process : ");
	scanf("%d",&newnode->priority);
	if(first==NULL||newnode->arrival_time<first->arrival_time)
	{
		newnode->next=first;
		first=newnode;
	}
	else
	{
		temp=first;
		while(temp!=NULL&&newnode->arrival_time>=temp->arrival_time)
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=newnode;
		newnode->next=temp;
	}
	return(first);
}
int main()
{
	NODE *first=NULL;
	NODE *temp1,*temp2,*temp3;
	int i,n,k=0,j;
	int choice;
	float w,t,m,z;
	float a=0,c=0;
	char y[5];
	printf("Enter number of processes\n");
	scanf("%d",&n);
	printf("\n1 : FCFS SCHEDULING\n2 : NON PREEMPTIVE SJF SCHEDULING\n3 : NON PREEMPTIVE PRIORITY SCHEDULING\n\nEnter your choice : ");
	scanf("%d",&choice);
	float b[n+1];
switch(choice)
{
	case 1: printf("\nFCFS SCHEDULING\n");
			for(i=1;i<=n;i++)
			{
				printf("\nEnter the name of the process%d : ",i);
				first=insert(first);
			}
			printf("\nGantt chart :\n\n");
			temp1=first;
			b[0]=first->arrival_time;
			printf("|| [%.1f]--",b[0]);
			m=b[0];
			while(temp1!=NULL)
			{
				if(temp1->arrival_time>m)
				{
					m=temp1->arrival_time;
					printf("Idle--[%.1f] | [%.1f]--",m,m);
					m=m+temp1->burst_time;
				}
				else
					m=m+temp1->burst_time;
				if(temp1->next==NULL)
					printf("%s--[%.1f] ||",temp1->name,m);
				else
					printf("%s--[%.1f] | [%.1f]--",temp1->name,m,m);
				b[++k]=m;
				temp1=temp1->next;
			}
			temp1=first;
			printf("\n\n---------------------------------------\n");
			printf("PROCESS\t\tWT\t\tTAT\n");
			printf("---------------------------------------\n");
			for(i=1;i<=k;i++)
			{
				w=b[i-1]-temp1->arrival_time;
				if(w<0)
					w=0;
				t=b[i]-temp1->arrival_time;
				a=a+w;
				c=c+t;
				printf("%s\t\t%.1f\t\t%.1f\n",temp1->name,w,t);
				temp1=temp1->next;
			}
			printf("---------------------------------------\n");
			printf("Average\t\t%.2f\t\t%.2f\n",a/n,c/n);
			printf("---------------------------------------\n");
			break;
	case 2:	printf("\nNON PREEMPTIVE SJF SCHEDULING\n");
			for(i=1;i<=n;i++)
			{
				printf("\nEnter the name of the process%d : ",i);
				first=insert(first);
			}
			printf("\nGantt chart :\n\n");
			temp1=first;
			b[0]=first->arrival_time;
			printf("|| [%.1f]--",b[0]);
			m=b[0];
			while(temp1!=NULL)
			{
			 again1:if(temp1->arrival_time>m)
				{
					m=temp1->arrival_time;
					printf("Idle--[%.1f] | [%.1f]--",m,m);
					goto again1;
				}
				else
				{
					temp2=temp1;
					while(temp2->arrival_time<=m&&temp2->next!=NULL)
					{
						temp3=temp1;
						while(temp3->arrival_time<=m&&temp3->next!=NULL)
						{
							if((temp3->burst_time>temp3->next->burst_time)&&(temp3->next->arrival_time<=m))
							{
								z=temp3->burst_time;
								temp3->burst_time=temp3->next->burst_time;
								temp3->next->burst_time=z;
								z=temp3->arrival_time;
								temp3->arrival_time=temp3->next->arrival_time;
								temp3->next->arrival_time=z;
								strcpy(y,temp3->name);
								strcpy(temp3->name,temp3->next->name);
								strcpy(temp3->next->name,y);
							}
							temp3=temp3->next;
						}
						temp2=temp2->next;
					}
					m=m+temp1->burst_time;
				}
				if(temp1->next==NULL)
					printf("%s--[%.1f] ||",temp1->name,m);
				else
					printf("%s--[%.1f] | [%.1f]--",temp1->name,m,m);
				b[++k]=m;
				temp1=temp1->next;
			}
			temp1=first;
			printf("\n\n---------------------------------------\n");
			printf("PROCESS\t\tWT\t\tTAT\n");
			printf("---------------------------------------\n");
			for(i=1;i<=k;i++)
			{
				w=b[i-1]-temp1->arrival_time;
				if(w<0)
					w=0;
				t=b[i]-temp1->arrival_time;
				a=a+w;
				c=c+t;
				printf("%s\t\t%.1f\t\t%.1f\n",temp1->name,w,t);
				temp1=temp1->next;
			}
			printf("---------------------------------------\n");
			printf("Average\t\t%.2f\t\t%.2f\n",a/n,c/n);
			printf("---------------------------------------\n");
			break;
	case 3: printf("\nNON PREEMPTIVE PRIORITY SCHEDULING\n");
			for(i=1;i<=n;i++)
			{
				printf("\nEnter the name of the process%d : ",i);
				first=insert1(first);
			}
			printf("\nGantt chart :\n\n");
			temp1=first;
			b[0]=first->arrival_time;
			printf("|| [%.1f]--",b[0]);
			m=b[0];
			while(temp1!=NULL)
			{
			 again2:if(temp1->arrival_time>m)
				{
					m=temp1->arrival_time;
					printf("Idle--[%.1f] | [%.1f]--",m,m);
					goto again2;
				}
				else
				{
					temp2=temp1;
					while(temp2->arrival_time<=m&&temp2->next!=NULL)
					{
						temp3=temp1;
						while(temp3->arrival_time<=m&&temp3->next!=NULL)
						{
							if((temp3->priority>temp3->next->priority)&&(temp3->next->arrival_time<=m))
							{
								z=temp3->burst_time;
								temp3->burst_time=temp3->next->burst_time;
								temp3->next->burst_time=z;
								z=temp3->arrival_time;
								temp3->arrival_time=temp3->next->arrival_time;
								temp3->next->arrival_time=z;
								strcpy(y,temp3->name);
								strcpy(temp3->name,temp3->next->name);
								strcpy(temp3->next->name,y);
								j=temp3->priority;
								temp3->priority=temp3->next->priority;
								temp3->next->priority=j;
							}
							temp3=temp3->next;
						}
						temp2=temp2->next;
					}
					m=m+temp1->burst_time;
				}
				if(temp1->next==NULL)
					printf("%s--[%.1f] ||",temp1->name,m);
				else
					printf("%s--[%.1f] | [%.1f]--",temp1->name,m,m);
				b[++k]=m;
				temp1=temp1->next;
			}
			temp1=first;
			printf("\n\n---------------------------------------\n");
			printf("PROCESS\t\tWT\t\tTAT\n");
			printf("---------------------------------------\n");
			for(i=1;i<=k;i++)
			{
				w=b[i-1]-temp1->arrival_time;
				if(w<0)
					w=0;
				t=b[i]-temp1->arrival_time;
				a=a+w;
				c=c+t;
				printf("%s\t\t%.1f\t\t%.1f\n",temp1->name,w,t);
				temp1=temp1->next;
			}
			printf("---------------------------------------\n");
			printf("Average\t\t%.2f\t\t%.2f\n",a/n,c/n);
			printf("---------------------------------------\n");
			break;
	default:printf("\nInvalid choice\n");
}
	return 0;
}

