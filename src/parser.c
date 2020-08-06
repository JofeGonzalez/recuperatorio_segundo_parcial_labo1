#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "LogEntry.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_FromText(FILE *pFile, LinkedList *pArrayList) {
	int ret = -1;
	char date[11];
	char time[6];
	char serviceName[65];
	char gravedad[4];
	char msg[65];
	LogEntry *nLogEntry = NULL;

	while (feof(pFile) == 0) {
		if (fscanf(pFile, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n", date, time,
				serviceName, gravedad, msg) == 5) {
			nLogEntry = LogEntry_newParametros(date, time, serviceName,
					gravedad, msg);
			if (nLogEntry != NULL) {
				ll_add(pArrayList,nLogEntry);
				ret = 0;
			}
		}
	}
	return ret;
}
