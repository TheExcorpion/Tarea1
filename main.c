#include "tdas/list.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct tipoPaciente {
  int prioridad;
  char nombre[MAX];
  int edad;
  char sintoma[MAX];
  time_t hora;
} tipoPaciente;

int totalPacientes = 0;

// Función para limpiar la pantall
void limpiarPantalla() { system("clear"); }

void strMay(char *cadena) {
  int i = 0;
  while (cadena[i] != '\0') {
    cadena[i] = toupper(cadena[i]);
    i++;
  }
}

void presioneTeclaParaContinuar() {
  puts("Presione una tecla para continuar...");
  getchar(); // Consume el '\n' del buffer de entrada
  getchar(); // Espera a que el usuario presione una tecla
}

// Menú principal
void mostrarMenuPrincipal() {
  limpiarPantalla();
  puts("========================================");
  puts("     Sistema de Gestión Hospitalaria");
  puts("========================================");

  puts("1) Registrar paciente");
  puts("2) Asignar prioridad a paciente");
  puts("3) Mostrar lista de espera");
  puts("4) Atender al siguiente paciente");
  puts("5) Mostrar pacientes por prioridad");
  puts("6) Salir");
}

void registrar_paciente(List *pacientes)
{
  printf("\nRegistrar nuevo paciente \n");
  tipoPaciente *paciente = malloc(sizeof(tipoPaciente));
  if (paciente == NULL)
  {
    printf("ERROR DE MEMORIA");
    return;
  }
  
  printf("Ingresa el nombre del paciente: \n");
  getchar();
  char nombreIngresado[MAX];
  scanf(" %[^\n]", nombreIngresado);
  strMay(nombreIngresado);

  bool encontPaciente = false;
  tipoPaciente *pacienteActual = list_first(listaPacientes);
  while (pacienteActual != NULL && !encontPaciente) 
  {
    if (strcmp(pacienteActual->nombre, nombreIngresado) == 0)
    {
      puts("El paciente ya se encuentra registrado");
      encontPaciente = true;
      return;
    } else
      pacienteActual = list_next(listaPacientes);
  }
  
}

void mostrar_lista_pacientes(List *pacientes) {
  // Mostrar pacientes en la cola de espera
  printf("Pacientes en espera: \n");
  // Aquí implementarías la lógica para recorrer y mostrar los pacientes
}

int main() {
  char opcion;
  List *pacientes =
      list_create(); // puedes usar una lista para gestionar los pacientes

  do {
    mostrarMenuPrincipal();
    printf("Ingrese su opción: ");
    scanf(" %c", &opcion); // Nota el espacio antes de %c para consumir el
                           // newline anterior

    switch (opcion) {
    case '1':
      registrar_paciente(pacientes);
      break;
    case '2':
      // Lógica para asignar prioridad
      break;
    case '3':
      mostrar_lista_pacientes(pacientes);
      break;
    case '4':
      // Lógica para atender al siguiente paciente
      break;
    case '5':
      // Lógica para mostrar pacientes por prioridad
      break;
    case '6':
      puts("Saliendo del sistema de gestión hospitalaria...");
      break;
    default:
      puts("Opción no válida. Por favor, intente de nuevo.");
    }
    presioneTeclaParaContinuar();

  } while (opcion != '6');

  // Liberar recursos, si es necesario
  list_clean(pacientes);

  return 0;
}