@echo off
color 0a
:1
adb devices
echo.
ping -n 1 localhost>nul
cls
goto 1