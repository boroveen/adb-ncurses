# adb-ncurses
## install android-tools
termux
```
pkg update && pkg upgrade && pkg install wget
wget -O - https://rendiix.github.io/install-repo.sh | bash && apt-get install adb
```
ubuntu
```
sudo apt install adb
```
arch linux
```
sudo pacman -S adb
```

## install adb-ncurses
```
make
sudo make install
adb-ncurses
```

![adb-ncurses](https://camo.githubusercontent.com/51e998273a02ef9b700494eb3749c929e430e4c523e372369cf74526618a892c/68747470733a2f2f626f726f7665656e2e6769746875622e696f2f766964656f2f6164622d6e6375727365732e676966 "make run")
