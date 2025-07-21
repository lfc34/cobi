#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

double
bytes_to_bits(double bytes)
{
        return bytes * 8;
}

double
bits_to_bytes(double bits)
{
        return bits < 8 ? 0 : bits / 8;
}

int 
main(int argc, char **argv)
{
        double val = 0;
        char power[3];
        if (argc == 1 || strcmp(argv[1], "--help") == 0) {
                printf("cobi. All lefts unprotected. ffs\n");
                printf("\tUsage: cobi [val] [pow] [pow_to_convert_to]\n");
                printf("\tExample: cobi 7.69 gib mb\n");
                return EXIT_SUCCESS;
        }
        if (argc == 4) {
                // it doesn't care about what goes after first char XD
                if (isdigit(*argv[1])) {
                        val = atof(argv[1]);
                } else {
                        printf("Incorrect argument. Enter number\n");
                        return EXIT_FAILURE;
                }

                // convert our value to bytes for convenience
                if (strcmp(argv[2], "tib") == 0) {
                        val = (val * pow(1024, 4));
                } else if (strcmp(argv[2], "tb") == 0) {
                        val = (val * pow(1000, 4));   
                } else if (strcmp(argv[2], "gib") == 0) {
                        val = (val * pow(1024, 3));
                } else if (strcmp(argv[2], "gb") == 0) {
                        val = (val * pow(1000, 3));
                } else if (strcmp(argv[2], "mib") == 0) {
                        val = (val * pow(1024, 2));
                } else if (strcmp(argv[2], "mb") == 0) {
                        val = (val * pow(1000, 2));
                } else if (strcmp(argv[2], "kib") == 0) {
                        val = val * 1024;
                } else if (strcmp(argv[2], "kb") == 0) {
                        val = val * 1000;
                } else if (strcmp(argv[2], "byte") == 0) {
                        // nothing ever happens
                } else if (strcmp(argv[2], "bit") == 0) {
                        val = bits_to_bytes(val);
                } else {
                        printf("Incorrect type: %s\n", argv[2]);
                        return EXIT_FAILURE;
                }

                // make final conversion
                if (strcmp(argv[3], "bit") == 0) {
                        printf("%.0lf bits\n", bytes_to_bits(val)); 
                } else if (strcmp(argv[3], "byte") == 0) {
                        printf("%.0lf bytes", val);
                } else if (strcmp(argv[3], "kb") == 0) {
                        printf("%lf kilobytes\n", val / 1000);
                } else if (strcmp(argv[3], "kib") == 0) {
                        printf("%lf kebibytes\n", val / 1024);
                } else if (strcmp(argv[3], "mb") == 0) {
                        val /= pow(1000, 2);
                        printf("%lf megabytes\n", val);
                } else if (strcmp(argv[3], "mib") == 0) {
                        val /= pow(1024, 2);
                        printf("%lf mebibytes\n", val);
                } else if (strcmp(argv[3], "gb") == 0) {
                        val /= pow(1000, 3);
                        printf("%lf gigabytes\n", val);
                } else if (strcmp(argv[3], "gib") == 0) {
                        val /= pow(1024, 3);
                        printf("%lf gebibytes\n", val);
                } else if (strcmp(argv[3], "tb") == 0) {
                        val /= pow(1000, 4);
                        printf("%lf terabytes\n", val);
                } else if (strcmp(argv[3], "tib") == 0) {
                        val /= pow(1024, 4);
                        printf("%lf tebibytes\n", val);
                } else {
                        printf ("Incorrect type: %s\n", argv[3]);
                        return EXIT_FAILURE;
                }
        } else {
                printf("Incorrect arguments. Check out --help\n");
                return EXIT_FAILURE;
        }
}
