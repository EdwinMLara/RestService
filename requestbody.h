#ifndef REQUESTBODY_H
#define REQUESTBODY_H

#include <iostream>
using namespace std;
#include "lista.h"

struct RequestBody{
    int cant;
    nodeL *data;
};

size_t numValues(const char *strbody);
void getBodyFromStr(const char*,RequestBody *);
void printRequestBody(RequestBody*);
bool keyExist(RequestBody *,const char key[]);
const char* getKeyValue(RequestBody *,const char*);

#endif // REQUESTBODY_H
