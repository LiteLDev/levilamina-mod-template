#include <exception>

#include <ll/api/plugin/Plugin.h>

#include "Plugin.h"

namespace plugins {

// The global plugin instance.
Plugin* plugin = nullptr;

extern "C" {
_declspec(dllexport) bool ll_plugin_load(ll::plugin::Plugin& self) {
    try {
        plugin = new Plugin(self);

    } catch (const std::exception& e) {
        self.getLogger().error(e.what());

        return false;
    }

    return true;
}

_declspec(dllexport) bool ll_plugin_enable(ll::plugin::Plugin&) {
    if (plugin == nullptr) {
        return false;
    }

    return plugin->enable();
}

_declspec(dllexport) bool ll_plugin_disable(ll::plugin::Plugin&) {
    if (plugin == nullptr) {
        return false;
    }

    return plugin->disable();
}
}

} // namespace plugins
