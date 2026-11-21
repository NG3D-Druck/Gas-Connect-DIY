# Builds and runs the tests for gas-costs.h with Visual Studio C++ (MSVC)
$ErrorActionPreference = 'Stop'
$vs = & "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
$out = Join-Path $env:TEMP 'gas-costs-test'
New-Item -ItemType Directory -Force $out | Out-Null
$src = Join-Path $PSScriptRoot 'gas-costs-test.cpp'
cmd /c "`"$vs\VC\Auxiliary\Build\vcvars64.bat`" >nul && cl /nologo /std:c++17 /W4 /EHsc `"$src`" /Fo`"$out\\`" /Fe`"$out\gas-costs-test.exe`""
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
& "$out\gas-costs-test.exe"
exit $LASTEXITCODE
