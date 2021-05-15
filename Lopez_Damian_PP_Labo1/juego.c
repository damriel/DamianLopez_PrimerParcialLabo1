#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "juego.h"
#include "categoria.h"

int buscarUnJuego(eJuego aJuegos[], int tamJue, int idBuscado)
{
    int indice=-1;
    if(aJuegos!=NULL && tamJue>0)
    {
        for(int i=0; i<tamJue; i++)
        {
            if(idBuscado==aJuegos[i].codigo)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int cargarCategoriaPorCodigo(eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat, int codigo, char descripcion[])
{
    int retorno=0;
    int indice;
    if(aJuegos!=NULL && aCategorias!=NULL && descripcion!=NULL && tamJue>0 && tamCat>0)
    {
        indice=buscarUnJuego(aJuegos,tamJue,codigo);
        if(indice!=-1)
        {
            if(cargarDescripcionCategoria(aJuegos[indice].idCategoria,aCategorias,tamCat,descripcion))
            {
                retorno=1;
            }
        }
    }
    return retorno;
}

void mostrarUnJuego(eJuego unJuego, eCategoria aCategorias[], int tamCat)
{
    char descripcion[20];
    cargarDescripcionCategoria(unJuego.idCategoria,aCategorias,tamCat);
    printf("%4d    %10s     %5.2f   %10s\n",unJuego.codigo,
                                            unJuego.descripcion,
                                            unJuego.importe,
                                            descripcion);
}

int mostrarJuegos(eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat)
{
    int retorno=-1;
    if(aJuegos!=NULL && tamJue>0)
    {
        retorno=0;
        printf("      LISTA DE JUEGOS\n");
        printf("  ID    Descripcion     Importe   Categoria\n");
        for(int i=0; i<tamJue; i++)
        {
            mostrarUnJuego(aJuegos[i],aCategorias,tamCat);
        }
    }
    system("pause");
    return retorno;
}

