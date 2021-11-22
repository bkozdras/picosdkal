# Raspberry Pi Pico SDK Abstract Layer

[![License](https://img.shields.io/badge/License-MIT-purple.svg)](LICENSE)
[![LibraryLanguage](https://img.shields.io/badge/Language-C%20%7C%20C%2B%2B-lightgrey)](LIBRARYLANGUAGE)
[![TestFramework](https://img.shields.io/badge/Test%20Framework-CMocka%20%7C%20GTest-lightgrey)](TESTFRAMEWORK)

[![OS](https://img.shields.io/badge/OS-Linux-lightgrey)](OS)
[![Distribution](https://img.shields.io/badge/Distribution-Ubuntu-lightgrey)](DISTRIBUTION)
[![BuildEnvironment](https://img.shields.io/badge/BuildEnvironment-Docker-lightgrey)](SOURCELANGUAGE)

The repo contains abstract layer / framework used in development for Raspberry Pi Pico target.

TODO

# CI Dashboard

[![CIStatus](https://img.shields.io/github/workflow/status/bkozdras/picosdkal/Pico-SDK-AL-CI?label=CI%20Status)](CISTATUS)

[![JobBuildDockerImage](https://img.shields.io/badge/Job-build--docker--image-lightgrey)](JOBBUILDOCKERIMAGE)
![badgeBuildDockerImage](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/bkozdras/cd2e383311dea01e5e1b133a9769a413/raw/badgeBuildDockerImage.json?service=github)

[![JobLibraryHost](https://img.shields.io/badge/Job-build--lib--host--x86__64-lightgrey)](JobLibraryHost)
![badgeLibHostCMake](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/bkozdras/cd2e383311dea01e5e1b133a9769a413/raw/badgeLibHostCmake.json?service=github)
![badgeLibHostBuild](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/bkozdras/cd2e383311dea01e5e1b133a9769a413/raw/badgeLibHostBuild.json?service=github)

[![JobLibraryTarget](https://img.shields.io/badge/Job-build--lib--target--ARM32--CortexM0%2B-lightgrey)](JobLibraryTarget)
![badgeLibTargetCMake](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/bkozdras/cd2e383311dea01e5e1b133a9769a413/raw/badgeLibTargetCmake.json?service=github)
![badgeLibTargetBuild](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/bkozdras/cd2e383311dea01e5e1b133a9769a413/raw/badgeLibTargetBuild.json?service=github)

[![JobLibraryMocks](https://img.shields.io/badge/Job-build--mocks--lib--host--x86__64-lightgrey)](JobLibraryMocks)
![badgeLibMocksCMake](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/bkozdras/cd2e383311dea01e5e1b133a9769a413/raw/badgeLibMocksCmake.json?service=github)
![badgeLibMocksBuild](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/bkozdras/cd2e383311dea01e5e1b133a9769a413/raw/badgeLibMocksBuild.json?service=github)

[![JobLibraryStubs](https://img.shields.io/badge/Job-build--mocks--lib--host--x86__64-lightgrey)](JobLibraryMocks)
![badgeLibMocksStubs](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/bkozdras/cd2e383311dea01e5e1b133a9769a413/raw/badgeLibStubsCmake.json?service=github)
![badgeLibMocksStubs](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/bkozdras/cd2e383311dea01e5e1b133a9769a413/raw/badgeLibStubsBuild.json?service=github)

[![JobUTX8664](https://img.shields.io/badge/Job-UT--x86--64-lightgrey)](JOBUTX8664)
![badgeUTX8664CMake](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/bkozdras/cd2e383311dea01e5e1b133a9769a413/raw/badgeUTX8664Cmake.json?service=github)
![badgeUTX8664Build](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/bkozdras/cd2e383311dea01e5e1b133a9769a413/raw/badgeUTX8664Build.json?service=github)
![badgeUTX8664CTest](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/bkozdras/cd2e383311dea01e5e1b133a9769a413/raw/badgeUTX8664CTest.json?service=github)

# Preparing of local build environment

All build commands should be executed from docker image attached to this repo as submodule: dockerenv.
It is assumed that Unix OS is used by user.

Build docker image named: nemuuser/rpi-pico-build with tag: latest:
```sh
bash dockerenv/buildImage.sh
```
Run and connect to the command interface (REPO_DIR - directory name of your cloned repository):
```sh
bash dockerenv/runImage.sh
cd workspace/<REPO_DIR>
```

All next steps should be executed from running docker image.

TODO next steps
