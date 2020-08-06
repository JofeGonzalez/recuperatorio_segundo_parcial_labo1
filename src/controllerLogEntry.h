/*
 * controllerLogEntry.h
 *
 *  Created on: 4 ago. 2020
 *      Author: jgonz
 */

#ifndef CONTROLLERLOGENTRY_H_
#define CONTROLLERLOGENTRY_H_
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "logEntry.h"
#include "parser.h"
#include "utn.h"

int controller_loadFromText(char *path, LinkedList *pArrayList);
int controller_saveAsText(char *path, LinkedList *pArrayList);
int controller_ListLogEntry(LinkedList *pArrayList);
int controller_LogEntryProcess(LinkedList *pArrayList);
int controller_EstadisticsLogEntry(LinkedList *pArrayList);
#endif /* CONTROLLERLOGENTRY_H_ */
