# adb-ncurses
## install android-tools
termux
```
pkg update && pkg upgrade && pkg install wget
wget -O - https://rendiix.github.io/install-repo.sh | bash && apt-get install adb fastboot
```
ubuntu
```
sudo apt install adb fastboot
```
arch linux
```
sudo pacman -S adb
```

## install ncurses

ubuntu

```
sudo apt install install libncurses-dev
```

arch linux

```
sudo pacman -S ncurses-dev
```

termux

```
pkg install ncurses-dev
```

## install adb-ncurses

linux

```
make
sudo make install
adb-ncurses
```

termux
```
make
make termuxinstall
adb-ncurses
```

![adb-ncurses](https://camo.githubusercontent.com/51e998273a02ef9b700494eb3749c929e430e4c523e372369cf74526618a892c/68747470733a2f2f626f726f7665656e2e6769746875622e696f2f766964656f2f6164622d6e6375727365732e676966 "make run")
