#include "WidgetHandler.hpp"

#include <godot_cpp/core/memory.hpp>
#include <godot_cpp/classes/window.hpp>

WidgetHandler::WidgetHandler()
{
    m_progressBar_0 = memnew(NProgressBar_0::ProgressBar_0);
    m_progressBar_1 = memnew(NProgressBar_1::ProgressBar_1);

    m_customLalbel = memnew(CustomLabel);
}

WidgetHandler::~WidgetHandler()
{
    if (m_progressBar_0 != nullptr)
    {
        godot::memdelete(m_progressBar_0);
    }

    if (m_progressBar_1 != nullptr)
    {
        godot::memdelete(m_progressBar_1);
    }

    if (m_customLalbel != nullptr)
    {
        godot::memdelete(m_customLalbel);
    }
}

void WidgetHandler::set_root(godot::Window* root)
{
    m_progressBar_0->set_root(root);
    m_progressBar_1->set_root(root);

    m_customLalbel->set_root(root);
}
