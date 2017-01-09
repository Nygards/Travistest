DRIVER=driver
LIB=lib
OBJ=obj
SRC=src
DEPS=deps
TESTDIR=test
# Lägg till alla undermappar till lib
CFOLDERS=$(SRC) $(LIB) $(DRIVER) $(TESTDIR)
HFOLDERS=$(CFOLDERS)

CC = gcc
# Lägg till alla undermappar till lib
INCLUDES=-I $(TESTDIR) -I $(LIB)
DEPFLAGS=-MMD -MT $@ -MF $(DEPS)/$*.d
CFLAGS=-ggdb -Wall -std=c11 -c $(DEPFLAGS)
LDFLAGS=-ggdb $(INCLUDES)

#FLAGS=-std=c11 -Wall -ggdb

VALGRIND=valgrind --leak-check=full --undef-value-errors=no


# Externa biblioteksfiler hamnar här:
LIBS = #tree.o list.o
# Includera alla .c filer här:
SOURCES = gc.c header.c stack.c
TESTSOURCES = test_runner.c header_test.c stack_test.c
MAIN = main.o

# object är samma som SOURCES men byter ut .c mot .o
OBJECTS = $(SOURCES:.c=.o) $(LIBS)
TESTOBJ = $(TESTSOURCES:.c=.o) $(LIBS)
DFILES = $(OBJECTS:.o=.d)

GCOBJECTS = $(addprefix $(OBJ)/, $(MAIN) $(OBJECTS))
TESTOBJECTS = $(addprefix $(OBJ)/, $(OBJECTS) $(TESTOBJ))

# $(filter-out $(DRIVER),$(OBJECTS))

vpath %.c $(CFOLDERS)
vpath %.h $(HFOLDERS)


main: $(GCOBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@.out



runtests: $(TESTOBJECTS)
	$(CC) $^ $(LDFLAGS) -lcunit -o $@.out

$(OBJ)/%.o: %.c
	@mkdir -p $(DEPS)
	@mkdir -p $(OBJ)
	$(CC) $(CFLAGS) $^
	@mv $*.o $(OBJ)

-include $(addprefix $(DEPS)/,$(DFILES))

.PHONY: clean doc test

.DEFAULT: main






test:
	$(MAKE) -B runtests
	$(VALGRIND) ./runtests.out

doc:
	doxygen Resources/Doxyfile


clean:
	rm -rf obj/*.o doc *.o *.d deps/*.d deps/test/*.d main.out runtests.out
	-rm -d deps/
	-rm -d obj/

#############################
# Travis config
#############################
ping_travis:
	echo "Hello travis!"

RESET_REPO = rm -rf Sandskaddorna; git clone git@github.com:IOOPM-UU/Sandskaddorna.git;

MERGE_CMD = cd ~/Sandskaddorna; git checkout $(TRAVIS_BRANCH); git pull origin $(TRAVIS_BRANCH);
ifdef TRAVIS_PULL_REQUEST
	MERGE_CMD += git pull origin $(TRAVIS_PULL_REQUEST_BRANCH);
endif

TEST_CMD = cd ~/Sandskaddorna; make clean; make test;

test_servers:
	ssh axny2639@tussilago.it.uu.se "$(RESET_REPO) $(MERGE_CMD) $(TEST_CMD)"
	ssh axny2639@fries.it.uu.se "$(TEST_CMD)"
ssh axny2639@yxan.it.uu.se "$(TEST_CMD)"

