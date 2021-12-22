#include "iostream"
#include "rest.h"
#include "jardinsensores.h"
#include <chrono>


#define EXAMPLE_REQUEST_HOME "GET / HTTP/1.1\nUser-Agent: Mozilla/4.0 (compatible; MSIE5.01; Windows NT)mm\nHost: www.tutorialspoint.com\nAccept-Language: en-us\nAccept-Encoding: gzip, deflate\nConnection: Keep-Alive\n\\n"
#define EXAMPLE_REQUEST_TEMPO "POST /tempo HTTP/1.1\nUser-Agent: Mozilla/4.0 (compatible; MSIE5.01; Windows NT)mm\nHost: www.tutorialspoint.com\nAccept-Language: en-us\nAccept-Encoding: gzip, deflate\nConnection: Keep-Alive\n\n{'conf':'tempo','status':'on','time':'min','ciclo':'1451'}\n"
#define EXAMPLE_REQUEST_LAMP "POST /lamp HTTP/1.1\nUser-Agent: Mozilla/4.0 (compatible; MSIE5.01; Windows NT)mm\nHost: www.tutorialspoint.com\nAccept-Language: en-us\nAccept-Encoding: gzip, deflate\nConnection: Keep-Alive\n\n{'conf':'lamp','l1':'on'}\n"

using namespace Insoel;
using namespace std::chrono;

template<typename T>
void temperatura(Request * req,Response *res, T* m){
    req->print_str_request();
    res->add_to_response("prueba","temp");
    res->add_to_response("temperatura","0.254");
    cout << "Se ejecuto temperatura" << endl;
    cout << m->temperatura << endl;
    float aux = 4;
    cout << jsonObject::convert(aux) << endl;
    bool aux2 = 0;
    cout << jsonObject::convert(aux2) << endl;
    size_t aux3 = 5654;
    cout << jsonObject::convert(aux3) << endl;
}

template<typename T>
void humedad(Request *req,Response *res, T* m){
    req->print_str_request();
    res->add_to_response("prueba","hum");
    res->add_to_response("humedad","18.9");
    res->add_to_response("otro","18123.052");
    cout << "se ejecuto humedad" << endl;
    cout << m->humedad << endl;
}

template <typename T>
void home(Request *req  ,Response *res, T *m){
    res->add_to_response("temperatura",jsonObject::convert(m->temperatura));
    res->add_to_response("humedad",jsonObject::convert(m->humedad));
    cout << "se ejecuto home" << endl;
}

/** limpiar respuesta para que funcione */

int main(){
    JardinSensores *js = new JardinSensores();
    auto start = high_resolution_clock::now();
    Rest<JardinSensores> rest(js);
    rest.add_endpoint("GET","/",home);
    rest.add_endpoint("POST","/lamp",temperatura);
    rest.add_endpoint("POST","/tempo",humedad);
    rest.run_server(EXAMPLE_REQUEST_HOME);
    rest.run_server(EXAMPLE_REQUEST_LAMP);
    rest.run_server(EXAMPLE_REQUEST_TEMPO);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
             << duration.count() << " microseconds" << endl;
    delete(js);

    return 0;
}
