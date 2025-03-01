#include "CustomLabel.hpp"

#include <cassert>
#include <string>

#include <godot_cpp/variant/utility_functions.hpp>

void CustomLabel::updateNumber_0()
{
    if (m_Label_0 == nullptr)
    {
        // ПОЛУЧЕНИЕ МЕТКИ
        m_Label_0 = m_root->get_node<godot::Label>(m_LabelPath_0);
    }

    assert(m_Label_0 != nullptr);

    if (m_Label_0 != nullptr)
    {
        constexpr uint8_t edgeValue = 0U;

        if (m_data_2.number_0 == edgeValue)
        {
            m_Label_0->add_theme_color_override("font_color", godot::Color(1.0f, 0.0F, 0.0f));
        }
        else
        {
            m_Label_0->add_theme_color_override("font_color", godot::Color(1.0f, 1.0f, 1.0f));
        }

        std::string str = std::to_string(m_data_2.number_0);

        m_Label_0->set_text(godot::String(str.c_str()));
    }
}

void CustomLabel::updateNumber_1()
{
    if (m_Label_1 == nullptr)
    {
        // ПОЛУЧЕНИЕ МЕТКИ
        m_Label_1 = m_root->get_node<godot::Label>(m_LabelPath_1);
    }

    assert(m_Label_1 != nullptr);

    if (m_Label_1 != nullptr)
    {
        constexpr uint8_t edgeValue = 0U;

        if (m_data_2.number_1 == edgeValue)
        {
            m_Label_1->add_theme_color_override("font_color", godot::Color(1.0f, 0.0f, 0.0f));
        }
        else
        {
            m_Label_1->add_theme_color_override("font_color", godot::Color(1.0f, 1.0f, 1.0f));
        }

        std::string str = std::to_string(m_data_2.number_1);

        m_Label_1->set_text(godot::String(str.c_str()));
    }
}

void CustomLabel::set_root(godot::Window* root)
{
    m_root = root;
}

void CustomLabel::update()
{
    godot::UtilityFunctions::print("\"CustomLabel::update\"");

    static uint8_t previousNumber_0 = m_data_2.number_0;
    static uint8_t previousNumber_1 = m_data_2.number_1;

    // ФЛАГ СОСТОЯНИЯ ПЕРВОГО ОБНОВЛЕНИЯ ДАННЫХ
    static bool state = false;

    if (state == false)
    {
        updateNumber_0();
        updateNumber_1();

        state = true;
    }

    if (previousNumber_0 != m_data_2.number_0)
    {
        previousNumber_0 = m_data_2.number_0;

        updateNumber_0();
    }

    if (previousNumber_1 != m_data_2.number_1)
    {
        previousNumber_1 = m_data_2.number_1;

        updateNumber_1();
    }
}