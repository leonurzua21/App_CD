#include "Acceso.h"
#include "AppUsuario.h"
#include "string.h"


using namespace AppCD;

int main() {
    Application::EnableVisualStyles();
    Application::Run(gcnew Acceso()); //Instancia al formulario "Acceso.h"
    Application::EnableVisualStyles();
    Application::Run(gcnew Registro()); //Instancia al formulario "AppUsuario.h"
    /*Colocar una instancia a la vez respecto al formulario inicial*/
}