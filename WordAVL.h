
/**
* Title: Trees
* Author: Hassam Abdullah
* ID: 21701610
* Assignment: 4
* Description: WordAVL.h the header file
*/


#include <iostream>
#include <fstream>

using namespace std;

#ifndef WORDAVL_H
#define WORDAVL_H

//
//class TreeNode {
//
//public:
//    TreeNode();
//    TreeNode(string newWord);
//
//    string item;
//    int count;
//    TreeNode *leftChildPtr, *rightChildPtr;
//
//    friend class freqAVL;
//};

class WordAVL {

    struct TreeNode{
                    string word;
                    int counter;
                    TreeNode *leftPtr, *rightPtr;


        TreeNode(){

        word = "";
        leftPtr = NULL;
        rightPtr = NULL;
        counter = 0;
        }

        TreeNode(string word1){

        word = word1;
        leftPtr = NULL;
        rightPtr = NULL;
        counter = 1;

        }

    };

public:
    WordAVL();
    ~WordAVL();

    void addWord(TreeNode* &node, string newWord);
    void generateTree(string fileName);
    void printHeight();
    void printTotalWordCount();
    void printWordFrequencies();
    void printMostFrequent();
    void printLeastFrequent();
    void printStandartDeviation();





private:
    void destructor( TreeNode* &treePtr);
    int compareHeight( TreeNode *node);
    int getHeight( TreeNode *node);
    void lRotation( TreeNode* &node);
    void rRotation( TreeNode* &node);
    void balanceTree( TreeNode* &node);

    void getWordCount( TreeNode *node, long long &counter);
    void getMostFrequent( TreeNode* node, long long &counter, string &word);
    void getLeastFrequent( TreeNode* node,long long &counter, string &word);
    void inorderPrint( TreeNode* node, ofstream &file);
    void getTotalFreq(TreeNode* node, double &total);
    void squareDifference(TreeNode* node, double &squareDif, double avg);

    TreeNode *root;
};


#endif
