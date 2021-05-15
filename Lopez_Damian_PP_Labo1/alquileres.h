#include "fecha.h"
#include "cliente.h"
#include "juego.h"
#include "categoria.h"

#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

typedef struct{
    int codigoAlq;
    int codigoJuego;
    int codigoCliente;
    eFecha fecha;
    int isEmpty;
}eAlquiler;

#endif // ALQUILERES_H_INCLUDED

int altaAlquiler(eAlquiler aAlquileres[], int tamAlq,
                 eCliente aClientes[], int tamCli,
                 eJuego aJuegos[], int tamJue,
                 eCategoria aCategorias[], int tamCat,
                 int* pIdAlquiler);

int bajaCliente(eCliente aClientes[], int tamCli, eAlquiler aAlquileres[], int tamAlq);
