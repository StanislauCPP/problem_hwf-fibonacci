SRC = $(wildcard *.c)
TESTFOLDER = tests/
POST_OUT = -o game.out

build :
	gcc $(SRC) $(POST_OUT)
	
buildTest :
	gcc $(TESTFOLDER)test.c MatchesFibonacciGame.c -o $(TESTFOLDER)/test.out
	
test :
	./runTest.sh
