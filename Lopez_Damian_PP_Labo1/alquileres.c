#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dam.h"
#include "alquileres.h"
#include "cliente.h"
#include "juego.h"
#include "categoria.h"

int buscarLibreAlquiler(eAlquiler aAlquileres[], int tamAlq)
{
    int indice=-1;
    if(aAlquileres!=NULL && tamAlq>0)
    {
        for(int i=0; i<tamAlq; i++)
        {
            if(aAlquileres[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int altaAlquiler(eAlquiler aAlquileres[], int tamAlq,
                 eCliente aClientes[], int tamCli,
                 eJuego aJuegos[], int tamJue,
                 eCategoria aCategorias[], int tamCat,
                 int* pIdAlquiler)
{
    int retorno=-1;
    int indice;
    int codigo;
    int idJuego;
    int index=-1;
    eAlquiler nuevoAlquiler;
    if(aAlquileres!=NULL && tamAlq>0 && pIdAlquiler!=NULL)
    {
        system("cls");
        printf("      Alta Almuerzo\n\n");
        printf("ID Almuerzo: %d\n",*pIdAlquiler);
        indice = buscarLibreAlquiler(aAlquileres,tamAlq); /*HACER*/

        if(indice!=-1)
        {
            /**ASIGNO ID Alquiler*/
            nuevoAlquiler.codigoAlq = *pIdAlquiler;

            mostrarClientes(aClientes, tamCli);
            dam_getNumero(&codigo,"Ingrese codigo del cliente: ","ERROR. ", 20000,30000,0);
            index=buscarUnCliente(aClientes,tamCli);
            while(index==-1)
            {
                printf("No es un cliente valido...\n");
                index=buscarUnCliente(aClientes,tamCli);
            }
            /**ASIGNO codigo Cliente*/
            nuevoAlquiler.codigoCliente=aClientes[index].codigo;
            printf("\n");

            mostrarJuegos(aJuegos,tamJue,aCategorias,tamCat);

            dam_getNumero(&idJuego,"Ingrese ID del juego: ","ERROR. ", 1,50000,0);
            while(buscarUnJuego(aJuegos,tamJue,idJuego)==-1)
            {
                printf("No es una comida valida...\n");
                dam_getNumero(&idJuego,"Reingrese ID: ","ERROR. ", 1,5000,0);
            }
            /**ASIGNO ID Juego*/
            nuevoAlquiler.codigoJuego=idJuego;

            /**ASIGNO Fecha*/
            dam_getNumero(&nuevoAlquiler.fecha.dia,"Ingrese dia (1-31): ","ERROR. ",1,31,10);
            dam_getNumero(&nuevoAlquiler.fecha.mes,"Ingrese mes (1-12): ","ERROR. ",1,12,10);
            dam_getNumero(&nuevoAlquiler.fecha.anio,"Ingrese anio (1999-2021): ","ERROR. ",1999,2021,10);

            /**ASIGNO 0 a isEmpty*/
            nuevoAlquiler.isEmpty=0;

            /**Copio los valores de la variable auxiliar al vector de alquileres*/
            aAlquileres[indice]=nuevoAlquiler;
            (*pIdAlquiler)++;
            retorno=0;
        }
        else
        {
            printf("No hay lugar para cargar mas alquileres.\n");
        }
    }
    return retorno;
}

int bajaCliente(eCliente aClientes[], int tamCli, eAlquiler aAlquileres[], int tamAlq)
{
    int retorno=-1;
    char confirm='n';
    int indice;

    system("cls");
    printf("     Baja Cliente\n\n");
    if(aClientes!=NULL && tamCli>0)
    {
        mostrarClientes(aClientes,tamCli);
        indice=buscarUnCliente(aClientes, tamCli);
        if(indice==-1)
        {
            printf("No se encontro ningun cliente con ese legajo.\n");
        }
        else
        {
            printf("Cliente encontrado:\n");
            printf("Codigo     Nombre      Apellido    Sexo   Telefono\n");
            mostrarClienteUnico(aClientes[indice]);
            if(!dam_getCaracter(&confirm,"Seguro desea dar de baja a este cliente? (s/n): ", "ERROR.\n",'s','n',10) && confirm=='s')
            {
                aClientes[indice].isEmpty=1;
                bajaAlquiler(aAlquileres, tamAlq, aClientes[indice].codigo);
                retorno = 0;
            }
            else
            {
                printf("Baja cancelada.\n");
            }
        }
    }

    return retorno;
}

int bajaAlquiler(eAlquiler aAlquileres[], int tamAlq, int codCliente)
{
    int cant=0;
    if(aAlquileres!=NULL && tamAlq>0)
    {
        for(int i=0; i<tamAlq; i++)
        {
            if(!aAlquileres[i].isEmpty && aAlquileres[i].codigoCliente==codCliente)
            {
                aAlquileres[i].isEmpty=1;
                cant++;
            }
        }
    }


    return cant;
}
