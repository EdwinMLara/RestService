#ifndef RESPONSE_H
#define RESPONSE_H

#include <iostream>
#include "responsebody.h"
#include <float.h>
#include <string.h>

using namespace std;

namespace Insoel {
    class Response{
        public:
            string strResponse;
            const char* response_state;
            ResponseBody *body;
            Response();
            const char* convert(float);
            void add_to_response(const char* ,const char*);
            void create_response(const char* response_status);
    };
}
#endif // RESPONSE_H
