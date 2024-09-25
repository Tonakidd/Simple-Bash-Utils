# Simple-Bash-Utils

Разработка утилит Bash по работе с текстом: cat, grep.

### Использование cat

`cat [OPTION] [FILE]...`

### Опции cat

| № | Опции | Описание |
| ------ | ------ | ------ |
| 1 | -b (GNU: --number-nonblank) | нумерует только непустые строки |
| 2 | -e предполагает и -v (GNU only: -E то же самое, но без применения -v) | также отображает символы конца строки как $  |
| 3 | -n (GNU: --number) | нумерует все выходные строки |
| 4 | -s (GNU: --squeeze-blank) | сжимает несколько смежных пустых строк |
| 5 | -t предполагает и -v (GNU: -T то же самое, но без применения -v) | также отображает табы как ^I |

### Использование grep 

`grep [options] template [file_name]`

### Опции grep 

| № | Опции | Описание |
| ------ | ------ | ------ |
| 1 | -e | Шаблон. |
| 2 | -i | Игнорирует различия регистра.  |
| 3 | -v | Инвертирует смысл поиска соответствий. |
| 4 | -c | Выводит только количество совпадающих строк. |
| 5 | -l | Выводит только совпадающие файлы.  |
| 6 | -n | Предваряет каждую строку вывода номером строки из файла ввода. |
| 7 | -h | Выводит совпадающие строки, не предваряя их именами файлов. |
| 8 | -s | Подавляет сообщения об ошибках о несуществующих или нечитаемых файлах. |
| 9 | -f file | Получает регулярные выражения из файла. |
| 10 | -o | Печатает только совпадающие (непустые) части совпавшей строки. |


## Part 1. Работа с утилитой cat

Тебе необходимо разработать утилиту cat:
- Она должна поддерживать все флаги (включая GNU версии), указанные [выше](#cat-опции)
- Исходные, заголовочные и сборочный файлы должны располагаться в директории src/cat/
- Итоговый исполняемый файл должен располагаться в директории src/cat/ и называться s21_cat

## Part 2. Работа с утилитой grep

Тебе необходимо разработать утилиту grep:
- Поддержка следующих флагов: `-e`, `-i`, `-v`, `-c`, `-l`, `-n`
- Для регулярных выражений можно использовать только библиотеки pcre или regex  
- Исходные, заголовочные и make файлы должны располагаться в директории src/grep/
- Итоговый исполняемый файл должен располагаться в директории src/grep/ и называться s21_grep

## Part 3. Дополнительно. Реализация некоторых флагов утилиты grep

А это необязательное задание на дополнительные баллы: разработай утилиту grep:
- Поддержка всех флагов, включая: `-h`, `-s`, `-f`, `-o`
- Для регулярных выражений можно использовать только библиотеки pcre или regex  
- Исходные, заголовочные и make файлы должны располагаться в директории src/grep/
- Итоговый исполняемый файл должен располагаться в директории src/grep/ и называться s21_grep

## Part 4. Дополнительно. Реализация комбинаций флагов утилиты grep

А это необязательное задание на дополнительные баллы: разработай утилиту grep:
- Поддержка всех флагов, включая их _парные_ комбинации (например, `-iv`, `-in`)
- Для регулярных выражений можно использовать только библиотеки pcre или regex
- Исходные, заголовочные и make файлы должны располагаться в директории src/grep/
- Итоговый исполняемый файл должен располагаться в директории src/grep/ и называться s21_grep
