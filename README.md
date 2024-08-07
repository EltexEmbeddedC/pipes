# Каналы

## Сборка и запуск

1. Необходимо перейти в корневую директорию и выполнить команду для сборки проекта `make`

2. Исполняемые файлы появятся в папке `bin`

3. Для удаления всех объектных и исполняемых файлов необходимо выполнить команду `make clean`

## Задания

### Задание 1. Реализовать программу, которая создает неименованный канал и порождает процесс. Родительский процесс закрывает дескриптор для чтения из канала и записывает в канал строку `Hi!`, затем ожидает завершения дочернего процесса. Дочерний процесс закрывает дескриптор для записи в канал, считывает строку из канала и выводит на экран.

В результате работы программа печатает строку `Hi!`.

### Задание 2. Реализовать 2 программы, первая сервер, вторая клиент. Сервер создает именованный канал и открывает его только на запись, записывает строку `Hi!` и завершается. Клиент открывает созданный канал сервером только на чтение, считывает строку из канала и выводит на экран. Удаляет канал.

> В мануале по FIFO говорится: "it has to be open at both ends simultaneously before you can proceed to do any input or output operations on it".

Поэтому запустим сервер в тихом режиме, а затем клиента и увидим надпись `Hi!`.

```bash
alexey@alexey-HVY-WXX9:~/Projects/Eltex/HW/pipes/bin$ ./t2server &
[1] 15381
alexey@alexey-HVY-WXX9:~/Projects/Eltex/HW/pipes/bin$ ./t2client 
Read from FIFO: Hi!
[1]+  Done                    ./t2server
```

### Задание 3. Переписать командный интерпретатор из задания по процессам так, чтобы он поддерживал конструкции вида:

```bash
$ ls -la | grep a
```

Дополненный командный интерпритатор можно найти в [этом репозитории](https://github.com/EltexEmbeddedC/process-management).
