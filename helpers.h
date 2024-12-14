#include <stdio.h>

#define RESET "\x1B[0m"
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"

void intro();
void cleanConsole();

void intro() {

	const char *art =
        " ██████╗██╗███████╗██████╗  █████╗ ██████╗ ██╗ ██████╗     ██████╗ ██╗     ██████╗███████╗███████╗ █████╗ ██████╗ ███████╗\n"
        "██╔════╝██║██╔════╝██╔══██╗██╔══██╗██╔══██╗██║██╔═══██╗    ██╔══██╗██║    ██╔════╝██╔════╝██╔════╝██╔══██╗██╔══██╗██╔════╝\n"
        "██║     ██║█████╗  ██████╔╝███████║██████╔╝██║██║   ██║    ██║  ██║██║    ██║     █████╗  ███████╗███████║██████╔╝█████╗  \n"
        "██║     ██║██╔══╝  ██╔══██╗██╔══██║██╔══██╗██║██║   ██║    ██║  ██║██║    ██║     ██╔══╝  ╚════██║██╔══██║██╔══██╗██╔══╝  \n"
        "╚██████╗██║██║     ██║  ██║██║  ██║██║  ██║██║╚██████╔╝    ██████╔╝██║    ╚██████╗███████╗███████║██║  ██║██║  ██║███████╗\n"
        " ╚═════╝╚═╝╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝ ╚═════╝     ╚═════╝ ╚═╝     ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝\n";
    
    printf("\n%s\n\n", art);

	printf(CYN "Il Cifrario di Cesare è un semplice metodo di cifratura che sposta ogni lettera dell'alfabeto di un numero fisso di posizioni.\n");
    printf("Puoi scegliere di cifrare o decifrare il tuo testo, specificando la chiave (numero di posizioni di spostamento).\n"RESET);
	printf("\nPremi INVIO per iniziare.");
	getchar();

	cleanConsole();
}

void cleanConsole() {
    printf("\033[H\033[J");
}