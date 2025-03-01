#include "viewModel.hpp"

#include <cassert>

#include <godot_cpp/variant/callable.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

ViewModel::ViewModel(Model* model)
    :   m_model(model)
{
}

void ViewModel::onChangedData_0()
{
    for (const godot::Callable& callback : m_data_0_callbacks)
    {
        if (callback.is_valid() == true)
        {
            callback.call();
        }
    }
}

void ViewModel::onChangedData_1()
{
    for (const godot::Callable& callback : m_data_1_callbacks)
    {
        if (callback.is_valid() == true)
        {
            callback.call();
        }
    }
}

void ViewModel::onChangedData_2()
{
    for (const godot::Callable& callback : m_data_2_callbacks)
    {
        if (callback.is_valid() == true)
        {
            callback.call();
        }
    }
}

ViewModel* ViewModel::getInstance(Model* model)
{
    assert(model != nullptr);

    if (model == nullptr)
    {
        return nullptr;
    }

    static ViewModel instance(model);

    return &instance;
}

Data::Data& ViewModel::getData()
{
    return m_model->getData();
}

void ViewModel::setData_0(const std::pair<uint16_t, uint8_t>& data)
{
    bool state = false; // ФЛАГ ЗАПИСИ ДАННЫХ

    if (data.first <= static_cast<uint16_t>(Data::ConstantsUint16_t::VALUE_0))
    {
        m_model->getData().data_0.value = data.first; // ЗАПИСЬ ДАННЫХ

        state = true;
    }

    if (data.second <= static_cast<uint8_t>(Data::ConstantsUint8_t::VALUE_0))
    {
        m_model->getData().data_0.number = data.second; // ЗАПИСЬ ДАННЫХ

        state = true;
    }

    if (state == true)
    {
        onChangedData_0(); // СИГНАЛ О ЗАПИСИ ДАННЫХ
    }
}

void ViewModel::setData_1(const std::pair<uint16_t, uint8_t>& data)
{
    bool state = false; // ФЛАГ ЗАПИСИ ДАННЫХ

    if (data.first <= static_cast<uint16_t>(Data::ConstantsUint16_t::VALUE_1))
    {
        m_model->getData().data_1.value = data.first; // ЗАПИСЬ ДАННЫХ

        state = true;
    }

    if (data.second <= static_cast<uint8_t>(Data::ConstantsUint8_t::VALUE_1))
    {
        m_model->getData().data_1.number = data.second; // ЗАПИСЬ ДАННЫХ

        state = true;
    }

    if (state == true)
    {
        onChangedData_1(); // СИГНАЛ О ЗАПИСИ ДАННЫХ
    }
}

void ViewModel::setData_2_0(const uint8_t number_0)
{
    bool state = false; // ФЛАГ ЗАПИСИ ДАННЫХ

    if (number_0 <= static_cast<uint8_t>(Data::ConstantsUint8_t::VALUE_4))
    {
        m_model->getData().data_2.number_0 = number_0;

        state = true;
    }

    if (state == true)
    {
        onChangedData_2(); // СИГНАЛ О ЗАПИСИ ДАННЫХ
    }
}

void ViewModel::setData_2_1(const uint8_t number_1)
{
    bool state = false; // ФЛАГ ЗАПИСИ ДАННЫХ

    if (number_1 <= static_cast<uint8_t>(Data::ConstantsUint8_t::VALUE_5))
    {
        m_model->getData().data_2.number_1 = number_1;

        state = true;
    }

    if (state == true)
    {
        onChangedData_2(); // СИГНАЛ О ЗАПИСИ ДАННЫХ
    }
}

void ViewModel::subscribeOnData_0Changed(godot::Callable callback)
{
    m_data_0_callbacks.push_back(callback);
}

void ViewModel::subscribeOnData_1Changed(godot::Callable callback)
{
    m_data_1_callbacks.push_back(callback);
}

void ViewModel::subscribeOnData_2Changed(godot::Callable callback)
{
    m_data_2_callbacks.push_back(callback);
}
