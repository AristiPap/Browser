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


void SessionNewAddress(char *StringAddress)
{
	SiteNodePtr NewSite;
	SiteNodePtr temp;
	SiteNodePtr del;
	SiteNodePtr currtemp;
    NewSite =malloc(sizeof(struct SiteNode));  
    temp=malloc(sizeof(struct SiteNode));
    currtemp=malloc(sizeof(struct SiteNode));
    del=malloc(sizeof(struct SiteNode));
   if(NewSite== NULL)  
   {  
       printf("\nOVERFLOW");  
          
   }  
   else  
   {   
       NewSite->Address=malloc(strlen(StringAddress+1));
	   strcpy(NewSite->Address,StringAddress); 
       if((*SessionInfo)->CurrTab->FirstSite== NULL)  
       {   printf("mpaini");
           NewSite->NextSite= NULL;  
           NewSite->PrevSite = NULL;  
           (*SessionInfo)->CurrTab->FirstSite=NewSite;
		   (*SessionInfo)->CurrTab->CurrSite=NewSite;  
       }  
       else  
       {    
          temp =(*SessionInfo)->CurrTab->FirstSite; 
          currtemp=(*SessionInfo)->CurrTab->CurrSite;
		  del=(*SessionInfo)->CurrTab->CurrSite->NextSite; 
          while(temp->NextSite!=NULL)  
          {  
              temp = temp->NextSite;  
             // printf("traversing:%s\n",temp->Address);
          } 
		  while(temp!=(*SessionInfo)->CurrTab->CurrSite)
		  {
		    if(del!=temp)
		    {
		    	if (del->NextSite!= NULL) 
                del->NextSite->PrevSite= del->PrevSite; 
  
        /* Change prev only if node to be deleted is NOT the firsttab */
    		    if (del->PrevSite!= NULL) 
        	    del->PrevSite->NextSite=del->NextSite; 
                (*SessionInfo)->CurrTab->CurrSite=del->NextSite;  
    	/* Finally, free the memory occupied by del*/
    		    free(del); 
    		    del=(*SessionInfo)->CurrTab->CurrSite;
			}
    		else if(del==temp)
    		{
    			del=temp;
    			temp=temp->PrevSite; // Move last pointer to 2nd last node
            	temp->NextSite= NULL; // Remove link to of 2nd last node with last node
        		free(del);
        		temp=currtemp;
        		puts(temp->Address);
        		 printf("SUCCESSFULLY DELETED NODE FROM END OF THE LIST.\n");
		    }
		  } 
          temp->NextSite=NewSite;  
          NewSite->PrevSite=temp;  
          NewSite->NextSite= NULL;  
          (*SessionInfo)->CurrTab->CurrSite=NewSite;
          (*SessionInfo)->CurrTab->AuxSite=(*SessionInfo)->CurrTab->CurrSite;
          printf("The currsite shows:%s\n",(*SessionInfo)->CurrTab->CurrSite->Address);
       }  
	    
       printf("\nNode Inserted\n");  
 
   }  
}

void SessionSiteNext()
{
	SiteNodePtr temp,temp2;
	temp=malloc(sizeof(struct SiteNode));
	temp2=malloc(sizeof(struct SiteNode));
	temp=(*SessionInfo)->CurrTab->CurrSite->NextSite;
	temp2=(*SessionInfo)->CurrTab->CurrSite;
   

	    if(temp==NULL)
        {
          	printf("there is no next site");
          	(*SessionInfo)->CurrTab->CurrSite=temp2;
          	(*SessionInfo)->CurrTab->CurrSite->NextSite=NULL;
          	(*SessionInfo)->CurrTab->CurrSite->PrevSite=(*SessionInfo)->CurrTab->CurrSite->PrevSite;
		}
	    else
        {
		  (*SessionInfo)->CurrTab->CurrSite=temp;
		  (*SessionInfo)->CurrTab->CurrSite->PrevSite=temp2;
		  if(temp->NextSite==NULL)
		  {
		     printf("You reached the lst site");
		     (*SessionInfo)->CurrTab->CurrSite->NextSite=NULL;
	      }
	      else
	      {
	    	(*SessionInfo)->CurrTab->CurrSite->NextSite=temp->NextSite;
		  }
	    }
}
void SessionSitePrev()
{
	SiteNodePtr temp,temp2;
	temp=malloc(sizeof(struct SiteNode));
	temp2=malloc(sizeof(struct SiteNode));
	temp=(*SessionInfo)->CurrTab->CurrSite->PrevSite;
	temp2=(*SessionInfo)->CurrTab->CurrSite;
	if(temp==NULL)
	{
		printf("Can't go to previous site as there is only one site created\n");
	}
	else
	{
		(*SessionInfo)->CurrTab->CurrSite=temp;
		(*SessionInfo)->CurrTab->CurrSite->NextSite=temp2;
		(*SessionInfo)->CurrTab->CurrSite->PrevSite=temp->PrevSite;
    }
}
void SessionOpenNewTab(char *StringAddress)
{
	TabNodePtr  TabCreated;
    SiteNodePtr SiteCreated;
   
	TabCreated=malloc(sizeof(struct TabNode));
    SiteCreated=malloc(sizeof(struct SiteNode));
    
	(*SessionInfo)->LastTab->NextTab=TabCreated;
	
	TabCreated->PrevTab=(*SessionInfo)->LastTab;
	(*SessionInfo)->LastTab=TabCreated;
	(*SessionInfo)->FirstTab->PrevTab=(*SessionInfo)->LastTab;
	(*SessionInfo)->LastTab->NextTab=(*SessionInfo)->FirstTab;
	(*SessionInfo)->CurrTab=TabCreated;
   //Both head and tail will point to newNode 

	SiteCreated->Address=malloc(strlen(StringAddress)+1);
	strcpy(SiteCreated->Address,StringAddress); 
    puts(SiteCreated->Address);
    TabCreated->FirstSite=SiteCreated;  
   //head's previous will point to NULL  
     TabCreated->FirstSite->PrevSite= NULL;  
   //tail's next will point to NULL, as it is the last node of the list 
	 TabCreated->FirstSite->NextSite=NULL;
     TabCreated->CurrSite=SiteCreated;
     SiteCreated->UpTab=TabCreated;
    (*SessionInfo)->CurrTab->PrevTab->AuxSite=(*SessionInfo)->CurrTab->PrevTab->CurrSite;
    (*SessionInfo)->AuxTab=(*SessionInfo)->CurrTab->PrevTab;
    CounterTab++;
    flagtab=1;
    printf("here is the default address:%s\n",TabCreated->FirstSite->Address);
	
}

void SessionSiteShow()
{
	if(((*SessionInfo)->CurrTab!=NULL) &&((*SessionInfo)->CurrTab->CurrSite!=NULL))
   {
   	 printf("Current Site Address:%s\n",(*SessionInfo)->CurrTab->CurrSite->Address);
   }
   else if((*SessionInfo)->CurrTab->CurrSite->Address==NULL)
   {
   	  printf("The list is empty,no history");
   }
}
