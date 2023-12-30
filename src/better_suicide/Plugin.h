#pragma once

#include <ll/api/plugin/Plugin.h>

namespace plugins {

class Plugin {
public:
    Plugin(ll::plugin::Plugin& self);

    Plugin(const Plugin&) = delete;

    Plugin(const Plugin&&) = delete;

    Plugin& operator=(const Plugin&) = delete;

    Plugin& operator=(const Plugin&&) = delete;

    ~Plugin() = default;

    /// @return True if the plugin is enabled successfully.
    bool enable();

    /// @return True if the plugin is disabled successfully.
    bool disable();

private:
    ll::plugin::Plugin& mSelf;
};

} // namespace plugins
