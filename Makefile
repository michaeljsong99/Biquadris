XX=g++
CXXFLAGS=-std=c++14 -Wall -g -Werror=vla
testexec: main.cc abstractBoard.cc block.cc board.cc cell.cc 
	${CXX} ${CXXFLAGS} -o testexec main.cc abstractBoard.cc block.cc board.cc cell.cc

