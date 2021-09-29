#include<stdio.h>
#include<malloc.h>
int room[200];
int top_x=0;
int top_y=40;
int top_z=90;
int top_w=190;
int push_x(int);
int push_y(int);
int push_z(int);
int push_w(int);

struct room *rStart=NULL,*rtemp=NULL,*rPrev=NULL;
int roomAllot( int pNO){
	int n;
	printf("\nPlease Select Room Type");
	printf("\n1.ICU()       2.OPERATION THEATRE\n3.OPD       4.FIRST AID ROOM ");
	printf("\nPlease Enter Your Choice");
	scanf("%d",&n);	
		switch(n){
		case 1:  top_x=rAvailable(0,40,top_x); 
		         room[top_x]=pNO;
		         return (top_x)+1;
				 break;
		case 2:  top_z=rAvailable(40,90,top_y); 
		         room[top_y]=pNO;
		         return (top_y)+1;
				 break; 
		case 3: top_z=rAvailable(90,190,top_z); 
		         room[top_z]=pNO;
		         return (top_z)+1;
				 break;  
	    case 4: top_w=rAvailable(190,200,top_w); 
		         room[top_w]=pNO;
		         return (top_w)+1;
				 break; 
		case 5:  break;			      
	}
}
		int rAvailable(int l,int m,int top){
			int i=0;
			for(i=top;i<m;i++){
				if(room[i]==0)
			           return i;
			}
			for(i=l;i<top;i++){
				if(room[i]==0)
			           return i;
			}
		}
int roomCheck(int pNO){
 int i;
  for(i=0;i<200;i++){
	if(room[i]==pNO) 
	   return i+1;
  }
return 0;	
}	
void deleteRoom(int pNO){
	int i;
	for(i=0;i<200;i++){
	if(room[i]==pNO){
		room[i]=0;
		printf("Room No %d is Available Now",i+1);
	}
  }
}	
	
