Pegar el archivo ejecutable "notif_horarios" en "/usr/bin/" para poder ejecutarlo como un comando
Pegar la siguiente linea como comando en un atajo de teclado:
sh -c 'zenity --notification --text="$(notif_horarios $(date))"'
