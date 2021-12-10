#ifndef ROUTER_H
#define ROUTER_H
#include <iostream>
#include <vector>
#include "stdlib.h"
#include "path.h"

using namespace std;
namespace Insoel {
    template<typename T>
    class Router{
        public:
            size_t numPaths;
            vector<Path<T>> paths;
            Router();
            static void add_path(Router*, string, string, void (*f)(Request*,Response*,T*));
            void exe_router_callback(string strRequest, T *);
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
    void Router<T>::exe_router_callback(string strRequest,T *m){
        bool bandera = false;
        size_t nPaths = this->numPaths;
        Request *req = nullptr;
        RequestBody reqbody;
        try {
            req = new Request(strRequest);
            reqbody.cant = 0;
            reqbody.data = nullptr;
        }  catch (const char * error) {
            cout << error << endl;
        }

        Response *res = new Response();
        ResponseBody resbody;
        resbody.cant = 0;
        resbody.data = nullptr;
        res->body = &resbody;


        for(size_t i=0;i<nPaths;i++){
            if(strcmp((this->paths[i].path).c_str(),req->path.c_str()) == 0){
                if(strcmp(req->method.c_str(),"GET") == 0){
                    (this->paths[i].callback)(req,res,m);
                }else{
                    getBodyFromStr(req->strbody.c_str(),&reqbody);
                    req->body = reqbody;
                    (this->paths[i].callback)(req,res,m);
                }
                bandera = true;
                break;
            }
        }

        if(!bandera){
            cout << "Punto final desconocido" << endl;
        }
        res->create_response("200");
        cout << res->strResponse << endl;
        freeList(req->body.data);
        freeList(res->body->data);
        cout <<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
        delete req;
    }
}

#endif // ROUTER_H
