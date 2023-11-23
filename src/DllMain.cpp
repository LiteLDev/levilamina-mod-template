#include <ll/api/memory/Hook.h>
#include <ll/api/plugin/Plugin.h>
#include <mc/server/ServerInstance.h>
#include <mc/server/ServerPlayer.h>

#include <Plugin.h>

// The global plugin instance.
Plugin plugin;

extern "C" {
_declspec(dllexport) bool ll_plugin_load(ll::plugin::Plugin& self) { return plugin.load(self); }

_declspec(dllexport) bool ll_plugin_unload(ll::plugin::Plugin& self) { return plugin.unload(self); }

_declspec(dllexport) bool ll_plugin_enable(ll::plugin::Plugin& self) { return plugin.enable(self); }

_declspec(dllexport) bool ll_plugin_disable(ll::plugin::Plugin& self) { return plugin.disable(self); }
}

LL_AUTO_INSTANCE_HOOK(
    AfterServerStartHook,
    ll::memory::HookPriority::Normal,
    "?sendServerThreadStarted@ServerInstanceEventCoordinator@@QEAAXAEAVServerInstance@@@Z",
    void,
    ServerInstance& instance
) {
    plugin.afterServerStart();

    origin(instance);
}

LL_AUTO_TYPED_INSTANCE_HOOK(
    OnPlayerJoinHook,
    ll::memory::HookPriority::Normal,
    ServerPlayer,
    "?setLocalPlayerAsInitialized@ServerPlayer@@QEAAXXZ",
    bool
) {
    bool shouldJoin = plugin.onPlayerJoin(*this);

    if (!shouldJoin) {
        return false;
    }

    return origin();
}
