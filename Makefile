CC=gcc
CFLAGS=-Wall

session.o : session.c Session.h
	 $(CC) $(CFLAGS) -c  session.c

site.o : site.c Session.h
	$(CC) $(CFLAGS) -c site.c

move.o : move.c Session.h
	$(CC) $(CFLAGS) -c move.c

close_rename.o : close_rename.c Session.h
	$(CC) $(CFLAGS) -c close_rename.c

main2.o : main2.c Session.h
	$(CC) $(CFLAGS) -c main2.c

browser : session.o site.o move.o close_rename.o main2.o
	$(CC) $(CFLAGS) -o browser  session.o site.o move.o close_rename.o  main2.o


clean :
	rm -f *.o browser

