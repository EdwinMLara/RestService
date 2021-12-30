#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "requestbody.h"
#include "lista.h"

size_t numValues(const char *strbody){
    size_t count = 0,i=0;
    while(strbody[i] != '\0'){
        if(strbody[i] == ':'){
            count++;
        }
        i++;
    }
    return count;
}

void getBodyFromStr(const char*strbody,RequestBody *body){
    size_t i=0,countFlag=0,numDatos = numValues(strbody);
    size_t *flag;
    if(numDatos > 0){
        flag= static_cast<size_t*>(malloc((2*numDatos)*sizeof (size_t)));
        body->cant = numDatos;
        while(strbody[i] != '\0'){
            if(strbody[i] == '\''){
                flag[countFlag] = i;
                countFlag++;
            }

            if(countFlag == 4){
                size_t difKey = (flag[1]-flag[0])-1;
                size_t difValue = (flag[3]-flag[2])-1;

                if(difKey > 0 && difValue >0){
                    char *auxKey = static_cast<char*>(malloc(difKey*sizeof (char)));
                    char *auxValue = static_cast<char*>(malloc(difValue*sizeof (char)));
                    memcpy(auxKey,&strbody[flag[0]+1],difKey);
                    memcpy(auxValue,&strbody[flag[2]+1],difValue);
                    auxKey[difKey] = '\0';
                    auxValue[difValue] = '\0';

                    insertL(body->data,auxKey,auxValue);
                }
                countFlag = 0;
            }
            i++;
        }
        free(flag);
    }
}

void printRequestBody(RequestBody *body){
    nodeL *aux = body->data;
    while(aux != nullptr){
        cout <<  "key:"<< aux->key << "  value:" << aux->dato << endl;
        aux = aux->sig;
    }
}

bool keyExist(RequestBody *b,const char key[]){
    char *ptrKey = const_cast<char*>(key);
    for(int i=0;i<b->cant;i++){
        if(strcmp(b->data[i].key,ptrKey) == 0){
            return true;
        }
    }
    return false;
}

/*const char* getKeyValue(RequestBody *b,const char *key){
    char *ptrKey = const_cast<char*>(key);
    for(int i=0;i<b->cant;i++){
        if(strcmp(b->data[i].key,ptrKey) == 0){
            return b->data[i].value;
        }
    }
    return "error";
}*/
