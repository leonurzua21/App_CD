#include "Acceso.h"
#include "AppUsuario.h"
#include "string.h"


using namespace AppCD;

int main() {
    /*Application::EnableVisualStyles();
    Application::Run(gcnew Acceso());*/ //Instancia al formulario "Acceso.h"
    Application::EnableVisualStyles();
<<<<<<< HEAD
=======
    Application::Run(gcnew Acceso()); //Instancia al formulario "Acceso.h"
    Application::EnableVisualStyles();
>>>>>>> 9b56156 (Cambios en las clases Consultar.h, registro.h y acceso.h, validación de usuario existente, credenciales existentes listo.)
    Application::Run(gcnew AppUsuario()); //Instancia al formulario "AppUsuario.h"
    /*Colocar una instancia a la vez respecto al formulario inicial*/
}