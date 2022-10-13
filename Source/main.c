#include "PJ_RPI.h"
#include <stdio.h>
#include "mysql.h"
#include <stdlib.h>

int gpio17val;
int gpio27val;
int gpio22val;

int Prevgpio17val;
int Prevgpio27val;
int Prevgpio22val;


void finish_with_error(MYSQL *con)
{
	fprintf(stderr, "%s\n", mysql_error(con));
	mysql_close(con);
	exit(1);
}

int main()
{
	printf("hello world\r\n");

	if(map_peripheral(&gpio) == -1) 
	{
			printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
			return -1;
	}

	// Define gpio 17 as input
	INP_GPIO(17);
	INP_GPIO(27);
	INP_GPIO(22);

	if (GPIO_READ(17))
		gpio17val = 1;
	else
		gpio17val = 0;

	if (GPIO_READ(27))
		gpio27val = 1;
	else
		gpio27val = 0;

	if (GPIO_READ(22))
		gpio22val = 1;
	else
		gpio22val = 0;

	Prevgpio17val = gpio17val;
	Prevgpio27val = gpio27val;
	Prevgpio22val = gpio22val;

	MYSQL *con = mysql_init(NULL);

	if (con == NULL)
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		exit(1);
	}

	if (mysql_real_connect(con, "localhost", "Admin", "Admin",
						   "Opdracht1", 0, NULL, 0) == NULL)
	{
		finish_with_error(con);
	}

    char s[50];

	while (1)
	{
		if (GPIO_READ(17))
			gpio17val = 1;
		else
			gpio17val = 0;

		if (GPIO_READ(27))
			gpio27val = 1;
		else
			gpio27val = 0;

		if (GPIO_READ(22))
			gpio22val = 1;
		else
			gpio22val = 0;

		if (gpio17val != Prevgpio17val){
			sprintf(s,"INSERT INTO gpiolog (Pin, Value) VALUES(17, %d)",gpio17val);
			if (mysql_query(con, s)) {
 				finish_with_error(con);
  			}
			printf("Pin 17 changed value to %d\r\n",gpio17val);
			Prevgpio17val = gpio17val;
		}

		if (gpio27val != Prevgpio27val){
			sprintf(s,"INSERT INTO gpiolog (Pin, Value) VALUES(27, %d)",gpio27val);
			if (mysql_query(con, s)) {
 				finish_with_error(con);
  			}
			printf("Pin 27 changed value to %d\r\n",gpio27val);
			Prevgpio27val = gpio27val;
		}

		if (gpio22val != Prevgpio22val){
			sprintf(s,"INSERT INTO gpiolog (Pin, Value) VALUES(22, %d)",gpio22val);
			if (mysql_query(con, s)) {
 				finish_with_error(con);
  			}
			printf("Pin 22 changed value to %d\r\n",gpio22val);
			Prevgpio22val = gpio22val;
		}

		sleep(1/100);
	}

	return 0;
}
