#include<string>
#include"ControlMessage.h"

using namespace std;

int main(int argc, char* argv[]){
    
    ControlMessage controlor;

    for (int i = 1; i < argc; i++)
    {
        controlor.AddMessage(argv[i]);
    } /*123*/
    int test/*½ö²âÊÔÓÃ*/;
    controlor.Distribution();
    controlor.Control();
    return 0;
}

