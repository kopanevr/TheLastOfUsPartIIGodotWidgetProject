#pragma once

#include "ProgressBar_0.hpp"
#include "ProgressBar_1.hpp"
#include "CustomLabel.hpp"

#include <godot_cpp/classes/window.hpp>

class WidgetHandler final
{
private:
    NProgressBar_0::ProgressBar_0* m_progressBar_0 = nullptr;
    NProgressBar_1::ProgressBar_1* m_progressBar_1 = nullptr;

    CustomLabel* m_customLalbel = nullptr;
public:
    WidgetHandler();
    ~WidgetHandler();

    void set_root(godot::Window* root);

    NProgressBar_0::ProgressBar_0* getProgerssBar_0() noexcept { return m_progressBar_0; }
    NProgressBar_1::ProgressBar_1* getProgerssBar_1() noexcept { return m_progressBar_1; }

    CustomLabel* getCustomLalbel() noexcept { return m_customLalbel; }
};
