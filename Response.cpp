#include "Response.h"
namespace Insoel {
    Response::Response(){
        this->body = new jsonObject();
        this->response_state = "200";
    }

    void Response::add_to_response(const char* key,const char* value){
        if(this->body->key_exist(key))
            throw "key exist";
        this->body->add_to_json(key,value);
    }

    string Response::create_response(){
        if(this->body->data == nullptr){
            throw "Body data is empty";
        }
        try {
            char *response = this->body->json_to_str();
            string strResponse = string(response);

            return strResponse;
        }  catch (const char * err) {
            cout << err << endl;
            return string("Error");
        }
    }

    Response::~Response(){
        delete(this->body);
    }

}
