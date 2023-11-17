
import tkinter as tk
from tkinter import ttk
from tkinter import messagebox
import math

def calcular():
    try:
        lado1 = float(entry_lado1.get())
        lado2 = float(entry_lado2.get())
        
        producto_lados = lado1 * lado2
        raiz_producto = math.sqrt(producto_lados)
        medida_entera_superior = math.ceil(raiz_producto)
        
        resultado_label.config(text=f"Valor del calculo: {raiz_producto:.2f}")
        medida_label.config(text=f"es como un circulo de : {medida_entera_superior}")
        
    except ValueError:
        messagebox.showerror("Error", "Ingresa valores numéricos válidos")

# Crear la ventana principal
window = tk.Tk()
window.title("Calculadora de Rectángulos y circulos ")
window.geometry("600x400")

# Crear estilo ttk
style = ttk.Style()
style.theme_use("clam")  # Puedes cambiar "clam" por "default", "alt", etc.

# Crear frame para contenido
content_frame = ttk.Frame(window, padding=20)
content_frame.pack(fill="both", expand=True)

# Crear etiquetas
label1 = ttk.Label(content_frame, text="Ingrese el primer VALOR:")
label1.grid(row=0, column=0, padx=10, pady=10, sticky="w")

entry_lado1 = ttk.Entry(content_frame)
entry_lado1.grid(row=0, column=1, padx=10, pady=10)

label2 = ttk.Label(content_frame, text="Ingrese el segundo VALOR:")
label2.grid(row=1, column=0, padx=10, pady=10, sticky="w")

entry_lado2 = ttk.Entry(content_frame)
entry_lado2.grid(row=1, column=1, padx=10, pady=10)

calcular_button = ttk.Button(content_frame, text="Calcular", command=calcular)
calcular_button.grid(row=2, column=0, columnspan=2, pady=20)

resultado_label = ttk.Label(content_frame, text="", font=("Helvetica", 16))
resultado_label.grid(row=3, column=0, columnspan=2, padx=10, pady=10)

medida_label = ttk.Label(content_frame, text="", font=("Helvetica", 16))
medida_label.grid(row=4, column=0, columnspan=2, padx=10, pady=10)

# Iniciar el bucle de la GUI
window.mainloop()
