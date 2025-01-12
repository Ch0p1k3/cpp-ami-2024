# WSL

## Вступление

Начиная с Windows 10 появилась такая фича как WSL: Windows Subsystem for Linux,
с её помощью можно запускать Linux-приложения на Windows.

Как мне кажется, то это самый легкий способ для пользователей Windows облегчить себе жизнь на курсе по C++. Установка WSL не занимает большого количества времени и в VSCode есть интеграция с ним.

## Quick start

Полная инструкция https://learn.microsoft.com/ru-ru/windows/wsl/install:

0. (Рекомендуется, но необязательно) Установить [Windows Terminal](https://www.microsoft.com/store/apps/9n0dx20hk701), чтобы красиво пользоваться терминалом на Windows.
1. Открыть PowerShell в режиме администратора и выполнить `wsl --install`, перезапустить компьютер.
2. Открыть PowerShell и выполнить `wsl --install -d Ubuntu-20.04`.
3. Запустить Ubuntu-20.04 ([все способы](https://learn.microsoft.com/ru-ru/windows/wsl/install#ways-to-run-multiple-linux-distributions-with-wsl)).
4. Если вы используете VSCode, то он автоматически предложит использовать WSL. [WSL в VSCode](https://learn.microsoft.com/en-us/windows/wsl/tutorials/wsl-vscode).


## P.S.

Я бы советовал однажды полноценно пересесть на Linux (я лично пользуюсь Ubuntu). Совсем необязательно сносить Windows, всегда можно поставить Linux второй системой - загуглите "ubuntu dual boot windows" и пойдите по одному из гайдов.
Также я совсем не знаю про интеграцию WSL с CLion, так что рекомендовал бы пользоваться VSCode или каким-нибудь "терминальным" текстовым редактором (vim, neovim).
