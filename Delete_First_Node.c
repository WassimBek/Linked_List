#include <stdio.h>
#include <stdlib.h>
/*creating a struct Has a data and The Link That has the adresses 
Of Next Nodes */
typedef struct Rm_Fisrt{
	int data ;
	struct Rm_First *link;
}Rm_First;
/* Add_Data Function That will Take
Number and The linked List as parameter
And Adding a single digit of the number to single node */
Rm_First *Add_Data (Rm_First *Node , int Number){
	Rm_First *Nodes = malloc(sizeof(Rm_First)) ;
	if(Number == 0)
	return Node ;
	else {
		Nodes->data = Number%10 ;
		Nodes->link = NULL ;
		Node->link = Nodes ;
		Node = Nodes ;
		return Add_Data(Node,Number/10) ;
	}
}
//Tha Function will remove first Node
Rm_First *Delet_First (Rm_First *User_Node){
	if(User_Node==NULL)
	printf("Linked List is empty ") ;
	else {
		Rm_First *Delet = malloc(sizeof(Rm_First)) ;
		Delet = User_Node ;
		User_Node = User_Node->link ;
		free(Delet) ;
		Delet = NULL ;
	}
	return User_Node ;
}
int main (){
	Rm_First *Head = NULL ;
	Rm_First *Start = malloc(sizeof(Rm_First)) ;
	int Number ;
	printf("Enter Number : ") ;
	scanf("%d",&Number) ;
	Start->data = Number % 10 ;
	Start->link = NULL ;
	Head = Start ;
	Start = Add_Data(Start,Number/10) ;
	Head = Delet_First(Head) ;
	//printing LInked list
	while(Head!=NULL){
		printf("%d\n",Head->data) ;
		Head = Head->link ;
	}
}
