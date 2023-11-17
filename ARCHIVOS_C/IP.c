#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libxlsxwriter/xlsxwriter.h>

#define MAX_LENGTH 100

// Función para buscar un usuario a partir de una IP en el archivo Excel
char* buscarUsuarioPorIP(const char* archivo, const char* ip) {
    lxw_workbook *workbook = workbook_new(archivo);
    lxw_worksheet *worksheet = workbook_get_worksheet_by_name(workbook, "IP - USUARIO");
    char linea[MAX_LENGTH];
    char* usuario = NULL;

    lxw_row_t row = 0;
    lxw_col_t col_ip = 0;
    lxw_col_t col_usuario = 0;
    lxw_cell *cell_ip = NULL;
    lxw_cell *cell_usuario = NULL;

    while ((cell_ip = worksheet_read_cell(worksheet, row, col_ip)) != NULL) {
        strcpy(linea, lxw_cell_get_string(cell_ip));

        if (strcmp(linea, ip) == 0) {
            cell_usuario = worksheet_read_cell(worksheet, row, col_usuario + 2);
            usuario = strdup(lxw_cell_get_string(cell_usuario));
            break;
        }

        row++;
    }

    workbook_close(workbook);
    return usuario;
}

// Función para buscar una IP a partir de un usuario en el archivo Excel
char* buscarIPPorUsuario(const char* archivo, const char* usuario) {
    lxw_workbook *workbook = workbook_new(archivo);
    lxw_worksheet *worksheet = workbook_get_worksheet_by_name(workbook, "IP - USUARIO");
    char linea[MAX_LENGTH];
    char* ip = NULL;

    lxw_row_t row = 0;
    lxw_col_t col_ip = 0;
    lxw_col_t col_usuario = 2;
    lxw_cell *cell_ip = NULL;
    lxw_cell *cell_usuario = NULL;

    while ((cell_usuario = worksheet_read_cell(worksheet, row, col_usuario)) != NULL) {
        strcpy(linea, lxw_cell_get_string(cell_usuario));

        if (strcmp(linea, usuario) == 0) {
            cell_ip = worksheet_read_cell(worksheet, row, col_ip);
            ip = strdup(lxw_cell_get_string(cell_ip));
            break;
        }

        row++;
    }

    workbook_close(workbook);
    return ip;
}

int main() {
    char archivo[] = "relevamiento_ip.xlsx";
    char ip[MAX_LENGTH];
    char usuario[MAX_LENGTH];
    char* resultado;

    printf("Ingrese una dirección IP: ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = '\0';  // Eliminar el salto de línea al final

    resultado = buscarUsuarioPorIP(archivo, ip);
    if (resultado != NULL) {
        printf("El usuario asociado a la IP %s es: %s\n", ip, resultado);
        free(resultado);
    } else {
        printf("No se encontró un usuario para la IP %s\n", ip);
    }

    printf("Ingrese un usuario: ");
    fgets(usuario, sizeof(usuario), stdin);
    usuario[strcspn(usuario, "\n")] = '\0';  // Eliminar el salto de línea al final

    resultado = buscarIPPorUsuario(archivo, usuario);
    if (resultado != NULL) {
        printf("La IP asociada al usuario %s es: %s\n", usuario, resultado);
        free(resultado);
    } else {
        printf("No se encontró una IP para el usuario %s\n", usuario);
    }

    return 0;
}
