#include<iostream>
#include<D:\Desktop\Libreria\Grafos.h>
#include<vector>
#include<stdlib.h>
#include<map>
using namespace std;
void menu_proyecto();
void menu_libreria();
void menu(){
int opcion;

cout<< "                            PROYECTO:"<<endl;

cout<< "1) ALGORITMO DE DIKJSTRA"<<endl;
cout<< "2) LIBRERIA DE GRAFOS"<<endl;
cout<<endl;
cout<< "Ingrese una opcion ->";
cin>> opcion;

if(opcion==1){
menu_proyecto();
}

if(opcion==2){
menu_libreria();
}


}



void menu_proyecto(){

int opcion;
int opcion_Dikjstra=0;
string punto_actual,destino;
system("cls");

cout<< "                             ALGORITMO DE DIKJSTRA:                                 "<<endl;
cout<< "Ingrese 1 si se encuentra con vehiculo"<<endl;
cout<< "Ingrese 2 si no se encuentra con vehiculo "<<endl;
cout<<endl;
cout<< "Ingrese la opcion-> ";cin>>opcion;
grafo g(opcion);

system("cls");
while(opcion_Dikjstra!=3){
cin.get();
system("cls");
cout<< "1) Algoritmo de Dikjstra"<<endl;
cout<< "2) Ver nombres de los nodos"<<endl;
cout<< "3) Salir"<<endl;
cout<< "Ingrese una opcion ->";
cin>>opcion_Dikjstra;
switch(opcion_Dikjstra){
case 1:{
system("cls");
cout<< "INGRESE SU PUNTO ACTUAL:"<<endl;
cin>> punto_actual;
cout<<"INGRESE SU DESTINO "<<endl;
cin>> destino;

g.Dikjstra(punto_actual,destino);
cout<<endl;

cout<<"Presione enter para continuar"<<endl;
cin.get();
break;
system("cls");
}
case 2:{
system("cls");
for (int i=0;i<g.getN_nodo();i++){

cout<<i<<") "<<g.get_nombres(i)<<endl;


}
cout<<"Presione enter para continuar"<<endl;
cin.get();
break;
system("cls");

}
}
}
}

void menu_libreria(){
int opcion=0;
grafo g(4);
system("cls");
while(opcion!=11){

cin.get();
system("cls");

cout<<endl;
cout<< "                                     Menu: "<<endl;
cout<< "1) Recorrido DFS"<<endl;
cout<< "2) Recorrido BFS"<<endl;
cout<< "3) Comprobar si el grafo es conexo"<<endl;
cout<< "4) Comprobar si el grafo es completo"<<endl;
cout<< "5) Comprobar si el grafo es bipartito"<<endl;
cout<< "6) Comprobar si el grafo es euleriano"<<endl;
cout<< "7) Comprobar si el grafo es hamiltoniano"<<endl;
cout<< "8) Isomorfismo"<<endl;
cout<< "9) Numero cromatico"<<endl;
cout<< "10) Grafo plano"<<endl;
cout<< "11) Salir"<<endl;
cout<<endl;
cout<< "Ingrese la opcion-> ";cin>>opcion;

switch(opcion){

case 1:{
system("cls");
vector<int> visita(g.getN_nodo(),0);
cout<< "El recorrido es: "<<endl;
g.DFS(0,visita,true);
cout<<endl;


cout<<"Presione enter para continuar"<<endl;
cin.get();

break;
}
case 2:{
system("cls");


cout<< "El recorrido es: "<<endl;
g.BFS(0);
cout<<endl;


cout<<"Presione enter para continuar"<<endl;
cin.get();

break;


}
case 3:{
system("cls");
if (g.conexo()==1){

cout<< "El grafo es conexo"<<endl;

}
else{
cout<< "El grafo no es conexo"<<endl;
}

cout<<"Presione enter para continuar"<<endl;
cin.get();

break;


}
case 4:{
system("cls");
if (g.completo()==1){

cout<< "El grafo es completo"<<endl;

}
else{
cout<< "El grafo no es completo"<<endl;
}

cout<<"Presione enter para continuar"<<endl;
cin.get();

break;


}
case 5:{
system("cls");
g.bipartito();

cout<<"Presione enter para continuar"<<endl;
cin.get();

break;


}
case 6:{
system("cls");
g.euleriano();
cout<<endl;

cout<<"Presione enter para continuar"<<endl;
cin.get();

break;


}
case 7:{
system("cls");
g.hamilton();
cout<<endl;

cout<<"Presione enter para continuar"<<endl;
cin.get();

break;


}
case 8:{
system ("cls");
grafo h(3);

if(g.isomorfismo(h)==1){
cout<<"Los grafos son isomorfos"<<endl;

}
else{
cout<< "No son isomorfos"<<endl;
}
cout<<endl;

cout<<"Presione enter para continuar"<<endl;
cin.get();
break;

}
case 9:{
system ("cls");

cout<<"El numero cromatico del grafo es:"<<endl;
cout<<g.numero_cromatico();
cout<<endl;

cout<<"Presione enter para continuar"<<endl;
cin.get();
break;

}
case 10:{
system ("cls");


if(g.plano()==1){

cout<<"El grafo es plano"<<endl;

}
else{

cout<<"El grafo no es plano"<<endl;
}
cout<<endl;

cout<<"Presione enter para continuar"<<endl;
cin.get();
break;

}
}
}
}




int main(){
menu();
}

