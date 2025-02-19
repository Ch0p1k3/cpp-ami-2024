---
marp: true
paginate: true
---

# Препроцессинг
- Начинается с `#`
  - `#include`
  - `#define`
```bash
clang++ -E -P main.cpp | less

clang++ -E -P -DTEST_FLAG=HELLO main.cpp | less
```
---
# Объектные файлы
В объектных файлах:
- Скомпилированный, соптимизированный машинный код
- Символы
  - Локальные
  - Глобальные
  - Неопределенные
```bash
clang++ main.cpp -c -o main.o
clang++ lib.cpp -c -o lib.o

objdump -t main.o | c++filt | less
```
- mangling
---
# Линковка
Соединяет все символы объектников и превращает все это в исполняемый файл
---
---
# ODR (One Definition Rule)
https://en.cppreference.com/w/cpp/language/definition
---
---
# Циклы в include
