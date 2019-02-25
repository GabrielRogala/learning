CC = g++
C_FLAGS = -c -o
T_FLAGS = -lgtest_main -lgtest -pthread
LIBS = -lm # libs

OBJ_S =\
	#src/demo.o\

OBJ_H =\
	# inc/example.hpp

OBJ_T =\
	test/iostreamTest.o\
	test/preprocTest.o\
	test/definedTypesTest.o\
	test/classMemberPointerTest.o\

run: $(OBJ_S)
	$(CC) -std=c++14 -pthread -g $(OBJ_S) $(LIBS) -o output.out
	./output.out

test: $(OBJ_T)
	$(CC) $(OBJ_T) $(LIBS) -o test_output.out $(T_FLAGS)
	./test_output.out

%.o: %.cc $(OBJ_H)
	$(CC) $(C_FLAGS) $@ $< -I src

clean:
	rm -f *.o src/*.o test/*.o output.out test_output.out

.PHONY: run clean

