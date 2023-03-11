#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data ;
	struct node *link ;
}node;
node* from_number(int Num,node *adress){
	node *Ptr = malloc(sizeof(node)) ;
	if(Num == 0)
	 return adress ;
	else {
		Ptr->data = Num % 10 ;
		Ptr->link = NULL ;
		adress->link = Ptr ;
		return from_number(Num/10,adress->link) ;
	}
}
int main (){
	int Number ;
	printf("Enter Number : ") ;
	scanf("%d",&Number);
	node *Node_num = malloc(sizeof(node)) ;
	node *save = Node_num ;
	Node_num = from_number(Number,Node_num) ;
	save = save->link ;
	while( save!= NULL){
		printf("%d ",save->data) ;
		save = save->link ; 
	}
}
