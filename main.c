/*
	Author: Lavrenty "Larry" Orlov
	Course: Computer Science 121 Section 1
	Date Created: 9/3/25

	Description: This program performs several calculations based on user input including total
				 resistance for three resistors connected in series, the total sales tax of an 
				 item, volume of a right rectangular pyramid, total parallel resistance of three 
				 resistors connected in series, the encoding of a character based on ASCII values,
				 the distance between two coordinate points, and the solution to a general equation.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <math.h>

#define PI 3.14159

int main(void) 
{
	int r1 = 0, r2 = 0, r3 = 0, shift_int = 0, equation_a = 0;

	double resistance_series = 0.0, parallel_resistance = 0.0, total_sales_tax = 0.00, 
		   salex_tax_rate = 0.00, item_cost = 0.00, length = 0.00, width = 0.00, 
		   height = 0.00, volume = 0.00, x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0, 
		   distance = 0.0, equation_x = 0.0, equation_y = 0.0, equation_z = 0.0,
		   display_equation_y = 0.0; // Question: used double-precision value in display_equation_y for 
									 // general equation in problem 7; 
									 // Question = used resistance_series as a double, then type-casted as an int?

	char plaintext_character = '\0', encoded_character = '\0';

	// 1a Prompt the user for three resistor values
	printf("Please enter the values of 3 resistors (all integers) connected in series: ");

	// 1b Get the three resistor values
	scanf("%d %d %d", &r1, &r2, &r3);

	// 1c Compute the total series resistance
	resistance_series = r1 + r2 + r3;

	// 1d Display the calculations and final answer for total series resistance to the screen
	printf("Total series resistance: resistance_series = R1 + R2 + R3 = %d + %d + %d = %d\n", r1, r2, r3, (int)resistance_series);

	// 2a Prompt the user for salex tax rate followed by item cost
	printf("Please enter the salex tax rate, followed by the item cost (both floating-point values): ");

	// 2b Get the salex tax rate and item cost values
	scanf("%lf %lf", &salex_tax_rate, &item_cost);

	// 2c Compute the total sales tax
	total_sales_tax = salex_tax_rate * item_cost;

	// 2d Display the calculations and final answer for total salex tax to the screen
	printf("Total sales tax: total_sales_tax = sales_tax_rate * item_cost = %.2lf * %.2lf = %.2lf\n", salex_tax_rate, item_cost, total_sales_tax);

	// 3a Prompt the user for length, width, and height of the pyramid
	printf("Please enter the length, width, and height of your right rectangular pyramid (all floating-point values): ");

	// 3b Get the length, width, and height
	scanf("%lf %lf %lf", &length, &width, &height);

	// 3c Compute the volume of the right rectangular pyramid
	volume = (length * width * height) / 3;

	// 3d Display the calculations and final answer for pyramid volume to the screen
	printf("Volume of the right rectangular pyramid: volume = (length * width * height) / 3 = (%lf * %lf * %lf) / 3 = %.2lf\n", length, width, height, volume);

	// 4a Compute the total parallel resistance using the R1, R2, and R3 integer values
	parallel_resistance = (double)1 / ((double)1 / r1 + (double)1 / r2 + (double)1 / r3); // Question: didn't prompt user again for parallel resistance values?

	// 4b Display the calculations and final answer for total series resistance to the screen
	printf("Total parallel resistance: parallel_resistance =  1 / (1 / R1 + 1 / R2 + 1 / R3) = 1 / (1 / %d + 1 / %d + 1 / %d) = %d\n", r1, r2, r3, (int)parallel_resistance);

	// 5a Prompt the user for a plain text character and an integer value to shift by on the ASCII table
	printf("Please enter a plain text character value, followed by an integer value to shift by on the ASCII table: ");

	// 5b Get the plain text character and shift integer values
	scanf(" %c %d", &plaintext_character, &shift_int);

	// 5c Compute the encoded character
	encoded_character = (plaintext_character - 'a') + 'A' - shift_int;

	// 5d Display the calculations and final answer for the encoded character to the screen
	printf("Encoded character: encoded_character = (plaintext_character - 'a') + 'A' - shift_int = (%c - 'a') + 'A' - %d = %c\n", plaintext_character, shift_int, encoded_character);

	// 6a Prompt the user for the x1, x2, y1, and y2 values of the two coordinate points
	printf("Please enter the values of x1, x2, y1, and y2 (all floating-point values) for two coordinate points: ");

	// 6b Get the values for x1, x2, y1, and y2
	scanf("%lf %lf %lf %lf", &x1, &x2, &y1, &y2);

	// 6c Compute the distance between the two points
	distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

	// 6d Display the calculations and final answer for the distance between the two points to the screen
	printf("Distance: distance = square root of ((x1 - x2)^2 + (y1 - y2)^2) = square root of ((%lf - %lf)^2 + (%lf - %lf)^2) = %lf\n", x1, x2, y1, y2, distance);

	// 7a Prompt the user for x, y, and z values that are part of a general equation
	printf("Please enter the values of x, y, z, (all floating-point values) that are part of a general equation: ");

	// 7b Get the values for x, y, z
	scanf("%lf %lf %lf", &equation_x, &equation_y, &equation_z);

	// 7c Save the y-value to a separate storage variable so the y-value entered by the user is displayed as part of the equation
	display_equation_y = equation_y;

	// 7d Prompt the user for value of a that is part of the general equation
	printf("Please enter the value of a (integer value) that is part of the general equation: ");

	// 7e Get the value for a
	scanf("%d", &equation_a);

	// 7f Compute the general equation
	equation_y = equation_y / ((double)3 / (double)17) - equation_z + equation_x / (equation_a % 2) + PI;

	// 7g Display the calculations and final answer for the general equation to the screen
	printf("General equation: y = y / (3/17) - z + x / (a %% 2) + PI = %lf / (3/17) - %lf + %lf / (%d %% 2) + %lf = %lf\n", display_equation_y, equation_z, equation_x, equation_a, PI, equation_y);

	return 0;
}