#pragma once

#include <string_view>

#include <ll/api/Logger.h>
#include <ll/api/plugin/Plugin.h>
#include <mc/server/ServerPlayer.h>

/// @brief Everything about the plugin.
class Plugin {
public:
    Plugin() = default;

    ~Plugin() = default;

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
    /// @return True if the player can join the server.
    bool onPlayerJoin(ServerPlayer& player);

    /// @brief Called after the server has started.
    void afterServerStart();

private:
    ll::plugin::Plugin* mSelf = nullptr;

    ll::Logger const& getLogger() const;

    std::string_view getName() const;

    ll::plugin::Plugin& getSelf() const;
};
