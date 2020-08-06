/*
 ============================================================================
 Name        : RecuperatorioSegundoParcial.c
 Author      : Jose Gonzalez
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "controllerLogEntry.h"
#include "LogEntry.h"

int main(void) {
	setbuf(stdout, NULL);
	int option = 0;
	LinkedList* logList = ll_newLinkedList();
	do {
		printf("1. Leer Log.\n"
				"2. Procesar Informacion.\n"
				"3. Mostrar estadisticas.\n"
				"4. Imprimir lista Logs.\n"
				"5. Salir. \n");
		if(!utn_getNumero(&option, "Ingrese la opcion deseada\n",
				"Error. Intente de nuevo\n", 1, 5, 3))
		switch(option){
		case 1:
			controller_loadFromText("log.txt", logList);
			break;
		case 2:
			controller_LogEntryProcess(logList);
			 break;
		case 3:
			controller_EstadisticsLogEntry(logList);
			 break;
		case 4:
			controller_ListLogEntry(logList);
			break;
		}
	} while (option != 5);
}
