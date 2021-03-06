/***********************************************************************************************************
    Descripcion:
        Creacion de un programa que realice el conteo del numero de veces que aparece un caracter
        y el porcentaje en en el que el caracter ocupa en el texto.
    Autores:
        Hernandez Lopez Bryan
        Martinez Islas Armando Samir
    Fecha de creacion:
        24/05/2022
    Version: 1.0
***********************************************************************************************************/

//Librerias
#include<bits/stdc++.h> //Libreria de cabecera.
using namespace std;

//Declaracion de las funcuines del programa.
void leer();
void porcentajes();
void conteo(string a);

//Declaracion de variables globales.
map<char, float> caracteres;
int total=0;

//Funcion principal.
int main(){
    leer();
    return 0;
}

//Funcion de lectura del archivo .txt que contiene las cadenas de caracteres.
void leer(){
    ifstream archivo;
    string contenido;
    archivo.open("input.txt",ios::in);  //Abrimos el archivo en lectura.
    if(archivo.fail()){
        cout<<"\t NO SE PUDO ABRIR EL ARCHIVO."<<endl;  //Mensaje en caso de no lograr encontrar o abrir el .txt
        exit(1);
    }
    cout<<"\n   -> Contenido del archivo de texto: "<<endl;
    cout<<"\n---------------------------------------------------------------------------------------------------------------------------"<<endl;
    while(!archivo.eof()){  //Recorremos el archivo hasta llegar al final.
        getline(archivo,contenido); //Copiamos el contenido del archivo .txt a una variable tipo string.
        cout<<"\t"<<contenido<<endl;    //Mostramos en pantalla el contenido del archivo .txt.
        conteo(contenido);
    }
    cout<<"---------------------------------------------------------------------------------------------------------------------------\n"<<endl;
    archivo.close();    //Cerramos el archivo.
    porcentajes();  //Mostramos resultados obtenidos.
}

void conteo(string a){
    for(auto i: a){ //Recorremos cada caracter de la cadena (por linea) encontrada en el archivo .txt.
        caracteres[static_cast<unsigned char>(i)]+=1;   //lo buscamos en la tabla hash e incremenetamos en uno su valor.
        total++;    //Realizamos el conteo total de caracteres.
    }
}

//Funcion que realiza el calculo del porcentaje, ademas de mostrar el resultado obtenido con el programa.
void porcentajes(){
    cout<<"   - Resultados: \n"<<endl;
    for(auto x: caracteres){
        cout<<"\t -> El carcater '"<<x.first<<"' se repite "<<x.second<<" veces  ->   "<< (x.second*100)/total<<"%."<<endl; //Recorremos y mostramos cada elemento de  la tabla hash.
    }
    cout<<"\n";
}
