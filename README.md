# Browser
The following project is a representation of an actual browser.Basically the structure of the browser (tabs,sites,how they are created/accessed/deleted) is an implementation of doubly-linked-lists and circular-doubly-linked-lists.The various features of this project are :

>>SessionNew=Creates a session on the browser(the user can open upto 2 sessions that control different tabs).Creates the InfoSession informational node, the first node in the Tab list, and the first site under TabNode.  Initializes the members of the InfoSession,the Tab node and Site node. 
>>SessionNewTab=Opens a new tab at the end of the circular doubly linked list and creates the first site under the tab(The tabs are created with the form of a doubly linked list).(every site opens with the default opening address).
>>SessionTabShow/SessionSiteShow= Print the address of the current site of the currebt tab.
>>SessionTabClose= Deletes the current tab and changes the pointers of the current tab,previous and next tab.
>>SessionNewOpeningAddress:User enters a new default address for the session(every tab will now be initialized with a new address)
>>SessionSiteNext= Moves the currsite pointer to the next site if it exists else remains at the same position
>>SessionSitePrev=Moves the currsite pointer to the previous site if it exists else remains at the same position
>>SessionNewAddress=The function takes as a parameter a string (the site Address that we follow or import), it creates the next node of the CurrSite. If more Site-nodes exist after the Current Site,function deletes them before importing the new site. Sets the CurrSite to the new node.  
>>SessionTabNext=Moves the currtab pointer to the next tab in a circular way which means that if we are at the last tab of the session, then the current pointer will point to the first tab.(Function imitates the Ctrl+Tab)
>>SessionTabPrev=Moves the currtab pointer to the previous tab in a circular way which means that if we are at the first tab of the session, then the current pointer will point to the last tab.(Function imitates the Ctrl+Shift+Tab)
>>SessionTabMoveLeft=Moves the node showing the CurrTab a position on the left.Basically the current tab is swapped with the previous node (but not in a circle! If the CurrTab is the first tab,it is not moved). The list of sites follows the node.
>>SessionTabMoveRight=Moves the node showing the CurrTab a position on the right.Basically the current tab is swapped with the next  node (but not in a circle! If the CurrTab is the last tab,it is not moved). The list of sites follows the node.
>>SessionOpenNewTab=With this function, we are able to open a new tab with the same address as current site of the that we are using currently.
>>SessionClose:Deletes the whole structure of the session that we have started on the browser.For every tab it deletes all its sites,then every tab is deleted and finally the Infosession node is erased.

******(The project-browser is developed with information-hiding)******
To compile the program the user has to type make browser.To execute you type ./browser
