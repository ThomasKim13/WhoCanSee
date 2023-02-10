//
// Created by Thomas Kim on 10/6/22.
//
#include <iostream>
#include "MonoStack.h"
#include<fstream>
using namespace std;
#ifndef PA3_SPEAKERVIEW_H
#define PA3_SPEAKERVIEW_H


class SpeakerView {
public:
    SpeakerView();//default constructor for SpeakerView
    ~SpeakerView();//deconstructor for SpeakerView
    void FileProcessor(string inputFile);//File will be processed then MonoStack will be used within the function

};


#endif //PA3_SPEAKERVIEW_H
