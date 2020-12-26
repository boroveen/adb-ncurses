@echo off
setlocal enableextensions enabledelayedexpansion
set tm=%time%
set hh=!tm:~0,2!
set mm=!tm:~3,2!
if !hh! lss 19 (
    goto bl_cl_a
    goto :done
)
if !hh! equ 19 (
    if !mm! lss 30 (
        goto bl_cl_a
        goto :done
    )
)
goto clcl_a
:done
endlocal

:bl_cl_a
@Color B0
goto adb

:clcl_a
@Color 0F
goto adb

:adb
title ADB and FASTBOOT command line
@explorer.exe "https://androidp1.ru"
@adb version & echo . & fastboot --version
@cmd