#include"WordCount.h"

using namespace std;
WordCount::WordCount(string str)
{
    this->inStream.open(str.data(),ios::in);
    if(inStream)
        this->isSet=true;
    else
        this->isSet=false;
}

WordCount::WordCount()
{
    isSet = false;
}

WordCount::~WordCount()
{
    this->inStream.close();
}



void WordCount::ReSetFile(string str)
{
    this->inStream.close();
    this->isSet=false;
    this->inStream.open(str.data(),ios::in);
    if(inStream)
        this->isSet=true;
    else
        this->isSet=false;
    this->InitData();
}

void WordCount::InitData()
{
    this->charsCount=0;
    this->wordsCount=0;
    this->linesCount=0;
    this->emptyLinesCount=0;
    this->dataLinesCount=0;
    this->notesLinesCount=0;
}



int WordCount::GetCharsCount()
{
    return this->charsCount;
}

int WordCount::GetWordsCount()
{
    return this->wordsCount;
}

int WordCount::GetLinesCount()
{
    return this->linesCount;
}

int WordCount::GetEmptyLinesCount()
{
    return this->emptyLinesCount;
}

int WordCount::GetDataLinesCount()
{
    return this->dataLinesCount;
}

int WordCount::GetNotesLinesCount()
{
    return this->notesLinesCount;
}

bool WordCount::IsSet()
{
    return isSet;
}

/**/

void WordCount::CharsCount()
{
    istreambuf_iterator<char>bInterator(this->inStream);
    istreambuf_iterator<char>eof;
    while(bInterator!=eof){
        char nowchar;
        nowchar=*bInterator;
        if(nowchar==' '||nowchar=='\n');
        else this->charsCount++;
        bInterator++;
     }
    inStream.seekg(ios::beg);
}

void WordCount::WordsCount()
{
    istreambuf_iterator<char>bInterator(this->inStream);
    istreambuf_iterator<char>eof;
    bool isWord=false;
    while(bInterator!=eof){
        char nowchar;
        nowchar=*bInterator;
        if((nowchar>='A'&&nowchar<='Z')||(nowchar>='a'&&nowchar<='z'))
            isWord=true;
        else if(isWord==true)
        {
            isWord=false;
            wordsCount++;
        }
        bInterator++;
     }
     if(isWord==true)
     {
         isWord=false;
         wordsCount++;
     }
     inStream.seekg(ios::beg);
}

void WordCount::LinesCount()
{
    istreambuf_iterator<char>bInterator(this->inStream);
    istreambuf_iterator<char>eof;
    while(bInterator!=eof){
        char nowchar;
        nowchar=*bInterator;
        if(nowchar=='\n')
            linesCount++;
        bInterator++;
     }
    linesCount++;
    inStream.seekg(ios::beg);
}

void WordCount::OthersLinesCount()
{
    istreambuf_iterator<char>bInterator(this->inStream);
    istreambuf_iterator<char>eof;
    bool isNote=false;
    bool isNoting=false;
    bool isNoteReady=false;
    bool isNoteEndReady=false;
    bool isDataLine=false;
    while(bInterator!=eof){
        char nowchar;
        nowchar=*bInterator;
        if(((nowchar>='A'&&nowchar<='Z')||(nowchar>='a'&&nowchar<='z'))&&!isNote)
            isDataLine=true;
        else if(nowchar=='/')
        {
            if(!isNoteReady)
                isNoteReady=true;
            else if(isNoteEndReady)
            {
                isNoting=false;
                isNoteEndReady=false;
            }
            else if(!isDataLine)
                isNote=true;
        }
        else if(nowchar=='*')
        {
            if(isNoteReady)
            {
                isNoting=true;
                isNote=true;
            }
            else if(isNoting)
                isNoteEndReady=true;
        }
        else if(nowchar=='\n')
        {
            if(isDataLine)
            {
                this->dataLinesCount++;
                isDataLine=false;
            }
            else if(isNote)
            {
                this->notesLinesCount++;
                if(!isNoting)
                isNote=false;
            }
            else
            {
                this->emptyLinesCount++;
            }
        }
        bInterator++;
     }
    inStream.seekg(ios::beg);
}


void WordCount::Controller(char c)
{
    switch(c)
    {
        case 'c':CharsCount();break;
        case 'w':WordsCount();break;
        case 'l':LinesCount();break;
        case 'a':OthersLinesCount();break;
        default :;
    }
}
