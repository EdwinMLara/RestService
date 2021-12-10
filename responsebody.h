#ifndef RESPONSEBODY_H
#define RESPONSEBODY_H

#ifndef MAX
#define MAX 50
#endif

#include <iostream>
#include "lista.h"
#include <string.h>

using namespace std;

struct ResponseBody{
    int cant;
    nodeL *data;
};

bool add_to_response(const char*,const char*);
string dato_to_str(nodeL *&,const char*);

#endif // RESPONSEBODY_H
