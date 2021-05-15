#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataWarehouse.h"

/**  DATOS JUEGOS **/
int codigosJuegos[9]={
    101,
    102,
    103,
    104,
    105,
    106,
    107,
    108,
    109
};

char descripcionesJuegos[9][30]={
    "CalabozosYDragones",
    "T.E.G.",
    "Monopoly",
    "Clue",
    "Batalla Naval",
    "Jenga",
    "Domino",
    "Pictionary",
    "Pathfinder"
};

float importesJuegos[9]={
    600,
    500,
    450,
    250,
    90,
    50,
    30,
    320,
    390
};

int idCategEnJuego[9]={
    501,
    502,
    503,
    503,
    502,
    503,
    502,
    503,
    501
};

int hardcodearJuegos(eJuego aJuegos[], int tamJue)
{
    int retorno=0;
    if(aJuegos!=NULL && tamJue>0)
    {
        retorno=1;
        for(int i=0; i<tamJue; i++)
        {
            aJuegos[i].codigo=codigosJuegos[i];
            strcpy(aJuegos[i].descripcion,descripcionesJuegos[i]);
            aJuegos[i].importe=importesJuegos[i];
            aJuegos[i].idCategoria=idCategEnJuego[i];
        }
    }
    return retorno;
}

/**  DATOS CATEGORIAS **/

int idCategorias[3]={
    501,
    502,
    503
};

char descripcionCategorias[3][51]={
    "RPG-Rol",
    "Estrategia",
    "Otros"
};

int hardcodearCategorias(eCategoria aCategorias[], int tamCat)
{
    int retorno=0;
    if(aCategorias!=NULL && tamCat>0)
    {
        retorno=1;
        for(int i=0; i<tamCat; i++)
        {
            aCategorias[i].id=idCategorias[i];
            strcpy(aCategorias[i].descripcion,descripcionCategorias[i]);
        }
    }
    return retorno;
}

