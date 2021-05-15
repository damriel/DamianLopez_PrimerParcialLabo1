#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dam.h"
#include "dataWarehouse.h"
#include "cliente.h"
#include "alquileres.h"

#define TAMJUE 9
#define TAMCAT 3
#define TAMCLI 50
#define TAMALQ 100

int main()
{
    int idClientes=20001;
    int idAlquiler=40001;
    char exitConfirm='n';
    eJuego juegos[TAMJUE];
    eCategoria categorias[TAMCAT];
    eCliente clientes[TAMCLI];
    eAlquiler alquileres[TAMALQ];

    inicializarArrayClientes(clientes,TAMCLI);
    hardcodearJuegos(juegos,TAMJUE);
    hardcodearCategorias(categorias,TAMCAT);

    do{
        switch(menuOpciones())
        {
        case 1:
            if(!altaCliente(clientes,TAMCLI,&idClientes))
            {
                printf("Alta exitosa!\n");
            }
            else
            {
                printf("No se pudo dar de alta al cliente.\n");
            }
            system("pause");
            break;
        case 2:
            modificarUnCliente(clientes,TAMCLI);
            system("pause");
            break;
        case 3:
            bajaCliente(clientes,TAMCLI,alquileres,TAMALQ);
            system("pause");
            break;
        case 4:
            ordenarClientesPorNombreYApellido(clientes,TAMCLI);
            mostrarClientes(clientes,TAMCLI);
            system("pause");
            break;
        case 5:
            altaAlquiler(alquileres,TAMALQ,clientes,TAMCLI,juegos,TAMJUE,categorias,TAMCAT,&idAlquiler);
            break;
        case 6:
            dam_getCaracter(&exitConfirm,"Seguro desea salir (s/n)?: ","Error. ",'s','n',10);
            break;
        }
    }while(exitConfirm=='n');

    return 0;
}
