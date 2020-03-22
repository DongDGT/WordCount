#define WORDCOUNT
#ifdef WORDCOUNT
#include<fstream>
#include<iostream>
#include<string>

using namespace std;

class WordCount{

private:
    ifstream inStream;
    bool isSet=false;

    int charsCount=0;
    int wordsCount=0;
    int linesCount=0;
    int emptyLinesCount=0;
    int dataLinesCount=0;
    int notesLinesCount=0;

public:
    WordCount(string str);
    WordCount();
    ~WordCount();
    void Controller(char c);
    void ReSetFile(string str);

    int GetCharsCount();
    int GetWordsCount();
    int GetLinesCount();
    int GetEmptyLinesCount();
    int GetDataLinesCount();
    int GetNotesLinesCount();
    bool IsSet();

private:
    void InitData();
    void CharsCount();
    void WordsCount();
    void LinesCount();
    void OthersLinesCount();
};





#endif
