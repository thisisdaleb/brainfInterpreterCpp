#include "coderandomizer.h"
#include <iostream>
#include <vector>

char charList[8] = {',', '.', '+', '-', '>', '<'};

codeRandomizer::codeRandomizer()
{
    randomCode="";
    list.resize(12,0);
}

void codeRandomizer::giveLine(string *code)
{
    *code = randomCode; //avoiding sending really long string, saving a little bit of memory.
}

void codeRandomizer::createCode()
{
    addCode();
    cout << "aaa" << endl;
}


void codeRandomizer::addCode()
{
    srand(time(0));
    for(int z=0; z<8;z++)
    {
        list.at(z)=((rand()%100)+(300*(z+1)));//adds loops
    }

    for(int k=0;k<5000;k++)
    {
        char newChar = charList[rand()%6];
        if(k==list.at(0)){
            if(list.size()>4)
                newChar='[';
            else
                newChar=']';
            list.erase(list.begin());
        }
        randomCode=randomCode+newChar;
        //cout << randomCode << "  " << randomCode.size() << endl;
    }
}
