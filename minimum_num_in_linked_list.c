#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data ;
	struct node *link;
}node;
// add data in struct 
node *Add_Data (node *Ad,int value){
	node *new_one = malloc(sizeof(node)) ;
	new_one->data = value ;
	new_one->link = NULL ;
	Ad->link =  new_one ;
	return new_one ;
}
int min (node *Head , int value){
	if(Head == NULL)
		return value ;
	else {
		if(value > Head->data)
			return min(Head->link,Head->data) ;
		else
		    return min(Head->link,value) ;
	}
}
int main (){
	int num , n , i , minimum;
	node *start = NULL;
	node *Start_Points = malloc(sizeof(node)) ;
	node *Miin ;
	printf("How Many elements : "); 
	scanf("%d",&n) ;
	printf("Enter Num : ") ;
	scanf("%d",&num) ;
	Start_Points->data = num ;
	Start_Points->link = NULL ;
	Miin = Start_Points ;
	start = Start_Points ;
	for(i = 2 ; i <= n ; i++){
		printf("Enter Num : ") ;
		scanf("%d",&num) ;
		Start_Points = Add_Data(Start_Points,num) ;
	}
	minimum = min(Miin->link,Miin->data) ;
	printf("%d",minimum) ;
}
