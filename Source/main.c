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

	gpio17val = Prevgpio17val;
	gpio27val = Prevgpio27val;
	gpio22val = Prevgpio22val;

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

	if (map_peripheral(&gpio) == -1)
	{
		printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
		return -1;
	}

	// Define gpio 17 as input
	INP_GPIO(17);
	INP_GPIO(27);
	INP_GPIO(22);

	if (mysql_query(con, 'INSERT INTO gpiolog (Pin, Value) VALUES(22, '+gpio22val+')')) {
 				finish_with_error(con);
  			}

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
			if (mysql_query(con, 'INSERT INTO gpiolog (Pin, Value) VALUES(17, '+gpio17val+')')) {
 				finish_with_error(con);
  			}
			gpio17val = Prevgpio17val;
		}

		if (gpio27val != Prevgpio27val){
			if (mysql_query(con, 'INSERT INTO gpiolog (Pin, Value) VALUES(27, '+gpio27val+')')) {
 				finish_with_error(con);
  			}
			gpio27val = Prevgpio27val;
		}

		if (gpio22val != Prevgpio22val){
			if (mysql_query(con, 'INSERT INTO gpiolog (Pin, Value) VALUES(22, '+gpio22val+')')) {
 				finish_with_error(con);
  			}
			gpio22val = Prevgpio22val;
		}

		sleep(1);
	}

	// if (mysql_query(con, "INSERT INTO gpiolog (Pin, Value) VALUES(1,'Audi',52642)")) {
    //   finish_with_error(con);
  	// }

	return 0;
}
