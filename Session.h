#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef __SESSION__
#define __SESSION__

typedef struct InfoSession *InfoSessionPtr;
InfoSessionPtr *SessionInfo;
InfoSessionPtr *MySessionA;
InfoSessionPtr *MySessionB;
int CounterTab;
int flagtab;

InfoSessionPtr SessionNew(int,int,char *);
void SessionNewTab(char*);
void SessionTabShow();
void SessionSiteShow();
int SessionNewOpeningAddress(int,char* ,char*,int);
int SessionShowOpeningAddress(char*);
int SessionTabMoveRight();
int SessionTabMoveLeft();
int SessionTabNext();
int SessionTabPrev();
void SessionNewAddress(char *);
void SessionSiteNext();
void SessionSitePrev();
void SessionOpenNewTab(char *);
void TabClose(char *);
void SessionClose(char *);

/* The rest of the interface functions follow */

#endif
