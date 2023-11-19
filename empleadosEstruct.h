typedef struct {
int id;
int borrado;
int tipo;
char contrasena[20];
char apellido [50];
char nombre[50];
char dni [10];
int edad;
char telefono [20];
char genero;
char estadoCivil [20];
}stEmpleado;

typedef struct nodoArbol {
 stEmpleado dato;
struct nodoArbol*der;
struct nodoArbol*izq;
}nodoArbol;

typedef struct stCeldas{

int tipoDeEmpleado;
struct nodoArbol*arbol;
}stCeldas;

void mostrarSoloEmpleadosValidos(stEmpleado dato);
void mostrarUnEmpleado(stEmpleado dato);
void mostrarArbolEmpleados(nodoArbol*arbol);
void recorrerYmostrar(stCeldas celdas[],int validos);
int cargarDatosEmpleadosDesdeArchivo(stCeldas celdas[],int validos, int dim);
int agregarTipoDeEmpleado(stCeldas celdas[],int tipo,int validos);
int buscarPosTipoEmpleado(stCeldas celdas[],int tipo,int validos);
int alta(stCeldas celdas[],int validos,stEmpleado auxEmpleado,stCeldas tipo);
nodoArbol*insertarNodoArbol (nodoArbol*arbol, nodoArbol*nuevo);
nodoArbol*crearNodoArbol (stEmpleado aux);
nodoArbol* inicArbol();
nodoArbol*buscarUnEmpleadoPorDni(nodoArbol*arbol,char buscado[]);
nodoArbol*modificarUnEmpleado(nodoArbol*arbol);
int subirEmpleadoManual(stCeldas celdas[],int validos);
