#include <stdio.h>
#include <stdlib.h>
typedef struct Rm {
	int data ;
	struct Rm *link ;
}Rm;
// Adding Single digit to The nodes from the User_number
Rm *Add_Data (Rm *Nodes , int num){
	if (num == 0){
		return Nodes ;
		}
    else {
		Rm *New_Node = malloc(sizeof(Rm)) ;
		New_Node->data = num % 10 ;
		New_Node->link = NULL ;
		Nodes->link = New_Node ;
		Nodes = New_Node ;
		return Add_Data(Nodes , num/10) ;
	}
}
//Function That will Deleting last Node 
Rm* Del_Last(Rm *Head){
	Rm *Test1 , *Test2 ;
	Test1 = Head;
    Test2 = Head ;
	while(Test1->link != NULL){
		Test2 = Test1;
		Test1 = Test1->link ;
	}
	Test2->link = NULL ;
	free(Test1);
	Test1 = NULL ;
	return Head ;
}
int main (){
	Rm *Head = NULL ;
	Rm *Start = malloc(sizeof(Rm)) ;
	int Number ;
	printf("Enter Number : ") ;
	scanf("%d",&Number) ;
	Start->data = Number % 10 ;
	Start->link = NULL ;
	Head = Start ;
	Start = Add_Data(Start,Number/10);
	Head = Del_Last(Head) ;
	while(Head!=NULL){
		printf("%d\n",Head->data) ;
		Head = Head->link ;
	}
}
