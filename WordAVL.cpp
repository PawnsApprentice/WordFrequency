
/**
* Title: Trees
* Author: Hassam Abdullah
* ID: 21701610
* Assignment: 4
* Description: WordAVL.cpp that constructs an AVL tree to store words
*/


#include "WordAVL.h"
#include "math.h"
#include <string.h>
#include <climits>
#include <sstream>
#include <string>
#include<bits/stdc++.h>

/**
 //constructor
*/
WordAVL::WordAVL()
{
    root = NULL;
}

/**
 //destructor
*/
WordAVL::~WordAVL()
{
    destructor(root);
}

/**
 //a method that checks if the left subtree is bigger than the right subtree and returns their difference
*/
int WordAVL::compareHeight( TreeNode *treePtr)
{
    return getHeight(treePtr->rightPtr) - getHeight(treePtr->leftPtr);
}

/**
 //returns an int that is the height of the tree
*/
int WordAVL::getHeight( TreeNode *treePtr)
{
    int height = 0;

    if ( treePtr != NULL)
    {
        height = 1 + max( getHeight(treePtr -> leftPtr), getHeight(treePtr -> rightPtr));
    }

    return height;
}

/**
 //a method that rotates the node in an anticlockwise direction
*/
void WordAVL::lRotation( TreeNode* &treePtr)
{
    TreeNode *temp = treePtr->rightPtr;
    treePtr->rightPtr = temp->leftPtr;
    temp->leftPtr = treePtr;

    treePtr = temp;
    temp = NULL;
    delete temp;
}

/**
 //a method that rotates the node in a clockwise direction
*/
void WordAVL::rRotation( TreeNode* &treePtr)
{
    TreeNode *temp = treePtr->leftPtr;
    treePtr->leftPtr = temp->rightPtr;
    temp->rightPtr = treePtr;

    treePtr = temp;
    temp = NULL;
    delete temp;
}

/**
 //a method that checks the tree if the left subtree or right subtree tree needs balancing and then balances the tree
*/
void WordAVL::balanceTree (TreeNode* &treePtr)
{
        if (compareHeight(treePtr) < -1) {

            if(compareHeight(treePtr->leftPtr) < 0 || compareHeight(treePtr-> leftPtr) == 0)
            {
                rRotation(treePtr);
            }

            else
            {
                lRotation(treePtr->leftPtr);
                rRotation(treePtr);
            }
    }

     else if (compareHeight(treePtr) > 1)
    {

        if(compareHeight(treePtr->rightPtr) > 0 || compareHeight(treePtr-> rightPtr) == 0)
            {
                lRotation(treePtr);
            }

            else
            {
                rRotation(treePtr->rightPtr);
                lRotation(treePtr);
            }
    }

}

/**
 // a method that returns the total word count by transversing the tree in inorder fashion
*/
void WordAVL::getWordCount( TreeNode* treePtr, long long &counter)
{
    if(treePtr == NULL)
    {
        return;
    }
   else
    {
        getWordCount(treePtr->leftPtr, counter);
        counter++;
        getWordCount(treePtr->rightPtr, counter);
    }
}

/**
 // a method that returns the most frequent word and its counter via reference
*/
void WordAVL::getMostFrequent( TreeNode* treePtr, long long &counter, string &word)
{
    if(treePtr == NULL)
    {
        return;
    }

     else
    {
        getMostFrequent(treePtr->leftPtr, counter, word);

        if (treePtr->counter > counter)
        {
            word = treePtr -> word;
            counter = treePtr->counter;
        }

        getMostFrequent(treePtr->rightPtr, counter, word);
    }
}


/**
 // a method that returns the least frequent word and its counter via reference
*/
void WordAVL::getLeastFrequent( TreeNode* treePtr , long long &counter, string &word)
{
    if(treePtr == NULL)
    {
       return;
    }

      else
    {
        getLeastFrequent(treePtr->leftPtr,counter, word);

        if (treePtr->counter < counter)
        {
            counter = treePtr->counter;
            word = treePtr -> word;
        }

        getLeastFrequent(treePtr->rightPtr, counter, word);
    }
}

/**
 // a method that adds a word into the AVL tree
*/
void WordAVL::addWord(TreeNode* &treePtr, string item)
{
    if( treePtr == NULL)
    {
        treePtr = new TreeNode(item);
    }

    else
    {
        if ( item.compare(treePtr->word) > 0)
        {
            addWord(treePtr->rightPtr, item);
            balanceTree(treePtr);
        }

        else if( item.compare(treePtr->word) < 0)
        {
            addWord(treePtr->leftPtr, item);
            balanceTree(treePtr);

        }

        else
        {
            treePtr->counter++;
        }

    }
}

/**
 // a method that prints out the total frequency by adding the counters of each node in inorder fashion
*/
void WordAVL::getTotalFreq(TreeNode* treePtr, double &total)
{
    if( treePtr == NULL)
    {
       return;
    }

    else
    {
        getTotalFreq(treePtr->leftPtr, total);
        total = total + treePtr->counter;
        getTotalFreq(treePtr->rightPtr, total);
    }
}

/**
 // a method that prints out the words in alphabetical order by traversing in inorder fashion
*/
void WordAVL::inorderPrint( TreeNode* treePtr, ofstream &file)
{

    if(treePtr == NULL)
    {
        return;
    }

    else
    {
        inorderPrint(treePtr->leftPtr, file);
        file << (treePtr->word) << " " << (treePtr->counter) << "\n";
        inorderPrint(treePtr->rightPtr, file);
    }

}

/**
 // a method that calculates the square difference of each node in in-order fashion
*/
void WordAVL::squareDifference(TreeNode* treePtr, double &squareDif, double avg)
{
    if( treePtr == NULL)
    {
        return;
    }
    else
    {
        squareDifference(treePtr->leftPtr, avg, squareDif);
        squareDif = squareDif + (avg - treePtr->counter) * (avg - treePtr->counter);
        squareDifference(treePtr->rightPtr, avg, squareDif);
    }
}



/**
 // a method that reads words from the txt file and seperates them by either a space or a punctuation i.e non-alpha
*/
void WordAVL::generateTree(string fileName)
{
    ifstream file;
    file.open(fileName.c_str());
    string str;
    string words;
//
//    while (file >> str)
//    {
//        getline(file, str);
//         string const delims{ " \'\".,:;/!?~)(@#%^&*+$-"};
//
//        size_t beg = 0, pos = 0;
//        string su = str.substr(beg, pos - beg);
//        pos = str.find_first_of(delims, beg + 1);
//        transform(su.begin(), su.end(), su.begin(), ::tolower);
//
//    }






    while (file >> words)
    {



        for (int i = 0; i < words.length(); i++)
        {
            if (!isalpha(words[i]))
            {
                words[i] = ' ';
            }

            else
            {
                words[i] = tolower(words[i]);
            }
        }


        char* wordarr;

        char* charArr = new char[words.length() + 1];
        strcpy(charArr,words.c_str());

        wordarr = strtok(charArr," ");

        for (; wordarr= wordarr; wordarr != NULL)
        {
            addWord(root, wordarr);
            wordarr = strtok (NULL, " ");
        }

    }

}

/**
 // writes the height of the tree into the statistics.txt
*/
void WordAVL::printHeight()
{
    ofstream file;
    file.open ("statistics.txt",file.app);
    file << "Tree Height: " << getHeight(root) << "\n";
    file.close();
}

/**
 // writes the total word count into the statistics.txt
*/
void WordAVL::printTotalWordCount()
{
    ofstream file;
    long long counter = 0;
    getWordCount( root, counter);


    file.open ("statistics.txt");
    file << "Total Word Count: " << counter << "\n";
    file.close();
}

/**
 // writes the words in alphabetic order and their frequencies into the wordfreqs.txt
*/
void WordAVL::printWordFrequencies()
{
    ofstream file;
    file.open ("wordfreqs.txt");
    inorderPrint(root,file);
    file.close();
}


/**
 // writes the most frequent word and its counter into the statistics.txt
*/
void WordAVL::printMostFrequent()
{
    long long counter = 0;
    string word = "";
    getMostFrequent( root, counter, word);

    ofstream file;
    file.open ("statistics.txt",file.app);
    file << "Most Frequent: " << word << " " << counter << "\n";
    file.close();
}

/**
 // writes the least frequent word and its counter into the statistics.txt
*/
void WordAVL::printLeastFrequent()
{
    long long counter;
    string word = "";
    getLeastFrequent( root,counter, word);

    ofstream file;
    file.open ("statistics.txt",file.app);
    file << "Least Frequent: " << word << " " << counter << "\n";
    file.close();
}

/**
 // helper method for the destructor
*/
void WordAVL::destructor( TreeNode* &treePtr)
{

    if ( treePtr != NULL)
    {
        destructor(treePtr -> leftPtr);
        destructor(treePtr -> rightPtr);

        delete treePtr;
        treePtr = NULL;
    }
}


/**
 // writes the standard deviation into the statistics .txt
*/
void WordAVL::printStandartDeviation()
{
    double total = 0;
    getTotalFreq(root, total);

    long long counter = 0;
    getWordCount( root, counter);



    double average = total/counter;
    double squareDiff = 0;
    squareDifference(root, average, squareDiff);

    ofstream file;
    file.open ("statistics.txt",file.app);
    file << "Standard Deviation: " << (sqrt(squareDiff/counter)) <<"\n";
    file.close();
}
