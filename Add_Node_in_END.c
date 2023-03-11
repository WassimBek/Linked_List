#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data ;
	struct node *link ;
}node;
node* Add_Data ( node *Nodes , int data){
	 node *New_One = malloc(sizeof( node)) ;
	 New_One->data = data ;
	 New_One->link = NULL ;
	 Nodes->link = New_One ;
	 return New_One ;
}
node* Add_End (node *End , int data){
	node *New = malloc(sizeof(node)) ;
	if(End->link == NULL){
		New->link = NULL ;
		New->data = data ;
		End->link = New ;
		return End ;
	} else {
		return Add_End(End->link,data) ;
	}
}
int main (){
	int n , i;
	node *Ptr = malloc(sizeof(node)) ;
	printf("How Many Number : ") ;
	scanf("%d",&n) ;
	printf("Enter Data : ") ;
	scanf("%d",&Ptr->data);
	Ptr->link = NULL ;
	node *Head = Ptr ;
	for(i = 1 ; i <= n-1 ; i++){
	    Head= Add_Data(Head,Head->data) ;
		printf("Enter Data : ") ;
	    scanf("%d",&Head->data);	
	}
	Head = Ptr ;
	Ptr = Add_End(Ptr,7) ;
	while(Head != NULL){
		printf("%d\n",Head->data) ;
		Head = Head->link ;
	} 
}
