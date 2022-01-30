# battery-status
script que devuelve información básica sobre el estado de la batería cuando se desconecta el equipo. utilidad pava para mi servidor privado.

# configuración
cambiar la ruta `/sys/class/power_supply/BAT#` al número que corresponda (mirar que onda) y elegir el archivo con la información de energía actual y energía total, que son los dos argumentos (en ese orden). usualmente se llaman `energy_now` y `energy_full` o `charge_now` y `charge_full`.
