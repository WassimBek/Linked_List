#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data ;
	struct node *link ;
}node ;
node* Add_Data ( node *Nodes , int data){
	 node *New_One = malloc(sizeof( node)) ;
	 New_One->data = data ;
	 New_One->link = NULL ;
	 Nodes->link = New_One ;
	 return New_One ;
}
node *New ;
node* insert(node *Hp , int num , int inx , int count){
	if(count == inx){
		node *New = malloc(sizeof(node)) ;
		New->link = Hp->link ;
		New->data = num ;
		Hp->link = New ;
		return Hp ;
	} else 
		return insert(Hp->link,num,inx,count+1) ;
}
int main (){
	int n , i , index , number;
	node *Ptr = malloc(sizeof(node)) ;
	node *new_one = Ptr ; 
	printf("How Many Number : ") ;
	scanf("%d",&n) ;
	printf("Enter Data : ") ;
	scanf("%d",&Ptr->data);
	Ptr->link = NULL ;
	node *Head = Ptr ;
	for(i = 1 ; i <= n-1 ; i++){
	    Head=Add_Data(Head,Head->data) ;
		printf("Enter Data : ") ;
	    scanf("%d",&Head->data);	
	}
	printf("Enter Number : ") ;
	scanf("%d",&number) ;
	printf("Enter index : ") ;
	scanf("%d",&index) ;
	new_one = insert(Ptr , number , index , 1) ;
	while(Ptr != NULL){
		printf("%d \n",Ptr->data) ;
		Ptr = Ptr->link ;
	}
}
