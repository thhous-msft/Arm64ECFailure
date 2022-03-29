param (
    [Parameter(Mandatory = $false)]
    [switch]$Clean = $false
)

$RootDir = $PSScriptRoot

$X64Dir = Join-Path $RootDir buildx64
$ArmDir = Join-Path $RootDir buildarm

if ($Clean) {
    if (Test-Path $X64Dir) { Remove-Item $X64Dir -Recurse -Force | Out-Null }
    if (Test-Path $ArmDir) { Remove-Item $ArmDir -Recurse -Force | Out-Null }
}

if (!(Test-Path $X64Dir)) { New-Item -Path $X64Dir -ItemType Directory -Force | Out-Null }
if (!(Test-Path $ArmDir)) { New-Item -Path $ArmDir -ItemType Directory -Force | Out-Null }

# Executes cmake with the given arguments.
function CMake-Execute([String]$Arguments, $BuildDir) {
    Write-Host "cmake $($Arguments)"
    $process = Start-Process cmake $Arguments -PassThru -NoNewWindow -WorkingDirectory $BuildDir
    $handle = $process.Handle # Magic work around. Don't remove this line.
    $process.WaitForExit();

    if ($process.ExitCode -ne 0) {
        Write-Error "[$(Get-Date)] CMake exited with status code $($process.ExitCode)"
    }
}

$X64ConfigureArguments = ".. -A x64"
$X64BuildArguments = "--build ."

CMake-Execute -Arguments $X64ConfigureArguments -BuildDir $X64Dir
CMake-Execute -Arguments $X64BuildArguments -BuildDir $X64Dir

$ArmConfigureArguments = ".. -A arm64ec"
$ArmBuildArguments = "--build ."

CMake-Execute -Arguments $ArmConfigureArguments -BuildDir $ArmDir
CMake-Execute -Arguments $ArmBuildArguments -BuildDir $ArmDir
