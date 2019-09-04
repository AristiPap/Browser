#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Session.h"
#define MAX_OPTIONS 14
void print_options()
{
	printf("\n");
	printf("0. Exit\n");
	printf("1. Create New Session\n");
	printf("2. Add Tab\n");
	printf("3. Open new tab with the same address as the current site (function SessionOpenNewTab)\n");
	printf("4. Go to next tab\n");
	printf("5. Go to previous tab\n");
	printf("6. Move to the tab to the left\n");
	printf("7. Move to the tab to the right\n");	
	printf("8. Change default address\n");
	printf("9. Go to the next site of the current tab(if it exists)\n");
	printf("10. Go to the previous site of the current tab(if it exists)\n");
	printf("11. Add new Site and URL\n");
	printf("12. Close current tab\n");
	printf("13. Close current session\n");
	printf("14. Choose Session(press 0 or 1)\n");
	
	printf("Enter your input (0-%d): ", MAX_OPTIONS);
}
char *stringBuilder()
{
	char *string,ch;
	int i=0;
	string=malloc(sizeof(char));
	while((ch=getchar())!='\n')
	{
		string[i]=ch;
		string=realloc(string,sizeof(string) + sizeof(char));
		i++;
	}
	string[i]='\0';

	return string;
}


int get_option()
{
	char buf[100];
	int option;

	option = -1;
	while (option < 0 || option > MAX_OPTIONS) {
		print_options();
		fgets(buf, sizeof(buf), stdin);
		sscanf(buf, "%d", &option);
	}
	return option;
}

int main()
{
	int counter1=0,counter2=0,option,flag=0,flagsession=0,flagname=0,size=35,session;
	InfoSessionPtr *SessionInfo;
	InfoSessionPtr *MySessionA=NULL;
	InfoSessionPtr *MySessionB=NULL;
	char *OpeningAddress;	
	char *NewString;
	char *StringAddress;
	OpeningAddress=malloc(sizeof(char));
    
	do {
		option = get_option();
		switch (option) {
		case 1:
			if (flag==1) {
				printf("\nTab-List already exists!\n");
			}
			else if(flag==0)
			{
			  SessionNew(flagsession,flagname,OpeningAddress);
			  SessionNewTab(OpeningAddress);
			  SessionTabShow();
			  flag=1;
			}
			break;
		case 2:
			if(flag==1)
			{
			  SessionNewTab(OpeningAddress);
			  printf("New Tab Created\n");
			  SessionTabShow();
            }
            else
            {
		      printf("Error:there is no tab-list created\n");
		   	}
			break;
		case 3:
			  SessionOpenNewTab(StringAddress);
			  SessionSiteShow();
			  break;
			  
		case 4:
		     SessionTabNext();
		      SessionTabShow();
		     break;
		case 5:
			 SessionTabPrev();
			 SessionTabShow();
			 break;
	    case 6:
			SessionTabMoveLeft();
			 SessionTabShow();
			break;	
		case 7:
			SessionTabMoveRight();
			SessionTabShow();
			break;
		case 8:
			flagname=0;
			printf("Enter new default address here:");	
			flagname=1;
			NewString=stringBuilder();
			size=strlen(NewString);
			SessionNewOpeningAddress(flagname,OpeningAddress,NewString,size);
            SessionShowOpeningAddress(OpeningAddress);
			break;
		case 9:
		     SessionSiteNext();
		     SessionSiteShow();
		     break;
		case 10:
			 SessionSitePrev();
			 SessionSiteShow();
			 break;
		case 11:
			printf("Enter address:");
			StringAddress=stringBuilder();
			SessionNewAddress(StringAddress);
			SessionTabShow();
			break;
		case 12:
		    TabClose(OpeningAddress);
		    SessionSiteShow();
			break;
		case 13:
			SessionClose(OpeningAddress);
			break;
		case 14:
			printf("enter number of session you prefer(0 or 1):");
			scanf("%d",&session);
			    if(session==0)
				{
			    	flagsession=0;
			    	counter1=counter1+1;
			    	if(counter1==1)
                    flag=0;
			    }
			    else if(session==1)
			    {
			    	counter2=counter2+1;
			    	flagsession=1;
			    	if(counter2==1)
			    	flag=0;
				}
		}
	}	while (option);
	return(0);
}
