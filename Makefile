
avlfreq: WordFreq.o WordAVL.o
	g++ WordFreq.o WordAVL.o -o avlfreq

WordFreq.o: WordFreq.cpp
	g++ -c WordFreq.cpp

WordAVL.o: WordAVL.cpp WordAVL.h
	g++ -c WordAVL.cpp

clean:
	rm *.o avlfreq
