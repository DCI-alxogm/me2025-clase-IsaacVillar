David Isaac Oliva Villar
Métodos numéricos
Programa Serie de Taylor
INICIO 

(DECLARACIÓN DE VARIABLES)
ENTERO: opcion, max_iter, n, n_cumple = -1
REAL: x, xi, Es, S = 0.0, S_prev = 0.0, term = 0.0, Ea = 100.0, Er = 0.0
REAL: h, denom, sign, deriv, factor, realv = 0.0

(SELECCIÓN DE FUNCIÓN)

MOSTRAR "Elige funcion (Taylor alrededor de xi):"
MOSTRAR "1) e^x\n2) sin(x)\n3) cos(x)\n4) ln(x)\n5) 1/(1-x)"
MOSTRAR "Opcion: "
    
LEER opcion
SI: opcion NO está entre 1 y 5 O error en lectura 
ENTONCES:
MOSTRAR "Entrada invalida."
TERMINAR programa con error 1
FIN SI

(ENTRADA DE PARÁMETROS)

MOSTRAR "Ingresa x (xi+1): "
LEER x
SI: error en lectura 
ENTONCES:
MOSTRAR "Entrada invalida."
TERMINAR programa
FIN SI
    
MOSTRAR "Ingresa xi (punto de expansion): "
LEER xi
SI: error en lectura 
ENTONCES:
MOSTRAR: "Entrada invalida."
TERMINAR programa
FIN SI
    
MOSTRAR "Ingresa Es (%): "
LEER Es
SI: error en lectura O Es <= 0 
ENTONCES:
MOSTRAR "Es invalido."
TERMINAR programa
FIN SI
    
MOSTRAR "Maximo de iteraciones: "
LEER max_iter
SI: error en lectura O max_iter < 1 
ENTONCES:
MOSTRAR "Iteraciones invalidas."
TERMINAR programa
FIN SI

(VALIDACIONES DE DOMINIO MATEMÁTICO)

SI: opcion = 4 Y (xi ≤ 0 O x ≤ 0) 
ENTONCES:
MOSTRAR "Para ln(x) se requiere xi>0 y x>0."
TERMINAR programa
FIN SI
    
SI: opcion = 5 Y (x = 1 O xi = 1) 
ENTONCES:
MOSTRAR "1/(1-x) es singular en x=1. Evita xi=1 y x=1."
TERMINAR programa
FIN SI

(PREPARACIÓN INICIAL)

h = x - xi (Calcula la diferencia para la serie de Taylor)

MOSTRAR encabezado de tabla: "n", "S_n (aprox)", "Ea(%)", "Er(%)"
MOSTRAR línea separadora

(CÁLCULO DEL VALOR REAL (referencia usando math.h))
SEGUN opcion:
CASO 1: realv = exp(x)           (Valor real de e^x))
CASO 2: realv = sin(x)           (Valor real de sin(x))
CASO 3: realv = cos(x)           (Valor real de cos(x))
CASO 4: realv = log(x)           (Valor real de ln(x))
CASO 5: realv = 1.0/(1.0 - x)    (Valor real de 1/(1-x))
FIN SEGUN

(TÉRMINO INICIAL (n = 0))

SEGUN opcion:
CASO 1:  e^x
S = exp(xi)      (Primer término: e^xi)
term = S         (Inicializar término actual)
        
CASO 2: sin(x)
factor = 1      (Inicializar factor factorial)
deriv = sin(xi)  (Derivada 0: sin(xi))
term = deriv * factor
S = term
        
CASO 3:   cos(x)
factor = 1.0
deriv = cos(xi)   (Derivada de orden 0: cos(xi))
term = deriv * factor
S = term
        
CASO 4:   ln(x)
S = log(xi)      (Primer término: ln(xi))
        
CASO 5:   1/(1-x)
denom = 1.0 - xi
S = 1.0/denom    (Primer término: 1/(1-xi))
FIN SEGUN

(Calcular y mostrar error inicial)

Er = |(realv - S) / realv| * 100.0
MOSTRAR "0", S, "N/A", Er  // Para n=0, Ea es "N/A"

(ITERACIONES PRINCIPALES (n ≥ 1))

PARA n DESDE 1 HASTA max_iter-1 HACER
        
SEGUN opcion:
            
CASO 1:   e^x - Serie exponencial
Término recursivo: termₙ = termₙ₋₁ * h / n
term = term * (h / n)
S_prev = S    (Guardar la suma anterior)
S = S + term  (Agregar un nuevo término ala suma)
            
CASO 2:   sin(x) - Serie trigonométrica
Actualizar factor factorial: n! = (n-1)! * n
factor = factor * (h / n)
                
(Calcular derivada n-ésima (patrón cíclico cada 4 términos))

SI: n mod 4 = 0 
ENTONCES: deriv = sin(xi)
SI: n mod 4 = 1 
ENTONCES: deriv = cos(xi)
SI: n mod 4 = 2 
ENTONCES: deriv = -sin(xi)
SI: n mod 4 = 3 
ENTONCES: deriv = -cos(xi)
                
S_prev = S
S = S + (deriv * factor) 
            
CASO 3:   cos(x) - Serie trigonométrica
factor = factor * (h / n)
                
(Patrón cíclico de derivadas para coseno)

SI: n mod 4 = 0 ENTONCES: deriv = cos(xi)
SI: n mod 4 = 1 ENTONCES: deriv = -sin(xi)
SI: n mod 4 = 2 ENTONCES: deriv = -cos(xi)
SI: n mod 4 = 3 ENTONCES: deriv = sin(xi)
                
S_prev = S
S = S + (deriv * factor)
            
CASO 4:  ln(x) - Serie logarítmica
Término alternante: ((-1)^n+1 * (h/xi)^n) / n
sign = (n mod 2 ≠ 0) ? 1 : -1  // Alternar signo
term = sign * (hⁿ) / (n * xiⁿ)
S_prev = S
S = S + term
            
CASO 5:   1/(1-x) - Serie geométrica
term = h^n / (1 - xi)^n+1
S_prev = S
S = S + term
        
FIN SEGUN

(CÁLCULO Y ERRORES)

Ea = |(S - S_prev) / S| * 100.0      (Error aproximado porcentual)
Er = |(realv - S) / realv| * 100.0   (Error real porcentual)
        
MOSTRAR n, S, Ea, Er  (Mostrar los resultados obtenidos de esta iteración)

(VERIFICACIÓN DE CONVERGENCIA)

SI: Ea ≤ Es 
ENTONCES:
n_cumple = n  (Registrar iteración de convergencia)
ROMPER BUCLE  (Salir anticipadamente)
FIN SI

FIN PARA

(RESULTADOS FINALES)

MOSTRAR línea separadora de la tabla
    
SI: n_cumple ≥ 0 
ENTONCES:
MOSTRAR "Ea <= Es en n =", n_cumple
MOSTRAR "Aprox final:", S, "con Ea =", Ea, "% | Er =", Er, "%"
SINO
MOSTRAR "No se alcanzo Ea <= Es en", max_iter, "iteraciones"
MOSTRAR "Ultima aprox:", S, "(Ea =", Ea, "%)"
FIN SI
    
MOSTRAR "Valor real:", realv

FIN Programa
