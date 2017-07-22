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
	PCB_t* newPCB = PCB_new_pointer(1, 4, metadata, 0);

	//Variable
	VARIABLE_T * variableA = variable_new('a',0,0,4);
	VARIABLE_T * variableG = variable_new('g',0,4,4);

	//Linea 0 SP
	t_list* list_vars = list_create();
	list_add(list_vars, variableA);
	list_add(list_vars, variableG);

	STACKPOINTER_T * lineSP = stack_new(NULL,list_vars,NULL,NULL);
	list_add(newPCB->StackPointer, lineSP);

	//Linea 1 SP
	VARIABLE_T * variableACopy = variable_new('a',0,8,4);

	t_list* list_args = list_create();
	list_add(list_args, variableACopy);

	STACKPOINTER_T * lineSP2 = stack_new(list_args,NULL,3,variableG);
	list_add(newPCB->StackPointer, lineSP2);

	//Muestro el PID Del proceso
	print_PCB(newPCB);

	//Sumo una instruccion
	next_ProgramCounter(newPCB);

	//Muestro el PID Del proceso
	print_PCB(newPCB);

	return EXIT_SUCCESS;
}
