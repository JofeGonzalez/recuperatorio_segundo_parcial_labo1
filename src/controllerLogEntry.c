#include <stdio.h>
#include <stdlib.h>
#include "controllerLogEntry.h"
#include "LinkedList.h"
#include "LogEntry.h"
#include "parser.h"
#include "utn.h"

int controller_loadFromText(char *path, LinkedList *pArrayList) {
	int r = 0;
	FILE *pFile = NULL;
	if (pArrayList != NULL && path != NULL) {
		pFile = fopen(path, "r");
		if (pFile != NULL) {
			r = parser_FromText(pFile, pArrayList);
			if (r == 0) {
				printf("Archivo leido con exito\n");
			} else {
				printf("Error al leer el archivo\n");
				fclose(pFile);
			}
		} else {
			printf("Error. El archivo no pudo ser leido\n");
		}
	}
	return r;
}

int controller_saveAsText(char *path, LinkedList *pArrayList) {
	FILE *newFile;
	LogEntry *auxLogEntry = NULL;
	char date[11];
	char time[6];
	char serviceName[65];
	int gravedad;
	char msg[65];

	if (path != NULL && pArrayList != NULL) {
		newFile = fopen(path, "w+");
			LogEntry_getDate(auxLogEntry, date);
			LogEntry_getTime(auxLogEntry, time);
			LogEntry_getServiceName(auxLogEntry, serviceName);
			LogEntry_getGravedad(auxLogEntry, &gravedad);
			LogEntry_getMsg(auxLogEntry, msg);
			fprintf(newFile, "%s;%s;%s;%d;%s\n", date, time, serviceName,
					gravedad, msg);
		fclose(newFile);
	}
	return 1;
}

int controller_ListLogEntry(LinkedList *pArrayList) {
	if (pArrayList != NULL) {
		printf("Fecha        Hora         Servicio       Gravedad   Mensaje\n");
		ll_filter(pArrayList, printLogEntry);
	}

	return 0;
}

int controller_LogEntryProcess(LinkedList *pArrayList) {
	int i = 0;
	LogEntry *auxLog;
	FILE *newFile;
	FILE *newFile2;
	char date[11];
	char time[6];
	char serviceName[65];
	int gravedad;
	char msg[65];
	newFile = fopen("warnings.txt", "w+");
	newFile2 = fopen("errors.txt", "w+");

	if (pArrayList != NULL) {
		for (i = 0; i < ll_len(pArrayList); i++) {
			auxLog = (LogEntry*) ll_get(pArrayList, i);
			if (auxLog->gravedad > 3 && auxLog->gravedad < 8) {
				printf("%s   %s   %s   %d   %s \n", auxLog->date, auxLog->time,
						auxLog->serviceName, auxLog->gravedad, auxLog->msg);
			} else {
				if(auxLog->gravedad == 3){
					LogEntry_getDate(auxLog, date);
					LogEntry_getTime(auxLog, time);
					LogEntry_getServiceName(auxLog, serviceName);
					LogEntry_getGravedad(auxLog, &gravedad);
					LogEntry_getMsg(auxLog, msg);
					fprintf(newFile, "%s;%s;%s;%d;%s\n", date, time, serviceName,
							gravedad, msg);
				} else {
					if(auxLog->gravedad > 7){
						LogEntry_getDate(auxLog, date);
						LogEntry_getTime(auxLog, time);
						LogEntry_getServiceName(auxLog, serviceName);
						LogEntry_getGravedad(auxLog, &gravedad);
						LogEntry_getMsg(auxLog, msg);
						fprintf(newFile2, "%s;%s;%s;%d;%s\n", date, time, serviceName,
								gravedad, msg);
					}
				}
			}
		}
	}
	fclose(newFile);
	fclose(newFile2);
	return 0;
}

int controller_EstadisticsLogEntry(LinkedList *pArrayList) {
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	if (pArrayList != NULL) {
		i = ll_count(pArrayList, EstadisticsLogEntryLessThanThree);
		j = ll_count(pArrayList, EstadisticsLogEntryThree);
		k = ll_count(pArrayList, EstadisticsLogEntryMoreThanThree);
		l = ll_count(pArrayList, EstadisticsLogEntryMoreThanSeven);
		printf("La cantidad de errores segun su gravedad son:\n"
				"1. Menores a 3: %d\n"
				"2. Iguales a 3: %d\n"
				"3. Entre 4 y 7: %d\n"
				"4. Mayores a 7: %d\n", i, j, k, l);
	}
	return 0;
}

