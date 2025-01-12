# Прочее

[Установка brew для MacOS](macos_brew.md)

## Установка последней стабильной версии clang
### MacOS
```zsh
brew install llvm
```
### Linux с Advanced Packaging Tool (APT)
https://apt.llvm.org/
```bash
sudo bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)"
sudo ln -s /usr/bin/clang++-17 /usr/bin/clang++
```

Первая команда скачивает скрипт, который впоследствии выполняет. Скрипт устанавливает последнюю стабильную версию `clang`. После установки (почти наверное) в директории `/usr/bin` будет находится исполняемый файл вида `clang++-<version>`. И вот нам нужна вторая команда, которая создает [symlink](https://ru.wikipedia.org/wiki/%D0%A1%D0%B8%D0%BC%D0%B2%D0%BE%D0%BB%D0%B8%D1%87%D0%B5%D1%81%D0%BA%D0%B0%D1%8F_%D1%81%D1%81%D1%8B%D0%BB%D0%BA%D0%B0) `clang++`, который ссылается на `clang++-<version>`.

## Установка git
### MacOS
```zsh
brew install git
```
### Linux с Advanced Packaging Tool (APT)
```bash
sudo apt update && sudo apt install git
```

## Установка make
### MacOS
```zsh
brew install make
```
### Linux с Advanced Packaging Tool (APT)
```bash
sudo apt update && sudo apt -y install make
```


## Установка cmake
### MacOS
```zsh
brew install cmake
```
### Linux с Advanced Packaging Tool (APT)
Не ставьте `cmake` через `snap`, в `snap` обычно `cmake` очень старой версии. Ставить `cmake` лучше через APT:
```bash
sudo apt install cmake
```

## Установка GDB
### MacOS с процессором x86
```zsh
brew install gdb
```
### Linux с Advanced Packaging Tool (APT)
```bash
sudo apt update && sudo apt install gdb
```

## Установка LLDB
### MacOS
```zsh
brew install lldb
```
