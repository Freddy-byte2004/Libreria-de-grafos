#include <iostream>
#include <vector>
# include<stdlib.h>
#include<fstream>
#include <map>

using namespace std;
class grafo{

private:
int n_nodos, n_aristas;
vector<vector<int>> matriz_adyacencia;
map<string,int> nombre_nodos;

public:

grafo(int opcion){
ifstream archivo_conexiones,archivo_nombres;
int nodo_1, nodo_2,peso, contador=0;
string nodo, N_nodo1,N_nodo2;
n_aristas=0;
if(opcion==1||opcion==2){
archivo_nombres.open("D:\\Desktop\\Libreria\\grafo_proyecto\\vertices.txt",ios::in);
if(archivo_nombres.fail()==1){

    cout<< "EPA"<<endl;
}
archivo_nombres>>n_nodos;
matriz_adyacencia=vector<vector<int>>(n_nodos,vector<int>(n_nodos,0));
while(archivo_nombres.eof()!=1){

archivo_nombres>>nodo;
agregar_nombres_nodos(contador,nodo);
}
archivo_nombres.close();
}
if(opcion==1){

archivo_conexiones.open("D:\\Desktop\\Libreria\\grafo_proyecto\\conexiones_dirigido.txt",ios::in);
if(archivo_conexiones.fail()==0){
while(archivo_conexiones.eof()!=1){
archivo_conexiones>>N_nodo1;
archivo_conexiones>>N_nodo2;
archivo_conexiones>>peso;
nodo_1=nombre_nodos[N_nodo1];
nodo_2=nombre_nodos[N_nodo2];
agregar_aristas_dirigidas(nodo_1,nodo_2,peso);
}
archivo_conexiones.close();

}

}

if(opcion==2){
archivo_conexiones.open("D:\\Desktop\\Libreria\\grafo_proyecto\\conexiones_no_dirigido .txt",ios::in);

while(archivo_conexiones.eof()!=1){
archivo_conexiones>>N_nodo1;
archivo_conexiones>>N_nodo2;
archivo_conexiones>>peso;
nodo_1=nombre_nodos[N_nodo1];
nodo_2=nombre_nodos[N_nodo2];
agregar_aristas_no_dirigidas(nodo_1,nodo_2,peso);
}
archivo_conexiones.close();
}
if(opcion==3){

archivo_nombres.open("D:\\Desktop\\Libreria\\grafo_libreria\\vertices_isomorfo.txt",ios::in);
archivo_nombres>>n_nodos;
matriz_adyacencia=vector<vector<int>>(n_nodos,vector<int>(n_nodos,0));
while(archivo_nombres.eof()!=1){

archivo_nombres>>nodo;
agregar_nombres_nodos(contador,nodo);
}
archivo_nombres.close();


archivo_conexiones.open("D:\\Desktop\\Libreria\\grafo_libreria\\conexiones_isomorfo.txt",ios::in);

while(archivo_conexiones.eof()!=1){
archivo_conexiones>>N_nodo1;
archivo_conexiones>>N_nodo2;
archivo_conexiones>>peso;
nodo_1=nombre_nodos[N_nodo1];
nodo_2=nombre_nodos[N_nodo2];
agregar_aristas_no_dirigidas(nodo_1,nodo_2,peso);
}
archivo_conexiones.close();



}
if(opcion==4){
archivo_nombres.open("D:\\Desktop\\Libreria\\grafo_libreria\\vertices.txt",ios::in);
archivo_nombres>>n_nodos;
matriz_adyacencia=vector<vector<int>>(n_nodos,vector<int>(n_nodos,0));
while(archivo_nombres.eof()!=1){

archivo_nombres>>nodo;

agregar_nombres_nodos(contador,nodo);
}
archivo_nombres.close();
archivo_conexiones.open("D:\\Desktop\\Libreria\\grafo_libreria\\conexiones_no_dirigido.txt",ios::in);

while(archivo_conexiones.eof()!=1){
archivo_conexiones>>N_nodo1;
archivo_conexiones>>N_nodo2;
archivo_conexiones>>peso;
nodo_1=nombre_nodos[N_nodo1];
nodo_2=nombre_nodos[N_nodo2];
agregar_aristas_no_dirigidas(nodo_1,nodo_2,peso);
}
archivo_conexiones.close();
}
}
int getN_nodo(){

return n_nodos;
}
int getN_arista(){
return n_aristas;
}
int get_matriz_adyacencia(int i, int j){
return matriz_adyacencia[i][j];
}
void matriz(){
    for(int i=0;i<n_nodos;i++){
            cout<<endl;
        for(int j=0;j<n_nodos;j++){
            cout<< matriz_adyacencia[i][j]<<" ";
        }

    }

}
void agregar_nombres_nodos(int &contador, string nodo){
nombre_nodos.insert(make_pair(nodo,contador));
contador++;
}
string get_nombres(int i){

for(auto ite=nombre_nodos.begin();ite!=nombre_nodos.end();ite++){
if(ite->second==i){
return ite->first;
}
}





}
void agregar_aristas_dirigidas(int nodo1, int nodo2, int peso){
matriz_adyacencia[nodo1][nodo2]=peso;
n_aristas++;
}

void agregar_aristas_no_dirigidas(int nodo1, int nodo2, int peso){

matriz_adyacencia[nodo1][nodo2]=peso;
matriz_adyacencia[nodo2][nodo1]=peso;
n_aristas++;


}

void DFS(int origen,vector<int>&visita, bool imprimir_nodos){
visita[origen]=1;
if(imprimir_nodos==true){
for(auto ite=nombre_nodos.begin(); ite!=nombre_nodos.end(); ite++){
if(ite->second==origen){
cout<<ite->first<<" ";
break;
}
}
}

for(int i=0;i<n_nodos;i++){

if((matriz_adyacencia[origen][i]!=0)&&(visita[i]==0)){
DFS(i,visita,imprimir_nodos);
}
}
}

void BFS(int clave_nodo){
string nodo;
vector<int> visita(n_nodos,0);
int i=0;
int policia_parada=1;
bool iterador=true;
visita[clave_nodo]=1;

for(auto ite=nombre_nodos.begin();ite!=nombre_nodos.end();ite++){
if(ite->second==clave_nodo){

nodo=ite->first;
break;

}


}

cout<< nodo<< " ";
while(iterador==true){

if ((matriz_adyacencia[clave_nodo][i]!=0)&&(visita[i]==0)){
visita[i]=1;
for(auto ite=nombre_nodos.begin(); ite!=nombre_nodos.end(); ite++){
if(ite->second==i){
cout<< ite->first<<" ";
break;
}
}
}
for(int i=0;i<n_nodos;i++){
if(visita[i]==0){
policia_parada=0;
break;
}
}
if(policia_parada==1){
iterador=false;
}
i++;
if(i==n_nodos){
i=0;
clave_nodo++;
}
policia_parada=1;

}




}

bool completo(){
int policia=1;
for(int i=0;i<n_nodos;i++){
for(int j=0;j<n_nodos;j++){
if((j!=i)&&(matriz_adyacencia[i][j]==0)){
policia=0;
j=n_nodos;
i=n_nodos;
}
}
}
if(policia==1){
return true;
}
else{
return false;
}
}

bool conexo(){
int policia_conexo=1;
vector<int> visita(n_nodos,0);
DFS(0,visita,false);
for(int i=0;i<n_nodos;i++){
if(visita[i]==0){
policia_conexo=0;
}
}
if(policia_conexo==0){
return false;
}
if (policia_conexo==1){
return true;
}
}

bool comprobar_bipartito(){

vector<int> grupo_a(n_nodos,0);// en este vector se almacena el grupo a conformado por todos los nodos no adyacentes al nodo 0

//condicional para comprobar si el grafo es completo
if(completo()==false){


//si no es completo se comienza con el otro condicional para hacer el grupo a que va a estar conformado por los nodos que no son adyacentes a el origen
for(int i=0;i<n_nodos;i++){
if(matriz_adyacencia[0][i]==0){
grupo_a[i]=i;
//cout<<grupo_a[i]<<" ";
}
}
/* bucle para comprobar que no haya nodos del grupo a que esten conectados y si los hay los saca del grupo*/
for(int i=0;i<n_nodos;i++){
for(int j=0;j<n_nodos;j++){
if(matriz_adyacencia[grupo_a[i]][grupo_a[j]]==1){
grupo_a[j]=0;
}

}
}


//bucle y condicional para comprobar que no haya nodos que se conecten entre si en el grupo b
for(int i=0;i<n_nodos;i++){
for(int j=0;j<n_nodos;j++){
if((i!=grupo_a[i])&&(j!=grupo_a[j])&&(matriz_adyacencia[i][j]!=0)){
// si hay nodos que se conectan entre si entonces el grafo no es bipartito
return false;
}
}
}

return true;

}
else if(completo()==true){
return false;
}
return false;

}

void bipartito(){

if(comprobar_bipartito()==1){
cout<< "El grafo es bipartito"<<endl;

}

else {
cout<< "El grafo no es bipartito"<<endl;
}


}
bool verificar_euleriano(){

int grado=0;
if (conexo()==1){
for(int i=0;i<n_nodos;i++){

    for(int j=0;j<n_nodos;j++){
        if(matriz_adyacencia[i][j]!=0){
            grado++;
        }
    }
    if(grado%2!=0){
        return false;
    }
    grado=0;
}

return true;





}
else{
return false;
}
}

void buscar_ciclo_euleriano(vector<int>& camino, int nodo,int& contador_aristas,vector<vector<int>> Matriz_adyacencia){
int nodo_actual,nodo_siguiente;
bool iterador=true;

nodo_actual=nodo;// la variable nodo actual se inicializa con la variable nodo

while(iterador==true){

    camino.push_back(nodo_actual);
    nodo_siguiente=-1;
    contador_aristas++;
// en este bucle se busca el nodo_siguiente a comprobar
    for(int i=0; i<n_nodos;i++){
        if((Matriz_adyacencia[nodo_actual][i]!=0)&&(i!=nodo)){
            Matriz_adyacencia[nodo_actual][i]=0;
            Matriz_adyacencia[i][nodo_actual]=0;// se eliminan las aristas para evitar repetir la misma arista
            nodo_siguiente=i; //el nodo siguiente es igual al nodo adyacente al nodo_actual
            break; //se termina el bucle
        }
    }

    if(nodo_siguiente==-1){
        iterador=false;// si nodo_siguiente es igual a -1 luego del ciclo for significa que se han recorrido todos las aristas del grafo
    }
    nodo_actual=nodo_siguiente;// si no nodo_actual es igual a nodo_siguiente y se almacena nodo_siguiente en el camino
}



}
void euleriano(){

vector<int> camino;// este vector va a almacenar el camino euleriano
int contador_aristas=0,tamano_camino,i=0;// la variable contador va a contar si en el camino se recoorren todas las aristas
//la variable tamano_camino va a almacenar el tamaño del vector camino
if(verificar_euleriano()==1){//primero se verifica si el grafo es euleriano
for( i=0; i<n_nodos;i++){
// se empieza a buscar el camino euleriano a traves de la funcion buscar_ciclo_euleriano
    buscar_ciclo_euleriano(camino,i,contador_aristas,matriz_adyacencia);
    tamano_camino=camino.size();

    if((matriz_adyacencia[camino[camino.size()-1]][i]!=0)&&(contador_aristas==n_aristas-1)){
// se comprueba si el ultimo elemento del camino conecta con el nodo i y si se han recorrido todas las aristas entonces se acaba el bucle y se ha encotrado el camino
       break;
    }
    else{
// si no se consigue el camino entonces se sacan todos los elementos del vector  y se comienza de cero
        for(int i=0;i<tamano_camino;i++){
            camino.pop_back();
        }
        contador_aristas=0;// se reinicia la variable contador
        // si no se consigue el camino se vuelve a empezar desde otro nodo

    }

}
cout<< "El grafo es euleriano y el camino es:"<<endl;
imprimir_ciclo(camino,i);
// se llama a la funcion imprimir camino para que imprima el camino recorrido



}
else{
    cout<< "El grafo no es euleriano";
}
}

void imprimir_ciclo(vector<int> camino, int nodo_final){


for(int i=0;i<camino.size();i++){


for(auto ite=nombre_nodos.begin();ite!=nombre_nodos.end();ite++){

if(ite->second==camino[i]){

cout<<ite->first<< "-";
break;
}

}

}
for(auto ite=nombre_nodos.begin();ite!=nombre_nodos.end();ite++){

if(ite->second==nodo_final){

cout<<ite->first;
break;
}

}





}

bool verificar_hamiltoniano(){

int grado_1=0, grado_2=0, nodo_no_adyacente;
if(conexo()==1){


for(int i=0;i<n_nodos;i++){

        if((matriz_adyacencia[0][i]==0)&&(i!=0)){
            nodo_no_adyacente=i;
            i=n_nodos;
        }

}


for(int i=0; i<n_nodos;i++){
        if(matriz_adyacencia[0][i]==1){
    grado_1++;
        }
}
for(int i=0;i<n_nodos;i++){
        if(matriz_adyacencia[nodo_no_adyacente][i]==1){
    grado_2++;
        }
}

if(grado_1+grado_2>=n_nodos-1){

    return true;
}
else{
    return false;
}

}
else{
return false;
}
}


bool verificar_ciclo_hamiltoniano(vector<int>& camino, vector<bool>& visita, int nodo, int contador){

if((matriz_adyacencia[nodo][camino[0]]!=0)&&(contador==n_nodos)){
    return true;
}
for(int i=0;i<n_nodos;i++){
    if((matriz_adyacencia[nodo][i]!=0)&&(visita[i]==false)){
        visita[i]=true;
        camino.push_back(i);
// Se va hacia el nodo adyacente y comrpueba si existe un ciclo a partir de eso nodo
        if(verificar_ciclo_hamiltoniano(camino,visita,i,contador+1)==true){
                return true;
        }
        // si no consigue el ciclo entonces saca al nodo del vector camino y se marca como no visitado y se iria hacia otro camino
        visita[i]=false;
        camino.pop_back();
    }
}
return false;
}

void hamilton(){
vector<int> camino;

vector<bool> visita(n_nodos, false);// vector policia que comprueba si se ha visitado el nodo en cuestion

int policia_hamiltoniano=0;
int contador=1;


for(int i=0;i<n_nodos;i++){
camino.push_back(i);
visita[i]=true;
    if(verificar_ciclo_hamiltoniano(camino,visita,i,contador)==true){
    cout<< "El grafo es hamiltoniano y el recorrido es:"<<endl;
        imprimir_ciclo(camino,i);
        policia_hamiltoniano=1;
        break;
    }

    else{
    contador=1;
    for(int i=0;i<camino.size();i++){
    camino.pop_back();
    }
    for(int i=0;i<visita.size();i++){

    visita[i]=false;
    }
    }

}
if(policia_hamiltoniano==0){


    cout<< "El grafo no es hamiltoniano"<<endl;

}

}
void Dikjstra(string nodo_origen, string nodo_destino ){

/*  la funcion recibe como parametros el nodo de origen y el nodo destino         */

 vector<int>distancia(n_nodos, 214748364); /*  esta funcion almacena la distancia de todos los nodos
 con respecto al origen, se inicializa con un tamaño igual a n_nodos y sus elementos son un numero muy grande
 que representa la distancia infinita o indeterminada que hay desde el nodo de origen con respecto a los otros nodos      */
vector<bool> visita(n_nodos, false);// este vector sirve para almacenar los nodos que se han visitado todos sus elementos son false ya que aun no se visita ningun nodo
vector<int> predecesor(n_nodos,-1);// este nodo sirve para almacenar todos los predecesores del nodo destino para llegar al nodo origen
vector<string> recorrido_corto_destino; // este vector almacena el recorrido mas corto pero este almacena los nombres tipo string de los nodos
int u,v,i=0,clave_nodo_origen,clave_destino,aux_clave_destino;
clave_nodo_origen=nombre_nodos[nodo_origen];// esta variable es igual a la identificacion numerica del nodo origen
clave_destino= nombre_nodos[nodo_destino];// esta variable es igual a la identificacion numerica del nodo destino
distancia[clave_nodo_origen] = 0; // la distancia del nodo origen con respecto a si mismo obviamente es igual a cero
aux_clave_destino=clave_destino;

// en este ciclo se realiza todo el algoritmo de Dikjstra
for (int i = 0; i< n_nodos-1 ; i++) {
u=-1;
// en este ciclo se busca el nodo con la distancia mas corta respecto al origen y se almacena en la variable u
for (int j = 0; j< n_nodos; j++) {
if ((visita[j]!=true) && ((u == -1) || (distancia[j] < distancia[u]))) {
u = j;
}
}// fin del ciclo for

visita[u] = true;
// se marca el nodo seleccionado como visitado

//  En este ciclo se actualiza la distancia de los vértices adyacentes del vértice seleccionado
// se va actualizando las distancias con los vértices adyacentes al origen
for (int v = 0; v<n_nodos; v++) {
if ((visita[v]!=true) && (matriz_adyacencia[u][v]!=0) && (distancia[u] + matriz_adyacencia[u][v]<distancia[v])) {
distancia[v] = distancia[u] + matriz_adyacencia[u][v];
predecesor[v]=u; // este vector va almacenando cada uno de los predecesores de los nodos
}
}// fin del ciclo for para actualizar las distancias
}// fin del algoritmo y del ciclo

// este ciclo se utiliza para almacenar el recorrido mas corto del origen al destino
while(clave_destino!=-1){
/* este ciclo for solo se utiliza para encontrar el nombre tipo string correspondiente a la identi
ficacion numerica del nodo destino y se termina de una vez se encuentre el nodo   */
for(auto ite=nombre_nodos.begin(); ite!=nombre_nodos.end(); ite++){
if(ite->second==clave_destino){
recorrido_corto_destino.push_back(ite->first);// una vez se encuentre el nodo se almacena en el vector
break;
}
}
clave_destino=predecesor[clave_destino];/* ahora clave destino es igual al predecesor de su predecesor
hasta que llegue al origen que sera igual a -1 y se termine el ciclo while, de esa manera el vector
recorrido_corto_destino almacenara la ruta mas corta desde el origen hasta el destino */
}
//muestra el recorrido
cout<< "La ruta más corta desde "<< nodo_origen<< " hasta "<< nodo_destino<< " es: "<<endl;
for(int j=recorrido_corto_destino.size()-1; j>=0;j--){

cout<<recorrido_corto_destino[j];
if(j!=0){
cout<<" -> ";
}

}
cout<< endl;
cout<< "la distancia es: "<< distancia[aux_clave_destino]<<"m";

 }

 bool isomorfismo(grafo h){// esta funcion tiene como parametros un grafo h
vector<int> grado_grafo_g(n_nodos,0);// vector que almacena todos los grados de cada nodo del grafo g
vector<int> grado_grafo_h(h.getN_nodo(),0);//vector que almacena todos los grados de cada nodo del grafo h
vector<bool> policia_grado(h.getN_nodo(),false);
vector<bool> asignacion(n_nodos,false);
int policia_grados=1;
map<int,int> funcion;// funcion que asigna a cada vertice del grafo g un vertice del grafo h preservando sus conexiones
 if(n_nodos==h.getN_nodo()){

 if(n_aristas==h.getN_arista()){

 for(int i=0;i<n_nodos;i++){
 for(int j=0;j<n_nodos;j++){
 if(matriz_adyacencia[i][j]==1){
 grado_grafo_g[i]++;
 }
 }
 }
for(int i=0;i<h.getN_nodo();i++){
 for(int j=0;j<h.getN_nodo();j++){
 if(h.get_matriz_adyacencia(i,j)==1){
 grado_grafo_h[i]++;
 }
 }
 }
for(int i=0;i<n_nodos;i++){// en este doble ciclo for se va a comprobar si los dos grafos tienen los mismos grados
for(int j=0;j<n_nodos;j++){
if((grado_grafo_g[i]==grado_grafo_h[j])&&(policia_grado[j]==false)){
policia_grado[j]=true;
break;
}
}
}
for(int i=0;i<n_nodos;i++){
if(policia_grado[i]==false){
return false;
policia_grados=0;
}
}
if(policia_grados==1){


for(int i=0;i<n_nodos;i++){

for(int j=0;j<n_nodos;j++){
if((grado_grafo_g[i]==grado_grafo_h[j])&&(asignacion[j]==false)&&(verificar_grado_adyacencia(grado_grafo_g,grado_grafo_h,i,j, h)==true)){
funcion[i]=j;
asignacion[j]=true;
break;


}

}
}
/*cout<< "CORRESPONDENCIA"<<endl;
for(auto ite=funcion.begin();ite!=funcion.end(); ite++){
cout<< ite->first <<" "<< ite->second<<endl;

}
cout<<endl;
*/
for (int i=0;i<n_nodos;i++){


for(int j=0;j<n_nodos;j++){

if((matriz_adyacencia[i][j]!=h.get_matriz_adyacencia(funcion[i],funcion[j]))){
return false;
}

}

}


return true;

}
}

 else if(n_aristas!=h.getN_arista()){
 return false;
 }

 }

 else if(n_nodos!=h.getN_nodo()) {
return false;
 }







 }
 int sacar_grado(int nodo){
 vector<int>grado(n_nodos,0);
 for(int i=0;i<n_nodos;i++){
 for(int j=0;j<n_nodos;j++){
 if(matriz_adyacencia[i][j]==1){
 grado[i]++;
 }
 }
 }

 return grado[nodo];




 }
 bool verificar_grado_adyacencia(vector<int> grado_grafo_g, vector<int>grado_grafo_h, int nodo_g, int nodo_h, grafo h){
//funcion que verificar que cada nodo adyacente a un nodo de g tenga el mismo grado que un nodo adyacente a h y poder asignarlo en la funcion
 vector<int> adyacencia_vertice_g;// vector que almacena todo los vertices adyacentes al nodo g
 vector<int> adyacencia_vertice_h;// vector que almacena todo los vertices adyacentes al nodo h
 vector<bool>policia_vertice_verificado(n_nodos,false);// vector policia que verifica si ese nodo ya fue verificado
 int policia_grado=0;

 for(int i=0;i<n_nodos;i++){
if(matriz_adyacencia[nodo_g][i]==1){
adyacencia_vertice_g.push_back(i);
}
 if(h.get_matriz_adyacencia(nodo_h,i)==1){
 adyacencia_vertice_h.push_back(i);
 }
 }

 /*if((nodo_g==3)&&(nodo_h==3)){

cout<< "LAS adyacencias son:"<<endl;
 for(int i=0;i<adyacencia_vertice_g.size();i++){
 cout<<adyacencia_vertice_g[i]<<" ";

 }
 cout<<endl;
  for(int i=0;i<adyacencia_vertice_h.size();i++){
 cout<<adyacencia_vertice_h[i]<<" ";

 }
 cout<<endl;

 }*/
 //cout<< "NODO g="<<nodo_g<<" "<<"NODO H="<<nodo_h<<endl;
 for(int i=0;i<grado_grafo_g[nodo_g];i++){

 for(int j=0;j<grado_grafo_g[nodo_g];j++){

 if((grado_grafo_g[adyacencia_vertice_g[i]]==grado_grafo_h[adyacencia_vertice_h[j]])&&(policia_vertice_verificado[j]==false)){
//cout<< adyacencia_vertice_g[i]<< " "<< "GRADO= "<<grado_grafo_g[adyacencia_vertice_g[i]]<<" "<<adyacencia_vertice_h[j]<<" "<<"GRADOH="<<grado_grafo_h[adyacencia_vertice_h[j]]<<endl;
 policia_grado=1;
 policia_vertice_verificado[j]=true;
 break;
 }


 }
 if(policia_grado==0){
 return false;
 }
policia_grado=0;

 }
 return true;
 }



 bool verificar_color(vector<int>colores, int v, int color){
 for(int i=0;i<n_nodos;i++){
 if((matriz_adyacencia[i][v]==1)&&(colores[i]==color)){
 return false;
 }
 }
 return true;
 }

 bool encontrar_numero_cromatico(int v,vector<int>colores,int numero_colores){
 int color;// esta variable identifica el color con que se va a colorear un grafo
 if(v==n_nodos){// si se ha llegado hasta el ultimo nodo signfifica que se ha coloreado todo el grafo
 return true;

 }

 for(color=1;color<=numero_colores;color++){
 if(verificar_color(colores,v,color)==1){// esta funcion verifica sise puede colorear el nodo con el numero
 colores[v]=color;

 if(encontrar_numero_cromatico(v+1,colores,numero_colores)==1){// la funcion se llama recursivamente hasta que llegue al ultimo nodo
 return true;

 }
 colores[v]=0;
 }
 }
 return false;

 }

 int numero_cromatico(){
int grado_mayor=0;
 vector<int>colores(n_nodos,-1);
 int numero_colores=1;// numero colores va a ser el numero de colores que necesita el grafo para colorearse

 while(encontrar_numero_cromatico(0,colores,numero_colores)==0){// va ir verificando si se puede colorear todo el grafo con la cantidad de colores que tenga el numero colores
 numero_colores++;// si no se puede colorear el grafo con la cantidad de colores que indica numero_colores enotnces se aumenta
 }
 for(int i=0;i<n_nodos;i++){
 if(grado_mayor<sacar_grado(i)){
 grado_mayor=sacar_grado(i);
 }

 }
if(comprobar_bipartito()==true){
return 2;
}

if(completo()==true){

return n_nodos;
}

 if((comprobar_bipartito()==false)&&(n_aristas>1)&&(plano()==true)&&(numero_colores<=3)){
 return 3;
 }
 if((comprobar_bipartito()==false)&&(n_aristas>1)&&(plano()==true)&&(numero_colores>3)){
 return 4;
 }

 if((comprobar_bipartito()==false)&&(n_aristas>1)&&(plano()==false)&&(numero_colores<=grado_mayor)){
 return numero_colores;
 }
if((comprobar_bipartito()==false)&&(n_aristas>1)&&(plano()==false)&&(numero_colores>grado_mayor)){
 return grado_mayor;
 }


 }


 bool plano(){

 if((comprobar_bipartito()==true)&&(n_nodos>=3)){
 if(n_aristas-1<=(2*n_nodos)-4);
 return true;
 }

if((comprobar_bipartito()==false)&&(n_nodos>=3)){

if(n_aristas-1<=(3*n_nodos)-6){

return true;


}
}
return false;

}



};








