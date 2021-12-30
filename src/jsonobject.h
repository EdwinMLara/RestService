#ifndef JSONOBJECT_H
#define JSONOBJECT_H
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

using namespace std;

namespace Insoel {
    class JsonObject{
        private:
            const char* strBody;
            size_t length;
        public:
            nodeL *data;
            JsonObject();
            JsonObject(const char *);
            ~JsonObject();
            size_t get_length();
            bool key_exist(const char *);
            string get_ValueByKey(const char*);
            void add_to_json(const char* ,const char*);
            char* json_to_str();
            void print();
            static const char* convert(float);
            static const char* convert(bool);
            static const char* convert(int);
            static const char* convert(size_t);
    };
}

#endif // JSONOBJECT_H


/**cout << "=========== Parseando cadena ==================================="<<endl;
jsonObject *test = new jsonObject("{'conf':'tempo','status':'on','time':'min','ciclo':'1451'}");
test->print();
cout << endl;

cout << "=========== Obteniendo tamano =================================="<<endl;
cout << test->get_length() << endl;
cout << endl;

cout << "=========== Probando si la key existe =========================="<<endl;
cout << test->key_exist("conf") << "  "<<test->key_exist("cicle") << endl;
cout << endl;

cout << "=========== Obteniendo valor por medio de la key ================"<<endl;
cout << test->get_ValueByKey("conf") << " ----- " << test->get_ValueByKey("ciclo") << endl;
cout << endl;

cout << "=========== Agregando al Json ==================================="<<endl;
test->add_to_json("status server","200");
test->print();
cout << endl;

cout << "=========== Parseando Objecto ==================================="<<endl;
cout << test->json_to_str() << endl;
cout << endl;
cout << "Pruba Finalizada" << endl;

delete(test);*/
