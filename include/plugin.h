#ifndef LEVILAMINA_EXAMPLE_PLUGIN_PLUGIN_H_
#define LEVILAMINA_EXAMPLE_PLUGIN_PLUGIN_H_

#include <ll/api/Logger.h>
#include <ll/api/plugin/Plugin.h>
#include <mc/server/ServerPlayer.h>

/// @brief Everything about the plugin.
class Plugin {
public:
    /// @param pluginName The plugin name.
    Plugin();

    ~Plugin();

    /// @brief Loads the plugin.
    /// @param self The plugin handle.
    /// @return True if the plugin was loaded successfully.
    bool load(ll::plugin::Plugin& self);

    /// @brief Unloads the plugin.
    /// @param self The plugin handle.
    /// @return True if the plugin was unloaded successfully.
    bool unload(ll::plugin::Plugin& self);

    /// @brief Enables the plugin.
    /// @param self The plugin handle.
    /// @return True if the plugin was enabled successfully.
    bool enable(ll::plugin::Plugin& self);

    /// @brief Disables the plugin.
    /// @param self The plugin handle.
    /// @return True if the plugin was disabled successfully.
    bool disable(ll::plugin::Plugin& self);

    /// @brief Called when a player joins the server.
    /// @param player The player.
    void onPlayerJoin(ServerPlayer* player);

private:
    ll::plugin::Plugin* mSelf;

    std::string_view GetName() const;

    ll::Logger const& GetLogger() const;
};

#endif // LEVILAMINA_EXAMPLE_PLUGIN_PLUGIN_H_
