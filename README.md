# KipTool

KipTool основан на [TegraExplorer](https://github.com/suchmememanyskill/TegraExplorer) v4.1.1

## Установка
1. Поместить `KipTool.bin` в `bootloader/payloads` на вашей карте
1. Загрузиться в `Hekate`
1. Загрузить пейлоад: `Payloads` -> `KipTool.bin`

## Управление

### Навигация в меню KipTool
- `A`: Выбрать
- `B`: Назад
- Левый стик или кнопки крестовины `верх`/`низ`: вверх/вниз по меню
- Левый стик или кнопки крестовины `лево`/`право`: перейти к первой/последней записи меню или переключение страниц
- Правый стик `верх`/`низ`: быстрое перемещение по меню вверх/вниз по меню
- `Кнопка захвата`: Сделать скриншот

### Навигация в окне редактирования значения параметра
- `A`: Задать новое значение
- `B`: Выйти без изменений
- Левый стик или кнопки крестовины `лево/право`: изменить значение на +- шаг
- Левый стик или кнопки крестовины `верх/низ`: изменить значение на +- шаг * 10

### Навигация в окне подтверждения
- `A`: Применить ответ
- `B`: Выйти
- Левый стик или кнопки крестовины `лево`/`право`: переключение между `Yes` и `No`

### Альтернативное управление
- `Громкость +` = `право`
- `Громкость -` = `лево`
- `Питание` = `A`
- `Громкость -` и `Громкость +` одновременно = `B`

### Режим сенсорного управления
Для включения `рижима сенсерного управления` необходимо при загрузке пейлоада `KipTool.bin` зажать кнопку `Громкость -` (области "сенсорных кнопок" не отображаются, используйте воображение)

![Touch mode](/screenshots/touch.jpg)

## Использование редактора параметров
1. `Browse SD`
1. Найти ваш `loader.kip` файл
1. Открыть меню файла
1. `Kip tool` -> `Kip Wizard`

При первом запуске `Kip Tool`'а в корне вашей карты будет создана служебная директория `.kt`.

При первом запуске `Kip Wizard`'а в директории `.kt` будет создан файл сессии `session.bin`.

Файл сессии ничто иное, как дамп `CustomizeTable` из вашего `loader.kip` файла. Таким образом, изменения значений параметров сперва производятся в сессии, а затем их можно применить к вашему файлу `loader.kip`.

При повторном открытии `Kip Wizard`'а, если ранее был создан файл сессии, вам будет предложено загрузить его в качестве текущей сессии. При отказе файл сессии будет перезаписан значениями из вашего `loader.kip`.

В текущей реализации нет привязки файла сессии к конкретному `.kip` файлу. Поэтому файл сессии может быть перезаписан при открытии другого `.kip` файла. БУДЬТЕ ВНИМАТЕЛЬНЫ!

При загрузке `loader.kip` файла и сессии производится минимальная проверка на соответствие текущей поддерживаемой версии (число после дефиса в версии `Kip Tool`) `CustomizeTable`'а и наличие `CUST` паттерна, что предотвращает случайное открытие других [модулей](https://github.com/Atmosphere-NX/Atmosphere/tree/master/docs/components/modules) `atmosphere`'ы, если в нем конечно случайно нет `CUST` паттерна\)

5. В главном меню выбрать необходимую `категорию`(`CPU`/`GPU`/`RAM`) параметров
6. Выбрать необходимый `параметр`/`таблицу`
7. Для выбранного параметра выбрать `фиксированное значение` или задать вручную, если это возможно через пункт `Manual value`
8. После внесения изменений вернуться на главный экран `Kip Wizard`'а и с помощью `Apply changes` применить изменения к текущему `.kip` файлу

## Цветовые обозначения
### Параметр (в меню выбора параметра)
-  ![#8040ff](https://placehold.co/15x15/8040ff/8040ff.png) - Имеет дефолтное значение
- ![#ff8c00](https://placehold.co/15x15/ff8c00/ff8c00.png) - Имеет недефолтное значение
- ![#ffff40](https://placehold.co/15x15/ffff40/ffff40.png) - Является таблицей

![Params menu](/screenshots/params_menu.jpg)

### Значение (в меню редактирования параметра)
- ![#00ddff](https://placehold.co/15x15/00ddff/00ddff.png) - Является текущим значением
- ![#8040ff](https://placehold.co/15x15/8040ff/8040ff.png) - Является дефолтным значением
- ![#ff8c00](https://placehold.co/15x15/ff8c00/ff8c00.png) - Является недефолтным значением
- ![#ffff40](https://placehold.co/15x15/ffff40/ffff40.png) - Пункт задания значения вручную

![Params menu](/screenshots/edit_param.jpg)

## Скриншоты

![Main menu](/screenshots/main_menu.jpg)

![CPU Params](/screenshots/cpu_params.jpg)

![Value editor](/screenshots/value_editor.jpg)