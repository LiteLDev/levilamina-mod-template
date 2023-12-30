#include "Plugin.h"

namespace plugin_template {

// The global plugin instance.
std::unique_ptr<Plugin> plugin = nullptr;

extern "C" {
_declspec(dllexport) bool ll_plugin_load(ll::plugin::NativePlugin& self) {
    plugin = std::make_unique<plugin_template::Plugin>(self);
    return true;
}

/// @brief Unloads the plugin.Uninstalling a dll plugin is a very dangerous
///  thing. You must ensure that all resources are released before proceeding.
// _declspec(dllexport) bool ll_plugin_unload(ll::plugin::Plugin&) {
//     plugin.reset();
//     return true;
// }

_declspec(dllexport) bool ll_plugin_enable(ll::plugin::NativePlugin&) { return plugin->enable(); }

_declspec(dllexport) bool ll_plugin_disable(ll::plugin::NativePlugin&) { return plugin->disable(); }
}

} // namespace plugin_template
