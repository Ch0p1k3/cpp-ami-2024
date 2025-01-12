# Visual Studio Code

## Установка

Переходим по [ссылке](https://code.visualstudio.com/), скачиваем и устанавливаем.

## После установки

Открываем VSCode. Можно открыть директорию, в которой вы будете решать задачи - `File -> Open Folder`. Через левую менюшку можно создавать файлы: `ПКМ -> New file`. Запускать можно через кнопку ▶️ (только после установки плагина [Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)) (я не советую такой подход и пропагандирую запуск, через [shell](shell.md)).

## Cписок плагинов
- [clangd](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd) - go-to-definition, intellisense, подсвечивание ошибок и т. д.
- [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) - для поддержки СMake в VSCode. Позволяет собирать и запускать таргеты СMake по кнопкам в VSCode.
- [CMake](https://marketplace.visualstudio.com/items?itemName=twxs.cmake) - подсветка синтаксиса и автодополнение СMake. Пока опционально, но скорее всего вы будете писать свои CMake файлы.
- [WSL](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-wsl) - для пользователей Windows, которым нужно подключиться к WSL.
- [Sort lines](https://marketplace.visualstudio.com/items?itemName=Tyriar.sort-lines) - вообще необязательно, но я с помощью этого расширения сортирую инклюды.
- [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) - вообще говоря это аналог `clangd`. Но этот плагин нам понадобиться только для дебага с помощью `GDB` внутри `vscode`. **Тем у кого MacOS с процессором `ARM` архитектуры (`M1`/`M2`) не нужно качать этот плагин, так как они не смогут установить себе `GDB`, так как он не поддержан на данной архитектуре процессоров.**
- [CodeLLDB](https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb) - этот плагин нужен пользователям MacOS c ARM для того, чтобы взаимодействовать с `LLDB` через MacOS.

## Дебаг через GDB в VSCode

**Если у вас MacOS с процессором `ARM` архитектуры (`M1`/`M2`), то нужно дебажиться через другой дебагер - [LLDB](#дебаг-через-lldb-в-vscode).**

[GNU Debugger (GDB)](https://en.wikipedia.org/wiki/GNU_Debugger) - дебагер, который используется для множества языков. Лично нам он нужен для дебага `C++` кода. Вообще говоря, советую использовать дебагер напрямую, через `shell`, а не настраивать взаимодействие с ним через `VSCode`. Советую глянуть [лекцию Кутенина про GDB и LLDB](https://www.youtube.com/watch?v=Q5pe47sjE1g).

1. Устанавливаем плагин [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools). Если будет нотификация о том, что `C/C++` и `clangd` плагины конфликтуют, то надо выключить `IntelliSense` в плагине `C/C++`.
2. Вставляем такой `JSON` в `.vscode/launch.json` (создаем директорию и файл, если такого пути еще нет):
<img src="images/launch.json.png"/>

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            // Resolved by CMake Tools:
            "program": "${command:cmake.launchTargetPath}",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [
                {
                    // add the directory where our target was built to the PATHs
                    // it gets resolved by CMake Tools:
                    "name": "PATH",
                    "value": "${env:PATH}:${command:cmake.getLaunchTargetDirectory}"
                },
            ],
            "console": "externalTerminal",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
    ]
}
```

3. Нажимаем `Run and Debug` (все должно выглядить как на скрине):
<img src="images/run_and_debug.png" width="500"/>

4. Выбираем нужный `target` в `CMake`:
<img src="images/cmake_target.png" width="500"/>

5. Ставим breakpoint (красную точку, надо нажать слева от цифры):
<img src="images/breakpoint.png"/>

6. Нажимаем `Start debugging` (или `F5` на клавиатуре):
<img src="images/start_debugging.png"/>

Все будет запущено. Можно дебажить через интерфейс `VSCode`. Через `DEBUG CONSOLE` можно писать команды `GDB` добавляя `--exec`, например:
```
--exec n
```
<img src="images/debug_console.png"/>


## Дебаг через LLDB  в VSCode

**Если у вас не MacOS с процессором `ARM` архитектуры (`M1`/`M2`), то лучше использовать [GDB](#дебаг-через-gdb-в-vscode).**

[LLDB](https://lldb.llvm.org/) - дебагер от проекта [LLVM](https://llvm.org/). `LLDB` отличается от `GDB`, если использовать его через `shell`, но кажется взаимодействие с ним через интерфейс `VSCode` не должно сильно отличаться от аналогичного взаимодействия с `GDB`.

1. Устанавливаем плагин [CodeLLDB](https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb).
2. Аналогично инструкции [GDB](#дебаг-через-gdb-в-vscode), только другой `launch.json`:
```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(lldb) Launch",
            "type": "lldb",
            "request": "launch",
            // Resolved by CMake Tools:
            "program": "${command:cmake.launchTargetPath}",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [
                {
                    // add the directory where our target was built to the PATHs
                    // it gets resolved by CMake Tools:
                    "name": "PATH",
                    "value": "${env:PATH}:${command:cmake.getLaunchTargetDirectory}"
                },
            ],
            "console": "externalTerminal",
            "MIMode": "lldb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for lldb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
    ]
}
```
3-6 шаги аналогично с [GDB](#дебаг-через-gdb-в-vscode).

## Полезные комбинации клавиш

Вообще вот ссылка на все стандартные комбинации клавиш:
- [Windows](https://code.visualstudio.com/shortcuts/keyboard-shortcuts-windows.pdf)
- [MacOS](https://code.visualstudio.com/shortcuts/keyboard-shortcuts-macos.pdf)
- [Linux](https://code.visualstudio.com/shortcuts/keyboard-shortcuts-linux.pdf)

Вообще я не вижу сильной разницы между Linux и Windows, но зато есть существенная разница с MacOS. Я напишу классный комбинации сюда, пользуясь Linux/Windows клавиатурой, так как таких большинство. Начнем:
- `Ctrl + O` - открыть файл.
- `Ctrl + P` - перейти к файлу, если написать `:` и номер строки (можно -1, если нужно в конец файла), то перейдете к строке.
- `Ctrl + Shift + P` - тоже самое, что `Ctrl + P` и написать `>`. Это откроет вам `command palette` (извиняйте русский перевод мне не нравится). Здесь можно перезагрузить окно - `Developer: Reload windows`, открыть настройки шорткатов `Preferences: Open Keyboard Shortcuts`, изменение темы `Preferences: Color Theme` и т.д. Также можно пользоваться штуками из плагинов, - просто начните писать название плагина и оно вам покажет, что доступно.
- `Ctrl + ЛКМ` по слову в коде или `F12` - часто говорят прямо на английском `Go to definition`, что в переводе и значит переход к определению чего-либо.
- `Ctrl + B` - открывает/закрывает левую панель.
- `Ctrl + ~` - открывает/закрывает терминал.
- `Ctrl + K Z` - включает/выключает Zen Mode. Также можно два раза нажать `Esc`, чтобы выйти.
- `Ctrl + Space` - автодополнение в коде.
- `F2` - рефакторинг - надо выделить нужную переменную и нажать F2, тогда можно будет переименовать ее везде (на самом деле неправда, но почти все переименовывает).
- `Ctrl + D` - выделите текст и нажмите эту комбинацию, тогда при каждом нажимании курсор будет размножаться на выделенный вами текст.
- `Ctrl + ↑`, `Ctrl + ↓` - переместить курсор вверх/вниз.
- `Ctrl + L` - выделить строку.
- `Ctrl + X` - вырезать строку.
- `Ctrl + /` - закомментировать строку кода.
- `Alt + Z` - включить режим `word wrap`.
- `Shift + Alt + F` - форматнуть документ.

## Открыть VSCode из терминала

```bash
code /home/chopik/python
```

То есть надо написать `code` и нужную директорию. Если директорию не указать, то по-умолчанию берется текущая. [Ссылка на базовые команды в терминале](terminal.md).

## Автоматическое удаление лишних пробелов в конце строк

https://bobbyhadz.com/blog/remove-trailing-whitespace-vscode

## Автоматическое добавление последней пустой строки в файле

https://stackoverflow.com/questions/44704968/visual-studio-code-insert-newline-at-the-end-of-files
