/*
 ============================================================================
 Name        : ProcessControlBlack.c
 Author      : Lucas Visser
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "ProcessControlBlock.h"

int main(void) {
	puts("PCB\n"); /* prints PCB */

	//Creo el metadata program del proceso
	char* programa = strdup(PROGRAMA);
	t_metadata_program* metadata = metadata_desde_literal(programa);

	//Creo el PCB
	PCB_t* newPCB = PCB_new_pointer(1, 4, metadata);

	//Variable
	VARIABLE_T * variableA = variable_new('a',0,0,4);
	VARIABLE_T * variableG = variable_new('g',0,4,4);

	t_queue* queue_vars = queue_create();
	queue_push(queue_vars, variableA);
	queue_push(queue_vars, variableG);

	//Linea 0 SP
	STACKPOINTER_T * lineSP = stack_new(NULL, queue_vars, NULL, NULL);
	push_stack(newPCB, lineSP);

	//Linea 1 SP
	t_queue* queue_args = queue_create();
	VARIABLE_T * variableACopy = variable_new('a',0,8,4);
	queue_push(queue_args, variableACopy);
	STACKPOINTER_T * lineSP2 = stack_new(queue_args, NULL, 3, variableG);
	push_stack(newPCB, lineSP2);

	//Muestro el PID Del proceso
	print_PCB(newPCB);

	return EXIT_SUCCESS;
}
