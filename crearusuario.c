#include <stdio.h>
#include <stdbool.h> // Necesario para el tipo de dato bool
#include <ctype.h>

bool ContCorrecta(const char* password) {
    bool has_digit = false;
    bool has_uppercase = false;

    for (int i = 0; password[i] != '\0'; i++) {
        if (isdigit(password[i])) {
            has_digit = true;
        } else if (isupper(password[i])) {
            has_uppercase = true;
        }

        if (has_digit && has_uppercase) {
            return true; // La contraseña cumple con las condiciones
        }
    }

    return false; // La contraseña no cumple con las condiciones
}

int main() {
    char us[50];
    char pass[50];
    char msg[100];
    int i = 0;

    do {
        printf("Ingrese el nombre de usuario: ");
        scanf("%s", us);

        printf("Ingrese la contraseña: ");
        scanf("%s", pass);

        i++;
    } while (!ContCorrecta(pass) && i <= 5);

    if (i <= 5) {
        sprintf(msg, "Usuario y contraseña creados con éxito.");
    } else {
        sprintf(msg, "Sus 5 intentos han fallado - reinicie el programa.");
    }

    printf("%s\n", msg);

    return 0;
}
