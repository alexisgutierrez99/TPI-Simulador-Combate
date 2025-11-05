/*
*Simulador de Combate con Modo Inteligente
Objetivo: Combate por turnos entre jugador y enemigo.
Requisitos:
● Personajes con atributos: vida, energía, ataque, defensa.
● Funciones: atacar, defender, curarse.
● Enemigo con modo inteligente: decide acción según reglas simples:
○ Vida baja → curar
○ Energía baja → defender
○ Jugador débil → atacar
● Registrar historial de turnos.
● Modularización: main, combate, decisiones.
● Validación de entradas y estados de personajes
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

typedef struct 
{
    char *nombre;
    int vida_max;
    int vida_actual;
    int ataque;
    int defensa;
    int energia_max;
    int energia_actual;
    int pocion;
}personaje_t;

/*Procedimiento encargado de mostrar como seleccionar las opciones de jugarador y dar una
* breve introducción
*/

void introduccion(void);

/*Funcion encargada de realizar todas las opciones del turno del jugador
*
@parámetro principal: puntero hacia la estructura con todos los datos del personaje protagonista
*
@paramétro enemigo: puntero hacia la estructura con los datos del enemigo actual
*/

void turno_jugador (personaje_t* principal, personaje_t* enemigo);

/*Funcion encargada de realizar todas las opciones del turno del enemigo
*
@paramétro enemigo: puntero hacia la estructura con los datos del enemigo actual
*
@parámetro principal: puntero hacia la estructura con todos los datos del personaje protagonista
*/

void turno_enemigo (personaje_t* enemigo, personaje_t* principal);

//void escribir_lentamente(const char *cadena, int pausa);

int main (int argc, char* argv[])
{

    personaje_t *principal = NULL;
    personaje_t *enemigo_1 = NULL;

    principal = (personaje_t *)malloc(sizeof(personaje_t));
    enemigo_1 = (personaje_t *)malloc(sizeof(personaje_t));

    if (principal != NULL)
    {
        principal->nombre = strdup("Caballero");
        principal->ataque = 20;
        principal->defensa = 50;
        principal->vida_max = 100;
        principal->vida_actual = 100;
        principal->energia_max = 100;
        principal->energia_actual = 100;
        principal->pocion = 3;
    }
    
    if (enemigo_1 != NULL)
    {
        enemigo_1->nombre = strdup("Orco común");
        enemigo_1->ataque = 8;
        enemigo_1->defensa = 35;
        enemigo_1->vida_max = 70;
        enemigo_1->vida_actual = 70;
        enemigo_1->energia_max = 70;
        enemigo_1->energia_actual = 70;
        enemigo_1->pocion = 2;
    }

    introduccion();

    while ((principal->vida_actual > 0) && (enemigo_1->vida_actual > 0))
    {
        turno_jugador(principal, enemigo_1);
        
        system ("cls");

        turno_enemigo(enemigo_1, principal);

        system("cls");
    }

    if (principal->vida_actual <= 0)
    {
        printf("Haz muerto\n");
        Sleep(2000);
        fflush(stdout);
        system("cls");
    }
    else
    {
        printf("Lograste derrotar al enemigo\n");
        Sleep(2000);
        fflush(stdout);
        system("cls");

        printf("Eres libre de continuar tu aventura\n");
        Sleep(2000);
        fflush(stdout);
        system("cls");
    }

    free (principal->nombre);
    free (principal);

    free (enemigo_1->nombre);
    free (enemigo_1);

    return EXIT_SUCCESS;
}

void introduccion(void)
{
    /*escribir_lentamente("BIENVENIDO JUGADOR.", 40);

    escribir_lentamente("LAS OPCIONES SE MANEJARAN CON LOS NÚMEROS CORRESPONDIENTES A CADA OPCION", 40);
    
    system("cls");

    escribir_lentamente("Eres un viajero que recorre el mundo.", 40);

    escribir_lentamente("Al comenzar tu viaje compras 3 pociones(40 de curacion)", 40);

    escribir_lentamente("En tu viaje alrededor del mundo, te haz encontrado con un monstruo errante.", 40);

    escribir_lentamente("¡Es un orco!", 40);

    escribir_lentamente("¡Este te ataca inmediatamente!", 50);*/

    printf("BIENVENIDO JUGADOR\n");
    Sleep(2000);
    fflush(stdout);
    system("cls");

    printf("LAS OPCIONES SE MANEJARAN CON LOS NÚMEROS CORRESPONDIENTES A CADA OPCION\n");
    Sleep(2000);
    fflush(stdout);
    system("cls");

    printf("Eres un viajero que recorre el mundo.\n");
    Sleep(2000);
    fflush(stdout);
    system("cls");

    printf("Al comenzar tu viaje compras 3 pociones(40 de curacion)\n");
    Sleep(2000);
    fflush(stdout);
    system("cls");

    printf("En tu viaje alrededor del mundo, te haz encontrado con un monstruo errante.\n");
    Sleep(2000);
    fflush(stdout);
    system("cls");

    printf("¡Es un orco!\n");
    Sleep(2000);
    fflush(stdout);
    system("cls");

    printf("¡Este te ataca inmediatamente!\n");
    Sleep(2000);
    fflush(stdout);
    system("cls");

    return;
}

void turno_jugador (personaje_t* principal, personaje_t* enemigo)
{
    int opciones_pelea = 0;

    while ((opciones_pelea != 1) && (opciones_pelea != 2) && (opciones_pelea != 3))
    {
        printf("1-Atacar ..... 2- Ataque fuerte(40 energia)\n 3- Usar poción\n");

        printf("---------------------------------------------\n");

        printf("[ %s ] Vida: %d/%d | Energía: %d/%d\n", principal->nombre, principal->vida_actual,
                            principal->vida_max, principal->energia_actual, principal->energia_max);

        printf("[ %s ] Vida: %d/%d | Energía: %d/%d\n", enemigo->nombre, enemigo->vida_actual,
                            enemigo->vida_max, enemigo->energia_actual, enemigo->energia_max);

        printf("---------------------------------------------\n");

        scanf("%d", &opciones_pelea);

        system("cls");

        switch (opciones_pelea)
        {
            case 1:
                enemigo->vida_actual = enemigo->vida_actual - principal->ataque;
            
                printf("¡%s a recibido %d daño!\n", enemigo->nombre, principal->ataque);
                fflush(stdout);

                Sleep(2500);
                break;

            case 2:
                if (principal->energia_actual >= 40)
                {
                    enemigo->vida_actual = enemigo->vida_actual - (principal->ataque * 2);

                    printf("¡%s a recibido %d daño!\n", enemigo->nombre, (principal->ataque * 2));
                    fflush(stdout);

                    Sleep(2500);
                }
                else 
                {
                    printf("Cantidad de energía insuficiente\n");
                }
        
            case 3:
                if (principal->pocion > 0)
                {
                    if (principal->vida_actual > 70)
                    {
                        principal->vida_actual = 100;
                        printf("Te haz curado toda la vida\n");
                    }
                    else
                    {
                        principal->vida_actual = principal->vida_actual + 30;
                        printf("Te haz curado 30 de vida\n");
                        Sleep(2500);

                        system("cls");
                    }
                    principal->pocion = principal->pocion - 1;
                }
                else
                {
                    printf("No tienes mas pociones.\n");
                    Sleep(1000);
                    printf("Turno perdido\n");
                    Sleep(2500);

                    system("cls");
                }

                default:
                    printf("Opción ingresada inválida. \n");
                    Sleep(2500);

                    system("cls");
        }
    }
}

void turno_enemigo (personaje_t* enemigo, personaje_t* principal)
{
    if (enemigo->vida_actual <= 0)
    {
        return;
    }
    else
    {
        if (enemigo->vida_actual <= (enemigo->vida_max / 5))
        {
            if (enemigo->pocion > 0)
            {
                if (enemigo->vida_actual >= (enemigo->vida_max - 20))
                {
                    printf("%s se curo toda la vida", enemigo->nombre);
                    fflush(stdout);

                    Sleep(2500);

                    enemigo->vida_actual = enemigo->vida_max;
                }
                else
                {
                    printf("¡%s se acaba de curar 20 de vida!\n", enemigo->nombre);
                    fflush(stdout);

                    Sleep(2500);
                
                    enemigo->vida_actual = enemigo->vida_actual + 20;
                }
                enemigo->pocion = enemigo->pocion - 1;
            }
            else
            {
                printf("¡%s no pudo curarse y ataca agotado\n", enemigo->nombre);
                fflush(stdout);

                Sleep(2500);

                principal->vida_actual = principal->vida_actual - (enemigo->ataque / 2);

                printf("Recibes %d daño",((enemigo->ataque / 2)));
                fflush(stdout);

                Sleep(2500);
            }
        }
        else
        {
            printf("%s te ataca\n", enemigo->nombre);
            fflush(stdout);

            Sleep(2500);
            principal->vida_actual = principal->vida_actual - enemigo->ataque;

            printf("Recibes %d daño\n", enemigo->ataque);
            fflush(stdout);

            Sleep(2500);
        }

        system ("cls");
    }
}

/*void escribir_lentamente(const char *cadena, int pausa) 
{
    for (size_t i = 0; i < strlen(cadena); i++) {
        printf("%c", cadena[i]);
        fflush(stdout); 
        Sleep(pausa); 
    }
    printf("\n");

    Sleep(2000);

    system("cls");
}*/
