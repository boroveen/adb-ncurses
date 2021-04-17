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

![adb-ncurses](https://boroveen.github.io/jpeg/screenadbncurses.png "make run")
