#include <stdio.h>
#include <stdlib.h>
#include "Session.h"
#include <string.h>

typedef struct TabNode *TabNodePtr;
typedef struct SiteNode *SiteNodePtr;
int CounterTab=0;
int flagtab=0;

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



InfoSessionPtr SessionNew(int flagsession,int flagname,char * OpeningAddress)
{
	char *tempstring="AAA1";
	char *tempstring2="AAA2";
    SessionInfo=malloc(sizeof(struct InfoSession));
    MySessionA=malloc(sizeof(struct InfoSession));
    MySessionB=malloc(sizeof(struct InfoSession));
    TabNodePtr  FirstTabNode=malloc(sizeof(struct TabNode));
    SiteNodePtr FirstSiteNode=malloc(sizeof(struct SiteNode));
/////////////////////////////////////////////////////////////////////
     //create a single node circular and doubly list 
        if(flagsession==0)
        {
        	if(((*SessionInfo)=(*MySessionB)))
        	(*SessionInfo)=(*MySessionA);	
		}
		else if(flagsession==1)
		{
			if((*SessionInfo)=(*MySessionA))
			{
			   (*SessionInfo)=NULL;
			  (*SessionInfo)=(*MySessionB);
		    }
		}
        FirstTabNode->NextTab=FirstTabNode->PrevTab =FirstTabNode; 
        (*SessionInfo)=FirstTabNode; 
//////////////////////////////////////////////////////////////////////
	if(flagname==0 && flagsession==0)
   	{
   	  OpeningAddress=realloc(OpeningAddress,strlen(tempstring) + sizeof(char)+1);
	  strcpy(OpeningAddress,tempstring);
    }
    else if(flagname==0 && flagsession==1)
    {
      OpeningAddress=realloc(OpeningAddress,strlen(tempstring2) + sizeof(char)+1);
	  strcpy(OpeningAddress,tempstring2);
    }
    (*SessionInfo)->AuxTab=NULL;
    (*SessionInfo)->LastTab->NextTab=FirstTabNode;
    FirstTabNode->PrevTab=(*SessionInfo)->LastTab;
    (*SessionInfo)->LastTab=FirstTabNode;
    (*SessionInfo)->FirstTab->PrevTab=(*SessionInfo)->LastTab;
    (*SessionInfo)->LastTab->NextTab=(*SessionInfo)->FirstTab;
    (*SessionInfo)->CurrTab=FirstTabNode;
////////////////////////////
     FirstSiteNode->Address=malloc(strlen(OpeningAddress));
     strcpy(FirstSiteNode->Address,OpeningAddress); 

    //Both head and tail will point to newNode  
     FirstTabNode->FirstSite=FirstSiteNode;  
    //head's previous will point to NULL  
     FirstTabNode->FirstSite->PrevSite= NULL;  
     FirstTabNode->FirstSite->NextSite=NULL;
     FirstTabNode->CurrSite=FirstSiteNode;
     FirstSiteNode->UpTab=FirstTabNode;
 
      // printf("here is the default address:%s\n",FirstSiteNode->Address);
    return &SessionInfo;

}
/////////////////////////////////////////////////////////////////////////////////////////////
void SessionNewTab(char *OpeningAddress)
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
	SiteCreated->Address=malloc(strlen(OpeningAddress)+1);
	strcpy(SiteCreated->Address,OpeningAddress); 
    puts(SiteCreated->Address);
    TabCreated->FirstSite=SiteCreated;  
        //head's previous and next node will point to NULL  
     TabCreated->FirstSite->PrevSite= NULL;  

	 TabCreated->FirstSite->NextSite=NULL;
     TabCreated->CurrSite=SiteCreated;

     SiteCreated->UpTab=TabCreated;
     //counter of how many tabs have been created(is used in SessionClose in a while loop so that we know how many tabs we are closing)
     CounterTab++;
     flagtab=0;
   // printf("here is the default address:%s\n",TabCreated->FirstSite->Address);
}
/////////////////////////////////////////////////////////////////////////////////////////////
void SessionTabShow()
{
   if(((*SessionInfo)->CurrTab!=NULL) &&((*SessionInfo)->CurrTab->CurrSite!=NULL))
   {
   	 printf("Tab-History:%s\n",(*SessionInfo)->CurrTab->CurrSite->Address);
   }
   else if((*SessionInfo)->CurrTab->CurrSite->Address==NULL)
   {
   	  printf("The list is empty,no history");
   }
}

