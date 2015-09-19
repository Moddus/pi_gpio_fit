#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define GPIO_PIN 29 /* Pin 40 / GPIO 21 */
#define TRUE 1
#define FALSE 0
#define ON TRUE
#define OFF FALSE
#define DELAY 100

void wiringpi_init() {
	if (wiringPiSetup() == -1)
		exit(EXIT_FAILURE);
	
	pinMode(GPIO_PIN, OUTPUT);
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

int main(int argc, char* argv[]) {
	wiringpi_init();
	MPI_Init(&argc, &argv);

	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    printf("%d/%d running\n", world_rank, world_size);

	int token;
    if(world_rank == 0){
		MPI_Send(&token, 1, MPI_INT, (world_rank + 1) % world_size, 0, MPI_COMM_WORLD);
    }

    while(TRUE){
        if (world_rank != 0) {
            MPI_Recv(&token, 1, MPI_INT, world_rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            wiringpi_led_on();		
            wiringpi_delay(DELAY);
            wiringpi_led_off();
			MPI_Send(&token, 1, MPI_INT, (world_rank + 1) % world_size, 0, MPI_COMM_WORLD);
        } else {
            MPI_Recv(&token, 1, MPI_INT, world_size-1 , 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            wiringpi_led_on();		
            wiringpi_delay(DELAY);
            wiringpi_led_off();
			MPI_Send(&token, 1, MPI_INT, (world_rank + 1) % world_size, 0, MPI_COMM_WORLD);
        }
    }
	
	MPI_Finalize();
}

