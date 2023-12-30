#include "Plugin.h"

namespace plugin_template {

Plugin::Plugin(ll::plugin::NativePlugin& self) : mSelf(self) {
    // Code for loading the plugin goes here.
    mSelf.getLogger().warn("plugin_template loading");
}

bool Plugin::enable() {
    // Code for enabling the plugin goes here.
    mSelf.getLogger().warn("plugin_template enable");
    return true;
}

bool Plugin::disable() {
    // Code for disabling the plugin goes here.
    mSelf.getLogger().warn("plugin_template disable");
    return true;
}

} // namespace plugin_template
