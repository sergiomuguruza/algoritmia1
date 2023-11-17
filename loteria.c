algoritmo loteria

lexico
max =30
Telem=(0...999)
Tdata={a pertenece arreglo[1...max]de Telem, cant pertenece [0...max]}
nums pertenece Tdata

accion sortear  (resultado: nums pertenece Tdata)
lexico local
i pertenece z//i pertenece a los numeros naturales
inicio
entrada nums.cant
para (i<--1, i<= nums.cant, i<-- i+1)
	nums.a[i] <-- random (1000)
fin para
fin accion


accion informar (dato: nums pertenece Tdata)
lexico local
	i pertenece z//i pertenece a los numeros naturales
	inicio 
		para (i<--1, i<= nums.cant, i<-- i+1)
		salida: nums.a[i]
		fin para
fin accion


inicio
		sortear (numeros)
		informar(numeros)
		
fin


