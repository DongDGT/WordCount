#include<string>
#include"ControlMessage.h"

using namespace std;

int main(int argc, char* argv[]){
    
    ControlMessage controlor;

    for (int i = 1; i < argc; i++)
    {
        controlor.AddMessage(argv[i]);
    }
    controlor.Distribution();
    controlor.Control();
    system("pause");
    return 0;
}
//wanjibane
/*wxeuan*/
