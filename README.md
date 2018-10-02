# Project 1: Linux -> Windows

## Opstelling Cross Compiler
### MXE
Voor een project te cross-compileren van Linux naar Windows  heb ik een VM gebruikt. Ik gebruikte VirtualBox om een VM aan te maken. De VM OS is Ubuntu.

Ik heb het volgende artikel gebruikt als leidraad:
[StackOverflow: Building Qt 5 on Linux, for Windows](https://bit.ly/2OGslJR) 

Voordat ik MXE kon downloaden moest ik eerst git zelf installeren.
De lijst van alle nodige libraries staat op mxe.cc/#requirements-debian

```
sudo apt install git`
git clone https://github.com/mxe/mxe.git
sudo apt-get install autoconf automake autopoint ... unzip wget wz-utils
```

### Qt5

Voor het crosscompilere heeft de docent het volgende commando ingevoerd:
```
cd /home/mxe
make qt5
```

Ik maak een omgevingsvariabele aan en voerde qmake en make:

```
export PATH=/home/quinten/mxe/usr/bin:$PATH
/home/quinten/mxe/usr/i686-w64-mingw32.static/qt5/bin/qmake
make
```

Ik gebruikte wine om de applicatie te laten zien:

```
wine ~/Desktop/Q/QtTimeTimer-master/release/TestCase.exe
```

![pic1]

## QtCreator

Ik begon aan het maken van mijn applicatie in Qt.
Mijn applicatie kan een lettertype of de inhoud van een bestand laten zien.


[pic1]: pic1.png