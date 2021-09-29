
#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<windows.h>

int main() {

int n;	
printf("*********************WELCOME TO HOSPITAL MANAGEMENT SYSTEM*********************");
	printf("\n1.DOCTOR             2.PATIENT\n3.INFORMATION        4.EXIT");
do{
	printf("\nEnter Your Choice=");
	scanf("%d",&n);
	switch(n){
		case 1:  Doctor();break;
		case 2:  Patient();break;
		case 3:  Info();break;
		case 4:  exit(0);break;
		
		default: printf("WRONG CHOICE");
	}
  }while(n!=0);

	return 0;
}
