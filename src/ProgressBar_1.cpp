#include "ProgressBar_1.hpp"

#include <cassert>
#include <algorithm>

#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/classes/texture_progress_bar.hpp>
#include <godot_cpp/classes/canvas_layer.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/classes/image.hpp>

namespace NProgressBar_1 {
// УСТАНОВКА ЗНАЧЕНИЯ ЗДОРОВЬЯ (ПРОГРЕСС)
void ProgressBar_1::updateValue(double delta)
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

        double maxValue = m_data_1.number * (static_cast<double>(Data::ConstantsUint16_t::VALUE_1) / static_cast<double>(Data::ConstantsUint8_t::VALUE_1));

        if (maxValue == 0.0)
        {
            return;
        }

        float progressRatio = MAX_VALUE / maxValue;

        m_parametersAmimation.targetValue = progressRatio * m_data_1.value;

        // ПОЛУЧЕНИЕ ТЕКУЩЕГО ЗНАЧЕНИЯ УГЛА ЗДОРОВЬЯ
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

            double edgeValue = progressRatio * (static_cast<double>(Data::ConstantsUint8_t::VALUE_3) * (m_data_1.number * (static_cast<double>(Data::ConstantsUint16_t::VALUE_1) / static_cast<double>(Data::ConstantsUint8_t::VALUE_1))) / 100.0);

            constexpr double tolerance_1 = 1.0;

            if ((m_parametersAmimation.currentValue - edgeValue) < tolerance_1)
            {
                m_textureProgressBar->set_tint_progress(godot::Color(1.0f, 0.0f, 0.0f));
            }
            else
            {
                m_textureProgressBar->set_tint_progress(godot::Color(1.0f, 1.0f, 1.0f));
            }

            m_textureProgressBar->set_value(m_parametersAmimation.currentValue);
        }
    }
}

// УСТАНОВКА УРОВНЕЙ ЗДОРОВЬЯ (ФОН ПРОГРЕССА)
void ProgressBar_1::updateNumber()
{
    // УРОВЕНЬ ЗДОРОВЬЯ
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

    // ПОЛУЧЕНИЯ ЗНАЧЕНИЯ УРОВНЕЙ ЗДОРОВЬЯ
    uint8_t number = m_data_1.number;

    assert(number < static_cast<uint8_t>(Number::VALUE_NUM));

    number = std::min<uint8_t>(number, static_cast<uint8_t>(Number::VALUE_NUM));

    // УСТАНОВКА ПУТИ К ТЕКСТУРЕ
    switch (number)
    {
    case static_cast<uint8_t>(Number::VALUE_0):
        break;
    case static_cast<uint8_t>(Number::VALUE_1):
        texturePath = "res://images/2/1.PNG";

        break;
    case static_cast<uint8_t>(Number::VALUE_2):
        texturePath = "res://images/2/2.PNG";

        break;
    case static_cast<uint8_t>(Number::VALUE_3):
        texturePath = "res://images/2/3.PNG";

        break;
    case static_cast<uint8_t>(Number::VALUE_4):
        texturePath = "res://images/2/4.PNG";

        break;
    case static_cast<uint8_t>(Number::VALUE_5):
        texturePath = "res://images/2/5.PNG";

        break;
    case static_cast<uint8_t>(Number::VALUE_6):
        texturePath = "res://images/2/6.PNG";

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
            // УСТАНОВКА ТЕКСТУРЫ УРОВНЕЙ ЗДОРОВЬЯ (ФОН ПРОГРЕССА)
            m_textureProgressBar->set_under_texture(texture);
        }
    }
}

void ProgressBar_1::set_root(godot::Window* root)
{
    m_root = root;
}

void ProgressBar_1::update(double delta)
{
    godot::UtilityFunctions::print("\"ProgressBar_1::update\"");

    static uint8_t previousNumber = m_data_1.number;

    // ФЛАГ СОСТОЯНИЯ ПЕРВОГО ОБНОВЛЕНИЯ ДАННЫХ
    static bool state = false;

    if (state == false)
    {
        updateNumber();

        state = true;
    }

    if (previousNumber != m_data_1.number)
    {
        previousNumber = m_data_1.number;

        updateNumber();
    }

    updateValue(delta);
}}
