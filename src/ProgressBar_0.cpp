#include "ProgressBar_0.hpp"

#include <cassert>
#include <algorithm>

#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/classes/texture_progress_bar.hpp>
#include <godot_cpp/classes/canvas_layer.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/classes/image.hpp>

namespace NProgressBar_0 {
// УСТАНОВКА ЗНАЧЕНИЯ КОНЦЕНТРАЦИИ (ПРОГРЕСС)
void ProgressBar_0::updateValue(double delta)
{
    if (m_textureProgressBar == nullptr)
    {
        // ПОЛУЧЕНИЕ ПРОГРЕССА ВЫПОЛНЕНИЯ
        m_textureProgressBar = m_root->get_node<godot::TextureProgressBar>(m_progressBarPath);
    }

    assert(m_textureProgressBar != nullptr);

    if (m_textureProgressBar != nullptr)
    {
        static_assert(static_cast<double>(Data::ConstantsUint8_t::VALUE_0) != 0.0);

        double maxValue = m_data_0.number * (static_cast<double>(Data::ConstantsUint16_t::VALUE_0) / static_cast<double>(Data::ConstantsUint8_t::VALUE_0));

        if (maxValue == 0.0)
        {
            return;
        }

        float progressRatio = MAX_VALUE / maxValue;

        m_parametersAmimation.targetValue = progressRatio * m_data_0.value;

        // ПОЛУЧЕНИЕ ТЕКУЩЕГО ЗНАЧЕНИЯ УГЛА КОНЦЕНТРАЦИИ
        m_parametersAmimation.currentValue = m_textureProgressBar->get_value();

        constexpr double tolerance_0 = 1.0;

        if (std::abs(m_parametersAmimation.targetValue - m_parametersAmimation.currentValue) > tolerance_0)
        {
            double valueChange = m_parametersAmimation.speed * delta;

            if (m_parametersAmimation.currentValue < m_parametersAmimation.targetValue)
            {
                // УВЕЛИЧЕНИЕ ЗНАЧЕНИЯ УГЛА ПРОГРЕССА
                m_parametersAmimation.currentValue += valueChange;

                m_parametersAmimation.currentValue = std::min<double>(m_parametersAmimation.currentValue, maxValue);
            }
            else
            {
                // УМЕНЬШЕНИЕ ЗНАЧЕНИЯ УГЛА ПРОГРЕССА
                m_parametersAmimation.currentValue -= valueChange;

                m_parametersAmimation.currentValue = std::max<double>(m_parametersAmimation.currentValue, 0.0f);
            }

            double edgeValue = progressRatio * (static_cast<double>(Data::ConstantsUint8_t::VALUE_2) * (m_data_0.number * (static_cast<double>(Data::ConstantsUint16_t::VALUE_0) / static_cast<double>(Data::ConstantsUint8_t::VALUE_0))) / 100.0);

            constexpr double tolerance_1 = 1.0;

            if ((m_parametersAmimation.currentValue - edgeValue) < tolerance_1)
            {
                m_textureProgressBar->set_tint_progress(godot::Color(1.0f, 0.0f, 0.0f));
            }
            else
            {
                m_textureProgressBar->set_tint_progress(godot::Color(0.376f, 0.58f, 0.596f));
            }

            m_textureProgressBar->set_value(m_parametersAmimation.currentValue);
        }
    }
}

// УСТАНОВКА УРОВНЕЙ КОНЦЕНТРАЦИИ (ФОН ПРОГРЕССА)
void ProgressBar_0::updateNumber()
{
    // УРОВЕНЬ КОНЦЕНТРАЦИИ
    enum class Number : uint8_t
    {
        VALUE_0 = 0U,
        VALUE_1,
        VALUE_2,
        VALUE_3,
        VALUE_4,
        VALUE_5,
        VALUE_6, VALUE_NUM
    };

    godot::String texturePath; // ПУТЬ К ТЕКСТУРЕ

    // ПОЛУЧЕНИЯ ЗНАЧЕНИЯ УРОВНЕЙ КОНЦЕНТРАЦИИ
    uint8_t number = m_data_0.number;

    assert(number < static_cast<uint8_t>(Number::VALUE_NUM));

    number = std::min<uint8_t>(number, static_cast<uint8_t>(Number::VALUE_NUM));

    // УСТАНОВКА ПУТИ К ТЕКСТУРЕ
    switch (number)
    {
    case static_cast<uint8_t>(Number::VALUE_0):
        break;
    case static_cast<uint8_t>(Number::VALUE_1):
        texturePath = "res://images/1/1.PNG";

        break;
    case static_cast<uint8_t>(Number::VALUE_2):
        texturePath = "res://images/1/2.PNG";

        break;
    case static_cast<uint8_t>(Number::VALUE_3):
        texturePath = "res://images/1/3.PNG";

        break;
    case static_cast<uint8_t>(Number::VALUE_4):
        texturePath = "res://images/1/4.PNG";

        break;
    case static_cast<uint8_t>(Number::VALUE_5):
        texturePath = "res://images/1/5.PNG";

        break;
    case static_cast<uint8_t>(Number::VALUE_6):
        texturePath = "res://images/1/6.PNG";

        break;

    default:
        break;
    }

    godot::UtilityFunctions::print(texturePath);

    // ЗАГРУЗКА ТЕКСТУРЫ
    godot::Ref<godot::Texture2D> texture = loadTexture(texturePath);

    assert(texture.is_valid() == true);

    if (texture.is_valid() == true)
    {
        // ПОЛУЧЕНИЕ ПРОГРЕССА ВЫПОЛНЕНИЯ
        m_textureProgressBar = m_root->get_node<godot::TextureProgressBar>(m_progressBarPath);

        assert(m_textureProgressBar != nullptr);

        if (m_textureProgressBar != nullptr)
        {
            // УСТАНОВКА ТЕКСТУРЫ УРОВНЕЙ КОНЦЕНТРАЦИИ (ФОН ПРОГРЕССА)
            m_textureProgressBar->set_under_texture(texture);
        }
    }
}

void ProgressBar_0::set_root(godot::Window* root)
{
    m_root = root;
}

void ProgressBar_0::update(double delta)
{
    godot::UtilityFunctions::print("\"ProgressBar_0::update\"");

    static uint8_t previousNumber = m_data_0.number;

    // ФЛАГ СОСТОЯНИЯ ПЕРВОГО ОБНОВЛЕНИЯ ДАННЫХ
    static bool state = false;

    if (state == false)
    {
        updateNumber();

        state = true;
    }

    if (previousNumber != m_data_0.number)
    {
        previousNumber = m_data_0.number;

        updateNumber();
    }

    updateValue(delta);
}}
