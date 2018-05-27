#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node{
	char type;
	int arrival;
	int servicelen;
	int servicestart=0;
	int officerid=0;
	struct Node* next;
	
};
typedef struct Node* customer;

int main(){
	int numcustomers,numofficers,maxarrival,maxservicelen;
	printf("\nCustomers: ");
	scanf("%d",&numcustomers);
	printf("\nBank officers: ");
	#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int type;
    int arrival;
    int servicelen;
    int servicestart;
    int officerid;
    struct Node* next;
};
typedef struct Node* customer;
struct Bank{
    int numcustomer;
    int numofficer;
    int maxarrival;
    int maxservicelen;
    struct Bank* next;
};
struct Bank* parseInput();
customer createCustomerList(struct Bank*);
int main(){
    struct Bank* current;
    current=(struct Bank*)malloc(sizeof(struct Bank));
    current=parseInput();
    printf("%d%d%d",current->numcustomer,current->numofficer,current->maxarrival);
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
    
}scanf("%d",&numofficers");
	printf("\nMaximum arrival time: ");
	scanf("%d",&maxarrival);
	printf("\nMaximum service time: ");
	scanf("%d",&maxservicelen);
	
	return 0 ;
	
}
