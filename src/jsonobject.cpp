#include "jsonobject.h"

namespace Insoel {
    JsonObject::JsonObject(){
        this->length = 0;
        this->strBody = "";
        this->data = nullptr;
    }

    JsonObject::JsonObject(const char * strbody){
        this->strBody = strbody;

        size_t count = 0,i=0,countFlag =0;
        size_t *flags;

        while(strbody[i] != '\0'){
            if(strbody[i] == ':')
                count++;
            if(strbody[i] == '\'')
                countFlag++;
            i++;
        }

        this->data = nullptr;

        if(count){
            if((countFlag % 2) != 0)
                throw "Parse Error";

            flags = static_cast<size_t*>(malloc((2*count)*sizeof (size_t)));
            this->length = count;
            i=0;
            countFlag = 0;
            while(strbody[i] != '\0'){

                if(strbody[i] == '\''){
                    flags[countFlag] = i;
                    countFlag++;
                }

                if(countFlag == 4){
                    size_t difKey = (flags[1]-flags[0])-1;
                    size_t difValue = (flags[3]-flags[2])-1;

                    if(difKey > 0 && difValue >0){
                        char *auxKey = static_cast<char*>(malloc(difKey*sizeof (char)));
                        char *auxValue = static_cast<char*>(malloc(difValue*sizeof (char)));
                        memcpy(auxKey,&strbody[flags[0]+1],difKey);
                        memcpy(auxValue,&strbody[flags[2]+1],difValue);
                        auxKey[difKey] = '\0';
                        auxValue[difValue] = '\0';

                        insertL(this->data,auxKey,auxValue);
                    }
                    countFlag = 0;
                }
                i++;
            }
            free(flags);
        }else
            throw "Parse Error";
    }

    size_t JsonObject::get_length(){
        return this->length;
    }

    bool JsonObject::key_exist(const char * key){
        char *ptrKey = const_cast<char*>(key);
        nodeL *aux = this->data;
        while(aux != nullptr){
            if(strcmp(this->data->key,ptrKey) == 0){
                return true;
            }
            aux = aux->sig;
        }
        return false;
    }

    string JsonObject::get_ValueByKey(const char* key){
        char * value  = getValueByKey(key,this->data);
        string val = string(value);
        free(value);
        return val;
    }

    void JsonObject::add_to_json(const char* key ,const char* value){
        insertL(this->data,key,value);
        this->length++;
    }

    const char* JsonObject::convert(float valor){
        static char buffer[50];
        sprintf (buffer, "%f", valor);
        return buffer;
    }

    const char* JsonObject::convert(bool valor){
        static char buffer[50];
        if(valor)
            sprintf (buffer,"%s","true");
        else
            sprintf (buffer,"%s","false");
        return buffer;
    }

    const char* JsonObject::convert(int valor){
        static char buffer[50];
        sprintf (buffer, "%d", valor);
        return buffer;
    }

    const char* JsonObject::convert(size_t valor){
        static char buffer[50];
        sprintf (buffer, "%zu", valor);
        return buffer;
    }

    char* JsonObject::json_to_str(){
        static char response[200] = "{\"";
        if(strcmp(response,"{\"") != 0)
            memcpy(response,"{\"",3);

        nodeL *aux = this->data;
        if(aux == nullptr)
            throw "Parse Error";

        const char* aux_str2 = "\":\"";
        const char* aux_str3 = "\"}";
        const char* aux_str4 = "\",\"";
        while (aux != nullptr) {
            strncat(response,aux->key,(strlen(aux->key)+1));
            strncat(response,aux_str2,3);
            strncat(response,aux->dato,(strlen(aux->dato)+1));
            if(aux->sig == nullptr){
                strncat(response,aux_str3,3);
            }else{
                strncat(response,aux_str4,3);
            }
            aux = aux->sig;
        }
        return response;
    }

    void JsonObject::print(){
        showListL(this->data);
    }

    JsonObject::~JsonObject(){
        freeList(this->data);
    }
}

