Algoritmo PROMEDIO
	definir a, b, c, d Como Real
	Definir r Como Caracter
	Repetir
		Escribir "nota 1"
		Leer a
		Escribir "nota 2"
		Leer b
		Escribir "nota 3"
		Leer c
		d = (a+b+c)/3
		Escribir "su promedio es: " d
		si d>=11 Entonces
			Escribir "aprobo"
		SiNo
			Escribir "desaprobo"
		FinSi
		Escribir "¿Quieres calcular otro promedio? (S/N)"
		Leer r 
	Hasta Que (r==S|r==s)
	
FinAlgoritmo