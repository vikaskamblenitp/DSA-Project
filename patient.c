#include <stdio.h>
#include<malloc.h>
#include<string.h>
#include<windows.h>
void addPatient();
void displayPatient();
void dischargePatient();
void searchPatient();
  void searchByID(int);
  void searchByName(char[]);
void editPatient();
char deletePatient();
int patientNO=1;
int NOP=0;
struct patient{
 int Room;
 int pNO;
 long int dateOfAdmit;
 long int dateOfDischarge;
 char fname[10];
 char lname[10];
 char sex;
 char add[20];
 char problem[20];
 float Charge;
 int pDoctor;
 long long int  phone;
 struct patient *next;	
};
struct patient *pStart=NULL,*ptemp=NULL,*pPrev=NULL;
void addPatient(){
	printf("*********************ADD PATIENT DETAILS*********************");
	ptemp=(struct patient*)malloc(sizeof(struct patient));
	ptemp->pNO=patientNO;
	printf("\nPatient NO               =%d",patientNO++);
    ptemp->Room=roomAllot(ptemp->pNO);
	printf("\nPatient Room No          =%d",ptemp->Room);
	    //scanf("%d",&ptemp->Room);
	printf("\nEnter Patient Name       =");
	    scanf("%s",&ptemp->fname);
/*	printf("Enter Patient Last Name   =");    
	    scanf("%s",&ptemp->lname);
	    char sex;
	printf("Enter Patient Sex(M/F)    =");
	    scanf("%s",&sex);
	if(sex=='M'||sex=='F'){
	      ptemp->sex=(char)sex;	
		}
	else
		  printf("Wrong Choice");	
	printf("Enter Patient Address\nCity                    =");
	    scanf("%s",&ptemp->add);
	printf("Date of Admit(dd/mm/yyyy) =");
	    scanf("%lu",&ptemp->dateOfAdmit);
	printf("\nEnter Patient Phone No  =");
	    scanf("%lld",&ptemp->phone);*/
	    int pProb;
    printf("\nPatient problem=");
     printf("\n1.Neurological    2.Psycho\n3.Tooth      4.Heart \n5.Child    6.Other\nEnter Your Problem No=");
     scanf("%d",&pProb);
    switch(pProb){
	    case 1:  strcpy(ptemp->problem,"Neurologist");break;
		case 2:  strcpy(ptemp->problem,"Psychiatrist");break;
		case 3:  strcpy(ptemp->problem,"Dentist");break;
		case 4:  strcpy(ptemp->problem,"Heart Surgeon");break;
		case 5:  strcpy(ptemp->problem,"Child Specialist");break;
		case 6:  strcpy(ptemp->problem,"Other");break;
		default: printf("WRONG CHOICE");
	}
	printf("Doctor Assigned           =");
	char p[20];
	 strcpy(p,ptemp->problem);
        ptemp->pDoctor=assignDoctor(ptemp->problem);
 	printf("\n*********Data Saved Successfully: Please press Enter****************\n"); 
	    
if(pStart==NULL){
	pStart=ptemp;
	pStart->next=NULL;
   }
 else{
 	pPrev=pStart;
 	pStart=ptemp;
 	pStart->next=pPrev;
 	pPrev->next=NULL;
   }  	    
}
void displayPatient(){
 printf("*********************PATIENT DETAILS*********************");
 
	ptemp=pStart;
  while(ptemp!=NULL){
  	printf("\nPatient Room No      =%d",ptemp->Room);
	printf("Patient Id             =%d",ptemp->pNO);
	printf("\nPatient Name         =%s",ptemp->fname);
	printf("\nPatient Last Name    =%s",ptemp->lname);    
	printf("\nPatient Sex          =%c",ptemp->sex);
	printf("\nPatient Address      =%s",ptemp->add);
	printf("\nPatient problem      =%s",ptemp->problem);
	printf("\nPatient Phone No     =%lld",ptemp->phone);
	NOP++;
	ptemp=ptemp->next;
  }
	printf("\nTOTAL NO OF PATIENTS=%d",NOP);
}
void dischargePatient(){     //discharge patient not completed
    int pNO;
    printf("\nEnter Patient NO=");	
    scanf("%d",&pNO);
	Billing(pNO); 
    //calculate total charge=room+medical+extra
    deleteRoom(pNO);
//	billing(ptemp);   
}
void searchPatient(){
	int n;
		printf("\n1.BY ID         2.BY NAME");
	printf("\nEnter Your Choice=");
	scanf("%d",&n);
	switch(n){
		case 1: 
		        printf("\nEnter Patient NO=");
		        int pNO;
                scanf("%d",&pNO);
		        searchByID(pNO);
				break;
		case 2: printf("\nEnter Patient Name=");
		        char Name[10];
		        scanf("%s",Name);
		        searchByName(Name);break;
	}
	
}
void searchByID(int pNO){
	 printf("****************PATIENT DETAILS SEARCHED BY ID****************");
		ptemp=pStart;
  while(ptemp!=NULL){
   if(ptemp->pNO==pNO){
    printf("\nPatient Room No                   =%d ",ptemp->Room);
	printf("\nPatient Id                        =%d",ptemp->pNO);
	printf("\nPatient Name                      =%s",ptemp->fname);
    printf("Patient Last Name                   =%s",ptemp->lname);
	printf("\nPatient Sex                       =%c ",ptemp->sex);
    printf("\nPatient Address                   =%s",ptemp->add);
	printf("\nPatient problem                   =%s",ptemp->problem);
	printf("  Patient Phone No                  =%lld",ptemp->phone);
  return;
   }
   else if(ptemp->next==NULL){
   	printf("\nNO SUCH ID EXIST");
   }
   ptemp=ptemp->next;
  }
}
 void searchByName(char Name[10]){
 	 printf("****************PATIENT DETAILS SEARCHED BY NAME****************");
		ptemp=pStart;
  while(ptemp!=NULL){
   if(strcmp(ptemp->fname,Name)){
    printf("\nPatient Room No=%d",ptemp->Room);
	printf("Patient Id=%d",ptemp->pNO);
	printf("\nPatient Name=%s",ptemp->fname);
	printf("\nPatient Last Name=%s",ptemp->lname);    
	printf("\nPatient Sex=%c",ptemp->sex);
	printf("\nPatient Address=%s",ptemp->add);
	printf("\nPatient problem=%s",ptemp->problem);
	printf("\nPatient Phone No=%lld",ptemp->phone);
   }
   else if(ptemp->next==NULL){
   	printf("\nNO SUCH ID EXIST");
   }
ptemp=ptemp->next;
  }
}
void editPatient(){    
int pNO,n;
printf("Enter Patient Patient No=");
scanf("%d",&pNO);
//searchByID(pNO);
do{
printf("Enter Which Data To Edit");
 printf("\n1.Room No    2.No     3.FName    4.LName    5.Sex\n6.Address     7.Problem    8.Phone No    0.No More Edit");
 scanf("%d",&n);
 if(n==1){
 	 int rNO=roomCheck(ptemp->pNO);
 	 if(rNO>90&&rNO<=190){
 	 //	ptemp->charge=//Calculate by considering date
	  }
 	 else if(rNO>0&&rNO<=40){
 	 	//ptemp->charge=//Calculate by considering date
	  }
	  else if(rNO>40&&rNO<=90){
 	 	//ptemp->charge=//Calculate by considering date
	  }
	  else if(rNO>190&&rNO<=200){
 	 	//ptemp->charge=//Calculate by considering date
	  }
 	 ptemp->Room=roomAllot(ptemp->pNO);
	 printf("\nPatient Room No=%d",ptemp->Room);
  }
  else if(n==2){
  	printf("\nPatient NO=");
  	  scanf("%d",&ptemp->pNO);
  }
  else if(n==3){
	printf("\nEnter Patient Name=");
	    scanf("%s",&ptemp->fname);
  }
  else if(n==4){
	printf("\nEnter Patient Last Name=");    
	    scanf("%s",&ptemp->lname);
	}
  else if(n==5){	
	printf("\nEnter Patient Sex=");
	    scanf("%c",&ptemp->sex);
	}
  else if(n==6){
	printf("\nEnter Patient Address=");
	    scanf("%s",&ptemp->add);
	}
   else if(n==7){
    printf("\nEnter Patient problem=");
	    scanf("%s",&ptemp->problem);
	}
   else if(n==8){
	printf("\nEnter Patient Phone No=");
	    scanf("%lld",&ptemp->phone);
	}
}while(n!=0);
	
}
char deletePatient(){
	int pNO;
	char y='Y';
	printf("\nEnter the Patient No Whose Data is To Be Deleted=");
	scanf("%d",&pNO);
			ptemp=pStart;
  while(ptemp!=NULL){
   if(ptemp->pNO==pNO){
   	pPrev->next=ptemp->next;
   	//free(ptemp);    TO FREE THE DATA
   	return y;
   }
   
   else if(ptemp->next==NULL){
   	printf("\nNO SUCH PATIENT EXIST");
   }
   else{ 
   ptemp->pNO--;
   pPrev=ptemp;
   }
		ptemp=ptemp->next;
  }
return y='N';	
}
void Billing(int patientNo){
		ptemp=pStart;
  while(ptemp!=NULL){
   if(ptemp->pNO==patientNo){
   	float Mcharge,Rcharge;
    printf("\nEnter Date of Discharge=");	
    scanf("%lu",&ptemp->dateOfDischarge);
    printf("\nEnter Medical Charges =");
	scanf("%f",&Mcharge);	
	printf("\tEnter Room Charges =");
	scanf("%f",&Rcharge);
	ptemp->Charge=Mcharge+Rcharge;
	system("cls");
	printf("*****************************Hospital Name***********************************");
	printf("\n******************************Bill Payment***********************************");
	printf("\nNIT Campus,");
	printf("\nPatna 800005");
	printf("\nPhone No:6205684286");printf("\t\t\tDate:%lu",ptemp->dateOfDischarge);
	printf("\n*********************************************************************");
	 
    printf("\nPatient Room No                   =%d ",ptemp->Room);
	printf("\nPatient Id                        =%d",ptemp->pNO);
	printf("\nPatient Name                      =%s %s",ptemp->fname,ptemp->lname);
   // printf("Patient Last Name                   =%s",ptemp->lname);
	printf("\nPatient Sex                       =%c",ptemp->sex);
    printf("\nPatient Address                   =%s",ptemp->add);
	printf("\nPatient problem                   =%s",ptemp->problem);
	printf("\nPatient Phone No                  =%lld",ptemp->phone);
	printf("\nDate of Admit(dd/mm/yyyy)         =%lu",ptemp->dateOfAdmit);
	printf("\nDate of Discharge(dd/mm/yyyy)     =%lu",ptemp->dateOfDischarge); 
	printf("\n*********************************************************************");
	printf("\nMedical Charges                   =Rs.%f",Mcharge);
	printf("\nRoom Charges                      =Rs.%f",Rcharge);
	printf("\nTotal Charges                     =Rs.%f",ptemp->Charge);
   }
   else if(ptemp->next==NULL){
   	printf("\nNO SUCH ID EXIST");
   }
   ptemp=ptemp->next;
  }
}
void Patient(){
	system("cls");
	int n;
do{ 
	printf("**********WELCOME TO PATIENT PORTAL****************");
	printf("\n1.ADMIT               2.DISCHARGE\n3.SEARCH               \b4.EDIT\n5.DELETE              6.MAIN MENU\n7.ALL PATIENTS DETAILS");
	printf("\nEnter Your Choice=");
	scanf("%d",&n);
	switch(n){
		case 1:  addPatient();break;
		case 2:  dischargePatient();break;
		case 3:  searchPatient();break;
		case 4:  editPatient();break;
		case 5:  printf("\nDeletion is successful(Y/N)?:%s",deletePatient());break;
		case 6:  main();break;
		case 7:  displayPatient();break;
		default: printf("WRONG CHOICE");
	}
//	system("cls");
  }while(n!=0);
}

