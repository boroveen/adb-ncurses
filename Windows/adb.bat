@echo off
title ADB_language
color 0a
goto language

:1
cls
set a=o
echo 1 - Русский
echo 2 - English
set /p a=: 
if "%a%"=="1" (goto 11)
if "%a%"=="2" (goto 21) else (goto 1)

: 11
cls
set a=0
echo вы уверены?
echo я буду обнавлять код adb только на английской версий!
echo 1 - да, согласен
echo 2 - нет, назад
set /p a=: 
if "%a%"=="1" (goto 1r)
if "%a%"=="2" (goto 1) else (goto 11)

: 21
cls
set a=0
echo are you sure?
echo I will update the adb code only in English!
echo 1 - yes, I agree
echo 2 - no, back
set /p a=: 
if "%a%"=="1" (goto 1e)
if "%a%"=="2" (goto 1) else (goto 21)

: 1r
echo. удалите этот файл если нужно сбросить язык adb (предложит опять выбрать язык) >> language-r.txt
attrib +h language-r.txt
pause
goto language

: 1e
echo. delete this file if you need to reset the adb language (prompts you again to select the language) >> language-e.txt
attrib +h language-e.txt
pause
goto language1

:language
if exist language-r.txt (goto 2r) else (goto language1)
:language1
if exist language-e.txt (goto 2e) else (goto 1)

:2e
cd ..
cd ..
cd ..
cd adb
start adbEnglish.bat
exit

:2r
cd ..
cd ..
cd ..
cd adb
start adbRashen.bat
exit