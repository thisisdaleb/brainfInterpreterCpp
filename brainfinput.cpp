#include "brainfinput.h"
#include<iostream>
#include <string>
#include "interpretcode.h"
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
    cout << "------brainf-Interpreter------" << endl << "please input some brainf*** code:\n";
    string inputCode = "";
    cin >> inputCode;
    if(inputCode=="auto")
    {
        interpretCode interpreter;//type auto to see a randomizer create code
        interpreter.setCode(); //puts the code into the vector
        interpreter.interpret(); //interprets the code
        cout << endl;
    }
    else
    {
        interpretCode interpreter(inputCode); // sets variables and prepares object
        interpreter.setCode(); //puts the code into the vector
        interpreter.interpret(); //interprets the code
        cout << endl;
    }
    return 0;
}
