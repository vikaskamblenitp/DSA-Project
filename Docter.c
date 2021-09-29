
#include <stdio.h>
#include<malloc.h>
#include<string.h>
void addDoctor();
void displayDoctor();
void searchDoctor();
char deleteDoctor();
void editDoctor();

int DId=0;
struct doctor{
	int id;
	char fname[10];
    char lname[10];
	char sex;
	//char add[20];
//	char *dob;
	char degree[4];
	char speciality[20];
	int exprience;
	//0long long int  phone;
	struct doctor *next;
};
struct doctor *stDoctor=NULL,*tempDoctor=NULL,*prevDoctor=NULL;
void addDoctor(){
	int DSp;
	tempDoctor=(struct doctor*)malloc(sizeof(struct doctor));
	tempDoctor->id=++DId;
	printf("doctor Id=%d",tempDoctor->id);
	printf("\nEnter doctor Name=");
	    scanf("%s",&tempDoctor->fname);
	printf("Enter doctor Last Name=");    
	    scanf("%s",&tempDoctor->lname);
	    char sex;
/*	printf("Enter doctor Sex(M/F)=");
	    scanf("%s",&sex);
	    if(sex=='M'||sex=='F'){
	      tempDoctor->sex=(char)sex;
		}
		else
		  printf("Wrong Choice");

//	scanf("%d",&tempDoctor->dob);
    printf("Enter doctor Degree(MS/MD)=");
	    scanf("%s",&tempDoctor->degree);*/
    printf("Choose Speciality=");
    printf("\n1.Neurologist    2.Psychiatrist\n3.Dentist     4.Heart Surgeon\n5.Child Specialist   6.Other\n");
    printf("\nEnter your choice=");
    scanf("%d",&DSp);
    switch(DSp){
		case 1:  strcpy(tempDoctor->speciality,"Neurologist");break;
		case 2:  strcpy(tempDoctor->speciality,"Psychiatrist");break;
		case 3:  strcpy(tempDoctor->speciality,"Dentist");break;
		case 4:  strcpy(tempDoctor->speciality,"Heart Surgeon");break;
		case 5:  strcpy(tempDoctor->speciality,"Child Specialist");break;
		case 6:  strcpy(tempDoctor->speciality,"Other");break;
		default: printf("WRONG CHOICE");
	}
    
	printf("Enter doctor Exprience in years=");
	    scanf("%d",&tempDoctor->exprience);
	if(stDoctor==NULL){
		stDoctor=tempDoctor;
		stDoctor->next=NULL;}
		else if(stDoctor->next==NULL){
			stDoctor->next=tempDoctor;
			prevDoctor=stDoctor->next;
			tempDoctor->next=NULL;
		}
		else{
			prevDoctor->next=tempDoctor;
	        prevDoctor=prevDoctor->next;
	        tempDoctor->next=NULL;
		}
		printf("\n****************Data Added Successfully****************************");	
}
void displayDoctors(){
	tempDoctor=stDoctor;
	while(tempDoctor!=NULL){
	    printf("\n doctor Id=%d",tempDoctor->id);
	    printf("\n doctor Name=%s",tempDoctor->fname);
	    printf("\n doctor Last Name=%s",tempDoctor->lname);    
	    printf("\n doctor Sex=%c",tempDoctor->sex);
	
//	printf("\nEnter doctor Id=");
//	scanf("%d",&tempDoctor->dob);
    printf("\n doctor Degree=%s",tempDoctor->degree);
	printf("\n doctor Speciality=%s",tempDoctor->speciality);    
	printf("\n doctor Exprience in Years=%d",tempDoctor->exprience);
	   
		tempDoctor=tempDoctor->next;
	}
	
}
char deleteDoctor(){
	int id;
	char y='Y';
	printf("\nEnter id of Doctor Whose Data You Want To Delete=");
	scanf("%d",&id);
	tempDoctor=stDoctor;
	while(tempDoctor!=NULL)
	{
       if(tempDoctor->id==id){
       	prevDoctor->next=tempDoctor->next;
	//	delete(tempDoctor);
		return y;
	    }
	else if(tempDoctor->next==NULL){
   	printf("\nNO SUCH DOCTOR EXIST");
   	return 'N';
   }
	prevDoctor= tempDoctor;   
	tempDoctor=tempDoctor->next;
	}
}
void  editDoctor(){
	
	
}
void searchDoctor(){
	printf("*********DOCTOR DETAILS SEARCHED BY ID************");
	int id;
	printf("\nEnter Doctor Id=");
	scanf("%d",&id);
  while(tempDoctor!=NULL){
   if(tempDoctor->id==id){
    
	printf("\nDoctor Id=%d",tempDoctor->id);
	printf("\nDoctor Name=%s",tempDoctor->fname);
    printf("\nDoctor Last Name=%s",tempDoctor->lname);
	printf("\nDoctor Sex=%c ",tempDoctor->sex);
    //printf("Patient Address=%s",tempDoctor->add);
	printf("\nDoctor Degree=%s",tempDoctor->degree);
	printf("\nDoctor Degree=%s",tempDoctor->speciality);
	//printf("  Patient Phone No=%lld",tempDoctor->phone);
	printf("\nDoctor Exprience In Years=%d ",tempDoctor->exprience);
   }
   else if(tempDoctor->next==NULL){
   	printf("\nNO SUCH ID EXIST");
   }
   tempDoctor=tempDoctor->next;
  }
}

int assignDoctor(char pProblem[20]){
	tempDoctor=stDoctor;
	char p[20];

  while(tempDoctor!=NULL){
  	strcpy(p,tempDoctor->speciality);
	if(strcmp(pProblem,p)){
	printf("\nDoctor Name=%s,%s",tempDoctor->fname,tempDoctor->lname);
	//printf("\nDoctor Name=%s",tempDoctor->lname);
    printf("\nDoctor Degree=%s",tempDoctor->degree);
	return tempDoctor->id;   
	}
    else
     {tempDoctor=tempDoctor->next;
	 }	
  }
 if(tempDoctor==NULL)
    {
	  printf("No doctor Available At the Moment Please wait");
	  return 0;
    }
}

int Doctor() {
	int n;
	system("cls");
	
do{
    printf("**********WELCOME TO DOCTOR PORTAL****************");
	printf("\n1.ADD DOCTOR        2.DELETE DOCTOR\n3.SEARCH DOCTOR         4.EDIT DOCTOR\n5.DISPLAY ALL DOCTOR         6.MAIN MENU");
	printf("\nEnter Your Choice=");
	scanf("%d",&n);
	switch(n){
		case 1:  addDoctor();break;
		case 2:   printf("Deletion is successful :%c",deleteDoctor());break;
		case 3:  searchDoctor();break;
		case 4:  editDoctor();break;
		case 5:  displayDoctors();break;
		case 6:  main();break;
		default: printf("WRONG CHOICE");
	}
	//system("cls");
  }while(n!=0);


	return 0;
}
