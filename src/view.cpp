#include "view.hpp"

#include <godot_cpp/core/memory.hpp>

// ОСНОВНОЕ ТЕЛО
void View::_body(double delta)
{
    // КОНЦЕНТРАЦИЯ
    m_widgetHandler->getProgerssBar_0()->update(delta);
    // ЗДОРОВЬЕ
    m_widgetHandler->getProgerssBar_1()->update(delta);

    // ПАТРОНЫ
    m_widgetHandler->getCustomLalbel()->update();
}

void View::_bind_methods()
{
    godot::ClassDB::bind_method(godot::D_METHOD("updateValueData_0"), &View::updateValueData_0);
    godot::ClassDB::bind_method(godot::D_METHOD("updateValueData_1"), &View::updateValueData_1);
    godot::ClassDB::bind_method(godot::D_METHOD("updateValueData_2"), &View::updateValueData_2);
}

View::View()
{
    m_widgetHandler = memnew(WidgetHandler);
}

View::~View()
{
    if (m_widgetHandler != nullptr)
    {
        godot::memdelete(m_widgetHandler);
    }
}

void View::setViewModel(ViewModel* viewModel)
{
    m_viewModel = viewModel;

    if (m_viewModel != nullptr)
    {
        m_callback_0 = godot::Callable(this, "updateValueData_0");
        m_callback_1 = godot::Callable(this, "updateValueData_1");
        m_callback_2 = godot::Callable(this, "updateValueData_2");

        m_viewModel->subscribeOnData_0Changed(m_callback_0);
        m_viewModel->subscribeOnData_1Changed(m_callback_1);
        m_viewModel->subscribeOnData_2Changed(m_callback_2);
    }
}

void View::updateValueData_0()
{
    if (m_viewModel != nullptr)
    {
        m_widgetHandler->getProgerssBar_0()->getData_0() = m_viewModel->getData().data_0;
    }
}

void View::updateValueData_1()
{
    if (m_viewModel != nullptr)
    {
        m_widgetHandler->getProgerssBar_1()->getData_1() = m_viewModel->getData().data_1;
    }
}

void View::updateValueData_2()
{
    if (m_viewModel != nullptr)
    {
        m_widgetHandler->getCustomLalbel()->getData_2() = m_viewModel->getData().data_2;
    }
}

void View::set_root(godot::Window* root)
{
    m_widgetHandler->set_root(root);
}

void View::update(double delta)
{
    _body(delta);
}
