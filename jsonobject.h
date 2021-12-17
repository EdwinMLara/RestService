#ifndef JSONOBJECT_H
#define JSONOBJECT_H
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

using namespace std;

namespace Insoel {
    class jsonObject{
        private:
            const char* strBody;
            size_t length;
            nodeL *data;
            const char* convert(float valor);

        public:
            jsonObject(const char *);
            size_t get_length();
            bool key_exist(const char *);
            string get_ValueByKey(const char*);
            void add_to_json(const char* ,const char*);
            const char* json_to_str();
            void print();
    };
}

#endif // JSONOBJECT_H
