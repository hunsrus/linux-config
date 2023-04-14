---
# Tabla de contenidos
1. [Soluciones](https://github.com/hunsrus/linux-config#soluciones)
    - [Touchpad](https://github.com/hunsrus/linux-config#touchpad-)
    - [Codecs](https://github.com/hunsrus/linux-config#codecs-privativos-)
    - [Arduino Original](https://github.com/hunsrus/linux-config#arduino-)
    - [Formato Office](https://github.com/hunsrus/linux-config#formato-office-)
    - [Super+#](https://github.com/hunsrus/linux-config#super-)
      - [Metodo sin Dash to Dock](https://github.com/hunsrus/linux-config#metodo-sin-dash-to-dock)
      - [Solución para Pop_OS](https://github.com/hunsrus/linux-config#soluci%C3%B3n-para-pop_os)
    - [Instalar ISE Design Suite](https://github.com/hunsrus/linux-config#instalar-ise-design-suite-)
    - [QtCreator kits](https://github.com/hunsrus/linux-config#qtcreator-rompe-las-bolas-con-los-kits-)
    - [Default magnet link handler](https://github.com/hunsrus/linux-config#cambiar-magnet-link-handler-por-defecto-)
    - [Default to high performance mode](https://github.com/hunsrus/linux-config#default-to-high-performance-mode-)
    - [Solución MATLAB](https://github.com/hunsrus/linux-config#soluci%C3%B3n-matlab-)
    - [Instalación de LaTeX](https://github.com/hunsrus/linux-config#instalaci%C3%B3n-de-latex-)
2. [Config](https://github.com/hunsrus/linux-config#config)
    - [Tema de PopOS](https://github.com/hunsrus/linux-config#tema-de-popos-)
    - [Extensiones](https://github.com/hunsrus/linux-config#extensiones-)
    - [Script instalador](https://github.com/hunsrus/linux-config#programas-que-insala-el-script-)
    - [Keybindings](https://github.com/hunsrus/linux-config#keybindings-)
---
# Soluciones
## Touchpad <img align="left" src="https://github.com/hunsrus/linux-config/blob/main/src/touchpad.png" width="28px">
Si el touchpad no funciona después de suspender, pegar `susp-touchpad.sh` en `/lib/systemd/system-sleep/`
(darle permisos de ejecución)
## Codecs Privativos <img align="left" src="https://github.com/hunsrus/linux-config/blob/main/src/codecs.png" width="36px">
Instalar codecs privativos para reconocer más archivos multimedia
```
sudo apt-get install ubuntu-restricted-extras
```
## Arduino <img align="left" src="https://github.com/hunsrus/linux-config/blob/main/src/arduino.png" width="32px">
Por lo general está mejor mantenido el paquete descargado directo de la [página de Arduino](https://www.arduino.cc/en/software).
### Permisos
Si al intentar subir un programa a la placa devuelve un error como el siguiente:
```
avrdude ser_open() can't open device /dev/ttyusb0 permission denied
```
Agregar el usuario al grupo ```dialouts```:
```
sudo adduser usuario dialouts
```
Reiniciar la sesión para que el cambio tenga efecto.
### Original
Si no podes comunicarte con arduinos originales usando el IDE, instalá estos paquetes
```
sudo apt-get install openjdk-8-jre avr-libc gcc-avr
```
## Formato Office <img align="left" src="https://github.com/hunsrus/linux-config/blob/main/src/office.png" width="32px">
Para que el formato en WPS sea más cercano a Office, crear carpeta
```
sudo mkdir /usr/share/fonts/wps-fonts
```
y agregar fuentes de microsoft ahí.
(Para OnlyOffice agregar las fuentes normalmente)
## Super+# <img align="left" src="https://github.com/hunsrus/linux-config/blob/main/src/hashtag.png" width="34px">
Para el acceso directo con `Super+#` a las aplicaciones favoritas, la extensión Dash to Dock agrega la funcionalidad de nuevo.

**Nota:** Para usar `dconf-editor` en los métodos siguientes **NO** instalar la versión *Flatpak*, instalar el paquete *.deb* preferentemente.
### Metodo sin Dash to Dock
Using the `dconf-editor` method;
```
dconf-editor /org/gnome/shell/keybindings
```
Select the entry you want from `switch-to-application-?`. The numbers correspond with the position in the dash from the top.

For example, I want to launch Settings, which is the fifth one down in my favorites dash: Click on `switch-to-application-5` In the **Custom value** field add the appropriate information in this format. `['<super>5']`.

Edit: Also toggle off the Use default value button.

### Solución para Pop_OS
Pop usa una versión modificada de *dash to dock* y se puede activar la funcionalidad usando también `dconf-editor`:
```
dconf-editor /org/gnome/shell/extensions/dash-to-dock
```
Activar el switch de `hot-keys` para devolver esa funcionalidad. Para que no muestre los números en el dock cuando se usa un atajo, desactivar `hotkeys-overlay` y `hotkeys-show-dock`.

## Instalar ISE Design Suite <img align="left" src="https://github.com/hunsrus/linux-config/blob/main/src/ise_de.png" width="32px">
Las instrucciones y todo lo necesario está en la carpeta `xilinx`
(No incluye instalador pesa una banda)
## QtCreator rompe las bolas con los kits <img align="left" src="https://github.com/hunsrus/linux-config/blob/main/src/qt.png" width="36px">
1. Execute in your terminal the command: `sudo apt-get install qt5-default` to install qt version 5.
2. Verify the version of your Qt and the location of your qmake file. Do this by executing in your terminal the command `qmake --version`. You may have a result similar to this line. QMake version 3.1 Using Qt version 5.9.5 in `/usr/lib/x86_64-linux-gnu`. What's important here is the location `/usr/lib/x86_64-linux-gnu`.
3. Open your Qt-creator.
4. Go to "Tools>Options"
5. Select the Qt Versions combobox and select and click "Add"
6. Then find the qmake file in the location of step 2. Here `/usr/lib/x86_64-linux-gnu/qt5/bin/` here you have the qmake file for qt5. Open it, click Apply.
7. Go to "Kits" combobox. Select Desktop(by default). Then scroll down to the button to select Qt version: and list down to select the version you just add. 
8. Then apply all. Check your compiler and debugger and it's ok. You're done.

Si después del paso 6 dice que no se instaló qt5 correctamente y necesitas hacer `make install`, probablemente es porque no instalaste qt con el paquete `qt5-default` y falta instalar:
```
sudo apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools
```
Si los proyectos de qt corren bien pero marca errores en las clases como q_dialog, ir a "Help"->"About Plugins" y desactivar "ClangCodeModel". Reiniciar Qt.

## Cambiar magnet link handler por defecto <img align="left" src="https://github.com/hunsrus/linux-config/blob/main/src/magnet.png" width="32px">
Mostrar opciones:
```
gio mime x-scheme-handler/magnet
```
Determinar handler por defecto:
```
xdg-mime default HANDLER.desktop x-scheme-handler/magnet
```

## Default to high performance mode <img align="left" src="https://github.com/hunsrus/linux-config/blob/main/src/performance.png" width="32px">
Para que el sistema inicie en modo de alto rendimiento agregar el comando a las aplicaciones de inicio:

    system76-power profile performance

## Solución MATLAB <img align="left" src="https://github.com/hunsrus/linux-config/blob/main/src/matlab.png" width="32px">
Si lo que falta empieza con g, excluir librerías en ```cefclient/sys/os/glnxa64/``` hasta que el error empiece con FT. (Se nota que no tengo la menor idea de por qué funciona esto).
En ese caso excluir la librería ```libfreetype``` en ```bin/glnxa64/```

## Instalación de LaTeX <img align="left" src="https://github.com/hunsrus/linux-config/blob/main/src/latex.png" width="32px">
Los pasos para la descarga e instalación son los siguientes (instalar con ```apt-get``` no es recomendado):

Ir a la carpeta temporal (o cualquier otra a elección)
    
    cd /tmp

Descargar el instalador con ```wget``` (o ```curl```)

    wget https://mirror.ctan.org/systems/texlive/tlnet/install-tl-unx.tar.gz

Descomprimir
    
    zcat install-tl-unx.tar.gz | tar xf -
    
Entrar en la carpeta del instalador

    cd install-tl-*

Instalar con ```perl```

    perl ./install-tl --no-interaction
    
Finalmente, agregar ```/usr/local/texlive/YYYY/bin/PLATFORM``` a ```PATH``` en el archivo ```.profile```,
por ejemplo con

    export PATH="/usr/local/texlive/2022/bin/x86_64-linux/:$PATH"

---
# Config
## Tema de PopOS <img align="left" src="https://github.com/hunsrus/linux-config/blob/main/src/pop.png" width="32px">
Para instalar el tema de Pop OS:
```
sudo apt-add-repository ppa:system76/pop
sudo apt update
sudo apt install pop-theme
```
Esto instala también las fuentes, que son:

Window Titles: `Fira Sans SemiBold 10`

Interface: `Fira Sans Book 10`

Documents: `Roboto Slab Regular 11`

Monospace: `Fira Mono Regular 11`
## Firefox url bar <img align="left" src="https://github.com/hunsrus/linux-config/blob/main/src/firefox.png" width="32px">
Por defecto, las modificaciones en `userChrome.css` están desabilitadas en Firefox. Primero hay que asegurarse que en la página `about:config` de Firefox, la preferencia `toolkit.legacyUserProfileCustomizations.stylesheets` esté seteada en `true` y luego reiniciar el buscador.

Una vez habilitadas las modificaciones, ir a `Menu`->`Help`->`More troubleshooting information` (o directamente ir a `about:support`) y buscar el campo `Profile Directory`. Ir al directorio indicado y pegar la carpeta [chrome](https://github.com/hunsrus/linux-config/tree/main/chrome) conteniendo el archivo `userChrome.css` con las modificaciones perinentes.
En este caso, el archivo contiene código para ocultar la barra url y mostrarla al pasar el mouse por encima.
## Extensiones <img align="left" src="https://github.com/hunsrus/linux-config/blob/main/src/extensiones.png" width="32px">
- [Caffeine](https://extensions.gnome.org/extension/517/caffeine/)
- [Unite](https://extensions.gnome.org/extension/1287/unite/)
- [Ubuntu Appindicators](https://extensions.gnome.org/extension/615/appindicator-support/)
- [Dash to Dock](https://extensions.gnome.org/extension/307/dash-to-dock/)
- [User Themes](https://extensions.gnome.org/extension/19/user-themes/) (para que funcione el tema de pop en el shell de gnome)
- [Color Picker](https://extensions.gnome.org/extension/3396/color-picker/)
- [Hide Top Bar](https://extensions.gnome.org/extension/545/hide-top-bar/)
- [Notification Timeout](https://extensions.gnome.org/extension/3795/notification-timeout/)
- [Removable drive menu](https://extensions.gnome.org/extension/7/removable-drive-menu/)
- [GSConnect](https://extensions.gnome.org/extension/1319/gsconnect/)
- [Vitals](https://extensions.gnome.org/extension/1460/vitals/)
- [DDC Brightness Control](https://extensions.gnome.org/extension/2645/brightness-control-using-ddcutil/)
  1. Install `ddcutil`
  ```
  sudo apt install ddcutil
  ```
  2. Set I2C permissions for non-root users:
  ```
  sudo adduser $USER i2c
  sudo /bin/sh -c 'echo i2c-dev >> /etc/modules'
  ```
  3. Reboot needed
- [Bluetooth Quick Connect](https://extensions.gnome.org/extension/1401/bluetooth-quick-connect/)
- [Fly-Pie](https://extensions.gnome.org/extension/3433/fly-pie/)
- [Sound Output Device Chooser](https://extensions.gnome.org/extension/906/sound-output-device-chooser/)
- [True Color Invert](https://extensions.gnome.org/extension/3530/true-color-invert/)
- Pop Shell

Exlusivas pop:
- Cosmic Dock
- Pop COSMIC
- System76 Power
## Programas que insala el script <img align="left" src="https://github.com/hunsrus/linux-config/blob/main/src/crunchbang.png" width="32px">
- Google Chrome
- Spotify
- VLC
- Crossover
- Office 365
- Discord
- Stremio
- VirtualBox
- Arduino IDE
- GIMP
- Wine
- Winetricks
- Transmission
- OnlyOffice
- Zoom
- Teams
- OBS
- MATLAB
- Proteus
- Multisim
- ISE Design Suite
- KiCad
- Qt Creator
- Audacity
- Gabut DM
- Telegram Desktop
- Vim
- Visual Studio Code
- Xournal

## Keybindings <img align="left" src="https://github.com/hunsrus/linux-config/blob/main/src/keybinding.png" width="32px">
(crear script para setear automáticamente)
## Apagar
**Comando:** `poweroff`

**Combinación:** Mayus+Super+P

## Reiniciar
**Comando:** `shutdown -r now`

**Combinación:** Mayus+Super+R

## Kill
**Comando:** `xkill`

**Combinación:** Mayus+Super+X

## Monitor del sistema
**Comando:** `gnome-system-monitor`

**Combinación:** Mayus+Ctrl+Escape

## SSH Server
**Comando:** `gnome-terminal --execute bash -c "ssh user@xxx.xxx.xxx.xxx -pXXXX"`

**Combinación:** Mayus+Super+D

## Screenshot GUI
**Comando:** `gnome-screenshot -i`

**Combinación:** Mayus+Super+S

## Carpeta Facultad
**Comando:** `nautilus /media/$USER/DATOS/Facultad/`

**Combinación:** Mayus+Super+F

---
# Arch
## WiFi <img align="left" src="https://github.com/hunsrus/linux-config/blob/main/src/crunchbang.png" width="32px">
### netctl
explicacion de uso de netctl-auto
### NetworkManager
explicacion de uso de NetworkManager

## NTFS
Para poder montar discos NTFS instalar `ntfs-3g`
```
sudo pacman -S ntfs-3g
```
Crear la carpeta `media`
```
sudo mkdir /media
```
Y montar ahí el disco
```
sudo mount --mkdir /dev/sdxx /media/DATOS
```
## Wallpaper
Instalar `feh`
```
sudo pacman -S feh
```
Uso:
```
feh --bg-scale /path/to/image.file
```

## audio
https://wiki.archlinux.org/title/Advanced_Linux_Sound_Architecture
https://dev.to/setevoy/linux-alsa-lib-pcmdmixc1108sndpcmdmixopen-unable-to-open-slave-38on

## bluethooth audio
https://unix.stackexchange.com/questions/703088/bluetooth-headset-unable-to-connect-org-bluez-error-failed-br-connection-profil
https://wiki.archlinux.org/title/Bluetooth#Audio

## fonts
Para instalar para todos los usuarios, mover carpeta de la fuente a
```
/usr/local/share/fonts
```

## composer REVISAR (creo que uso otro build)
Un compositor posible es `picom`
```
sudo pacman -S picom
mkdir /home/gabriel/.config/picom
cp /etc/xdg/picom.conf /home/gabriel/.config/picom
```
modificar a gusto (desactivar sombras y redondear bordes)
```
picom --config /home/gabriel/.config/picom/picom.conf
```
FALTA LO DE -B PARA CORRER EN SEGUNDO PLANO

### picom exlude window
Para saber la clase de la ventana y especificarla, ejecutar
```
xprop
```
Hacer click en la ventana y xprop va a tirar toda la información. Buscar el dato `WM_CLASS` y usar eso como identificador en el archivo de configuracion de picom.
Por ejemplo, para excluir una ventana de las reglas de opacidad, modificar la sección de `opacity-rule` y agregar:
```
"100:class_g *= 'texto presente en WM_CLASS'"
```

## autostart
AGREGAR INFORMACIÓN SOBRE EL PATCH DE AUTOSTART PARA DWM
Dar permisos de ejecucion a `.dwm/autostart.sh`.
Agregar en este archivo todo lo que se quiera ejecutar al inicio.
AGREGAR INFORMACIÓN SOBRE LA EJECUCIÓN DE COMANDOS EN ORDEN Y EN SIMULTÁNEO

## kdeconnect
```
sudo pacman -S kdeconnect
/usr/lib/kdeconnect
```

## gestión de monitores
```
git clone https://aur.archlinux.org/mons.git
cd mons/
```
(instalar dependencias)
```
sudo pacman -S help2man
makepkg
git clean dfx
sudo pacman -U mons-0.8.2-1-any.pkg.tar.zst
```
Ejemplo: extender el monitor a la izquierda
```
mons -e left (extender monitor a la izquierda)
```

## screenshots
```
sudo pacman -S maim
```
Sacar una captura de toda la pantalla y guardarla en la ruta de capturas con la fecha como nombre:
```
maim ~/Imágenes/Capturas\ de\ pantalla/$(date +%s).png
```
Asignar el comando a la tecla de imprimir pantalla:
Para identificar la tecla, usar
```
xbindkeys --key
```
Despues de este comando apretar la tecla y las dos ultimas lineas que aparecen son identificadores que se pueden usar en `.xbindkeysrc`.
Por ejemplo, un identificador cómodo es `Print`.

Pegar el siguiente comando en `.xbindkeysrc`:
```
"maim ~/Imágenes/Capturas\ de\ pantalla/$(date +%s).png"
    Print
```
(creo que hay que reiniciar para que tome efecto)

## montar particion de disco identificandola por UUID
Primero averiguar el UUID
```
ls -l /dev/disk/by-uuid/
```
Usar este uuid como argumento para `mount`
```
sudo mount UUID=ARGUMENTO /media/DATOS/
```
Montar en `/media/DATOS` o donde sea
(agregar el comando al autostart)
NO FUNCIONA BIEN
SI LO HACES CON GNOME-DISKS ES MAS FACIL Y DESPUES DE CONFIGURAR EL MONTADO AUTOMATICO TENES QUE REINICIAR SYSTEMD PORQUE SIGUE USANDO LA VERSIÓN VIEJA DE FSTAB
```
sudo systemctl daemon-reload
```

## distribución de teclado US con acentos

https://bbs.archlinux.org/viewtopic.php?id=85392
```
cd /usr/share/X11/xorg.conf.d/
vim 50-gabriel.conf
```
Pegar lo siguiente:
```
Section "InputClass"
    Identifier             "Keyboard Defaults"
    MatchIsKeyboard        "yes"
    Option                 "XkbLayout" "us"
    Option                 "XkbVariant" "intl"
EndSection
```

## configurar fuente en dwm
Explicacion del formato de los parametros:
https://keithp.com/~keithp/render/Xft.tutorial

## dar permiso para apagar a un usuario común a través de polkit
http://www.lukylx.org/polkit.html
```
vim /etc/polkit-1/rulse.d/40-allow-shutdown.rules
```
Pegar:
```
/* Allow specific users to shutdown without authentication */
polkit.addRule(function(action, subject) {
   if ( ( action.id == "org.freedesktop.login1.power-off" ||
          action.id == "org.freedesktop.login1.power-off-multiple-sessions"
        ) && subject.isInGroup("power") ) {
     polkit.log("Powering Off permitted for subject" + subject)
     return polkit.Result.YES;
   }
});
```

## habilitar los repositorios `multilib`
Son necesarios para instalar `wine` por ejemplo.
En el archivo:
```
sudo vim /etc/pacman.conf
```
Descomentar:
```
[multilib]
Include = /etc/pacman.d/mirrorlist
```
IMPORTANTE DESCOMENTAR AMBAS LINEAS

## instalar iconos y cursor de pop-os
dependencias: `meson`, `git`
```
yay -S pop-icon-theme
```
Para tener el dark descargar del repositorio https://github.com/pop-os/icon-theme y copiar la carpeta `Pop-Dark` en `/usr/share/icons` o donde estés instalando los iconos
```
vim .config/gtk-4.0/settings.ini
gtk-icon-theme-name=Pop-Dark
```

## ocultar csd (client side decorations [botones inútiles de ventana]) en gtk
Editar:
```
vim .config/gtk-4.0/settings.ini
```
Agregar:
```
gtk-decoration-layout=:menu
```
(hacer lo mismo para las demás versiones de gtk si es necesario)

## keep screen on
```
xset s off & xset -dpms
```

## juegos viejos de 32 bits
Por ejemplo CMR 2.0

Instalar `wine`
```
sudo pacman -S wine
```
Instalar drivers de audio de 32 bits
```
sudo pacman -S lib32-alsa-lib lib32-alsa-plugins
sudo pacman -S libpulse lib32-libpulse
```
Instalar drivers gráficos de 32 bits
```
sudo pacman -S lib32-mesa
```
Instalar Vulkan de 64 y 32 bits (no recuerdo si es necesario, creo que lo vi en archwiki de steam)
```
sudo pacman -S vulkan-icd-loader lib32-vulkan-icd-loader
sudo pacman -S vulkan-intel lib32-vulkan-intel
```

## abrir terminal desde nautilus
```
yay -S nautilus-open-any-terminal
```
Elegir la terminal (en este caso `alacritty`)
```
gsettings set com.github.stunkymonkey.nautilus-open-any-terminal terminal alacritty
```

## error con aplicaciones java
En caso de que alguna aplicación hecha con Java no muestre correctamente el contenido (caso de software de osciloscopio owon), setear la siguiente environment variable
```
export _JAVA_AWT_WM_NONREPARENTING=1
```

## brillo
crear archivo `rules`
```
sudo vim /etc/udev/rules.d/backlight.rules
```
pegar lo siguiente (permite que usuarios en el grupo `video` modifiquen los archivos referentes al backlight)
```
ACTION=="add", SUBSYSTEM=="backlight", RUN+="/bin/chgrp video $sys$devpath/brightness", RUN+="/bin/chmod g+w $sys$devpath/brightness"
```
agregar usuario al grupo `video`
```
sudo usermod -aG video USER
```
para cambiar el brillo mirar los archivos en
```
/sys/class/backligh/CARPETA_CONTROLADOR/
```
YA HICE UN SCRIPT QUE CONTROLA TODO Y MUESTRA NOTIFICACIONES (ctrl-brightness)
