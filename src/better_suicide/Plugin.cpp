#include "Plugin.h"

#include <ll/api/plugin/Plugin.h>

namespace plugins {

Plugin::Plugin(ll::plugin::Plugin& self) : mSelf(self) {
    // Code for loading the plugin goes here.
}

bool Plugin::enable() {
    // Code for enabling the plugin goes here.

    return true;
}

bool Plugin::disable() {
    // Code for disabling the plugin goes here.

    return true;
}

} // namespace plugins
