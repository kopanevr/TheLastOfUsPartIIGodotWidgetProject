#pragma once

#include "viewModel.hpp"
#include "WidgetHandler.hpp"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/window.hpp>

class View final : public godot::Node
{
    GDCLASS(View, godot::Node)

private:
    ViewModel* m_viewModel = nullptr;

    WidgetHandler* m_widgetHandler = nullptr;

    godot::Callable m_callback_0;
    godot::Callable m_callback_1;
    godot::Callable m_callback_2;

    //

    // ОСНОВНОЕ ТЕЛО
    void _body(double delta);

    static void _bind_methods();
public:
    View();
    ~View();

    void setViewModel(ViewModel* viewModel);

    void updateValueData_0();
    void updateValueData_1();
    void updateValueData_2();

    void set_root(godot::Window* window);

    void update(double delta);
};
