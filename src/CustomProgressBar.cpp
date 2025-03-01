#include "CustomProgressBar.hpp"

#include <cassert>

#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

godot::Ref<godot::Texture2D> CustomProgressBar::loadTexture(const godot::String& path)
{
    godot::ResourceLoader* resourceLoader = godot::ResourceLoader::get_singleton();

    assert(path.is_empty() != true);

    if (path.is_empty() != true)
    {
        godot::Ref<godot::Resource> resource = resourceLoader->load(path);

        assert(resource.is_valid() == true);

        if (resource.is_valid() == true)
        {
            godot::Ref<godot::Texture2D> texture = godot::Object::cast_to<godot::Texture2D>(resource.ptr());

            assert(texture.is_valid() == true);

            if (texture.is_valid() == true)
            {
                return texture;
            }
            else
            {
                godot::UtilityFunctions::printerr("Faild to load texture.");
            }
        }
    }

    return nullptr;
}

CustomProgressBar::~CustomProgressBar()
{
    m_textureProgressBar = nullptr;
}
