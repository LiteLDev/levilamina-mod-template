#include <ll/api/plugin/Plugin.h>

extern "C" bool ll_plugin_load(ll::plugin::Plugin &self) { return true; }

extern "C" bool ll_plugin_unload(ll::plugin::Plugin &self) { return true; }

extern "C" bool ll_plugin_enable(ll::plugin::Plugin &self) { return true; }

extern "C" bool ll_plugin_disable(ll::plugin::Plugin &self) { return true; }
