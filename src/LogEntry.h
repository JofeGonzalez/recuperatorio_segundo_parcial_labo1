/*
 * LogEntry.h
 *
 *  Created on: 4 ago. 2020
 *      Author: jgonz
 */

#ifndef LOGENTRY_H_
#define LOGENTRY_H_

typedef struct S_LogEntry{
	char date[11];
	char time[6];
	char serviceName[65];
	int gravedad;
	char msg[65];
}LogEntry;

LogEntry* LogEntry_new();
LogEntry* LogEntry_newParametros(char *dateStr, char *timeStr,
		char *serviceName, char *gravedad, char *msgStr);
void LogEntry_delete(LogEntry *auxLogEntry);

int LogEntry_setDate(LogEntry *this, char *date);
int LogEntry_getDate(LogEntry *this, char *date);

int LogEntry_setTime(LogEntry *this, char *time);
int LogEntry_getTime(LogEntry *this, char *time);

int LogEntry_setServiceName(LogEntry *this, char *serviceName);
int LogEntry_getServiceName(LogEntry *this, char *serviceName);

int LogEntry_setGravedad(LogEntry *this, int gravedad);
int LogEntry_getGravedad(LogEntry *this, int *gravedad);

int LogEntry_setMsg(LogEntry *this, char *msg);
int LogEntry_getMsg(LogEntry *this, char *msg);

void printLogEntry(void *this);
void filterLogEntry(void *this);
int EstadisticsLogEntryLessThanThree(void *this);
int EstadisticsLogEntryThree(void *this);
int EstadisticsLogEntryMoreThanThree(void *this);
int EstadisticsLogEntryMoreThanSeven(void *this);
#endif /* LOGENTRY_H_ */
