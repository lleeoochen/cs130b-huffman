cpp=g++ -g
db=gdb

test: hello
	./$<

debug: hello
	$(db) $<

hello: main.o hello.o
	$(cpp) -o $@ $^

hello.o main.o:: hello.h

%.o:: %.cpp
	$(cpp) -c -o $@ $<

tidy:
	rm -f *~

clean: tidy
	rm -f hello *.o
	
.PHONY: test debug tidy clean
