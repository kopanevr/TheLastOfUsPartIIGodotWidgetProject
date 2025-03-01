#pragma once

#include <stdint.h>

namespace Data {
enum class ConstantsUint16_t : uint16_t
{
    VALUE_0 = 600U, // МАКСИМАЛЬНОЕ ЗНАЧЕНИЕ УРОВНЯ КОНЦЕНТРАЦИИ
    VALUE_1 = 600U // МАКСИМАЛЬНОЕ ЗНАЧЕНИЕ УРОВНЯ ЗДОРОВЬЯ

    //

    //, CONSTANTS_UINT16_T_NUM
};

enum class ConstantsUint8_t : uint8_t
{
    VALUE_0 = 6U, // МАКСИМАЛЬНОЕ ЗНАЧЕНИЕ КОЛИЧЕСТВА УРОВНЕЙ КОНЦЕНТРАЦИИ
    VALUE_1 = 6U, // МАКСИМАЛЬНОЕ ЗНАЧЕНИЕ КОЛИЧЕСТВА УРОВНЕЙ ЗДОРОВЬЯ

    //

    VALUE_2 = 50U, // ГРАНИЧНЫЙ ПРОЦЕНТ ЗНАЧЕНИЯ УРОВНЯ КОНЦЕНТРАЦИИ
    VALUE_3 = 50U, // ГРАНИЧНЫЙ ПРОЦЕНТ ЗНАЧЕНИЯ УРОВНЯ ЗДОРОВЬЯ

    //

    VALUE_4 = 99,
    VALUE_5 = 99

    //

    //, CONSTANTS_UINT8_T_NUM
};

// КОНЦЕНТРАЦИЯ
struct Data_0 final
{
    uint16_t value = 0U; // ЗНАЧЕНИЕ УРОВНЯ ОТ 0 ДО 600
    uint8_t number = 0U; // КОЛИЧЕСТВО УРОВНЕЙ ОТ 0 ДО 6

    const uint8_t _pad_0[1] = {0U};

    //

    Data_0& operator=(const Data_0& other)
    {
        value = other.value;
        number = other.number;

        return *this;
    }
};

// ЗДОРОВЬЕ
struct Data_1 final
{
    uint16_t value = 0U; // ЗНАЧЕНИЕ УРОВНЯ ОТ 0 ДО 600
    uint8_t number = 0U; // КОЛИЧЕСТВО УРОВНЕЙ ОТ 0 ДО 6

    const uint8_t _pad_0[1] = {0U};

    //

    Data_1& operator=(const Data_1& other)
    {
        value = other.value;
        number = other.number;

        return *this;
    }
};

// ПАТРОНЫ
struct Data_2 final
{
    uint8_t number_0 = 0U; // КОЛИЧЕСТВО ПАТРОНОВ В МАГАЗИНЕ ОТ 0 ДО 99
    uint8_t number_1 = 0U; // КОЛИЧЕСТВО ПАТРОНОВ В ЗАПАСЕ ОТ 0 ДО 99

    Data_2& operator=(const Data_2& other)
    {
        number_0 = other.number_0;
        number_1 = other.number_1;

        return *this;
    }
};

struct Data final
{
    // КОНЦЕНТРАЦИЯ
    Data_0 data_0;

    // ЗДОРОВЬЕ
    Data_1 data_1;

    Data_2 data_2;
};}
