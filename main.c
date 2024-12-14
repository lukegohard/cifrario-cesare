#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "helpers.h"

#define RESET "\x1B[0m"
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"

void cifratura(char *text, int key);
void cifraturaFile(FILE *input, FILE *output, int key);

int main() {

    cleanConsole();
	intro();

    int choice;
    do {

        printf(GRN "[1] " RESET "Cifrare una stringa.\n\n");
        printf(GRN "[2] " RESET "Cifrare un file di testo.\n\n");
        printf(GRN "[3] " RESET "Decifrare una stringa.\n\n");
        printf(GRN "[4] " RESET "Decifrare un file di testo.\n\n");
        printf(RED "[0] " RESET "Esci.\n\n");
        printf(YEL "> " RESET);
        scanf("%d", &choice);
		getchar();
        cleanConsole();

        switch (choice) {
        case 1: // Cifratura stringa

			int c_key;
            char *c_str = NULL;
            size_t c_len = 0;

			// Getline() per allocare dinamicamente la memoria
            printf(YEL "Inserisci la stringa da cifrare: " RESET);
            getline(&c_str, &c_len, stdin);
            c_str[strcspn(c_str, "\n")] = '\0';

            printf(YEL "Inserisci la chiave per cifrare (numero intero): " RESET);
			scanf("%d", &c_key);

			cleanConsole();

			cifratura(c_str, c_key);
			printf(CYN "Stringa cifrata: " RESET "%s\n\n", c_str);

            free(c_str);
            break;

		case 2: // Cifratura file
			int c_file_key; // chiave per cifrare

			// filename del file da cifrare
            char *c_input_filename = NULL;
            size_t c_len_input_filename = 0;

            printf(YEL "Inserisci il nome del file da cifrare: " RESET);
            getline(&c_input_filename, &c_len_input_filename, stdin);
            c_input_filename[strcspn(c_input_filename, "\n")] = '\0';

            printf(YEL "Inserisci la chiave per cifrare (numero intero): " RESET);
			scanf("%d", &c_file_key);
			getchar();
			cleanConsole();

			// apertura file input e gestione errori 
			FILE *c_input_file = fopen(c_input_filename, "r");
			if (c_input_file == NULL) {
				printf(RED "Errore nell'apertura del file di input.\n"RESET);
            	free(c_input_filename);
				break;
			}

			// filename del file di output
			char *c_output_filename = NULL;
            size_t c_len_output_filename = 0;
            printf(YEL "Inserisci il nome del file output: " RESET);
            getline(&c_output_filename, &c_len_output_filename, stdin);
            c_output_filename[strcspn(c_output_filename, "\n")] = '\0';

			cleanConsole();

			// apertura file output e gestione errori 
			FILE *c_output_file = fopen(c_output_filename, "w");
			if (c_output_file == NULL) {
				printf(RED "Errore nell'apertura del file di output.\n\n"RESET);

				fclose(c_input_file);

            	free(c_input_filename);
            	free(c_output_filename);
				break;
			}

			cifraturaFile(c_input_file, c_output_file, c_file_key);
			printf(GRN "File cifrato con successo!\n\n" RESET);

			fclose(c_input_file);
			fclose(c_output_file);
            free(c_input_filename);
            free(c_output_filename);

			break;

        case 3: // Decifratura stringa

			int d_key; // chiave per decifrare

            char *d_str = NULL;
            size_t d_len = 0;

            printf(YEL "Inserisci la stringa da decifrare: " RESET);
            getline(&d_str, &d_len, stdin);
            d_str[strcspn(d_str, "\n")] = '\0';

            printf(YEL "Inserisci la chiave per decifrare (numero intero): " RESET);
			scanf("%d", &d_key);

			cleanConsole();

			// Decifrare equivale a cifrare con -(key)
			cifratura(d_str, -d_key);
			printf(CYN "Stringa decifrata: " RESET "%s\n\n", d_str);

            free(d_str);
            break;

		case 4: // Decifratura file
			int d_file_key; // chiave per decifrare file
			
			// filename del file di input da decifrare
            char *d_input_filename = NULL;
            size_t d_len_input_filename = 0;
            printf(YEL "Inserisci il nome del file da decifrare: " RESET);
            getline(&d_input_filename, &d_len_input_filename, stdin);
            d_input_filename[strcspn(d_input_filename, "\n")] = '\0';

			// chiave per decifrare file
            printf(YEL "Inserisci la chiave per decifrare (numero intero): " RESET);
			scanf("%d", &d_file_key);
			getchar();
			cleanConsole();

			// apertura file input e gestione errori
			FILE *d_input_file = fopen(d_input_filename, "r");
			if (d_input_file == NULL) {
				printf(RED "Errore nell'apertura del file di input.\n"RESET);
            	free(d_input_filename);
				break;
			}

			// filename file di output
			char *d_output_filename = NULL;
            size_t d_len_output_filename = 0;
            printf(YEL "Inserisci il nome del file output: " RESET);
            getline(&d_output_filename, &d_len_output_filename, stdin);
            d_output_filename[strcspn(d_output_filename, "\n")] = '\0';

			cleanConsole();

			// apertura file output e gestione errori
			FILE *d_output_file = fopen(d_output_filename, "w");
			if (d_output_file == NULL) {
				printf(RED "Errore nell'apertura del file di output.\n\n"RESET);

				fclose(d_input_file);

            	free(d_input_filename);
            	free(d_output_filename);
				break;
			}

			// Decifrare equivale a cifrare con -(key)
			cifraturaFile(d_input_file, d_output_file, -d_file_key);
			printf(GRN "File decifrato con successo!\n\n" RESET);

			fclose(d_input_file);
			fclose(d_output_file);
            free(d_input_filename);
            free(d_output_filename);

			break;
        case 0:
            break;
        default:
            printf(RED"Input non valido!\n\n" RESET);
            break;
        }

    } while(choice != 0);
    cleanConsole();

    printf(MAG"Vshur fkh wl vld vwdwr xwloh! Dood survvlpd!\n"RESET);
    return 0;
}

void cifratura(char *text, int key) {
	for (int i=0; text[i] != '\0'; i++) {
		char c = text[i];
		if (isalpha(c)) {
			char base = islower(c) ? 'a' : 'A';
			text[i] = (c - base + key + 26) % 26+base;
		}
	}
}

void cifraturaFile(FILE *input, FILE *output, int key) {

	int c;
	while ((c = fgetc(input)) != EOF) {
		if (isalpha(c)) {
			char base = islower(c) ? 'a' : 'A';
			c = (c - base + key + 26) % 26 + base;
		}

		fputc(c, output);
	}

}
