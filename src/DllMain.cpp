#include <Global.h>
#include <Plugin.h>
#include <ll/api/memory/Hook.h>
#include <ll/api/plugin/Plugin.h>
#include <mc/server/ServerPlayer.h>

extern "C" {
_declspec(dllexport) bool ll_plugin_load(ll::plugin::Plugin& self) { return plugin.load(self); }

_declspec(dllexport) bool ll_plugin_unload(ll::plugin::Plugin& self) { return plugin.unload(self); }

_declspec(dllexport) bool ll_plugin_enable(ll::plugin::Plugin& self) { return plugin.enable(self); }

_declspec(dllexport) bool ll_plugin_disable(ll::plugin::Plugin& self) { return plugin.disable(self); }
}

// The global plugin instance.
Plugin plugin();

LL_AUTO_TYPED_INSTANCE_HOOK(
    PlayerJoinHook,
    ll::memory::HookPriority::Normal,
    ServerPlayer,
    "?setLocalPlayerAsInitialized@ServerPlayer@@QEAAXXZ",
    bool
) {
    return origin();
}
