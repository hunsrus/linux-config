# Soluciones
## Touchpad
Si el touchpad no funciona después de suspender, pegar `susp-touchpad.sh` en `/lib/systemd/system-sleep/`
## Codecs Privativos
Instalar codecs privativos para reconocer más archivos multimedia
```
sudo apt-get install ubuntu-restricted-extras
```
## Arduino Original
Si no podes comunicarte con arduinos originales usando el IDE, instalá estos paquetes
```
sudo apt-get install openjdk-8-jre avr-libc gcc-avr
```
## Formato Office
Para que el formato en WPS sea más cercano a Office, crear carpeta
```
sudo mkdir /usr/share/fonts/wps-fonts
```
y agregar fuentes de microsoft ahí.
(Para OnlyOffice agregar las fuentes normalmente)
## Super+#
Para el acceso directo con `Super+#` a las aplicaciones favoritas, la extensión Dash to Dock agrega la funcionalidad de nuevo.
## Instalar ISE Design Suite
Las instrucciones y todo lo necesario está en la carpeta `xilinx`
(No incluye instalador pesa una banda)
## QtCreator rompe las bolas con los kits
1. Execute in your terminal the command: `sudo apt-get install qt5-default` to install qt version 5.
2. Verify the version of your Qt and the location of your qmake file. Do this by executing in your terminal the command `qmake --version`. You may have a result similar to this line. QMake version 3.1 Using Qt version 5.9.5 in `/usr/lib/x86_64-linux-gnu`. What's important here is the location `/usr/lib/x86_64-linux-gnu`.
3. Open your Qt-creator.
4. Go to "Tools>Options"
5. Select the Qt Versions combobox and select and click "Add"
6. Then find the qmake file in the location of step 2. Here `/usr/lib/x86_64-linux-gnu/qt5/bin/` here you have the qmake file for qt5. Open it, click Apply.
7. Go to "Kits" combobox. Select Desktop(by default). Then scroll down to the button to select Qt version: and list down to select the version you just add. 
8. Then apply all. Check your compiler and debugger and it's ok. You're done.

Si los proyectos de qt corren bien pero marca errores en las clases como q_dialog, ir a "Help"->"About Plugins" y desactivar "ClangCodeModel". Reiniciar Qt.
# Config
## Tema de PopOS
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
## Extensiones
- [Caffeine](https://extensions.gnome.org/extension/517/caffeine/)
- [Unite](https://extensions.gnome.org/extension/1287/unite/)
- [Ubuntu Appindicators](https://extensions.gnome.org/extension/615/appindicator-support/)
- [Dash to Dock](https://extensions.gnome.org/extension/307/dash-to-dock/)
- [User Themes](https://extensions.gnome.org/extension/19/user-themes/) (para que funcione el tema de pop en el shell de gnome)
- Removable drive menu
- Pop Shell
Exlusivas pop:
- Cosmic Dock
- Pop COSMIC
- System76 Power
## Programas
- [Google Chrome](https://www.google.com/intl/es/chrome/)
- Spotify
- VLC
- Crossover
- Office 365
- Discord
- Stremio
- VirtualBox
- Arduino IDE
- Telegram
- GIMP
- Wine
- Winetricks
- Transmission
- OnlyOffice
## Programas facultad
- Zoom
- Teams
- OBS
- MATLAB
- Proteus
- Multisim
- ISE Design Suite
- KiCad
- Qt Creator
