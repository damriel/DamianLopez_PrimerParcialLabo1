#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "dam.h"

int inicializarArrayClientes(eCliente aClientes[], int tamCli)
{
    int retorno=-1;
    if(aClientes!=NULL && tamCli>0)
    {
        retorno=0;
        for(int i=0; i<tamCli; i++)
        {
            aClientes[i].isEmpty=1;
        }
    }
    return retorno;
}

int altaCliente(eCliente aClientes[], int tamCli, int* pId)
{
    int retorno=-1;
    int indice;
    eCliente nuevoCliente;

    if(aClientes!=NULL && tamCli>0)
    {
        system("cls");
        printf("      Alta Cliente\n\n");
        indice = buscarLibreCliente(aClientes,tamCli);
        if(indice!=-1)
        {
            printf("Codigo: %d\n",*pId);
            if(!dam_getNombre(nuevoCliente.nombre,"Ingrese nombre: ","Error.\n",51,10)&&
               !dam_getNombre(nuevoCliente.apellido,"Ingrese apellido: ","Error.\n",51,10)&&
               !dam_getCaracter(&nuevoCliente.sexo,"Ingrese sexo: ","Error.\n",'f','m',10)&&
               !dam_getTextoEspecial(nuevoCliente.telefono,"Ingrese telefono: ","Error.\n",21,10))
            {
                aClientes[indice]=nuevoCliente;
                aClientes[indice].isEmpty=0;
                aClientes[indice].codigo = *pId;
                (*pId)++;
                retorno=0;
            }
            else
            {
                printf("Error, no se pudo dar de alta al cliente.");
            }
        }
        else
        {
            printf("No hay lugar para cargar mas clientes.\n");
        }
    }
    return retorno;
}

int buscarLibreCliente(eCliente aClientes[], int tamCli)
{
    int indice=-1;
    if(aClientes!=NULL && tamCli>0)
    {
        for(int i=0; i<tamCli; i++)
        {
            if(aClientes[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int buscarUnCliente(eCliente aClientes[], int tamCli)
{
    int indice=-1;
    int codigoBuscado;
    if(aClientes!=NULL && tamCli>0 &&
       !dam_getNumero(&codigoBuscado,"\n\nIngrese el legajo del empleado: ","ERROR. Legajo no valido.\n",1,999999,10))
    {
        for(int i=0; i<tamCli; i++)
        {
            if(codigoBuscado==aClientes[i].codigo && !aClientes[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

void mostrarClienteUnico(eCliente unCliente)
{
    printf("%5d   %10s    %10s    %c    %10s\n",unCliente.codigo,
                                                unCliente.nombre,
                                                unCliente.apellido,
                                                unCliente.sexo,
                                                unCliente.telefono);
}

int mostrarClientes(eCliente aClientes[], int tamCli)
{
    int retorno=-1;
    int flag=0;
    if(aClientes!=NULL && tamCli>0)
    {
        retorno=0;
        for(int i=0; i<tamCli; i++)
        {
            if(aClientes[i].isEmpty==0)
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            printf("      LISTA DE CLIENTES\n");
            printf("Codigo     Nombre      Apellido    Sexo   Telefono\n");
        }
        else
        {
            printf("NO HAY EMPLEADOS CARGADOS POR EL MOMENTO...\n");
        }
        for(int i=0; i<tamCli; i++)
        {
            if(!aClientes[i].isEmpty)
            {
                mostrarClienteUnico(aClientes[i]);
            }
        }
    }
    return retorno;
}

int modificarUnCliente(eCliente aClientes[], int tamCli)
{
    int retorno=-1;
    int indice;
    int opcion;
    eCliente auxCliente;
    int flagNombre=1;
    int flagApellido=1;
    int flagTelefono=1;

    if(aClientes!=NULL && tamCli>0)
    {
        mostrarClientes(aClientes,tamCli);
        indice = buscarUnCliente(aClientes,tamCli);
        if(indice==-1)
        {
            printf("No se encontro ningun cliente con ese codigo.\n");
        }
        else
        {
            printf("Cliente encontrado:\n");
            printf("Codigo     Nombre      Apellido    Sexo   Telefono\n");
            mostrarClienteUnico(aClientes[indice]);

            do{
                opcion=menuModificaciones();
                switch(opcion)
                {
                case 1:
                    flagNombre = dam_getNombre(auxCliente.nombre,"Ingrese nuevo nombre: ","Error. ",51,10);
                    break;
                case 2:
                    flagApellido = dam_getNombre(auxCliente.apellido,"Ingrese nuevo apellido: ","Error. ",51,10);
                    break;
                case 3:
                    flagTelefono = dam_getTextoEspecial(auxCliente.telefono,"Ingrese nuevo telefono: ","Error. ",21,10);
                    break;
                case 4:
                    if(!flagNombre)
                    {
                        strcpy(aClientes[indice].nombre,auxCliente.nombre);
                    }
                    if(!flagApellido)
                    {
                        strcpy(aClientes[indice].apellido,auxCliente.apellido);
                    }
                    if(!flagTelefono)
                    {
                        strcpy(aClientes[indice].telefono,auxCliente.telefono);
                    }
                    printf("\nCliente modificado!\n");
                    mostrarClienteUnico(aClientes[indice]);
                    printf("\nCambios guardados, volviendo al menu principal...\n\n");
                    retorno=0;
                    break;
                case 5:
                    printf("Cambios descartados, volviendo al menu principal...\n\n");
                    break;
                }
            }while(opcion!=4 && opcion!=5);
        }
    }
    return retorno;
}

int ordenarClientesPorNombreYApellido(eCliente aClientes[], int tamCli)
{
    int retorno=-1;
    eCliente auxCliente;
    if(aClientes!=NULL && tamCli>0)
    {
        retorno=0;
        for(int i=0; i<tamCli-1 && !aClientes[i].isEmpty; i++)
        {
            for(int j=i+1; j<tamCli && !aClientes[j].isEmpty; j++)
            {
                 if(strcmp(aClientes[i].nombre, aClientes[j].nombre)>0 || (strcmp(aClientes[i].nombre, aClientes[j].nombre)==0 && strcmp(aClientes[i].apellido, aClientes[j].apellido)>0))
                {
                    auxCliente = aClientes[i];
                    aClientes[i] = aClientes[j];
                    aClientes[j] = auxCliente;
                }
            }
        }
    }
    return retorno;
}
