# Component Programming Technologies

Учебный репозиторий по курсу **«Технологии компонентного программирования»** (COM / ActiveX). Проект содержит лабораторные работы на C++, C# и Visual Basic с пошаговым усложнением: от собственного in-process COM-сервера до ActiveX-элемента управления.

**Автор:** Игнатович, группа 40332

## Требования

- **ОС:** Windows (x86 / x64)
- **IDE:** Visual Studio с поддержкой C++, C# и VB.NET
- **Компоненты:** ATL, MIDL, Windows SDK
- Для Lab-3 (`CalendarCSharp`): Microsoft Calendar Control (MSACAL)

Сборочные артефакты (`*.dll`, `*.exe`, `*.tlb` и т.п.) в репозиторий не входят — они создаются при сборке и перечислены в `.gitignore`.

## Структура репозитория

| Каталог | Тема | Решение |
|---------|------|---------|
| [Lab-1](Lab-1/) | In-process COM-сервер `CMath`, интерфейсы `IUnknown` | `Lab-1/Lab-1.slnx` |
| [Lab-2](Lab-2/) | Регистрация COM-компонента в реестре (`DllRegisterServer`) | `Lab-2/Lab-1.slnx` |
| [Lab-3](Lab-3/) | Automation-сервер `AutoSvr` (`IDispatch`), клиенты на разных языках | `Lab-3/Lab-3.slnx` |
| [Lab-5](Lab-5/) | ActiveX-элемент управления `PolyCtl` (многоугольник) | `Lab-5/Lab-5.slnx` |
| [Lab-5-IZ](Lab-5-IZ/) | Расширенный `PolyCtl` с построением графика функции | `Lab-5-IZ/Lab-5.slnx` |

> Каталог **Lab-4** в текущей версии репозитория отсутствует (в истории git есть коммиты по lab 4).

## Lab-1 — Базовый COM-сервер

**Server** — DLL in-process сервер с классом `CMath` и интерфейсами:

- `IMath` — арифметика (`Add`, `Subtract`, `Multiply`, `Divide`)
- `IFN_04` — пользовательские функции (`Fun41`, `Fun42`, `Fun43`)
- `IVer` — `GetAuthor`

**Клиенты:**

| Проект | Подход |
|--------|--------|
| `Client` | `CoGetClassObject` + `CreateInstance` по ProgID `Server40332.MathComponent.1` |
| `ClientV2` | `CoCreateInstance` по CLSID с прямым получением `IMath` |

## Lab-2 — Регистрация в реестре

Тот же COM-сервер `CMath`, дополненный `DllRegisterServer` / `DllUnregisterServer` и записью в реестр Windows (ProgID, CLSID, Friendly Name). Клиенты аналогичны Lab-1.

После сборки **Server** зарегистрируйте DLL (от имени администратора):

```cmd
regsvr32 Server.dll
```

Для снятия регистрации:

```cmd
regsvr32 /u Server.dll
```

## Lab-3 — Automation (OLE Automation)

**AutoSvr** — ATL Automation-сервер с интерфейсом `IMyMath` (`IDispatch`): свойства, методы `Add` / `Sub`, `Fun41`–`Fun43`, интерфейс `IVer`. Описание — в [AutoSvr.idl](Lab-3/AutoSvr/AutoSvr.idl).

**Клиенты:**

| Проект | Язык | Связь с сервером |
|--------|------|------------------|
| `ClientCppDisp` | C++ | Позднее связывание через `IDispatch` |
| `ClientCSharp` | C# | Раннее связывание (TLB / interop) |
| `ClientCSharpLate` | C# | Позднее связывание |
| `ClientVB` | VB.NET | WinForms-клиент |
| `CalendarCSharp` | C# | Работа с ActiveX `MSACAL.Calendar` |

Сборка: сначала **AutoSvr**, затем клиенты. ProgID сервера в C++-клиенте: `Lb3AutoSvr.MyMath.1`.

## Lab-5 — ActiveX-элемент управления

**Polygon** — in-process ActiveX `PolyCtl`: рисование многоугольника с настраиваемым числом сторон (3–10), цветами границы и заливки, событиями `ClickIn` / `ClickOut`. IDL: [Polygon.idl](Lab-5/Polygon/Polygon.idl).

**PolygonPS** — proxy/stub для маршалинга (собирается как зависимость, в решении отключён от общей сборки).

Для использования в контейнере (например, Internet Explorer / тестовый хост) зарегистрируйте `Polygon.dll`:

```cmd
regsvr32 Polygon.dll
```

## Lab-5-IZ — Расширенный ActiveX

Вариант **Lab-5** с дополнительной отрисовкой графика функции  
`f(x) = e^x / x³ − sin³(x)` на заданном интервале по оси X. Базовая логика многоугольника сохранена.

## Сборка и запуск

1. Откройте нужный `*.slnx` в Visual Studio.
2. Выберите конфигурацию **Debug** или **Release** и платформу **x86** (для 32-битных COM-компонентов) или **x64**, если проекты настроены под 64-bit.
3. Соберите решение (**Build Solution**).
4. Для серверных DLL (Lab-1/2 **Server**, Lab-3 **AutoSvr**, Lab-5 **Polygon**) выполните регистрацию через `regsvr32` или контекстное меню «Register» в VS (если настроено post-build).
5. Запустите клиентский проект как **Startup Project**.

### Типичные проблемы

| Симптом | Возможная причина |
|---------|-------------------|
| `0x80040154` (Class not registered) | DLL не зарегистрирована или неверная разрядность (x86 vs x64) |
| `CLSIDFromProgID` failed | Неверный ProgID или отсутствует запись в `HKCR` |
| C#-клиент не видит `MyMath` | Не собран **AutoSvr** / не сгенерирована TLB |
| Календарь не создаётся | Не установлен Microsoft Calendar Control |

## Идентификаторы (Lab-1 / Lab-2)

- **ProgID:** `Server40332.MathComponent.1`
- **Version-independent ProgID:** `Server40332.MathComponent`
- **CLSID `CMath`:** `{E06DF13A-55C5-460E-ABEE-C28E19562FBE}`

## Лицензия

Учебный проект. Использование — в рамках учебного процесса, если иное не оговорено отдельно.
