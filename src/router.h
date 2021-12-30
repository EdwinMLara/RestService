#ifndef ROUTER_H
#define ROUTER_H
#include <iostream>
#include <vector>
#include "stdlib.h"
#include "path.h"
#include "jsonobject.h"

using namespace std;
namespace Insoel {
    template<typename T>
    class Router{
        public:
            size_t numPaths;
            vector<Path<T>> paths;
            Router();
            static void add_path(Router*, string, string, void (*f)(Request*,Response*,T*));
            string exe_router_callback(string strRequest, T *);
    };

    template<typename T>
    Router<T>::Router(){
        this->numPaths = 0;
    }

    template<typename T>
    void Router<T>::add_path(Router *ro,string method,string path,void (*f)(Request* req,Response *res,T* m)){

        Path<T> newPath;
        newPath.method = method;
        newPath.path = path;
        newPath.callback = f;
        ro->paths.push_back(newPath);
        ro->numPaths++;
        if(!ro->numPaths){
            throw "no se puedo agregar el endpoint";
        }
    }

    template<typename T>
    string Router<T>::exe_router_callback(string strRequest,T *m){
        string response;
        bool bandera = false;
        size_t nPaths = this->numPaths;
        Request *req = nullptr;
        try {
           req = new Request(strRequest.c_str());
        }  catch (const char * err) {
            cout << err << endl;
        }

        Response *res = new Response();

        for(size_t i=0;i<nPaths;i++){
            if(strcmp((this->paths[i].path).c_str(),req->path.c_str()) == 0){
                if(strcmp(req->method.c_str(),"GET") == 0){
                    (this->paths[i].callback)(req,res,m);
                }else{
                    try {
                        JsonObject *body = new JsonObject(req->strbody.c_str());
                        req->body = body;
                        (this->paths[i].callback)(req,res,m);
                    }  catch (const char * err) {
                        cout << err << endl;
                    }
                }
                bandera = true;
                break;
            }
        }
        if(!bandera)
            cout << "Punto final desconocido" << endl;
        try {
            response =  res->create_response();
        }  catch (const char * err) {
            cout << err << endl;
            response = "{\"response\":\"error\"}";
        }

        delete(req);
        delete(res);
        return response;
    }
}

#endif // ROUTER_H
