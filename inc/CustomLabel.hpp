#pragma once

#include "data.hpp"

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/window.hpp>

class CustomLabel
{
private:
    Data::Data_2 m_data_2;

    godot::Window* m_root = nullptr;

    godot::Label* m_Label_0 = nullptr;
    godot::Label* m_Label_1 = nullptr;

    godot::NodePath m_LabelPath_0 = "Node3D/Node/CanvasLayer/Label";
    godot::NodePath m_LabelPath_1 = "Node3D/Node/CanvasLayer/Label1";

    //

    void updateNumber_0();
    void updateNumber_1();
public:
    CustomLabel() = default;
    ~CustomLabel() = default;

    Data::Data_2& getData_2() noexcept { return m_data_2; }

    void set_root(godot::Window* root);

    void update();
};
