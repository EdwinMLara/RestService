#ifndef RESPONSE_H
#define RESPONSE_H

#include <iostream>
#include <float.h>
#include <string.h>
#include "jsonobject.h"

using namespace std;

namespace Insoel {
    class Response{
        public:
            string strResponse;
            const char* response_state;
            jsonObject *body;
            Response();
            ~Response();
            void add_to_response(const char* ,const char*);
            string create_response();
    };
}
#endif // RESPONSE_H
