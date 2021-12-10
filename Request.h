#ifndef REQUEST_H
#define REQUEST_H
#include <iostream>
#include <string.h>
#include "requestbody.h"
#include "lista.h"

using namespace std;

namespace Insoel{
    class Request{
        private:
            string get_str_method(string strRequest);
            string get_str_path(string strRequest);
            string get_str_body(string strRequest);
        public:
            string method;
            string path;
            string strbody;
            RequestBody body;
            Request();
            void print_str_request();
            string getValByKey(const char*);
            void print_values();
            Request(string strRequest);
    };
}

#endif // REQUEST_H
