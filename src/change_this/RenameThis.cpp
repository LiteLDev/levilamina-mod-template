#include "RenameThis.h"

#include <ll/api/plugin/NativePlugin.h>
#include <memory>

namespace rename_this {

RenameThis::RenameThis() = default;

RenameThis& RenameThis::getInstance() {
    static RenameThis instance;
    return instance;
}

ll::plugin::NativePlugin& RenameThis::getSelf() const { return *mSelf; }

bool RenameThis::load(ll::plugin::NativePlugin& self) {
    mSelf = std::addressof(self);
    getSelf().getLogger().info("loading...");

    // Code for loading the plugin goes here.

    return true;
}

bool RenameThis::enable() {
    getSelf().getLogger().info("enabling...");

    // Code for enabling the plugin goes here.

    return true;
}

bool RenameThis::disable() {
    getSelf().getLogger().info("disabling...");

    // Code for disabling the plugin goes here.

    return true;
}

extern "C" {
_declspec(dllexport) bool ll_plugin_load(ll::plugin::NativePlugin& self) {
    return RenameThis::getInstance().load(self);
}

_declspec(dllexport) bool ll_plugin_enable(ll::plugin::NativePlugin&) { return RenameThis::getInstance().enable(); }

_declspec(dllexport) bool ll_plugin_disable(ll::plugin::NativePlugin&) { return RenameThis::getInstance().disable(); }

/// @warning Unloading the plugin may cause a crash if the plugin has not released all of its
/// resources. If you are unsure, keep this function commented out.
// _declspec(dllexport) bool ll_plugin_unload(ll::plugin::NativePlugin&) {
//     return RenameThis::getInstance().unload();
// }
}

} // namespace rename_this
