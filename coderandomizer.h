#ifndef CODERANDOMIZER_H
#define CODERANDOMIZER_H
#include <string>
#include <vector>
#include <cstdlib> //contains rand
#include <ctime> //contains time

using namespace std;

class codeRandomizer
{
    public:
        codeRandomizer();
        void createCode();
        void addCode();
        void giveLine(string *code);
    protected:
    private:
        string randomCode;
        vector<int> list;
};

#endif // CODERANDOMIZER_H
