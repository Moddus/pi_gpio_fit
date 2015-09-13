#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define GPIO_PIN 29 /* Pin 40 / GPIO 21 */
#define TRUE 1
#define FALE 0
#define ON TRUE
#define OFF FALSE

void wiringpi_init() {
	if (wiringPiSetup() == -1)
		exit(EXIT_FAILURE);
	
	pinMode(PIN, OUTPUT);
}

void wiringpi_led_on() {
	digitalWrite(GPIO_PIN, ON);
}

void wiringpi_led_off() {
	digitalWrite(GPIO_PIN, OFF);
}

void wiringpi_delay(long t) {
	delay(t);
}

int main() {
	wiringpi_init();
	MPI_Init(NULL, NULL);

	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	int token;
	if (world_rank != 0) {
		MPI_Recv(&token, 1, MPI_INT, world_rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		wiringpi_led_on();		
		wiringpi_delay(500);
		wiringpi_led_off();
	} else {
		token = -1;
	}
	
	MPI_Send(&token, 1, MPI_INT, (world_rank + 1) % world_size, 0, MPI_COMM_WORLD);
	
	if (world_rank == 0) {
		MPI_Recv(&token, 1, MPI_INT, world_size - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	}

	MPI_Finalize();
}
