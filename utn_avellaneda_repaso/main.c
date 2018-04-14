#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

/*
id de producto
descripcion
stock
precio unitario

*/

int buscarLibre(int [], int);
float calcularPromedio(int, int);
void mostrarProductos(int[], char[][50], int[], int[], int); // MATRIZ PASAR LAS CANTIDAD DE COLUMAS
int cargarProducto(int[], char[][50], int[], int[], int);
int modificarProducto(int [], int, int);
int BuscarProducto(int [], int, int);


int main()
{
    /*
id de producto
descripcion
stock
precio unitario

*/

    int idProducto[TAM]= {10,11,12};
    char descripcionProducto[TAM][50] = {"galletitas", "cafe", "yerbamate"};
    int stockProducto[TAM] = {10,8,9};
    int precioUnitario[TAM]= {7,6,9};
    /*float promedio[TAM] = {8.5, 7, 9};*/
    int opcion;
    int index;
    int modificar;
    int dato;
    int posicion;
    int len;


    do
    {
        printf("1. ALTAS DE PRODUCTO\n2. MOSTRAR PRODUCTOS\n3. MODIFICAR PRODUCTOS\n4. BAJA DE PRODUCTO\n9. SALIR\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            index= cargarProducto(idProducto, descripcionProducto, stockProducto, precioUnitario, TAM);
            if(index == -1)
            {
            printf("no hay lugar!!!\n");
            }else
            {
             printf("Se ingreso el Producto\n");
            }

            break;
        case 2:

        mostrarProductos(idProducto, descripcionProducto, stockProducto, precioUnitario, TAM);
        break;


        case 3:
        //Buscar producto por nro de id
        printf("Buscar producto por ID:\n");
        scanf("%d", &dato);

        posicion = BuscarProducto(idProducto, dato, TAM);

        while(posicion == -1)
        {
            printf("Producto no encontrado, reingresar:\n");
            fflush(stdin);
            scanf("%d", &dato);
            posicion = BuscarProducto(idProducto, dato, TAM);

        }

        printf("Modificar:\n1-Id del Producto\n2-Descripcion(no disp)\n3-Stock del Producto\n4-Precio Unitario\nElija campo a modificar: ");
        scanf("%d", &modificar);

        //campo a modificar
         switch(modificar)
         {
              case 1:
                //legajo
                printf("Modificar ID  de Producto\n: ");
                scanf("%d", &idProducto[posicion]);
                break;
            case 2:
               //

                printf("Modificar descripcion de Producto de\n: ");
                fflush(stdin);
                gets(descripcionProducto[posicion]);
                break;
            case 3:
                //Nota1
                printf("Modificar Stock de producto de\n: ");
                scanf("%d", &stockProducto[posicion]);
                /*promedio[posicion] = calcularPromedio(stockProducto[posicion], precioUnitario[posicion]);*/
                break;

            case 4:
                //Nota2
                printf("Modificar precio Unitario de\n: ");
                scanf("%d", &precioUnitario[posicion]);
                /*promedio[posicion] = calcularPromedio(stockProducto[posicion], precioUnitario[posicion]);*/
                break;


         }
           break;


            case 4:
                //baja
                //Buscar producto por nro de idProducto
                printf("Buscar producto por ID");
                scanf("%d", &dato);

                posicion = BuscarProducto(idProducto, dato, TAM);

                idProducto[posicion] = 0;
                len = strlen(descripcionProducto[posicion]);
                for (int i=0; i<len; i++)
                {
                    descripcionProducto[posicion][i] = 0;
                }
                stockProducto[posicion] = 0;
                precioUnitario[posicion] = 0;
                /*promedio[posicion] = 0;*/
                break;
        }


    printf("\n\n");
    system("pause");
    system("cls");

    }
    while(opcion!=9);




    return 0;
}

int buscarLibre(int idProducto[], int tamano)
{

    int index = -1;
    int i;


    for(i=0; i<tamano; i++)
    {
        if (idProducto[i] == 0)
        {
            index = i;
            break;
        }

    }
    return index;
}


void mostrarProductos(int idProducto[], char descripcionProducto[][50], int stockProducto[], int precioUnitario[], int tam)
{


     for(int i=0; i<tam; i++)
            {
                if(idProducto[i] != 0)
                {
                     printf("ID: %d Descripcion: %s Stock: %d Precio: $%d\n", idProducto[i], descripcionProducto[i], stockProducto[i], precioUnitario[i]);
                }

            }


}


int cargarProducto(int idProducto[], char descripcionProducto[][50], int stockProducto[], int precioUnitario[]/*, float promedio[]*/, int tam)
{


           int index;

           index = buscarLibre(idProducto, tam);
            if(index !=-1)
            {

            printf("Ingrese Id del producto: ");
            scanf("%d", &idProducto[index]);


            printf("Ingrese Descripcion del producto: ");
            fflush(stdin);
            gets(descripcionProducto[index]);

            printf("Ingrese stock Producto: ");
            scanf("%d", &stockProducto[index]);

            printf("Ingrese precio Unitario: ");
            scanf("%d", &precioUnitario[index]);

            }
            return index;

}

int BuscarProducto(int vector[], int dato, int tam)
{
     int i;
     int posicion = -1;

     for(i=0; i<tam; i++)
            {
                if(vector[i] == dato)
                {

                   posicion = i;

                }

            }

            return posicion;
}

int modificarProducto(int vector[], int dato, int tam)
{
     int i;

     for(i=0; i<tam; i++)
            {
                if(vector[i] == dato)
                {

                    printf("Ingresar nuevo dato: ");
                    fflush(stdin);
                    scanf("%d", &vector[i]);
                    break;
                }
            }

            return vector[i];
}
