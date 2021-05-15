#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    int codigo;
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono[21];
    int isEmpty;
}eCliente;

#endif // CLIENTE_H_INCLUDED

int altaCliente(eCliente aClientes[], int tamCli, int* pId);

int buscarLibreCliente(eCliente aClientes[], int tamCli);

int inicializarArrayClientes(eCliente aClientes[], int tamCli);

int mostrarClientes(eCliente aClientes[], int tamCli);

void mostrarClienteUnico(eCliente unCliente);

int modificarUnCliente(eCliente aClientes[], int tamCli);

int ordenarClientesPorNombreYApellido(eCliente aClientes[], int tamCli);

int buscarUnCliente(eCliente aClientes[], int tamCli);
