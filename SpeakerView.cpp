//
// Created by Thomas Kim on 10/6/22.
//

#include "SpeakerView.h"
#include <iostream>
#include <stdlib.h>
#include<fstream>
#include <sstream>
using namespace std;
//Default constructor
SpeakerView::SpeakerView() {}
//deconstructor
SpeakerView::~SpeakerView() {}

//File will be processed then MonoStack will be called to determine whether or not a person can see
void SpeakerView::FileProcessor(string inputFile) {
    string line;
    ifstream inFile;
    inFile.open(inputFile);
    int cols = 0;
    int rows = 0;
    double x;
    //these two while loops get the number of rows and columns of the file
    while(getline(inFile,line)){
        istringstream  iss(line);
        string result;
        while(getline(iss, result , ' ')){
            ++cols;
        }
        ++rows;
    }
    //Because we did getline with inFile I then have to reset the inFile to the beginning
    inFile.clear();
    inFile.seekg(0,ios::beg);
    //to get the actual amount of columns I had to get the cols var and divide it by the rows var
    int fCol = cols / rows;
    //creating a double array to insert the input file's content to iterate through later
    double arr[rows][fCol];
    for(int i = 0; i < rows; i++){
        getline(inFile,line);
        stringstream ss(line);
        for(int j =0; j < fCol; j++){
            ss >> x;
            arr[i][j] = x;
        }
    }
    //creating an array that holds MonoStack instances to be called later on
    //for loop will go through the array that is holding the contents of the input file then use push to push it to the stack
    //after a column is done that column is stored into stackArr to reveal who can see
    MonoStack<double>** stackArr = new MonoStack<double>* [fCol] ;
    for(int i = 0; i < fCol; i++){
        MonoStack<double>* stacks = new MonoStack<double>(rows,'d');
        stackArr[i] = stacks;
        for(int j = rows - 1; j >= 0; j--){
            stacks->push(arr[j][i]);
        }
    }
    //for loop now interates through the arrays that hold the stacks
    //reveals the column and how many people can see as well as their heights
    for(int i = 0; i < fCol; i++){
        int k = stackArr[i]->size();
        cout << "COLUMN: " << i << " contains " << k << " that are able to see. The heights of the people are ";
        for(int j = 0; j < k; j++){
            cout << stackArr[i]->pop() << " ";
        }
        cout << endl;
    }




















    inFile.close();
}


