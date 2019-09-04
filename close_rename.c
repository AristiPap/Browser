#include <stdio.h>
#include <stdlib.h>
#include "Session.h"
#include <string.h>

typedef struct TabNode *TabNodePtr;
typedef struct SiteNode *SiteNodePtr;


struct InfoSession {
	TabNodePtr FirstTab; //pointer at the first node of the list Tab
	TabNodePtr LastTab;  //pointer at the last node of the list Tab
	TabNodePtr CurrTab; //pointer at the current node of the list Tab
	TabNodePtr AuxTab;  //pointer that is used for moving nodes from left to right
	char* 	  OpeningAddress; //The default address of the site of a New Tab
};

struct TabNode {	
	TabNodePtr PrevTab, NextTab;
	SiteNodePtr FirstSite;
	SiteNodePtr CurrSite;
	SiteNodePtr AuxSite;
};

struct SiteNode{
	SiteNodePtr PrevSite, NextSite;
	TabNodePtr UpTab;
	char *Address;
};

int SessionNewOpeningAddress(int flagname,char*OpeningAddress,char *NewString,int size)
{	  
	//we reallocate the memory of the opening address(size is same as the size of the newstring)
    OpeningAddress=realloc(OpeningAddress,(size+1));
	strcpy(OpeningAddress,NewString);
	//when flagname=1 means that the default opening address is no longer the default  
	flagname=1;
    return flagname;
}
int SessionShowOpeningAddress(char*OpeningAddress)
{
	puts(OpeningAddress);
	printf("The new default address is:%s\n",OpeningAddress);
	return 0;
}

void TabClose(char *OpeningAddress)
{
	SiteNodePtr del_site;
	TabNodePtr  del_tab;
	int flag=0;
	
	del_site=malloc(sizeof(struct SiteNode));
	del_tab=malloc(sizeof(struct SiteNode));
	
	del_site=(*SessionInfo)->CurrTab->FirstSite;
	del_tab=(*SessionInfo)->CurrTab;
	while((*SessionInfo)->CurrTab->CurrSite!=NULL)
	{
		if(flagtab==1)
		{
			flag=1;
		}
        (*SessionInfo)->CurrTab->FirstSite=(*SessionInfo)->CurrTab->FirstSite->NextSite; // Move head pointer to 2nd node
        
        if ((*SessionInfo)->CurrTab->FirstSite!= NULL)
            (*SessionInfo)->CurrTab->FirstSite->PrevSite= NULL; // Remove the link to previous node
         
        (*SessionInfo)->CurrTab->CurrSite=del_site->NextSite;  
        free(del_site); // Delete the first node from memory
        del_site=(*SessionInfo)->CurrTab->CurrSite;
		//printf("deleted site from the top\n");
	}
	if(del_tab!=(*SessionInfo)->FirstTab && del_tab!=(*SessionInfo)->LastTab )
	{
		del_tab->NextTab->PrevTab= del_tab->PrevTab; 
  
        /* Change prev only if node to be deleted is NOT the first node */
    		if (del_tab->PrevTab!= NULL) 
        	del_tab->PrevTab->NextTab=del_tab->NextTab;
			if(flag==1)
			{  
			  	(*SessionInfo)->CurrTab=(*SessionInfo)->AuxTab;
			  	(*SessionInfo)->CurrTab->CurrSite=(*SessionInfo)->CurrTab->AuxSite;
			} 
			else
			{
				 (*SessionInfo)->CurrTab=del_tab->NextTab;  
			}
    	// Finally, free the memory occupied by del
    		free(del_tab); 
    		printf("Tab deleted");
    	
	}
	else if(del_tab==(*SessionInfo)->FirstTab)
	{
	   if((*SessionInfo)->FirstTab->NextTab==(*SessionInfo)->FirstTab)  
       {  
         (*SessionInfo)->FirstTab= NULL;   
         free((*SessionInfo)->FirstTab);  
         printf("\nNode Deleted\n");  
       }  
       else  
       {  
          del_tab=(*SessionInfo)->FirstTab;   
          while(del_tab->NextTab!=(*SessionInfo)->FirstTab)  
          {  
            del_tab = del_tab->NextTab;  
          }  
          del_tab ->NextTab=(*SessionInfo)->FirstTab->NextTab;  
          (*SessionInfo)->FirstTab-> NextTab -> PrevTab =del_tab;  
          (*SessionInfo)->FirstTab= del_tab->NextTab; 
          if((*SessionInfo)->FirstTab!=NULL)
          {
           (*SessionInfo)->CurrTab=del_tab->NextTab;
	      }
          free(del_tab);    
          printf("\nNode Deleted!\n");  
        }  	
        
	} 
	else if(del_tab==(*SessionInfo)->LastTab)
	{
		del_tab=(*SessionInfo)->LastTab;  
		  
        del_tab->PrevTab->NextTab=(*SessionInfo)->FirstTab;   
        (*SessionInfo)->LastTab=del_tab->PrevTab;
        (*SessionInfo)->FirstTab= del_tab->NextTab; 
        if(flag==1 &&(*SessionInfo)->AuxTab!=NULL)
        {
        	(*SessionInfo)->CurrTab=(*SessionInfo)->AuxTab;
		}
		else
        (*SessionInfo)->CurrTab=del_tab->NextTab;
        free(del_tab);
   }
	CounterTab--;
}

void SessionClose(char *OpeningAddress)
{
	SiteNodePtr del_site;
	TabNodePtr  del_tab;
		
	del_site=malloc(sizeof(struct SiteNode));
	del_tab=malloc(sizeof(struct TabNode));
    printf("%d",CounterTab);
	del_site=(*SessionInfo)->CurrTab->FirstSite;
	del_tab=(*SessionInfo)->FirstTab;
	(*SessionInfo)->CurrTab=del_tab;
	//call function TabClose for its tab seperately
	while(CounterTab>0 )
	{
		TabClose(OpeningAddress);
		//tab deleted
		CounterTab--;
	}

     (*SessionInfo)=NULL;
     //free the whole session
     free((*SessionInfo));
	printf("Session terminated\n");
}
