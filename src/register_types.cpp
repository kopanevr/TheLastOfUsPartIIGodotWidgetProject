#include "register_types.hpp"

#include "SystemUIManager.hpp"
#include "View.hpp"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_extension(ModuleInitializationLevel p_level)
{
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
    {
        return;
    }

    GDREGISTER_CLASS(SystemUIManager);
    GDREGISTER_CLASS(View);
}

void uninitialize_extension(ModuleInitializationLevel p_level)
{
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
    {
        return;
    }
}

extern "C" {
GDExtensionBool GDE_EXPORT godot_gdextension_init(GDExtensionInterfaceGetProcAddress p_get_poc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization* r_initialization)
{
    godot::GDExtensionBinding::InitObject init_obj(p_get_poc_address, p_library, r_initialization);

    init_obj.register_initializer(initialize_extension);
    init_obj.register_terminator(uninitialize_extension);
    init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

    return init_obj.init();
}}
