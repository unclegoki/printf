#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

#define UNUSED(x) (void)(x)

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct f_flags
{
	int plus;
	int space;
	int hash;
} f_flags;

/* SIZES */
#define LONG_SIZE 2
#define SHORT_SIZE 1

/**
 * struct fmt - Struct op
 *
 * @frmt: The format.
 * @fxn: The associated function
 */
struct frmt
{
	char frmt;
	int (*fxn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @frmt: The format.
 * @for_mat: The function associated.
 */
typedef struct frmt for_mat;

int _printf(const char *format, ...);
int handles_print(const char *formatted_string, int *i, va_list arg_list, int flags, int width, int prec, int size);
int printchar(va_list arg_list, char arr_buffer[], int flags, int width, int prec, int size);
int print_str(va_list arg_list, char arr_buffer[], int flags, int width, int prec, int size);
int print_percentage(va_list arg_list, char arr_buffer[],int flags, int width, int prec, int size);

/* Functions to print numbers */
int print_integer(va_list arg_list, char arr_buffer[], int flags, int width, int prec, int size);
int printbinary(va_list arg_list, char arr_buffer[], int flags, int width, int prec, int size);
int print_unsigned(va_list arg_list, char arr_buffer[], int flags, int width, int prec, int size);
int print_octa_num(va_list arg_list, char arr_buffer[], int flags, int width, int prec, int size);
int lowercase_hex_num(va_list arg_list, char arr_buffer[], int flags, int width, int prec, int size);
int uppercase_hex_num(va_list arg_list, char arr_buffer[], int flags, int width, int prec, int size);

int print_hex_num(va_list arg_list, char arr_map[], char arr_buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_ascii(va_list arg_list, char arr_buffer[], int flags, int width, int prec, int size);

int pointer_printer(va_list arg_list, char arr_buffer[], int flags, int width, int prec, int size);

int my_flag(const char *formatted_string, int *print_args);
int print_width(const char *formatted_string, int *print_args, va_list arg_list);
int print_precision(const char *formatted_string, int *print_args, va_list arg_list);
int print_size(const char *formatted_string, int *print_args);

/*Function to print string in reverse*/
int print_reverse_str(va_list arg_list, char arr_buffer[], int flags, int width, int prec, int size);

/*Function to print a string in rot 13*/
/*int print_rot13(va_list arg_list, f_flags flags)*/
int print_rot13(va_list arg_list, char arr_buffer[], int flags, int width, int precision, int size);

/* width handler */
int handles_write_char(char c, char arr_buffer[], int flags, int width, int prec, int size);
int write_number(int is_positive, int ind, char arr_buffer[], int flags, int width, int precision, int size);
int write_num(int ind, char arr_buffer[], int flags, int width, int precision, int length, char padd, char extra_char);
int write_pointer(char arr_buffer[], int ind, int length, int width, int flags, char padd, char extra_c, int padd_start);

int write_unsigned_int(int is_neg, int i, char arr_buffer[], int flags, int width, int preci, int size);

/****************** UTILS ******************/
int printable(char);
int append_hex(char, char[], int);
int is_number(char);

long int convert_size_num(long int num, int size);
long int convert_unsigned_int(unsigned long int num, int size);

int _putchar(char c);

#endif
