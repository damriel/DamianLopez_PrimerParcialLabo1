#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "categoria.h"

int cargarDescripcionCategoria(int id, eCategoria aCategorias[], int tamCat, char descripcion[])
{
    int retorno=0;
    if(aCategorias!=NULL && tamCat>0 && descripcion!=NULL)
    {
        for(int i=0; i<tamCat; i++)
        {
            if(aCategorias[i].id==id)
            {
                strcpy(descripcion, aCategorias[i].descripcion);
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}
