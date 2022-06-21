---
# Tabla de contenidos
1. [Soluciones](https://github.com/hunsrus/linux-config#soluciones)
    - [Touchpad](https://github.com/hunsrus/linux-config#touchpad-)
    - [Codecs](https://github.com/hunsrus/linux-config#codecs-privativos-)
    - [Arduino Original](https://github.com/hunsrus/linux-config#arduino-original-)
    - [Formato Office](https://github.com/hunsrus/linux-config#formato-office-)
    - [Super+#](https://github.com/hunsrus/linux-config#super-)
      - [Metodo sin Dash to Dock](https://github.com/hunsrus/linux-config#metodo-sin-dash-to-dock)
      - [Solución para Pop_OS](https://github.com/hunsrus/linux-config#soluci%C3%B3n-para-pop_os)
    - [Instalar ISE Design Suite](https://github.com/hunsrus/linux-config#instalar-ise-design-suite-)
    - [QtCreator kits](https://github.com/hunsrus/linux-config#qtcreator-rompe-las-bolas-con-los-kits-)
    - [Default magnet link handler](https://github.com/hunsrus/linux-config#cambiar-magnet-link-handler-por-defecto-)
    - [Default to high performance mode](https://github.com/hunsrus/linux-config#default-to-high-performance-mode-)
2. [Config](https://github.com/hunsrus/linux-config#config)
    - [Tema de PopOS](https://github.com/hunsrus/linux-config#tema-de-popos-)
    - [Extensiones](https://github.com/hunsrus/linux-config#extensiones-)
    - [Script instalador](https://github.com/hunsrus/linux-config#programas-que-insala-el-script-)
    - [Keybindings](https://github.com/hunsrus/linux-config#keybindings-)
---
# Soluciones
## Touchpad <img align="left" src="https://st.depositphotos.com/1010146/3709/v/600/depositphotos_37097981-stock-illustration-pointing-finger-click-icon.jpg" width="28px">
Si el touchpad no funciona después de suspender, pegar `susp-touchpad.sh` en `/lib/systemd/system-sleep/`
(darle permisos de ejecución)
## Codecs Privativos <img align="left" src="https://www.iconpacks.net/icons/1/free-video-icon-831-thumb.png" width="36px">
Instalar codecs privativos para reconocer más archivos multimedia
```
sudo apt-get install ubuntu-restricted-extras
```
## Arduino <img align="left" src="https://electronperdido.com/wp-content/uploads/2021/02/arduino-logo-1.png" width="32px">
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
## Formato Office <img align="left" src="https://download.onlyoffice.com/assets/fb/fb_icon_325x325.jpg" width="32px">
Para que el formato en WPS sea más cercano a Office, crear carpeta
```
sudo mkdir /usr/share/fonts/wps-fonts
```
y agregar fuentes de microsoft ahí.
(Para OnlyOffice agregar las fuentes normalmente)
## Super+# <img align="left" src="https://cdn2.hubspot.net/hub/53/file-23123745-jpg/blog/images/hashtag.jpg" width="34px">
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

## Instalar ISE Design Suite <img align="left" src="https://github.com/hunsrus/linux-config/blob/main/xilinx/ise_ds.png" width="32px">
Las instrucciones y todo lo necesario está en la carpeta `xilinx`
(No incluye instalador pesa una banda)
## QtCreator rompe las bolas con los kits <img align="left" src="https://upload.wikimedia.org/wikipedia/commons/thumb/0/0b/Qt_logo_2016.svg/1200px-Qt_logo_2016.svg.png" width="36px">
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

## Cambiar magnet link handler por defecto <img align="left" src="https://cdn-icons-png.flaticon.com/512/2292/2292246.png" width="32px">
Mostrar opciones:
```
gio mime x-scheme-handler/magnet
```
Determinar handler por defecto:
```
xdg-mime default HANDLER.desktop x-scheme-handler/magnet
```

## Default to high performance mode
Para que el sistema inicie en modo de alto rendimiento agregar el comando a las aplicaciones de inicio:

    system76-power profile performance
---
# Config
## Tema de PopOS <img align="left" src="https://betanews.com/wp-content/uploads/2017/06/pop_logo.png" width="32px">
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
## Extensiones <img align="left" src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/c8/Antu_kt-plugins.svg/1024px-Antu_kt-plugins.svg.png" width="34px">
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
## Programas que insala el script <img align="left" src="https://zhihuicao.files.wordpress.com/2016/03/2000px-poundexclam-svg.png" width="34px">
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

## Keybindings <img align="left" src="https://github.com/hunsrus/linux-config/blob/main/src/keybindings.png" width="34px">
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
