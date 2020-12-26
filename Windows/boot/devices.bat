@echo off
color 0a
:1
adb devices
ping -n 3 localhost>nul
goto 1