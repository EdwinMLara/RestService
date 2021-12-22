#ifndef REQUEST_H
#define REQUEST_H
#include <iostream>
#include <string.h>
#include "jsonobject.h"
#include "lista.h"

using namespace std;

namespace Insoel{
    class Request{
        private:
            string get_str_method(const char *);
            string get_str_path(const char *);
            string get_str_body(const char *);
        public:
            string method;
            string path;
            string strbody;
            jsonObject *body;
            Request();
            Request(const char *);
            ~Request();
            void print_str_request();
            string getValfromResponse(const char*);
            void print_values();
    };
}

#endif // REQUEST_H
