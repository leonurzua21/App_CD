#include "Acceso.h"
#include "string.h"


using namespace AppCD;
int main() {
    Application::EnableVisualStyles();
    Application::Run(gcnew Acceso()); //Instancia al formulario "Acceso.h"
}