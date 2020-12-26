@echo off
title ADB_TOOLS
color 0a
adb start-server
ping -n 1 localhost>nul
echo.
echo Версия 2.0 БЕТА
echo.
echo       ADB
echo.
pause
: 11
set a=0
cls
adb devices
echo MAIN
echo 1 - cmd
echo 2 - перезагрузга и вход в recovery
echo 3 - вход в загрущик - bootloader
echo 4 - дальше
echo 5 - выход
set /p a=: 
if "%a%"=="1" (goto 1)
if "%a%"=="2" (goto 2)
if "%a%"=="3" (goto 3)
if "%a%"=="4" (goto next)
if "%a%"=="5" (goto exit) else (goto 11)

:1
echo.
cmd
goto 11

:2
adb reboot recovery
echo.
cmd
goto 11

:3
adb reboot bootloader
echo.
cmd
goto 11

: next
set next=0
cls
adb devices
echo NEXT MAIN
echo 1 - запуск recover с папки recover (обезательно скачайте рекавори своего телефона для запуска)
echo 2 - устройства
echo 3 - проверка устройства с другого батника
echo 4 - запуск cmd
echo 5 - дальше 2
echo 6 - назад
set /p next=: 
if "%next%"=="1" (goto fast)
if "%next%"=="2" (goto devices)
if "%next%"=="3" (start devices.bat&&goto next)
if "%next%"=="4" (goto scmd)
if "%next%"=="5" (goto 2next)
if "%next%"=="6" (goto 11) else (goto next)

: fasterror
cls
echo error: нет файла recovery.img
pause
cd ..
goto next

: fast
cd recovery
if exist recovery.img (goto fast1) else (goto fasterror)
: fast1
set devic=0
cls
dir N recovery.img
adb devices
echo fastboot
echo 1 - запуск с папки recovery (обезательно recovery должа быть для телефона)
echo 2 - прошить recovery (обезательно recovery должа быть для телефона)
echo 3 - назад
set /p devic=: 
if "%devic%"=="1" (goto runrecovery)
if "%devic%"=="2" (goto flashrecovery)
if "%devic%"=="3" (cd ..&&goto next) else (goto fast1)

: runrecovery
adb reboot bootloader
ping -n 10 localhost>nul
fastboot devices
pause
fastboot boot recovery.img
cd ..
goto 11

: flashrecovery
adb reboot bootloader
ping -n 10 localhost
fastboot devices
pause
fastboot flash recovery recovery.img
fastboot reboot
goto 11

: devices
cls
adb devices -l
echo 1 - меню
echo 2 - ещё
set /p devis=: 
if "%devis%"=="1" (set devis=2&&goto 11) else (goto devices)

: scmd
start cmd
goto 11

: exit
adb kill-server
exit

: 2next
set next=0
cls
adb devices
echo 1 - загрузка boot из папки boot
echo 2 - назад
set /p next=: 
if "%next%"=="1" (goto flashboot)
if "%next%"=="2" (goto next) else (goto 2next)

: flashbooterror
echo error: нет файла boot.img
pause
cd ..
goto 2next

: flashboot
cd boot
if exist boot.img (goto flashboot1) else (goto flashbooterror)

: flashboot1
set flash=0
cls
adb devices
dir N boot.img
echo 1 - запуск boot
echo 2 - прошивка boot
echo 3 - назад
set /p flash=: 
if "%flash%"=="1" (goto launchboot)
if "%flash%"=="2" (goto flashboot2)
if "%flash%"=="3" (cd ..&&goto 2next) else (goto flashboot)

: launchboot
adb reboot bootloader
ping -n 10 localhost>nul
fastboot devices
pause
fastboot boot boot.img
cd ..
goto 11

: flashboot2
adb reboot bootloader
ping -n 10 localhost
fastboot devices
pause
fastboot flash boot boot.img
fastboot reboot
goto 11