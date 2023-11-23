#include <global.h>
#include <ll/api/plugin/Plugin.h>
#include <plugin.h>

// The global plugin instance.
Plugin plugin(kPluginName);

extern "C" {
_declspec(dllexport) bool ll_plugin_load(ll::plugin::Plugin &self) {
  return plugin.Load(self);
}

_declspec(dllexport) bool ll_plugin_unload(ll::plugin::Plugin &self) {
  return plugin.Unload(self);
}

_declspec(dllexport) bool ll_plugin_enable(ll::plugin::Plugin &self) {
  return plugin.Enable(self);
}

_declspec(dllexport) bool ll_plugin_disable(ll::plugin::Plugin &self) {
  return plugin.Disable(self);
}
}
