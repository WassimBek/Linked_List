#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data ;
	struct node *link;
}node;
node *Add_Data (node *Ad,int value){
	node *new_one = malloc(sizeof(node)) ;
	new_one->data = value ;
	new_one->link = NULL ;
	Ad->link =  new_one ;
	return new_one ;
}
node *start ;
void nodee (node *P){
		if(P->link == NULL){
			start = P ;
			return;
		}
		nodee(P->link) ;
		node *A = P->link ;
		A->link = P ;
		P->link = NULL ;
	}
int main (){
	int num , n , i;
	node *save ;
	node *Start_Points = malloc(sizeof(node)) ;
	printf("How Many elements : "); 
	scanf("%d",&n) ;
	printf("Enter Num : ") ;
	scanf("%d",&num) ;
	Start_Points->data = num ;
	Start_Points->link = NULL ;
	start = Start_Points ;
	for(i = 2 ; i <= n ; i++){
		printf("Enter Num : ") ;
		scanf("%d",&num) ;
		Start_Points = Add_Data(Start_Points,num) ;
	}
	nodee(start) ;
	save = Start_Points ;
	while(save != NULL){
		printf("%d\n",save->data) ;
		save=save->link ;
	}
}
