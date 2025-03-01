#pragma once

#include <stdint.h>

#include "CustomProgressBar.hpp"
#include "data.hpp"

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/window.hpp>

namespace NProgressBar_1 {
constexpr double MAX_VALUE = 216.0; // ЗНАЧЕНИЕ РАДИАЛЬНОГО КОНЕЧНОГО УГЛА
constexpr double MIN_VALUE = 0.0; // ЗНАЧЕНИЕ РАДИАЛЬНОГО НАЧАЛЬНОГО УГЛА

class ProgressBar_1 final : public CustomProgressBar
{
private:
    Data::Data_1 m_data_1;

    godot::Window* m_root = nullptr;

    ParametersAmimation m_parametersAmimation
    =
    {
        .currentValue = 0.0,
        .targetValue = 0.0,
        .speed = 100.0
    };

    godot::NodePath m_progressBarPath = "Node3D/Node/CanvasLayer/CenterContainer/CenterContainer/TextureProgressBar1";

    //

    void updateValue(double delta);
    void updateNumber();
public:
    ProgressBar_1() = default;
    ~ProgressBar_1() = default;

    Data::Data_1& getData_1() noexcept { return m_data_1; }

    void set_root(godot::Window* root);

    void update(double delta);
};}
