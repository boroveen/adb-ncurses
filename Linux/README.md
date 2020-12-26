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

![adb-ncurses](https://github.com/boroveen/boroveen.github.io/blob/master/video/adb-ncurses.gif "make run")
