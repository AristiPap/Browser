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
        char*     OpeningAddress; //The default address of the site of a New Tab
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


int SessionTabMoveRight()
{
    TabNodePtr temp;
    TabNodePtr tempb;

    temp=malloc(sizeof(struct TabNode));
    tempb=malloc(sizeof(struct TabNode));
    temp=(*SessionInfo)->CurrTab;
    tempb=(*SessionInfo)->CurrTab->NextTab;

    if ((*SessionInfo)->CurrTab!=(*SessionInfo)->LastTab)
    {
          if( temp->PrevTab)
          {
            temp->PrevTab->NextTab =tempb;
          }
          else
          {
            (*SessionInfo)->FirstTab=tempb;
          }
          if ( tempb->NextTab!=(*SessionInfo)->FirstTab)
          {
            tempb->NextTab->PrevTab = temp;
          }
          else
          {
            (*SessionInfo)->LastTab=temp;
          }
          temp->NextTab= tempb->NextTab;
          tempb->PrevTab=temp->PrevTab;
          tempb->NextTab = temp;
          temp->PrevTab=tempb;
    }
    else
    {
        //if currtab is the last tab then we don't swap with the right node(first node)
        printf("can't move tab to the right as it's the last tab\n");
        (*SessionInfo)->CurrTab=(*SessionInfo)->LastTab;
        (*SessionInfo)->CurrTab->NextTab=(*SessionInfo)->FirstTab;
    }

    return ;
}
///////////////////////////////////////////////////////////////////

int SessionTabMoveLeft()
{
    TabNodePtr temp;
    TabNodePtr tempb;

    temp=malloc(sizeof(struct TabNode));
    tempb=malloc(sizeof(struct TabNode));
    temp=(*SessionInfo)->CurrTab->PrevTab;
    tempb=(*SessionInfo)->CurrTab;

    if((*SessionInfo)->CurrTab!=(*SessionInfo)->FirstTab)
    {
          if( temp->PrevTab!=(*SessionInfo)->LastTab)
          {
            temp->PrevTab->NextTab =tempb;
          }
          else
          {
            (*SessionInfo)->FirstTab=tempb;
          }
          if ( tempb->NextTab )
          {
            tempb->NextTab->PrevTab=temp;
          }
          temp->NextTab= tempb->NextTab;
          tempb->PrevTab=temp->PrevTab;
          tempb->NextTab = temp;
          temp->PrevTab=tempb;

    }
    else
    {
     //if currtab is the first tab we dont swap with the left node(lasttab)
      printf("can't move tab to the right as it's the last tab\n");
    }

    return ;
}
////////////////////////////////////////////////////////////////////////
int SessionTabNext()
{
        TabNodePtr temp,temp2;
        temp=malloc(sizeof(struct TabNode));
        temp2=malloc(sizeof(struct TabNode));
        temp=(*SessionInfo)->CurrTab->NextTab;
        temp2=(*SessionInfo)->CurrTab;
        if((*SessionInfo)->CurrTab==(*SessionInfo)->FirstTab==(*SessionInfo)->LastTab)
        {
          printf("Can't go to the next tab as there is only one tab created");
        }
        else
        {
           if((*SessionInfo)->CurrTab==(*SessionInfo)->LastTab->PrevTab)
           {
                (*SessionInfo)->CurrTab=(*SessionInfo)->LastTab;
                (*SessionInfo)->CurrTab->NextTab=(*SessionInfo)->FirstTab;
                (*SessionInfo)->CurrTab->PrevTab=temp2;
           }
           else if((*SessionInfo)->CurrTab==(*SessionInfo)->LastTab)
           {
                (*SessionInfo)->CurrTab=(*SessionInfo)->FirstTab;
                (*SessionInfo)->CurrTab->NextTab=(*SessionInfo)->FirstTab->NextTab;
                (*SessionInfo)->CurrTab->PrevTab=(*SessionInfo)->LastTab;
           }
           else
           {
                (*SessionInfo)->CurrTab=temp;
                (*SessionInfo)->CurrTab->NextTab=temp->NextTab;
                (*SessionInfo)->CurrTab->PrevTab=temp2;
           }
        }
}
////////////////////////////////////////////////////////////////////////////
int SessionTabPrev()
{
        TabNodePtr temp,temp2;
        temp=malloc(sizeof(struct TabNode));
        temp2=malloc(sizeof(struct TabNode));
        temp=(*SessionInfo)->CurrTab->PrevTab;
        temp2=(*SessionInfo)->CurrTab;
        if((*SessionInfo)->CurrTab==(*SessionInfo)->FirstTab==(*SessionInfo)->LastTab)
        {
                printf("Can't go to previous tab as there is only one tab created");
        }
        else
        {
                if((*SessionInfo)->CurrTab->PrevTab==(*SessionInfo)->FirstTab)
                {
                        (*SessionInfo)->CurrTab=(*SessionInfo)->FirstTab;
                        (*SessionInfo)->CurrTab->PrevTab=(*SessionInfo)->LastTab;
                        (*SessionInfo)->CurrTab->NextTab=(*SessionInfo)->FirstTab->NextTab;
                }
                else if((*SessionInfo)->CurrTab==(*SessionInfo)->FirstTab)
                {
                        (*SessionInfo)->CurrTab=(*SessionInfo)->LastTab;
                        (*SessionInfo)->CurrTab->PrevTab=(*SessionInfo)->LastTab->PrevTab;
                        (*SessionInfo)->CurrTab->NextTab=(*SessionInfo)->FirstTab;
                }
                else
                {
                        (*SessionInfo)->CurrTab=temp;
                        (*SessionInfo)->CurrTab->NextTab=temp2;
                        (*SessionInfo)->CurrTab->PrevTab=temp->PrevTab;
                }
        }
}

