#include "Request.h"

/**compare is a method from the class string and before we have
been used strcmp which is from c*/

/** its needed to make a doble check in how is getting the
data from the string request*/

namespace Insoel {
    Request::Request(){
    }

    Request::Request(string strRequest){
        this->method = this->get_str_method(strRequest);
        if(this->method.compare("error") == 0)
            throw "method error";

        this->path = this->get_str_path(strRequest);
        if(this->path.compare("error") == 0)
            throw "path error";
        if(strcmp(this->method.c_str(),"GET") == 0)
            return;

        this->strbody = this->get_str_body(strRequest);
        if(this->strbody.compare("error") == 0)
            throw "strbody error";
    }

    void Request::print_str_request(){
        std::cout << this->strbody << std::endl;
    }

    string Request::get_str_method(string strRequest){
        if(strstr(strRequest.c_str(),string("GET").c_str())){
            return "GET";
        };
        if(strstr(strRequest.c_str(),string("POST").c_str())){
            return "POST";
        };
        if(strstr(strRequest.c_str(),string("PUT").c_str())){
            return "GET";
        };
        if(strstr(strRequest.c_str(),string("DELETE").c_str())){
            return "GET";
        };
        return "error";
    }

    string Request::get_str_path(string strRequest){
        int i=0,count=0;
        int positions[2] = {0,0};

        while(strRequest[i] != '\0'){
            if(strRequest[i] == ' '){
                positions[count] = i;
                count++;
            }
            if(count ==  2){
                break;
            }
            i++;
        }
        size_t difPath = (positions[1]-positions[0])-1;
        if(difPath != 0){
            char *auxPath = static_cast<char*>(malloc(difPath*sizeof (char)));
            memcpy(auxPath,&strRequest[positions[0]+1],difPath);
            auxPath[difPath] = '\0';
            string path(auxPath,difPath);
            free(auxPath);
            return path;
        }else{
            return "error";
        }
    }

    string Request::get_str_body(string strRequest){
        int positions[2] = {0,0};
        int i=0;
        while(strRequest[i] != '\0'){
             switch(strRequest[i]){
               case '{':
                 positions[0] = i;
                 break;
               case '}':
                 positions[1] = i;
                 break;
            }
            i++;
        }

        size_t bodyLength = (positions[1] - positions[0]) + 1;
        if(bodyLength > 3){
            char *auxBody = static_cast<char*>(malloc(bodyLength*sizeof (char)));
            memcpy(auxBody,&strRequest[positions[0]],bodyLength);
            auxBody[bodyLength] = '\0';
            string body(auxBody,bodyLength);
            free(auxBody);
            return body;
        }
        return "error";
    }

    void Request::print_values(){
        nodeL *aux = this->body.data;
        while (aux != nullptr) {
            cout << aux->key << " --- " << aux->dato << endl;
            aux = aux->sig;
        }
    }

    string Request::getValByKey(const char* key){
        char * value  = getValueByKey(key,this->body.data);
        string val = string(value);
        free(value);
        return val;
    }


}
