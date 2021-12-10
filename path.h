#ifndef PATH_H
#define PATH_H
#include <iostream>
#include "Request.h"
#include "Response.h"

namespace Insoel{
    template <typename T>
    class Path{
        public:
            std::string method;
            std::string path;
            Path();
            Path(string,string,void (*f)(Request*,Response*,T*));
            void (*callback)(Request*,Response*,T*);
    };

    template <typename T>
    Path<T>::Path(){
    }

    template <typename T>
    Path<T>::Path(string method,string path,void(*f)(Request *req,Response *res,T*)){
        this->method = method;
        this->path = path;
        this->callback = f;
    }
}

#endif // PATH_H
