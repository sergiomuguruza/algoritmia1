

// alumno SERGIO MUGURUZA -- comision 1

// problema N° 14
// calculo del salario semanal de un empleado
// precio hora ordinaria $10 , hora extra $15

#include <stdio.h>

int main() {
    float horasTrabajadas, montoAPagar, montoHorasExtras, montoHorasOrdina;
        
    printf("Ingrese las horas trabajadas: ");
    scanf("%f", &horasTrabajadas);
    
    if (horasTrabajadas > 40) {
        montoHorasOrdina = 40 * 10;
        montoHorasExtras = (horasTrabajadas - 40) * (10 * 1.5);
        montoAPagar = montoHorasOrdina + montoHorasExtras;
    } else {
        montoAPagar = horasTrabajadas * 10;
    }
    
    printf("El monto a pagar es: %.2f", montoAPagar);
	
    return 0;
}
