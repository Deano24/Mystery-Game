#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include <sstream>

using namespace std;

typedef struct{
    stringstream person_name_first;
    stringstream person_name_last;
    stringstream information_clues;
    stringstream location;
}clues;

extern clues list_clues [30];



#endif // DATA_H_INCLUDED
