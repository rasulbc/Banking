#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

struct Bank* parseInput();
customer createCustomerList(struct Bank*);
int randomiser(int);
int* initialiseSimulator(struct Bank*);
void reportStatistics(struct Bank*,int);
int main(){
	srand(time(0));
	int* p;
	int clock=0;
	
	struct Bank* input;
	customer listhead;
	customer current;
	listhead =  (customer)malloc(sizeof(struct Node));
	current =  (customer)malloc(sizeof(struct Node));
    input=(struct Bank*)malloc(sizeof(struct Bank));
    input=parseInput();
    listhead=createCustomerList(input);
    current=listhead;
    p=initialiseSimulator(input);
    customer queue;
    queue =  (customer)malloc(sizeof(struct Node));
    int freenum,i,j,randomofficer;
    while(current->next!=NULL){
    	freenum=0;
    	for (i=0;i<input->numofficer;i++){
    		if (p[i]=1) freenum++;
		}
		if (freenum==1){
			for(j=0;j<input->numofficer;j++){
				if (p[j]=1) current->officerid=j+1;				
			}
			if (freenum>1){
				do{
					randomofficer=randomise(input->numofficer);
					
				}while(p[randomofficer]!=1);
				current->officerid=randomofficer;
			}
			
		}
    	newCustomer(queue,current);
    	current=current->next;
	}
    reportStatistics(input,clock);
    return 0;
}

struct Bank* parseInput(){
    struct Bank* input;
    input=(struct Bank*)malloc(sizeof(struct Bank));
    printf("Number of customers: ");
    scanf("%d",&input->numcustomer);
    printf("Number of officers: ");
    scanf("%d",&input->numofficer);
    printf("Max arrival time: ");
    scanf("%d",&input->maxarrival);
    printf("Max service time: ");
    scanf("%d",&input->maxservicelen);
    return input;
}
customer createCustomerList(struct Bank* input){
	
	int i ;
	customer head;
	customer current; 
	head = (customer)malloc(sizeof(struct Node));
	current = (customer)malloc(sizeof(struct Node));
   	current->type=randomiser(4);
   	current->arrival=randomiser(input->maxarrival);
   	current->servicelen=randomiser(input->maxservicelen);
   	current->servicestart=0;
   	head=current;
    for(i = 1;i < input->numcustomer;i++){
    	current->next=(customer)malloc(sizeof(struct Node));
    	current=current->next;
    	current->type=randomiser(4);
    	current->arrival=randomiser(input->maxarrival);
    	current->servicelen=randomiser(input->maxservicelen);
    	current->servicestart=0;
    	
	}
	current->next=NULL;
	bubbleSort(head);
	display(head);
	return head;
}
int* initialiseSimulator(struct Bank* input){
	int *p;
	int i;
	p = (int*)malloc(input->numofficer*sizeof(int));
	for (i=0;i<input->numofficer;i++){
		p[i]=1;
	}
	return p;
}

void reportStatistics(struct Bank* input,int clock){
	printf("\nThe number of bank officers: %d\nThe number of customers: %d",input->numofficer,input->numcustomer);
	printf("\nThe number of customers for each bank officers: %d/%d",input->numcustomer,input->numofficer);
	printf("\nThe completion time: %d",clock);
	printf("\nAverage time spent in the queue: ");
	printf("\nMaximum waiting time: ");
}
int randomiser(int max){
	int generated;
	generated=1+(rand())%max;
	return generated;
}
