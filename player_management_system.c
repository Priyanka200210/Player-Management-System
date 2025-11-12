#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Player{
     char name[20];
     int jersyNo;
     int runs;
     int wickets;
     int matchPlayed;
}Player;

int HardCodedValue(Player* ,int );
void addPlayer(Player* ,int );
void displayAllPlayers(Player* ,int );
void displayHeaders();
void display(Player* ,int );
void searchPlayer(Player* ,int );
int searchByJersyName(Player* ,char* ,int );
int searchByJersyNo(Player* ,int ,int );
void deletePlayer(Player* ,int ,int);
void sortPlayer(Player* ,int );
void AscSortByJersyNo(Player* ,int );
void DescSortByJersyNo(Player* ,int );
void AscSortByRuns(Player* ,int );
void DescSortByRuns(Player* ,int );
void AscSortByWickets(Player* ,int);
void DescSortByWickets(Player* ,int);
void AscSortByMatchesPlayed(Player* ,int );
void DescSortByMatchesPlayed(Player* ,int );
void updatePlayerData(Player* ,int );

void main(){
     int choice,size=7,ctr=0;
     Player* player = (Player*)malloc(sizeof(Player)*size);
     ctr = HardCodedValue(player,ctr);
     do{
     	
     	printf("\n1. Add Player\n2. Display All Players\n3. Search Player\n4. Remove Player\n5. Display Sorted Players\n6. Update Player Data\n0. To exit\n Enter your choice:  ");
     	scanf("%d",&choice);
     	switch(choice){
     		case 1:{
     			if(ctr!=size){
     				addPlayer(player,ctr);
     				ctr++;
     				printf("\nPlayer Data Added Successfully!!");
				 }
				 else{
				 	char ch;
					printf("\nInsufficient Memory!!");
					printf("\nDo you want to increase memory?(y/n)");
					fflush(stdin);
					scanf("%c",&ch);
					
					if(ch=='y'){
						size =  size + 1;
						player = (Player*)realloc(player,sizeof(Player)*size);
						addPlayer(player,ctr);
						ctr++;
						printf("\nPlayer Data Added Successfully!!");
					}
				 }
				break;
			 }
			 
			 case 2:{
			 	if(ctr==0){
			 		printf("\nNo Data Present!!");
				}
				else{
					displayAllPlayers(player,ctr);
				}
				 
				break;
			 }
			 
			 case 3:{
			 	 if(ctr==0){
                         printf("\nNo Data Present!!");
                 }
                 else{
                 	searchPlayer(player,ctr);
				 }
				break;
			 }
     		case 4:{
     			if(ctr==0){
     				printf("\nNo data present!!");
				 }
				 else{
					int jNo;
					printf("\nEnter Jersy No: ");
					scanf("%d",&jNo);
					int res = searchByJersyNo(player,jNo,ctr);
					if(res==-1){
						printf("\nPlayer not found!!");
					}
					else{
						deletePlayer(player,res,ctr);
						ctr--;
						printf("\nPlayer Data Deleted Successfully!!");
					}
				 }
				break;
			 }
     		
     		case 5:{
     				sortPlayer(player,ctr);
				break;
			 }
			 
			 case 6:{
			 	updatePlayerData(player,ctr);
				break;
			 }
     		case 0:{
     			printf("\nThank You!!");
				break;
			 }
			 default:{
			 	
				printf("\nInvalid Choice....\n");
			 }
     		
		 }
     	
     	
     	
     	
	 }while(choice!=0);





}

void addPlayer(Player* player,int ctr){
	Player p;
	int flag;
	do{
		flag=0;
		printf("\nEnter the jersy no: ");
		scanf("%d",&p.jersyNo);
		
		for(int i=0;i<ctr;i++){
			if(player[i].jersyNo==p.jersyNo){
				printf("\nThis Jersy No is already exist!!");
				flag=1;
				break;
			}
		}
	}while(flag==1);
	
	printf("\nEnter the Player Name: ");
	fflush(stdin);
	gets(p.name);
	printf("\nEnter Runs: ");
	scanf("%d",&p.runs);
	printf("\nEnter Wickets: ");
	scanf("%d",&p.wickets);
	printf("\nEnter no of matches played: ");
	scanf("%d",&p.matchPlayed);	
	player[ctr] = p;
}

void displayAllPlayers(Player* player,int ctr){
	 printf("\n+---------------+------------------------------+-----------------+----------------+-----------------+\n" );
     printf("\n|   Jersy No    |        Player Name           |     Runs        |    Wickets     |  Matches Played |\n" );
     printf("\n+---------------+------------------------------+-----------------+----------------+-----------------+\n" );
	 
	 for(int i=0;i<ctr;i++){
	 	printf("\n|  %11d  |  %27s | %15d | %14d | %16d|\n",player[i].jersyNo,player[i].name,player[i].runs,player[i].wickets,player[i].matchPlayed);
	 	printf("\n+---------------+------------------------------+-----------------+----------------+-----------------+\n" );
	 }	
}

void displayHeaders(){
	 printf("\n+---------------+------------------------------+-----------------+----------------+-----------------+\n" );
     printf("\n|   Jersy No    |        Player Name           |     Runs        |    Wickets     |  Matches Played |\n" );
     printf("\n+---------------+------------------------------+-----------------+----------------+-----------------+\n" );
}

void display(Player* player,int res){
		printf("\n|  %11d  |  %27s | %15d | %14d | %16d|\n",player[res].jersyNo,player[res].name,player[res].runs,player[res].wickets,player[res].matchPlayed);
	 	printf("\n+---------------+------------------------------+-----------------+----------------+-----------------+\n" );
}

void searchPlayer(Player* player,int ctr){
	int ch;
	printf("\n1. Search By Jersy No\n2. Search by Player Name\n Enter your choice: ");
	scanf("%d",&ch);
	if(ch==1){
		int jNo;
		printf("\nEnter the Jersy No: ");
		scanf("%d",&jNo);
		
		int res = searchByJersyNo(player,jNo,ctr);
		if(res==-1){
			printf("\nPlayer not found!!");
		}
		else{
			displayHeaders();
			display(player,res);
		}
	}
	else if(ch==2){
		char name[20];
		printf("\nEnter the Player Name: ");
		fflush(stdin);
		gets(name);
		
		int res = searchByJersyName(player,name,ctr);
		if(res==-1){
			printf("\nPlayer not found...");
		}
		else{
			displayHeaders();
			display(player,res);
		}
	}
	else{
		printf("\nInvalid Choice!!");
	}
}

int searchByJersyNo(Player* player,int JNo,int ctr){
	for(int i=0;i<ctr;i++){
		if(player[i].jersyNo==JNo){
			return i;
		}

	}
		return -1;
}

int searchByJersyName(Player* player,char* name,int ctr){
	for(int i=0;i<ctr;i++){
		if(strcasecmp(player[i].name,name)==0){
		
			return i;
		}
}
	return -1;
}

void deletePlayer(Player* player,int res,int ctr){
		for(int i=res;i<ctr;i++){
			player[i] = player[i+1];	
		}
}

void sortPlayer(Player* player,int ctr){
		int ch;
		printf("\n1. Sort by Jersy No\n2. Sort by Runs\n3. Sort by wickets\n4. Sort by match played\nEnter your choice: ");
		scanf("%d",&ch);
		
		int cho;
		if(ch>0 && ch<5){	
			printf("\n1. Ascending\n2. Descending\nEnter your choice: ");
			scanf("%d",&cho);
			
			if(ch==1){
				if(cho==1){
					AscSortByJersyNo(player,ctr);	
				}
				else if(cho==2){
					DescSortByJersyNo(player,ctr);
				}
				else{
					printf("\nInvalid Choice!!");
				}
			}
			else if(ch==2){
				if(cho==1){
					AscSortByRuns(player,ctr);	
				}
				else if(cho==2){
					DescSortByRuns(player,ctr);
				}
				else{
					printf("\nInvalid Choice!!");
				}
			}
			else if(ch==3){
				if(cho==1){
					AscSortByWickets(player,ctr);	
				}
				else if(cho==2){
					DescSortByWickets(player,ctr);
				}
				else{
					printf("\nInvalid Choice!!");
				}
			}
			else if(ch==4){
				if(cho==1){
					AscSortByMatchesPlayed(player,ctr);	
				}
				else if(cho==2){
					DescSortByMatchesPlayed(player,ctr);
				}
				else{
					printf("\nInvalid Choice!!");
				}
			}
		}
		else{
			 printf("\nInvalid Choice!!");
		}
}

void AscSortByJersyNo(Player* player,int ctr){

	for(int i=0;i<ctr;i++){
		for(int j=i+1;j<ctr;j++){
			if(player[i].jersyNo>player[j].jersyNo){
				Player temp = player[i];
				player[i] = player[j];
				player[j] = temp;
			}
		}
	}

	
	printf("\nSorted Successfully!!");
	displayAllPlayers(player,ctr);
}

void DescSortByJersyNo(Player* player,int ctr){
	for(int i=0;i<ctr;i++){
		for(int j=i+1;j<ctr;j++){
			if(player[i].jersyNo<player[j].jersyNo){
				Player temp = player[i];
				player[i] = player[j];
				player[j] = temp;
			}
		}
	}
	
	printf("\nSorted Successfully!!");
	displayAllPlayers(player,ctr);
}



void AscSortByRuns(Player* player,int ctr){
	for(int i=0;i<ctr;i++){
		for(int j=i+1;j<ctr;j++){
			if(player[i].runs>player[j].runs){
				Player temp = player[i];
				player[i] = player[j];
				player[j] = temp;
			}
		}
	}
	
	printf("\nSorted Successfully!!");
	displayAllPlayers(player,ctr);
}

void DescSortByRuns(Player* player,int ctr){
	for(int i=0;i<ctr;i++){
		for(int j=i+1;j<ctr;j++){
			if(player[i].runs<player[j].runs){
				Player temp = player[i];
				player[i] = player[j];
				player[j] = temp;
			}
		}
	}
	
	printf("\nSorted Successfully!!");
	displayAllPlayers(player,ctr);
}

void AscSortByWickets(Player* player,int ctr){
	for(int i=0;i<ctr;i++){
		for(int j=i+1;j<ctr;j++){
			if(player[i].wickets>player[j].wickets){
				Player temp = player[i];
				player[i] = player[j];
				player[j] = temp;
			}
		}
	}
	
	printf("\nSorted Successfully!!");
	displayAllPlayers(player,ctr);
}

void DescSortByWickets(Player* player,int ctr){
	for(int i=0;i<ctr;i++){
		for(int j=i+1;j<ctr;j++){
			if(player[i].wickets<player[j].wickets){
				Player temp = player[i];
				player[i] = player[j];
				player[j] = temp;
			}
		}
	}
	
	printf("\nSorted Successfully!!");
	displayAllPlayers(player,ctr);
}



void AscSortByMatchesPlayed(Player* player,int ctr){
	for(int i=0;i<ctr;i++){
		for(int j=i+1;j<ctr;j++){
			if(player[i].matchPlayed>player[j].matchPlayed){
				Player temp = player[i];
				player[i] = player[j];
				player[j] = temp;
			}
		}
	}
	
	printf("\nSorted Successfully!!");
	displayAllPlayers(player,ctr);
}

void DescSortByMatchesPlayed(Player* player,int ctr){
	for(int i=0;i<ctr;i++){
		for(int j=i+1;j<ctr;j++){
			if(player[i].matchPlayed<player[j].matchPlayed){
				Player temp = player[i];
				player[i] = player[j];
				player[j] = temp;
			}
		}
	}
	
	printf("\nSorted Successfully!!");
	displayAllPlayers(player,ctr);
}

void updatePlayerData(Player* player,int ctr){
		Player p;
		printf("\nEnter Jersy No: ");
		scanf("%d",&p.jersyNo);
		
		int res;		
	   res = searchByJersyNo(player,p.jersyNo,ctr);
	   if(res==-1){
	   	printf("\nInvalid Jersy No");
	   }	
	   else{
	   	 	   int choice;
               printf("\nWhat you want to update:");
               printf("\n1. Update by Runs\n2. Update by Wickets\n3. Update by Matches Played\nEnter your choice: ");
               scanf("%d",&choice);
               
               if(choice==1){
               		printf("\nEnter Runs to update: ");
               		scanf("%d",&p.runs);
               		player[res].runs = p.runs; 
               		printf("\nUpdated Successfully!!");
			   }
			   else if(choice==2){
			   	    printf("\nEnter Wickets to update: ");
               		scanf("%d",&p.wickets);
               		player[res].wickets = p.wickets; 
               		printf("\nUpdated Successfully!!");
			   }
			   else if(choice==3){
			   		printf("\nEnter Matches Played to update: ");
               		scanf("%d",&p.matchPlayed);
               		player[res].matchPlayed = p.matchPlayed; 
               		printf("\nUpdated Successfully!!");
			   }
			   else{
			   	printf("\nInvalid Choice!!");
			   }
	   }
}

int HardCodedValue(Player* player,int ctr){
     Player p;
     p.jersyNo = 18;
     strcpy(p.name,"Virat Kohli");
     p.runs = 12000;
     p.wickets = 40;
     p.matchPlayed = 344;
     player[ctr++] = p;

     p.jersyNo = 45;
     strcpy(p.name,"Rohit Sharma");
     p.runs = 11500;
     p.wickets = 8;
     p.matchPlayed = 254;
     player[ctr++] = p;
     
     p.jersyNo = 7;
     strcpy(p.name,"MS Dhoni");
     p.runs = 10773;
     p.wickets = 1;
     p.matchPlayed = 420;
     player[ctr++] = p;
     
     p.jersyNo = 10;
     strcpy(p.name,"Sachin Tendulkar");
     p.runs = 18426;
     p.wickets = 6;
     p.matchPlayed = 432;
     player[ctr++] = p;
     
     p.jersyNo = 12;
     strcpy(p.name,"Yuvraj Singh");
     p.runs = 8701;
     p.wickets = 8;
     p.matchPlayed = 304;
     player[ctr++] = p;
     
     
     return ctr;
     
     
}