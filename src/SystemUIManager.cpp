#include "SystemUIManager.hpp"

#include <stdint.h>

#include <chrono>
#include <string>
#include <cassert>

#include "Timer.hpp"

#include <godot_cpp/core/memory.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/window.hpp>
#include <godot_cpp/classes/scene_tree.hpp>

enum class ConstantsInt64_t : int64_t
{
    VALUE_0 = 3, // ЗНАЧЕНИЕ ИНТЕРВАЛА ВРЕМЕНИ 0
    VALUE_1 = 6, // ЗНАЧЕНИЕ ИНТЕРВАЛА ВРЕМЕНИ 1
    VALUE_2 = 1, // ЗНАЧЕНИЕ ИНТЕРВАЛА ВРЕМЕНИ 2
    VALUE_3 = 2 // ЗНАЧЕНИЕ ИНТЕРВАЛА ВРЕМЕНИ 3

    //

    // , CONSTANTS_INT16_T_NUM 
};

// ОСНОВНОЕ ТЕЛО
void SystemUIManager::_body(double delta)
{
    static Timer timer_0;
    static Timer timer_1;
    static Timer timer_2;
    static Timer timer_3;

    static bool state_0 = true;
    static bool state_1 = true;
    static bool state_2 = true;
    static bool state_3 = true;

    static uint16_t value_0 = 0U;
    static uint8_t number_0 = 6U;

    static uint16_t value_1 = 0U;
    static uint8_t number_1 = 6U;

    static uint8_t number_0_0 = 0U;
    static uint8_t number_1_0 = 6U;

    if (m_startUpState == false)
    {
        state_0 = true;
        state_1 = true;

        value_0 = 0U;
        number_0 = 1U;
        value_1 = 0U;
        number_1 = 1U;

        number_0_0 = 0U;
        number_1_0 = 0U;

        return;
    }

    if (timer_0.isRunning() == false)
    {
        m_viewModel->setData_0({value_0, number_0});

        timer_0.start(std::chrono::seconds(static_cast<int64_t>(ConstantsInt64_t::VALUE_0)));

        godot::UtilityFunctions::print("Timer \"timer_0\" has started.");
    }

    if (timer_1.isRunning() == false)
    {
        m_viewModel->setData_1({value_1, number_1});

        timer_1.start(std::chrono::seconds(static_cast<int64_t>(ConstantsInt64_t::VALUE_1)));

        godot::UtilityFunctions::print("Timer \"timer_1\" has started.");
    }

    if (timer_2.isRunning() == false)
    {
        m_viewModel->setData_2_0(number_0_0);

        timer_2.start(std::chrono::seconds(static_cast<int64_t>(ConstantsInt64_t::VALUE_2)));

        godot::UtilityFunctions::print("Timer \"timer_2\" has started.");
    }

    if (timer_3.isRunning() == false)
    {
        m_viewModel->setData_2_1(number_1_0);

        timer_3.start(std::chrono::seconds(static_cast<int64_t>(ConstantsInt64_t::VALUE_3)));

        godot::UtilityFunctions::print("Timer \"timer_3\" has started.");
    }

    m_view->update(delta);

    //

    if (timer_0.isFinished() == true)
    {
        godot::UtilityFunctions::print("Timer \"timer_0\" has finished.");

        if (state_0 == true)
        {
            value_0 += 100U;
        }
        else
        {
            value_0 -= 100U;
        }

        uint16_t valueRatio = number_0 * (static_cast<uint16_t>(Data::ConstantsUint16_t::VALUE_0) / static_cast<uint16_t>(Data::ConstantsUint8_t::VALUE_0));

        if (value_0 >= valueRatio)
        {
            state_0 = false;
        }
        else if (value_0 <= 0U)
        {
            state_0 = true;
        }

        timer_0.reset();
    }

    if (timer_1.isFinished() == true)
    {
        godot::UtilityFunctions::print("Timer \"timer_1\" has finished.");

        if (state_1 == true)
        {
            value_1 += 100U;
        }
        else
        {
            value_1 -= 100U;
        }

        uint16_t valueRatio = number_1 * (static_cast<uint16_t>(Data::ConstantsUint16_t::VALUE_0) / static_cast<uint16_t>(Data::ConstantsUint8_t::VALUE_1));

        if (value_1 >= valueRatio)
        {
            state_1 = false;
        }
        else if (value_1 <= 0U)
        {
            state_1 = true;
        }

        timer_1.reset();
    }

    if (timer_2.isFinished() == true)
    {
        godot::UtilityFunctions::print("Timer \"timer_2\" has finished.");

        if (state_2 == true)
        {
            number_0_0 += 1U;
        }
        else
        {
            number_0_0 -= 1U;
        }

        if (number_0_0 >= 9U)
        {
            state_2 = false;
        }
        else if (number_0_0 <= 0U)
        {
            state_2 = true;
        }

        timer_2.reset();
    }

    if (timer_3.isFinished() == true)
    {
        godot::UtilityFunctions::print("Timer \"timer_3\" has finished.");

        if (state_3 == true)
        {
            number_1_0 += 1U;
        }
        else
        {
            number_1_0 -= 1U;
        }

        if (number_1_0 >= 9U)
        {
            state_3 = false;
        }
        else if (number_1_0 <= 0U)
        {
            state_3 = true;
        }

        timer_3.reset();
    }
}

void SystemUIManager::_bind_methods()
{
}

SystemUIManager::SystemUIManager()
{
    m_model = Model::getInstance();

    if (m_model != nullptr)
    {
        m_viewModel = ViewModel::getInstance(m_model);

        if (m_viewModel != nullptr)
        {
            m_view = memnew(View);

            m_view->setViewModel(m_viewModel);
        }
    }
}

SystemUIManager::~SystemUIManager()
{
    if (m_view != nullptr)
    {
        godot::memdelete(m_view);
    }

    m_model = nullptr;
    m_viewModel = nullptr;
    m_view = nullptr;
}

void SystemUIManager::startUp()
{
    if (m_startUpState == false)
    {
        m_root = get_tree()->get_root();

        m_view->set_root(m_root);

        // КОНЦЕНТРАЦИЯ
        m_view->updateValueData_0();

        // ЗДОРОВЬЕ
        m_view->updateValueData_1();

        // ПАТРОНЫ
        m_view->updateValueData_2();

        m_startUpState = true;
    }
}

void SystemUIManager::shutDown()
{
    if (m_startUpState == true)
    {
        m_startUpState = false;
    }
}

void SystemUIManager::_process([[maybe_unused]] double delta)
{
    _body(delta);
}

void SystemUIManager::_ready()
{
    startUp();
}

void SystemUIManager::_exit_tree()
{
    shutDown();
}
