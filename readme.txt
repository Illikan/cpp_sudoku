Создание консольной версии игры "Судоку"
Было разработано консольное приложение которое позволяет играть в судоку, или смотреть решение судоку, как итоговое, так и пошаговое.

Объявлены такие классы как: 
- Ячейка поля
- Поле судоку
- Валидатор

В классе Ячейка реализованы методы:
- Получение значения
- Установка значения
- Возможность защиты ячейки от редактирования

В классе Валидатор реализованы методы:
- Проверка корректности строчки
- Проверка корректности столбца
- Проверка корректности района
- Проверка корректности решения
- Проверка того, является ли судоку решенным
- Проверка корректности хода

В классе Поле судоку реализованы методы:
- Установки и получения значения в конкретной ячейке
- Решения судоку
- Вывода поля судоку на экран
- Чтения поля судоку с консоли или из переменной
- Совершения хода игроком
- Демонстрационного режима игры

В main происходит выбор режима игры и его исполнение: собственно игра через консоль, вывод решенного судоку или демонстрационный режим

