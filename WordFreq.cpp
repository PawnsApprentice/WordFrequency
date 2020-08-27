/**
* Title: Trees
* Author: Hassam Abdullah
* ID: 21701610
* Assignment: 4
* Description: WordFreq.cpp that uses the AVL tree class
*/


#include <iostream>
#include "WordAVL.h"


using namespace std;

int main( int argc, char* argv[]) {



    WordAVL avl;

    avl.generateTree(argv[1]);

    avl.printWordFrequencies();

    avl.printTotalWordCount();

    avl.printHeight();

    avl.printMostFrequent();

    avl.printLeastFrequent();

    avl.printStandartDeviation();

}
