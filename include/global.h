#ifndef LEVILAMINA_EXAMPLE_PLUGIN_GLOBAL_H_
#define LEVILAMINA_EXAMPLE_PLUGIN_GLOBAL_H_

#include <plugin.h>
#include <string_view>

////////////////////////////////////////////////////////////////
// Modify these values when creating your own plugin.

constexpr std::string_view kPluginName = "levilamina-example-plugin";

////////////////////////////////////////////////////////////////

extern Plugin plugin;

#endif // LEVILAMINA_EXAMPLE_PLUGIN_GLOBAL_H_
