# **THE LAST OF US PART II GODOT WIDGET PROJECT**

## ПРЕДИСЛОВИЕ

Данный проект представляет собой пример реализации виджета, вдохновленного интерфейсом из игры [The Last of Us Part II](https://store.steampowered.com/app/2531310/The_Last_of_Us_Part_II_Remastered). В проекте используется GDExtension API для создания виджета в игровом движке [Godot Engine](https://godotengine.org).

|  |
| :--: |
| **Интерфейс The Last of Us Part II - [Источник](https://www.naughtydog.com/blog/the_last_of_us_part_ii_remastered_announcement)** |
| ![1](/doc/images/1.JPG) |

## ОПИСАНИЕ

Виджет представляет собой визуальный элемент, отображаемый в нижнем правом углу экрана и предназначенный для интеграции в HUD (Heads-Up Display).
Он предназначен для отображения динамически изменяющихся данных, управляемых через шаблон MVVM.

Взаимодействие с виджетом осуществляется посредством шаблона MVVM через `SystemUIManager`.

Бизнес-логика работы виджета представлена в методе-члене `_body`:

```cpp
// ОСНОВНОЕ ТЕЛО
void SystemUIManager::_body()
{
    ...
}
```

> [!WARNING]
> Обработка виджета завершена частично: реализована поддержка 4 элементов.

Элементы виджета расположены в клссе `WidgetHandler`:

```cpp
class WidgetHandler final
{
private:
    NProgressBar_0::ProgressBar_0* m_progressBar_0 = nullptr;
    NProgressBar_1::ProgressBar_1* m_progressBar_1 = nullptr;

    CustomLabel* m_customLalbel = nullptr;
public:
    WidgetHandler();
    ~WidgetHandler();

    void set_root(godot::Window* root);

    NProgressBar_0::ProgressBar_0* getProgerssBar_0() noexcept { return m_progressBar_0; }
    NProgressBar_1::ProgressBar_1* getProgerssBar_1() noexcept { return m_progressBar_1; }

    CustomLabel* getCustomLalbel() noexcept { return m_customLalbel; }
};
```

**Результат работы**:
На изображениях показаны примеры работы.

|  |  |
| :--: | :--: |
| ![1](/doc/images/2.PNG) | ![2](/doc/images/2.PNG) |
| ![3](/doc/images/3.PNG) | ![4](/doc/images/4.PNG) |

Используемый шрифт: [DIN Next LT Arabic Medium](https://www.onlinewebfonts.com/download/aba1a083bf50980a05f0265179103a09)

|  |
| :--: |
| ![1](/doc/images/1.GIF) |

## ЗАКЛЮЧЕНИЕ

Этот репозиторий предоставляет базовый пример реализации виджета в стиле The Last of Us Part II с использованием GDExtension и MVVM.

Репозиторий содержит уже собранную библиотеку расширения.

## ССЫЛКИ

* [Godot Engine](https://godotengine.org) - Официальный сайт Godot Engine.
* [Godot Docs](https://docs.godotengine.org/en/stable/index.html) - Официальная сайт документации Godot Engine.
