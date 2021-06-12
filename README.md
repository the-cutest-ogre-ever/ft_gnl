## get_next_line
Функция get_next_line считывает символы из входного файла в буффер заданного при компиляции размера. В качестве входных данных она принимает файловый дескриптор и указатель на строку, в которую будет записана считанная из файла строчка. Функция возвращает 1, если выводимая сейчас строка не является последней в рассматриваемом файле, и 0, если является.

Пример компиляции:
```с
gcc -D BUFFER_SIZE=XX get_next_line.h get_next_line.c get_next_line_utils.c
```
, где на месте XX можно указать любое число. Это размер буфера, куда функция записывает считанные данные.
Если в качетве размера буфера задать отрицательное число или ноль, функция ничего не считает.

Прототип функции:
```с
int get_next_line(int fd, char **line);
```
Пример использования функции:
```с
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

int main() {
    int ret;
    char *line;

    line = 0;
	int fd = open("text", O_RDONLY);
    ret = get_next_line(fd, &line);
    while (ret > 0) {
        write(1, line, ft_strlen(line));
        write(1, "\n", 1);
        free(line);
        line = 0;
        ret = get_next_line(fd, &line);
    }
    if (ret == 0) {
        write(1, line, ft_strlen(line));
        free(line);
        line = 0;
   }
	return (0);
}
```
