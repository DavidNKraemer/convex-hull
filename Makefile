# Makefile
# implicit linking

CXX = g++
CXXFLAGS = -std=c++1z -g -Wall -Wextra

TEST_FILE =

all:
	$(CXX) $(CXXFLAGS) main.cpp cvhull/GrahamScan.cpp -o cvxhull

test:
	./cvxhull $(TEST_FILE)


.PHONY: test

clean:
	rm -rf cvxhull

.PHONY: clean

cleanall:
	rm -rf cvxhull *.txt

.PHONY: cleanall
