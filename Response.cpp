#include "Response.h"
namespace Insoel {
    Response::Response(){
    }

    void Response::add_to_response(const char* key,const char* value){
        insertL(this->body->data,key,value);
        this->body->cant++;
    }

    void Response::create_response(const char* response_status){
        nodeL *aux = this->body->data;
        char response[200] = "{\"status\":\"";
        strncat(response,response_status,4);
        const char* aux_str = "\",\"";
        const char* aux_str2 = "\":\"";
        const char* aux_str3 = "\"}";
        const char* aux_str4 = "\",\"";
        strncat(response,aux_str,4);

        while (aux != nullptr) {
            cout << aux->key << " --- " << aux->dato << endl;
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

        cout<<response<<endl;
    }

    const char* Response::convert(float valor){
        static char buffer[50];
        sprintf (buffer, "%f", valor);
        return buffer;
    }
}
