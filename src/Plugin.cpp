#include "Plugin.h"

#include <ll/api/plugin/NativePlugin.h>

namespace plugin {

Plugin::~Plugin() = default;

static std::unique_ptr<Plugin> plugin{};

Plugin& Plugin::getInstance() { return *plugin; }

Plugin::Plugin(ll::plugin::NativePlugin& self) : mSelf(self) {
    mSelf.getLogger().info("loading...");

    // Code for loading the plugin goes here.
}

ll::plugin::NativePlugin& Plugin::getSelf() const { return mSelf; }

bool Plugin::enable() {
    mSelf.getLogger().info("enabling...");

    // Code for enabling the plugin goes here.

    return true;
}

bool Plugin::disable() {
    mSelf.getLogger().info("disabling...");

    // Code for disabling the plugin goes here.

    return true;
}

extern "C" {
_declspec(dllexport) bool ll_plugin_load(ll::plugin::NativePlugin& self) {
    plugin = std::make_unique<plugin::Plugin>(self);
    return true;
}

/// @warning Unloading the plugin may cause a crash if the plugin has not released all of its
/// resources. If you are unsure, keep this function commented out.
// _declspec(dllexport) bool ll_plugin_unload(ll::plugin::Plugin&) {
//     plugin.reset();
//
//     return true;
// }

_declspec(dllexport) bool ll_plugin_enable(ll::plugin::NativePlugin&) { return plugin->enable(); }

_declspec(dllexport) bool ll_plugin_disable(ll::plugin::NativePlugin&) { return plugin->disable(); }
}

} // namespace plugin
