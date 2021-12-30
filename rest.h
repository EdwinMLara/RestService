#ifndef INSOEL_REST_H
#define INSOEL_REST_H

/**los template no pueden ser separados en .h and cpp*/

#include <iostream>
#include "./src/router.h"
#include "./src/Request.h"
#include "./src/Response.h"
#include "./src/jsonobject.h"

namespace Insoel {
    #define HTTP_GET "GET"
    #define HTTP_POST "POST"
    #define HTTP_DELETE "DELETE"
    #define HTTP_UPDATE "UPDATE"

    template <typename T>
    class Rest{
        private:
            Router<T> *ro;
            T *m;
        public:
            std::string strRequest;
            Rest();
            Rest(T*);
            bool add_endpoint(string ,string ,void (*f)(Request*,Response*,T*));
            string run_server(string);
    };

    template <typename T>
    Rest<T>::Rest(T *m){
        this->ro = new Router<T>();
        this->m = m;
    }

    template <typename T>
    bool Rest<T>::add_endpoint(string method, string path,void (*f)(Request*,Response*,T* m)){
        try {
            Router<T>::add_path(this->ro,method,path,f);
            return true;
        }  catch (const char * error) {
            cout << error << endl;
            return false;
        }
    }

    template <typename T>
    string Rest<T>::run_server(string strRequest){
        return this->ro->exe_router_callback(strRequest,this->m);
    }
} // namespace Insoel

#endif // INSOEL_REST_H
