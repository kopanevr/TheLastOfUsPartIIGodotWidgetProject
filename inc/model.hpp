#pragma once

#include <stdint.h>

#include "data.hpp"

class Model final
{
private:
    Data::Data m_data
    =
    {
        // КОНЦЕНТРАЦИЯ
        .data_0
        =
        {
            .value = 0U, // ЗНАЧЕНИЕ УРОВНЯ КОНЦЕНТРАЦИИ
            .number = 6U // КОЛИЧЕСТВО УРОВНЕЙ КОНЦЕНТРАЦИИ
        },

        // ЗДОРОВЬЕ
        .data_1
        =
        {
            .value = 0U, // ЗНАЧЕНИЕ УРОВНЯ ЗДОРОВЬЯ
            .number = 6U // КОЛИЧЕСТВО УРОВНЕЙ ЗДОРОВЬЯ
        },

        // ПАТРОНЫ
        .data_2
        =
        {
            .number_0 = 0U, // ЗНАЧЕНИЕ ПАТРОНОВ В МАГАЗИНЕ
            .number_1 = 0U // ЗНАЧЕНИЕ ПАТРОНОВ В ЗАПАСЕ
        }
    };

    //

    Model() = default;

    Model(const Model&) = delete;
    Model& operator=(const Model&) = delete;
public:
    ~Model() = default;

    static Model* getInstance();

    //

    Data::Data& getData() noexcept { return m_data; }
};
