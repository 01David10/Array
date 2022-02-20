# include <iostream>
# include <string.h>

using namespace std;

// programa que llena un vector y lo muestra

/*
    Vector[]:       vector de edades
    Cant_F:         cantidad de filas o tamaño    
    Indice_F:       indice o numero de fila
    Estado:         variable bandera para el buscar
    Vr_Buscar:      valor a buscar
    Indice_F2:      indice de la fila siguiente (para ordenar)
    Aux:            valor auxiliar para no borrar datos en ordenar
    Vr_Borrar:      valor a borrar
    Vr_Insertar:    valor a insertar
*/

// parametrizacion
void LLENAR (short[], short);
void MOSTRAR (short[], short);
short BUSCAR_S (short[], short, short);
void ORDENAR_B (short[], short);
void INSERTAR (short[], short &);
void BORRAR (short[], short &, short);

// programa principal
int main ()
{
    // variables
    short Vector[100], Cant_F, Estado, Vr_Buscar, Vr_Borrar;

    cout << "Ingrese el número de estudiantes (maximo 100) "; 
    cin >> Cant_F;

    LLENAR (Vector, Cant_F);

    MOSTRAR (Vector, Cant_F);

    cout << "Ingrese el valor a Buscar en el arreglo ";
    cin >> Vr_Buscar;

    Estado = BUSCAR_S (Vector, Cant_F, Vr_Buscar);

    if (Estado == -1) 
    {
        cout << "EL valor no fue encontrado";
    }
    else
    { 
        cout << "EL valor fue encontrado en la posición " << Estado << endl;
    }

    ORDENAR_B (Vector, Cant_F);

    INSERTAR (Vector, Cant_F);

    cout << "Ingrese el valor que desea borrar en el arreglo ";
    cin >> Vr_Borrar;

    BORRAR (Vector, Cant_F, Vr_Borrar);

    return EXIT_SUCCESS;
}

// procedimiento para llenar
void LLENAR (short Vect[], short CantF)
{
    // variables
    short Indice_F;

    for (Indice_F = 1; Indice_F <= CantF; Indice_F ++)
    {
        cout << "Ingrese la Edad ";
        cin >> Vect [Indice_F]; 
    }
}

// procedimiento para mostrar
void MOSTRAR (short Vect[], short CantF)
{
    // variables
    short Indice_F;

    for (Indice_F = 1; Indice_F <= CantF; Indice_F ++)
    {
        cout << Vect [Indice_F] << endl;
    }
}

// funcion para busqueda secuencial
short BUSCAR_S (short Vect[], short CantF, short VrBuscar)
{
    // variables
    short Indice_F;

    Indice_F = 1;

    while (Indice_F <= CantF && VrBuscar != Vect [Indice_F])
    {
        Indice_F = Indice_F + 1;
    }

    if (Indice_F <= CantF)
    {
        return (Indice_F);
    }
    else
    {
        return -1;
    }
}

// procedimiento para ordenar (metodo burbuja)
void ORDENAR_B (short Vect[], short CantF)
{
    // variables
    short Indice_F, Indice_F2, Aux;

    for (Indice_F = 1; Indice_F <= CantF; Indice_F ++)
    {
        for (Indice_F2 = 1; Indice_F2 <= CantF-1; Indice_F2 ++)
        {
            if (Vect [Indice_F2] > Vect [Indice_F2+1])  
            {
                Aux = Vect [Indice_F2];
                Vect [Indice_F2] = Vect [Indice_F2+1];
                Vect [Indice_F2+1] = Aux;
            }
        }
    }
    // esta parte de mostrar es opcional
    MOSTRAR (Vect, CantF);
}

// procedimiento para insertar
void INSERTAR (short Vect[], short &CantF)
{
    // variables
    short Vr_Insertar;

    cout << "ingresa el valor que desea insertar ";
    cin >> Vr_Insertar;

    CantF = CantF + 1;
    Vect [CantF] = Vr_Insertar;

    // esta parte de mostrar es opcional
    MOSTRAR (Vect, CantF);
}

// procedimiento para borrar
void BORRAR (short Vect[], short &CantF, short VrBorrar)
{
    // variables
    short Indice_F, Indice_F2;

    Indice_F = 1;

    while (Indice_F <= CantF && VrBorrar != Vect [Indice_F])
    {
        Indice_F = Indice_F + 1;
    }
    
    if (Indice_F <= CantF)
    {
        for (Indice_F2 = Indice_F; Indice_F2 <= CantF-1; Indice_F2 ++)
        {
            Vect [Indice_F2] = Vect [Indice_F2+1];
        }
        CantF = CantF - 1;
    }
    else
    {
        cout << VrBorrar << " No esta en el arreglo";
    }
    // esta parte de mostrar es opcional
    MOSTRAR (Vect, CantF);
}