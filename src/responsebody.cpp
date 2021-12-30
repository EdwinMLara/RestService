#include "responsebody.h"

string dato_to_str(nodeL *&data,const char* status_code){
    nodeL *auxPointer = data;
    /*char buffer[MAX];
    const char* str = "\"status\":";
    memccpy(buffer, str, '\0', MAX);
    memccpy(buffer - 1, status_code, '\0', MAX);
    memccpy(buffer - 1, ",", '\0', MAX);

    string strResponse = string(buffer);
    cout << strResponse << endl;*/

    while (auxPointer != nullptr) {
        cout << auxPointer->key << "---" << auxPointer->dato << endl;
        auxPointer = auxPointer->sig;
    }
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;

    return "error";
}


