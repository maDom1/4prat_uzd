CC = gcc

TARGET = list
TEST_TARGET = test_list

SRCS = main.c list.c filename.c
OBJS = main.o list.o filename.o

TEST_SRCS = test_list.c list.c
TEST_OBJS = test_list.o list.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

test: $(TEST_OBJS)
	$(CC) -o $(TEST_TARGET) $(TEST_OBJS)

main.o: main.c list.h filename.h
	$(CC) -c main.c

list.o: list.c list.h
	$(CC) -c list.c

filename.o: filename.c filename.h
	$(CC) -c filename.c

test_list.o: test_list.c list.h
	$(CC) -c test_list.c

clean:
	rm -f $(TARGET) $(TEST_TARGET) *.o
