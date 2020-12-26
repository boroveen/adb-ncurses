@echo off
color 0a
title reset language
goto language

:language
if exist language-r.txt (
    goto language-r
) else (
    goto language1
)
:language1
if exist language-e.txt (
    goto language-e
) else (
    goto language2
)

:language-r
echo ...
attrib -h language-r.txt
del language-r.txt
exit


:language-e
attrib -h language-e.txt
del language-e.txt
exit



:language2
echo error: no file language
pause
exit