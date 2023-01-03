#ifndef INC_FSM_H
#define INC_FSM_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "uart.h"
#include "timer.h"

void command_parser_fsm();

void uart_communication_fsm();

#endif
