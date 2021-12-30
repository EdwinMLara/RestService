#include <SPI.h>
#include <Ethernet.h>
#include <rest.h>

class JardinSensores{
    public:
       float temperatura;
       float humedad;
       JardinSensores(){
        this->temperatura = 0;
        this->humedad = 0;
       }
};

void home(Request *req  ,Response *res, T *m){
    res->add_to_response("temperatura",JsonObject::convert(m->temperatura));
    res->add_to_response("humedad",JsonObject::convert(m->humedad));
}

EthernetServer server(80);
Insoel::Rest<JardinSensores> rest(js);

void setup() {
    Serial.begin(9600);
    while (!Serial);   
    Serial.println("Servidor Ethernet.");
    rest.add_endpoint(HTTP_GET,"/",home);
    Serial.println("Inciando Rest Seridor");
}

/**falta mandar la respuesta al cliente*/

void loop() {
    EthernetClient client = server.available();
    if(client){
    char response[100] = "";
    while(client.connected()){
        if(client.available()){  
            uint8_t typeRequest = 0,count = 0;
            char request[500];
            
            while(client.available() && count < 500){
            char c;
            c = client.read();
            request[count] = c;
            count++;
            }
              
            request[count] = '\0';
            response = rest.run_server(request); 
            client.println(response);    
        }   
      }
      client.flush();
      client.stop();
  }
}
