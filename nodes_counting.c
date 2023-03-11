#include <stdio.h>
#include <stdlib.h>
typedef struct Nodes {
	int data ;
	struct Nodes *link ;
}Nodes;
Nodes *Add_Data (Nodes *N1,int value){
	Nodes *New_Node = malloc(sizeof(Nodes)) ;
	New_Node->data = value ;
	New_Node->link = NULL ;
	N1->link = New_Node ;
	return New_Node ;
}
int count_Nodes (Nodes *User_Linked_List){
   if(User_Linked_List->link==NULL)
   	return 1 ;
   else
     return 1 + count_Nodes(User_Linked_List->link) ;
}
int main (){
	int num , n , i;
	Nodes *Head = NULL ;
	Nodes *Body = malloc(sizeof(struct Nodes)) ;
	printf("How Many Data You want ? ") ;
	scanf("%d",&n) ;
	if(n > 0){
		printf("Enter num : ") ;
		scanf("%d",&num) ;
		Body->data = num ;
		Body->link = NULL ;
		Head = Body ;
		if(Head != NULL){
		  	for(i = 2 ; i <= n ; i++){
		  		printf("Enter num : ") ;
		        scanf("%d",&num) ;
		        Body = Add_Data(Body,num) ;
			  }
			  printf("This Linked List Has %d Nodes ",count_Nodes(Head)) ;
		}
	}
}

