#ifndef INTERPRETCODE_H
#define INTERPRETCODE_H
#include <string>
#include <vector>

using namespace std;

class interpretCode
{
    public:
        interpretCode();
        interpretCode(string code);
        void setCode();
        void interpret();
    protected:

    private:
        void comma();
        void period();
        void plus();
        void minus();
        void forward();
        void back();
        int open(int k);
        int close(int k);
        int jump(int k);

        //variables
        int currentCell;
        string codeLine;
        vector<int> cellList;
        vector<int> loopList;
        vector<char> code;
        string validChars;
};

#endif // INTERPRETCODE_H
