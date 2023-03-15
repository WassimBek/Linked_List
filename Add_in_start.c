#include <stdio.h>
#include <stdlib.h>
//creating struct 
typedef struct node {
	int data ;
	struct node *link ;
}node;
//procedure that will add node at begin
void Add_Data (node **head , int Node_Data){
	node *First_node = malloc(sizeof(node)) ;
	First_node->data = Node_Data ;
	First_node->link = *head ;
	*head = First_node ;
}
int main (){
	node *first_nd = malloc(sizeof(node)) ;
	first_nd->data = 5 ;
	first_nd->link = NULL ;
	node *Head = first_nd ;
	node *second_nd = malloc(sizeof(node)) ;
	second_nd->data = 10 ; 
	second_nd->link = NULL ;
	first_nd->link = second_nd ;
	Add_Data(&Head,55) ;
	//printing the new linked list
	while(Head!=NULL){
		printf("%d\n",Head->data) ;
		Head = Head->link ;
	}
}
