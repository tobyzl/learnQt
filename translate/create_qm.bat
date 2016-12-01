@echo off
for %%q in (*.qm*) do (
    del "%%q"
)

pause

for %%i in (*.ts*) do (
    lrelease "%%i"
)


pause