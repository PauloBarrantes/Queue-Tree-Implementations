#import <iostream>
#import "ArbolLDL.h"

using namespace std;


/*!
   \brief "Creamos una Cajita a partir de un Nodo"
   \param "Nodo al que va apuntar la Cajita"
   \return ""
*/
Arbol::Cajita::Cajita(Nodo nodo){
  this->nodo = nodo;
  this->hermanoDerecho = 0;
}

/*!
   \brief "Destruye la cajita y sus atributos"
   \param ""
   \return ""
*/
Arbol::Cajita::~Cajita(){
  if(nodo){
    delete this->nodo;
  }
  if(this->hermanoDerecho != 0){
    delete this->hermanoDerecho;
  }
}

/*!
   \brief "Imprime la Caja a la que apunta y a su hermanoDerecho"
   \param "Output stream de donde se van a hacer las impresiones"
   \return "El Output stream"
*/
ostream& Arbol::Cajita::imprimir(ostream& salida){
  this->nodo->imprimir(salida);
  salida<< ", ";
  if(hermanoDerecho){
    this->hermanoDerecho->imprimir(salida);
  }
  return salida;
}

/*!
   \brief "Construye una Caja con una etiqueta"
   \param "Entra una etiqueta"
   \return ""
*/
Arbol::Caja::Caja(int etiqueta){
  this->etiqueta = etiqueta;
  this->hijoMasIzquierdo = 0;
  this->siguiente = 0;
}

/*!
   \brief "Destruye la Caja y sus atributos, si no son nulos"
   \param ""
   \return ""
*/
Arbol::Caja::~Caja(){
  if(this->hijoMasIzquierdo != 0){
    delete hijoMasIzquierdo;
  }
  if(this->siguiente != 0){
    delete siguiente;
  }
}

/*!
   \brief "Imprime la etiqueta y a su hijoMasIzquierdo"
   \param "Ostream de donde se van a hacer las impresiones"
   \return "El ostream"
*/
ostream& Arbol::Caja::imprimir(ostream& salida){
  salida<< this->etiqueta;
  if(hijoMasIzquierdo){
    salida<<" {";
    hijoMasIzquierdo->imprimir(salida);
    salida<<"} ";
  }
  return salida;
}

/*!
   \brief "Busca la Cajita que apunta al nodo que entra como parámetro"
   \param "Entra un Nodo al que hace referencia la Cajita buscada"
   \return "Retorna la Cajita que apunta al Nodo que entró como parámetro"
*/
Arbol::Cajita* Arbol::buscarCajita(Nodo nodoRef){
  Cajita* buscado = 0;
  Nodo padreActual = raizArbol;
  Cajita* cajitaActual = padreActual->hijoMasIzquierdo;
  while (padreActual->siguiente != 0) {
    while (cajitaActual != 0){
      if(cajitaActual->nodo == nodoRef){
        buscado = cajitaActual;
      }
      cajitaActual = cajitaActual->hermanoDerecho;
    }
    padreActual = padreActual->siguiente;
  }
  return buscado;
}

/*!
   \brief "Construye un Arbol implementado por Lista de Listas e inicializa sus atributos"
   \param ""
   \return ""
*/
Arbol::Arbol(){
  this->_init();
}

/*!
   \brief "Inicializa nulos los atributos del Arbol"
   \param ""
   \return ""
*/
void Arbol::_init(){
  numeroNodos = 0;
  raizArbol = 0;
}

/*!
   \brief "Destruye el Arbol,"
   \param ""
   \return ""
*/
Arbol::~Arbol(){
  delete raizArbol;
}

/*!
   \brief "Vacía el Arbol"
   \param ""
   \return ""
*/
void Arbol::vaciar(){
  delete this;
  this->_init();
}

/*!
   \brief "Indica si el Arbol está vacío"
   \param ""
   \return "Retrona 1 si está vacía, 0 si no"
*/
int Arbol::vacia(){
  return numeroNodos == 0;
}

/*!
   \brief "Devolvemos el padre del nodoarbol que entro como parametro"
   \param "Entra un nodo arbol"
   \return "Retorna el nodo padre"
*/
Arbol::Nodo Arbol::raiz(){
  return this->raizArbol;
}

/*!
   \brief "Devolvemos el padre del nodoarbol que entro como parametro"
   \param "Entra un nodo arbol"
   \return "Retorna el nodo padre"
*/
Arbol::Nodo Arbol::hijoMasIzq(Nodo nodoRef){
  return nodoRef->hijoMasIzquierdo->nodo;
}

/*!
   \brief "Devolvemos el padre del nodoarbol que entro como parametro"
   \param "Entra un nodo arbol"
   \return "Retorna el nodo padre"
*/
Arbol::Nodo Arbol::hermanoDer(Nodo nodoRef){
  return buscarCajita(nodoRef)->hermanoDerecho->nodo;
}

/*!
   \brief "Devolvemos el padre del nodoarbol que entro como parametro"
   \param "Entra un nodo arbol"
   \return "Retorna el nodo padre"
*/
Arbol::Nodo Arbol::padre(Nodo nodoRef){
  Nodo padre = 0;
  Nodo padreActual = raizArbol;
  Cajita* cajitaActual = padreActual->hijoMasIzquierdo;
  while (padreActual->siguiente != 0) {
    while (cajitaActual != 0){
      if(cajitaActual->nodo == nodoRef){
        padre = padreActual;
      }
      cajitaActual = cajitaActual->hermanoDerecho;
    }
    padreActual = padreActual->siguiente;
  }
  return padre;
}

/*!
   \brief "Devolvemos el padre del nodoarbol que entro como parametro"
   \param "Entra un nodo arbol"
   \return "Retorna el nodo padre"
*/
int Arbol::esHoja(Nodo nodoRef){
  return nodoRef->hijoMasIzquierdo == 0;
}

/*!
   \brief "Devolvemos el padre del nodoarbol que entro como parametro"
   \param "Entra un nodo arbol"
   \return "Retorna el nodo padre"
*/
int Arbol::etiqueta(Nodo nodoRef){
  return nodoRef->etiqueta;
}

/*!
   \brief "Devolvemos el padre del nodoarbol que entro como parametro"
   \param "Entra un nodo arbol"
   \return "Retorna el nodo padre"
*/
int Arbol::numNodos(){
  return numeroNodos;
}

/*!
   \brief "Devolvemos el padre del nodoarbol que entro como parametro"
   \param "Entra un nodo arbol"
   \return "Retorna el nodo padre"
*/
int Arbol::numHijos(Nodo nodoRef){
  int numeroHijos = 0;
  Arbol::Cajita* siguiente = nodoRef->hijoMasIzquierdo;
  while (siguiente != 0) {
    ++numeroHijos;
    siguiente = siguiente->hermanoDerecho;
  }
  return numeroHijos;
}

/*!
   \brief "Devolvemos el padre del nodoarbol que entro como parametro"
   \param "Entra un nodo arbol"
   \return "Retorna el nodo padre"
*/
void Arbol::modificarEtiq(Nodo nodoRef, int nuevaEtiqueta){
  nodoRef->etiqueta = nuevaEtiqueta;
}

/*!
   \brief "Devolvemos el padre del nodoarbol que entro como parametro"
   \param "Entra un nodo arbol"
   \return "Retorna el nodo padre"
*/
Arbol::Nodo Arbol::agregarHijoIesimo(Nodo padre, int etiqueta, int posicion){
  Nodo nuevoNodo = new Caja(etiqueta);
  nuevoNodo->siguiente = raizArbol->siguiente;
  raizArbol->siguiente = nuevoNodo;
  Nodo nodoActual = raizArbol;
  while(nodoActual != padre){
    nodoActual = nodoActual->siguiente;
  }
  Cajita* nuevaCajita = new Cajita(nuevoNodo);
  Cajita* cajitaActual = padre->hijoMasIzquierdo;
  if(posicion > 1){
    for(int i = 1; i < posicion-1; ++i){
      cajitaActual = cajitaActual->hermanoDerecho;
    }
    nuevaCajita->hermanoDerecho = cajitaActual->hermanoDerecho;
    cajitaActual->hermanoDerecho = nuevaCajita;
  }
  else{
    nuevaCajita->hermanoDerecho = cajitaActual;
    padre->hijoMasIzquierdo = nuevaCajita;
  }
  ++numeroNodos;
  return nuevoNodo;
}

/*!
   \brief "Devolvemos el padre del nodoarbol que entro como parametro"
   \param "Entra un nodo arbol"
   \return "Retorna el nodo padre"
*/
void Arbol::borrarHoja(Nodo hoja){
  Nodo nodoActual = raizArbol;
  while(nodoActual->siguiente != hoja){
    nodoActual = nodoActual->siguiente;
  }
  nodoActual->siguiente = hoja->siguiente;
  hoja->siguiente = 0;
  std::cout << "aisla nodo victima" << '\n';
  Cajita* victima = buscarCajita(hoja);
  std::cout << "encuentra a la cajita victima" << '\n';
  nodoActual = padre(hoja);
  std::cout << "encuentra al padre del nodo victima" << '\n';

  if(nodoActual->hijoMasIzquierdo == victima){
    std::cout << "va a hacer el if" << '\n';
    nodoActual->hijoMasIzquierdo = victima->hermanoDerecho;
    std::cout << "hizo el if" << '\n';

  }
  else{
    std::cout << "va a hacer el else" << '\n';
    Cajita* cajitaActual = nodoActual->hijoMasIzquierdo;
    while(cajitaActual->hermanoDerecho != victima){
      cajitaActual = cajitaActual->hermanoDerecho;
    }
    std::cout << "encuentra al hermano izquierdo de la victima" << '\n';
    cajitaActual->hermanoDerecho = victima->hermanoDerecho;
  }
  victima->hermanoDerecho = 0;
  std::cout << "aisla la cajita" << '\n';
  delete victima;
  --numeroNodos;
}

/*!
   \brief "Devolvemos el padre del nodoarbol que entro como parametro"
   \param "Entra un nodo arbol"
   \return "Retorna el nodo padre"
*/
void Arbol::ponerRaiz(int etiqueta){
  if(vacia()){
    raizArbol = new Caja(etiqueta);
    ++numeroNodos;
  }
}

/*!
   \brief "Devolvemos el padre del nodoarbol que entro como parametro"
   \param "Entra un nodo arbol"
   \return "Retorna el nodo padre"
*/
Arbol::Nodo Arbol::buscarNodo(int etiqueta){
  Nodo buscado = raizArbol;
  while(buscado->etiqueta != etiqueta && buscado){
    buscado = buscado->siguiente;
  }
  return buscado;
}

/*!
   \brief "Devolvemos el padre del nodoarbol que entro como parametro"
   \param "Entra un nodo arbol"
   \return "Retorna el nodo padre"
*/
ostream& Arbol::imprimir(ostream& salida){
  return raizArbol->imprimir(salida);
}
