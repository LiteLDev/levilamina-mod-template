#include <ll/api/plugin/Plugin.h>

#include <Plugin.h>

namespace plugins {

// The global plugin instance.
Plugin plugin;

extern "C" {
_declspec(dllexport) bool ll_plugin_load(ll::plugin::Plugin& self) { return plugin.load(self); }
}

} // namespace plugins
