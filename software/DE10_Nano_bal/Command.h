/*
 * Command.h
 *
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include "terasic_includes.h"

typedef enum{
	CMD_FOWARD=1,
	CMD_BACKWARD,
	CMD_LEFT,
	CMD_RIGHT,
	CMD_STOP,
	CMD_AKBT,
	CMD_ATDM,
	CMD_ATUTON,
	CMD_ATUTOFF,
}COMMAND_ID;
typedef struct{
	char szCommand[10];
	int CommandId;
	bool bParameter;
}COMMAND_INFO;

COMMAND_INFO gCommandList[] = {
		{"ATFW", CMD_FOWARD, false},
		{"ATBW", CMD_BACKWARD, false},
		{"ATTL", CMD_LEFT, false},
		{"ATTR", CMD_RIGHT, false},
		{"ATST", CMD_STOP, false},
		{"ATAB", CMD_AKBT, false},
		{"ATDM", CMD_ATDM, false},
		{"ATUTON", CMD_ATUTON, false},
		{"ATUTOFF", CMD_ATUTOFF, false},

};

#endif /* COMMAND_H_ */
