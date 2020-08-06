#include "LogEntry.h"
#include "controllerLogEntry.h"
#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

LogEntry* LogEntry_new(void) {
	LogEntry *auxPointer = NULL;
	auxPointer = (LogEntry*) malloc(sizeof(LogEntry));
	return auxPointer;
}
LogEntry* LogEntry_newParametros(char *dateStr, char *timeStr,
		char *serviceName, char *gravedad, char *msgStr) {

	LogEntry *auxLogEntry = NULL;
	auxLogEntry = LogEntry_new();
	int auxGravedad;
	if (auxLogEntry != NULL) {
		LogEntry_setDate(auxLogEntry, dateStr);
		LogEntry_setTime(auxLogEntry, timeStr);
		LogEntry_setServiceName(auxLogEntry, serviceName);
		auxGravedad = atoi(gravedad);
		LogEntry_setGravedad(auxLogEntry, auxGravedad);
		LogEntry_setMsg(auxLogEntry, msgStr);
	} else {
		LogEntry_delete(auxLogEntry);
		auxLogEntry = NULL;
	}
	return auxLogEntry;
}

void LogEntry_delete(LogEntry *auxLogEntry) {
	if (auxLogEntry != NULL) {
		free(auxLogEntry);
	}
}

int LogEntry_setDate(LogEntry *this, char *date) {
	if (this != NULL && date != NULL) {
		strncpy(this->date, date, 11);
		return 0;
	}
	return -1;
}
int LogEntry_getDate(LogEntry *this, char *date) {
	if (this != NULL && date != NULL) {
		strncpy(date, this->date, 11);
		return 0;
	}
	return -1;
}

int LogEntry_setTime(LogEntry *this, char *time) {
	if (this != NULL && time != NULL) {
		strncpy(this->time, time, 6);
		return 0;
	}
	return -1;
}
int LogEntry_getTime(LogEntry *this, char *time) {
	if (this != NULL && time != NULL) {
		strncpy(time, this->time, 6);
		return 0;
	}
	return -1;
}

int LogEntry_setServiceName(LogEntry *this, char *serviceName) {
	if (this != NULL && serviceName != NULL) {
		strncpy(this->serviceName, serviceName, 65);
		return 0;
	}
	return -1;
}
int LogEntry_getServiceName(LogEntry *this, char *serviceName) {
	if (this != NULL && serviceName != NULL) {
		strncpy(serviceName, this->serviceName, 65);
		return 0;
	}
	return -1;
}

int LogEntry_setGravedad(LogEntry *this, int gravedad) {
	if (this != NULL && gravedad > 0) {
		this->gravedad = gravedad;
		return 0;

	}
	return -1;
}
int LogEntry_getGravedad(LogEntry *this, int *gravedad) {
	if (this != NULL) {
		*gravedad = this->gravedad;
		return 0;
	}
	return -1;
}

int LogEntry_setMsg(LogEntry *this, char *msg) {
	if (this != NULL && msg != NULL) {
		strncpy(this->msg, msg, 65);
		return 0;
	}
	return -1;
}
int LogEntry_getMsg(LogEntry *this, char *msg) {
	if (this != NULL && msg != NULL) {
		strncpy(msg, this->msg, 65);
		return 0;
	}
	return -1;
}
void printLogEntry(void *this) {
	LogEntry *auxLogEntry = this;
	printf("%s   %s   %s   %d   %s \n", auxLogEntry->date, auxLogEntry->time,
			auxLogEntry->serviceName, auxLogEntry->gravedad, auxLogEntry->msg);
}

void filterLogEntry(void *this) {
	LogEntry *auxLogEntry = this;
	if (auxLogEntry->gravedad > 3 && auxLogEntry->gravedad < 8) {
		printf("%s   %s   %s   %d   %s \n", auxLogEntry->date,
				auxLogEntry->time, auxLogEntry->serviceName,
				auxLogEntry->gravedad, auxLogEntry->msg);
	}
}

int EstadisticsLogEntryLessThanThree(void *this) {
	LogEntry *auxLogEntry = this;
	if (auxLogEntry->gravedad < 3) {
		return 1;
	}
	return 0;
}

int EstadisticsLogEntryThree(void *this) {
	LogEntry *auxLogEntry = this;
	if (auxLogEntry->gravedad == 3) {
		return 1;
	}
	return 0;
}

int EstadisticsLogEntryMoreThanThree(void *this) {
	LogEntry *auxLogEntry = this;
	if (auxLogEntry->gravedad > 3 && auxLogEntry->gravedad < 8) {
		return 1;
	}
	return 0;
}

int EstadisticsLogEntryMoreThanSeven(void *this) {
	LogEntry *auxLogEntry = this;
	if (auxLogEntry->gravedad > 7) {
		return 1;
	}
	return 0;
}
