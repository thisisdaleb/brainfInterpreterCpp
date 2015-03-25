#include "interpretcode.h"
#include "coderandomizer.h"
#include<iostream>
#include <string>
#include <vector>

using namespace std;

interpretCode::interpretCode()
{
    //default constructor is for automatic code creation, instead of typing the code in.
    validChars = " +-[]<>,+.";
    codeRandomizer randomCode;
    randomCode.createCode();
    randomCode.giveLine(&codeLine);
    currentCell = 0;
    cellList.resize(1024, 0);
    loopList.resize(1, 0);
    cout << endl << codeLine << endl <<endl;
}

interpretCode::interpretCode(string codes)
{
    validChars = " -[]<>,+.";
    codeLine=codes;
    currentCell = 0;
    cellList.resize(1024, 0);
    loopList.resize(1, 0);
}

void interpretCode::setCode()
{
    cout << "-----code input-----" << endl;
    for(unsigned int k=0;k<codeLine.length();k++)
    {
        if(validChars.find(codeLine.at(k)))
        {
            code.push_back(codeLine.at(k));
        }
    }
    cout << endl;
}

void interpretCode::interpret()
{
    for(unsigned int k=0;k<code.size();k++)
    {
        switch(code.at(k))
        {
            case ',':comma(); break;
            case '.':period(); break;
            case '+':plus(); break;
            case '-':minus(); break;
            case '>':forward(); break;
            case '<':back(); break;
            case '[':k=open(k); break;
            case ']':k=close(k); break;
            default: break;
        }
    }
}

void interpretCode::comma()
{
    cin >> cellList.at(currentCell);
}

void interpretCode::period()
{
    cout << static_cast<char>(cellList.at(currentCell));
}

void interpretCode::plus()
{
    if(cellList.at(currentCell)<255)
        cellList.at(currentCell)++;
    else
        cellList.at(currentCell)=0;
}

void interpretCode::minus()
{
    if(cellList.at(currentCell)>0)
        cellList.at(currentCell)--;
    else
        cellList.at(currentCell)=255;
}

void interpretCode::forward()
{
    if(currentCell<1023)
        currentCell++;
    else
        currentCell=0;
}

void interpretCode::back()
{
    if(currentCell>0)
        currentCell--;
    else
        currentCell=1023;
}

int interpretCode::open(int k)
{
    if(cellList.at(currentCell)!=0)
        loopList.push_back(k);
    else
        return jump(k);
    return k;
}

int interpretCode::close(int k)
{
    if(cellList.at(currentCell)==0){
        loopList.pop_back();
        return k;
    }
    else
        return loopList.back();
}

int interpretCode::jump(int k)
{
    int newK = k;//jump to point
    for(unsigned int z=k;z<code.size();z++)
    {
        if(code.at(k)==']')
        {
            cout << "jump";
            newK=z;
            break;
        }
    }
    return newK;
}

