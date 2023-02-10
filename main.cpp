//
// Created by Thomas Kim on 10/5/22.
//
#include "MonoStack.h"
#include "SpeakerView.h"
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char* argv[]){
    //creating an instance of SpeakerView
    SpeakerView sp;
    //gets an inputfile from runtime
    sp.FileProcessor(argv[1]);
    return 0;
}