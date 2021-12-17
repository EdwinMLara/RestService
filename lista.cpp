#include "lista.h"
#include <string.h>

void insertL(nodeL*& node,const char* key,const char* dato){
    nodeL* tem = nullptr;
    if(node == nullptr){
        tem = static_cast<nodeL *>(malloc(sizeof (struct nodeL)));
        tem->key = key;
        tem->dato = dato;
        node = tem;
        node->sig = nullptr;
    }else{
      insertL(node->sig,key,dato);
    }
}

bool removeL(nodeL*& node,const char* dato){
    nodeL *aux = node;
    nodeL *prev = nullptr;
    while(aux->dato != dato){
        prev = aux;
        aux = aux->sig;
        if(aux == nullptr)
            return false;
    }
    if(prev != nullptr){
        prev->sig = aux->sig;
    }
    free(aux);
    return true;
}

bool updateL(nodeL*& node,const char* key,const char* newdato){
    bool resultUpdate = false;
    nodeL *aux = node;
    while(aux != nullptr){
        if(strcmp(aux->key,key)==0){
            aux->dato = newdato;
            resultUpdate = true;
            break;
        }
        aux = aux->sig;
    }

    return resultUpdate;
}

void showListL(nodeL*& node){
    nodeL *aux = node;
    if(node != nullptr){
        printf("key: %s , value: %s\n",aux->key,aux->dato);
        showListL(aux->sig);
    }
}

void freeList(nodeL *& node){
    nodeL *aux = node;
    nodeL *tem;
   while (aux != nullptr){
       tem = aux;
       aux = aux->sig;
       free(tem);
   }
}

char* getValueByKey(const char* key,nodeL *& data){
    static char * value = nullptr;
    nodeL *aux  = data;
    while(aux != nullptr){
        if(strcmp(key,aux->key) == 0){
            value = static_cast<char*>(malloc((strlen(aux->dato)+1)*sizeof(char)));
            memcpy(value, aux->dato, strlen(aux->dato)+1);
            break;
        }
        if(aux->sig == nullptr){
            value = static_cast<char*>(malloc(6*sizeof(char)));
            memcpy(value, "error",6);
            break;
        }
        aux = aux->sig;
    }

    return value;
}
