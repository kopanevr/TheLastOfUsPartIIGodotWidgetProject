#pragma once

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/canvas_layer.hpp>
#include <godot_cpp/classes/texture_progress_bar.hpp>
#include <godot_cpp/classes/texture2d.hpp>

struct ParametersAmimation final
{
    double currentValue = 0.0f;
    double targetValue = 0.0f;
    double speed = 0.0f;
};

class CustomProgressBar : public godot::Node
{
protected:
    godot::TextureProgressBar* m_textureProgressBar = nullptr;

    //

    godot::Ref<godot::Texture2D> loadTexture(const godot::String& path);
public:
    CustomProgressBar() = default;
    virtual ~CustomProgressBar();
};
