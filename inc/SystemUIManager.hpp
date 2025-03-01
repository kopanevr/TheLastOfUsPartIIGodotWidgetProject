#pragma once

#include <stdint.h>

#include "model.hpp"
#include "viewModel.hpp"
#include "view.hpp"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/window.hpp>

class SystemUIManager final : public godot::Node
{
    GDCLASS(SystemUIManager, godot::Node)

private:
    Model* m_model = nullptr;
    ViewModel* m_viewModel = nullptr;
    View* m_view = nullptr;

    godot::Window* m_root = nullptr;

    bool m_startUpState = false;

    const uint8_t _pad_0[7] = {0U};

    //

    // ОСНОВНОЕ ТЕЛО
    void _body(double delta);

    static void _bind_methods();
public:
    SystemUIManager();
    ~SystemUIManager();

    void startUp();
    void shutDown();

    void _process([[maybe_unused]] double delta);

    void _ready();
    void _exit_tree();
};
