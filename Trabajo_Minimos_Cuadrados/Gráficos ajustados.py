import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
from google.colab import files
import io

# DATOS
print("Por favor, sube el archivo CSV de datos aquí:")
uploaded = files.upload()

# Leer el archivo subido (toma el primero que encuentre)
filename = next(iter(uploaded))
try:
    df = pd.read_csv(io.BytesIO(uploaded[filename]))
    print(f"\nArchivo '{filename}' cargado exitosamente.")
except Exception as e:
    print(f"Error al leer el archivo: {e}")
    print("Asegúrate de subir un archivo CSV válido.")

# DEFINICIÓN DE MODELOS

# Modelo Peleg: Xe = b0*aw^b1 + b2*aw^b3
def peleg_model(aw, b0, b1, b2, b3):
    return b0 * (aw ** b1) + b2 * (aw ** b3)

# Modelo DLP: Xe = b0 + b1*chi + b2*chi^2 + b3*chi^3
# Donde chi = ln(-ln(aw))
def dlp_model_func(aw, b0, b1, b2, b3):
    # Evitar log(0) o valores inválidos
    valid_mask = (aw > 0) & (aw < 1)
    chi = np.zeros_like(aw)
    chi[valid_mask] = np.log(-np.log(aw[valid_mask]))
    chi[~valid_mask] = np.nan 
    return b0 + b1 * chi + b2 * (chi**2) + b3 * (chi**3)

# PROCESAMIENTO Y AJUSTE

# Configuración de gráficas
tipos_cafe = ['Roasted beans', 'Ground-Medium', 'Ground-Fine']
temperaturas = [25, 35, 45]
colores = {25: 'blue', 35: 'green', 45: 'red'}

fig, axes = plt.subplots(1, 3, figsize=(18, 6))
resultados = []

print("\nRealizando ajustes de curvas...\n")

for i, tipo in enumerate(tipos_cafe):
    ax = axes[i]
    datos_tipo = df[df['Type'] == tipo]
    
    for temp in temperaturas:
        subset = datos_tipo[datos_tipo['Temperature'] == temp]
        
        if subset.empty:
            continue
            
        aw_exp = subset['Water activity'].values
        me_exp = subset['Moisture content (% dry basis)'].values # Usamos base seca
        
        chi_exp = np.log(-np.log(aw_exp))
        try:
            # Polyfit devuelve [b3, b2, b1, b0]
            p_dlp = np.polyfit(chi_exp, me_exp, 3)
            params_dlp = [p_dlp[3], p_dlp[2], p_dlp[1], p_dlp[0]] 
            
            # Calcular Chi2
            me_pred_dlp = dlp_model_func(aw_exp, *params_dlp)
            chi2_dlp = np.sum((me_exp - me_pred_dlp)**2)
        except:
            params_dlp = [np.nan]*4
            chi2_dlp = np.inf

        # Ajuste Peleg
        # Estimación inicial para ayudar a la convergencia
        p0_peleg = [2.0, 0.5, 25.0, 10.0]
        try:
            popt_peleg, _ = curve_fit(peleg_model, aw_exp, me_exp, p0=p0_peleg, maxfev=20000)
            
            # Calcular Chi2 (SSE)
            me_pred_peleg = peleg_model(aw_exp, *popt_peleg)
            chi2_peleg = np.sum((me_exp - me_pred_peleg)**2)
        except:
            popt_peleg = [np.nan]*4
            chi2_peleg = np.inf
            
        # Determinar el mejor modelo
        mejor_modelo = "Peleg" if chi2_peleg < chi2_dlp else "DLP"
        
        # Guardar resultados
        resultados.append({
            'Tipo': tipo,
            'Temp': temp,
            'Peleg Params': popt_peleg,
            'Peleg Chi2': chi2_peleg,
            'DLP Params': params_dlp,
            'DLP Chi2': chi2_dlp,
            'Mejor Modelo': mejor_modelo
        })
        
        # Graficar
        # Puntos experimentales
        ax.scatter(aw_exp, me_exp, color=colores[temp], label=f'{temp}°C Exp', marker='o')
        
        aw_suave = np.linspace(min(aw_exp), max(aw_exp), 100)
        
        if mejor_modelo == "Peleg":
            y_suave = peleg_model(aw_suave, *popt_peleg)
            estilo_linea = '-'
        else:
            y_suave = dlp_model_func(aw_suave, *params_dlp)
            estilo_linea = '--'
            
        ax.plot(aw_suave, y_suave, color=colores[temp], linestyle=estilo_linea, label=f'{temp}°C {mejor_modelo}')

    ax.set_title(tipo)
    ax.set_xlabel('Water Activity ($a_w$)')
    ax.set_ylabel('Moisture Content (% d.b.)')
    if i == 0: 
        ax.legend()

plt.tight_layout()
plt.show()

# TABLA DE RESULTADOS

res_df = pd.DataFrame(resultados)

tabla_final = res_df[['Tipo', 'Temp', 'Peleg Chi2', 'DLP Chi2', 'Mejor Modelo']].copy()
print("\n=== COMPARACIÓN DE MODELOS (Menor Chi2 es mejor) ===")
print(tabla_final)

print("\n=== PARÁMETROS DEL MODELO PELEG (b0, b1, b2, b3) ===")
for index, row in res_df.iterrows():
    params = row['Peleg Params']
    if not np.isnan(params[0]):
        print(f"{row['Tipo']} {row['Temp']}°C: [{params[0]:.4f}, {params[1]:.4f}, {params[2]:.4f}, {params[3]:.4f}]")
